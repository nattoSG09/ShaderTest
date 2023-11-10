#include "Stage.h"
#include "Engine/Model.h"

//�R���X�g���N�^
Stage::Stage(GameObject* parent)
    :GameObject(parent, "Stage"),pSprite_(nullptr)
{
}

//�f�X�g���N�^
Stage::~Stage()
{
}

//������
void Stage::Initialize()
{
    //���f���f�[�^�̃��[�h

    pSprite_ = new Sprite;
    pSprite_->Initialize();
}

//�X�V
void Stage::Update()
{
}

//�`��
void Stage::Draw()
{
    pSprite_->Draw(transform_);
}

//�J��
void Stage::Release()
{
    pSprite_->Release();
}