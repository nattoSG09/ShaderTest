#pragma once
#include "Engine/GameObject.h"

struct CBUFF_STAGESCENE
{
    XMFLOAT4 lightPosition;
    XMFLOAT4 eyePosition;
};

//���������Ǘ�����N���X
class Stage : public GameObject
{
    int hmGround_;
    int hmArrow_;
    int hmSphere_;
    int hmLightPos_;
    int hmDonuts_;

    void InitConstantBuffer();
    XMFLOAT4 lightSourcePosition_;

    ID3D11Buffer* pCBStageScene_;

public:
    //�R���X�g���N�^
    Stage(GameObject* parent);

    //�f�X�g���N�^
    ~Stage();

    //������
    void Initialize() override;

    //�X�V
    void Update() override;

    //�`��
    void Draw() override;

    //�J��
    void Release() override;
};