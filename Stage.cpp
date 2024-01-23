#include "Stage.h"
#include "Engine/Model.h"
#include "Light.h"
#include "Global.h"
#include "Engine/Input.h"
#include "Engine/Camera.h"

void Stage::InitConstantBuffer()
{
    D3D11_BUFFER_DESC cb;
    cb.ByteWidth = sizeof(CBUFF_STAGESCENE);
    cb.Usage = D3D11_USAGE_DEFAULT;
    cb.BindFlags = D3D11_BIND_CONSTANT_BUFFER;
    cb.CPUAccessFlags = 0;
    cb.MiscFlags = 0;
    cb.StructureByteStride = 0;

    // �R���X�^���g�o�b�t�@�̍쐬
    HRESULT hr;
    hr = Direct3D::pDevice_->CreateBuffer(&cb, nullptr, &pCBStageScene_);
    if (FAILED(hr))
    {
        MessageBox(NULL, "�R���X�^���g�o�b�t�@�̍쐬�Ɏ��s���܂���", "�G���[", MB_OK);
    }
}

//�R���X�g���N�^
Stage::Stage(GameObject* parent)
    :GameObject(parent, "Stage"), hmGround_(-1),hmArrow_(-1),hmSphere_(-1), hmLightPos_(-1), hmDonuts_(-1),
    lightSourcePosition_(ConvertXMVECTORToXMFLOAT4(Light::GetPosition()))
{
}

//�f�X�g���N�^
Stage::~Stage()
{
}

//������
void Stage::Initialize()
{
    hmDonuts_ = Model::Load("Assets/download/Torus.fbx");
    assert(hmDonuts_ >= 0);

    InitConstantBuffer();
}

//�X�V
void Stage::Update()
{
    XMFLOAT3 lightPos = ConvertXMVECTORToXMFLOAT3(Light::GetPosition());

    if (Input::IsKey(DIK_W))lightPos.z+= 0.1f;
    if (Input::IsKey(DIK_A))lightPos.x-= 0.1f;
    if (Input::IsKey(DIK_S))lightPos.z-= 0.1f;
    if (Input::IsKey(DIK_D))lightPos.x += 0.1f;
    if (Input::IsKey(DIK_UP))lightPos.y += 0.1f;
    if (Input::IsKey(DIK_DOWN))lightPos.y-= 0.1f;

    Light::SetPosition(lightPos);

    CBUFF_STAGESCENE cb;
    cb.lightPosition = XMFLOAT4(lightPos.x,lightPos.y,lightPos.z,0);
    cb.eyePosition = ConvertXMVECTORToXMFLOAT4(Camera::GetPosition());
    Direct3D::pContext_->UpdateSubresource(pCBStageScene_, 0, NULL, &cb, 0, 0);

    Direct3D::pContext_->VSSetConstantBuffers(1, 1, &pCBStageScene_);	//���_�V�F�[�_�[�p	
    Direct3D::pContext_->PSSetConstantBuffers(1, 1, &pCBStageScene_);	//�s�N�Z���V�F�[�_�[�p

}

//�`��
void Stage::Draw()
{
    //- -  Donuts  - -//
    static Transform tDonuts; {
        tDonuts.rotate_.y += 0.2f;
        tDonuts.rotate_.z +=0.2f;
    }
    Model::SetTransform(hmDonuts_, tDonuts);

    Direct3D::SetShader(SHADER_NORMALMAP);
    Model::Draw(hmDonuts_);
}

//�J��
void Stage::Release()
{
}