#pragma once
#include "Engine/Direct3D.h"
#include <DirectXMath.h>

using namespace DirectX;

//-----------------------------------------------------------
//ライト
//-----------------------------------------------------------
namespace Light
{
	//初期化（プロジェクション行列作成）
	void Initialize();

	//ライトの位置を設定
	void SetPosition(XMVECTOR position);
	void SetPosition(XMFLOAT3 position);

	XMVECTOR GetPosition();

};