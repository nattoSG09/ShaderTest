#include "Stage.h"
#include "Engine/Model.h"

//コンストラクタ
Stage::Stage(GameObject* parent)
    :GameObject(parent, "Stage"), hmGround_(-1),hmArrow_(-1),hmSphere_(-1)
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
}

//更新
void Stage::Update()
{
}

//描画
void Stage::Draw()
{
    static Transform tGround; {
        tGround.position_.y = -1.0f;
        tGround.scale_ = { 10.0f,1.0f,10.0f };
    }
    Model::SetTransform(hmGround_, tGround);
    Model::Draw(hmGround_);

    static Transform tArrow; {
        tArrow.position_.y = 2.0f;
        tArrow.rotate_.y += 1.0f;

    }
    Model::SetTransform(hmArrow_, tArrow);
    Model::Draw(hmArrow_);

    static Transform tSphere; {
        tSphere.rotate_.y += 1.0f;
    }
    Model::SetTransform(hmSphere_, tSphere);
    Model::Draw(hmSphere_);
}

//開放
void Stage::Release()
{
}