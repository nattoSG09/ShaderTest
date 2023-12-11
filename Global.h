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

XMFLOAT4 ConvertXMFLOAT3ToXMFLOAT4(const XMFLOAT3& float3Vector) {
    XMFLOAT4 float4Vector;
    float4Vector.x = float3Vector.x;
    float4Vector.y = float3Vector.y;
    float4Vector.z = float3Vector.z;
    float4Vector.w = 0;
    return float4Vector;

}

XMFLOAT3 ConvertXMVECTORToXMFLOAT3(const DirectX::XMVECTOR& vector) {
    XMFLOAT3 float3Vector;
    DirectX::XMStoreFloat3(&float3Vector, vector);
    return float3Vector;
}


XMFLOAT4 ConvertXMVECTORToXMFLOAT4(const DirectX::XMVECTOR& vector) {
    XMFLOAT4 float4Vector;
    DirectX::XMStoreFloat4(&float4Vector, vector);
    return float4Vector;
}

XMVECTOR ConvertXMFLOAT4ToXMVECTOR(const XMFLOAT4& float4Vector) {
    // XMFLOAT4‚©‚çXMVECTOR‚Ö‚Ì•ÏŠ·
    return XMLoadFloat4(&float4Vector);
}

XMVECTOR ConvertXMFLOAT3ToXMVECTOR(const XMFLOAT3& float3Vector) {
    // XMFLOAT4‚©‚çXMVECTOR‚Ö‚Ì•ÏŠ·
    return XMLoadFloat3(&float3Vector);
}
