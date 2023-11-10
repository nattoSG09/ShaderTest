#include "Stage.h"
#include "Engine/Model.h"

//コンストラクタ
Stage::Stage(GameObject* parent)
    :GameObject(parent, "Stage"),pSprite_(nullptr)
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

    pSprite_ = new Sprite;
    pSprite_->Initialize();
}

//更新
void Stage::Update()
{
}

//描画
void Stage::Draw()
{
    pSprite_->Draw(transform_);
}

//開放
void Stage::Release()
{
    pSprite_->Release();
}