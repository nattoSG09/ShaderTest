#pragma once
#include "Engine/Direct3D.h"
#include <DirectXMath.h>

using namespace DirectX;

//-----------------------------------------------------------
//���C�g
//-----------------------------------------------------------
namespace Light
{
	//�������i�v���W�F�N�V�����s��쐬�j
	void Initialize();

	//���C�g�̈ʒu��ݒ�
	void SetPosition(XMVECTOR position);
	void SetPosition(XMFLOAT3 position);

	XMVECTOR GetPosition();

};