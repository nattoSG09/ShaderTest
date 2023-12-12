#pragma once

#include <d3d11.h>
#include <fbxsdk.h>
#include <string>
#include "Transform.h"
#include <vector>


#pragma comment(lib, "LibFbxSDK-MD.lib")
#pragma comment(lib, "LibXml2-MD.lib")
#pragma comment(lib, "zlib-MD.lib")

using std::vector;

class Texture;

class Fbx
{
	//マテリアル
	struct MATERIAL
	{
		Texture* pTexture;
		XMFLOAT4 diffuse;
		XMFLOAT4 ambient;
		XMFLOAT4 specular;
		float shininess;
	};

	struct CONSTANT_BUFFER
	{
		XMMATRIX	matW;			//ワールド行列
		XMMATRIX	matWVP;			//ワールドビュープロジェクション行列
		XMMATRIX	matNormal;		//ノーマル
		XMFLOAT4	diffuseColor;	//色
		int			isTextured;		//テクスチャの有無
	};

	struct VERTEX
	{
		XMVECTOR position;//位置
		XMVECTOR uv; //テクスチャ座標
		XMVECTOR normal; //法線ベクトル
	};

	int vertexCount_;	//頂点数
	int polygonCount_;	//ポリゴン数
	int materialCount_;	//マテリアルの個数

	ID3D11Buffer* pVertexBuffer_;
	ID3D11Buffer** pIndexBuffer_;
	ID3D11Buffer* pConstantBuffer_;
	MATERIAL* pMaterialList_;
	vector <int> indexCount_;
	
	void InitVertex(fbxsdk::FbxMesh* mesh);
	void InitIndex(fbxsdk::FbxMesh* mesh);
	void IntConstantBuffer();
	void InitMaterial(fbxsdk::FbxNode* pNode);
public:
	
	Fbx();
	HRESULT Load(std::string fileName);
	void    Draw(Transform& transform);
	void    Release();
};