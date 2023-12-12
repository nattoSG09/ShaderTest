#include "Light.h"

namespace Light
{
	//�ϐ�
	XMVECTOR position_;	//���C�g�̈ʒu
}

void Light::Initialize()
{
	position_ = XMVectorSet(0, 0, 1, 0);
}

void Light::SetPosition(XMVECTOR position)
{
	position_ = position;
}

void Light::SetPosition(XMFLOAT3 position)
{
	SetPosition(XMLoadFloat3(&position));
}

XMVECTOR Light::GetPosition()
{
    return position_;
}
