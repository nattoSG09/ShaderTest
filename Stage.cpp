#include "Stage.h"
#include "Engine/Model.h"
#include "Light.h"
#include "Global.h"
#include "Engine/Input.h"

//コンストラクタ
Stage::Stage(GameObject* parent)
    :GameObject(parent, "Stage"), hmGround_(-1),hmArrow_(-1),hmSphere_(-1), hmLightPos_(-1), hmDonuts_(-1)
{
}

//デストラクタ
Stage::~Stage()
{
}

//初期化
void Stage::Initialize()
{
    //モデルデータのロード
    hmGround_ = Model::Load("Assets/ShaderTest/Ground.fbx");
    assert(hmGround_ >= 0);

    //モデルデータのロード
    hmArrow_ = Model::Load("Assets/ShaderTest/Arrow.fbx");
    assert(hmArrow_ >= 0);

    //モデルデータのロード
    hmSphere_ = Model::Load("Assets/ShaderTest/Sphere.fbx");
    assert(hmSphere_ >= 0);

    hmLightPos_ = Model::Load("Assets/ShaderTest/Sphere.fbx");
    assert(hmLightPos_ >= 0);

    hmDonuts_ = Model::Load("Assets/ShaderTest/donuts.fbx");
    assert(hmDonuts_ >= 0);
}

//更新
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

}

//描画
void Stage::Draw()
{
    //- -  Ground  - -//
    static Transform tGround; {
        tGround.position_.y = -1.0f;
        tGround.scale_ = { 10.0f,1.0f,10.0f };
    }
    Model::SetTransform(hmGround_, tGround);
    //Model::Draw(hmGround_);

    //- -  Arrow  - -//
    static Transform tArrow; {
        tArrow.scale_ = { 0.5f,0.5f,0.5f };
        tArrow.position_.y = 2.0f;
        tArrow.rotate_.y += 1.0f;

    }
    Model::SetTransform(hmArrow_, tArrow);
    //Model::Draw(hmArrow_);

    //- -  Sphere  - -//
    static Transform tSphere; {
        tSphere.rotate_.y += 1.0f;
    }
    Model::SetTransform(hmSphere_, tSphere);
    //Model::Draw(hmSphere_);

    //- -  Light  - -//
    static Transform tLightPos; {
        tLightPos.scale_ = { 0.2f,0.2f,0.2f };
        tLightPos.position_ = ConvertXMVECTORToXMFLOAT3(Light::GetPosition());
    }
    Model::SetTransform(hmLightPos_, tLightPos);
    Model::Draw(hmLightPos_);

    //- -  Donuts  - -//
    static Transform tDonuts; {
    }
    Model::SetTransform(hmDonuts_, tDonuts);
    Model::Draw(hmDonuts_);
}

//開放
void Stage::Release()
{
}