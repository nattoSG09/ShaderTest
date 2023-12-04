#pragma once
#include <DirectXMath.h>
using namespace DirectX;

XMFLOAT3 ConvertXMFLOAT4ToXMFLOAT3(const XMFLOAT4& float4Vector) {
    XMFLOAT3 float3Vector;
    float3Vector.x = float4Vector.x;
    float3Vector.y = float4Vector.y;
    float3Vector.z = float4Vector.z;
    return float3Vector;
}

XMFLOAT3 ConvertXMVECTORToXMFLOAT3(const DirectX::XMVECTOR& vector) {
    XMFLOAT3 float3Vector;
    DirectX::XMStoreFloat3(&float3Vector, vector);
    return float3Vector;
}