#pragma once
#include "Engine/GameObject.h"

struct CBUFF_STAGESCENE
{
    XMFLOAT4 lightPosition;
    XMFLOAT4 eyePosition;
};

//◆◆◆を管理するクラス
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
    //コンストラクタ
    Stage(GameObject* parent);

    //デストラクタ
    ~Stage();

    //初期化
    void Initialize() override;

    //更新
    void Update() override;

    //描画
    void Draw() override;

    //開放
    void Release() override;
};