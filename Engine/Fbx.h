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
	//�}�e���A��
	struct MATERIAL
	{
		Texture* pTexture;
		Texture* pNormalTexture;
		XMFLOAT4 diffuse;
		XMFLOAT4 ambient;
		XMFLOAT4 specular;
		float shininess;
	};

	struct CONSTANT_BUFFER
	{
		XMMATRIX	matW;			//���[���h�s��
		XMMATRIX	matWVP;			//���[���h�r���[�v���W�F�N�V�����s��
		XMMATRIX	matNormal;		//�m�[�}��
		XMFLOAT4	diffuseColor;	//�F
		XMFLOAT4	ambientColor;	//�F
		XMFLOAT4	specularColor;	//�F
		float		shininess;
		int			isTextured;		//�e�N�X�`���̗L��
		bool		isNormalTexture;
	};

	struct VERTEX
	{
		XMVECTOR position;//�ʒu
		XMVECTOR uv; //�e�N�X�`�����W
		XMVECTOR normal; //�@���x�N�g��
		XMVECTOR tangent;// �ڐ�
	};

	int vertexCount_;	//���_��
	int polygonCount_;	//�|���S����
	int materialCount_;	//�}�e���A���̌�

	ID3D11Buffer* pVertexBuffer_;
	ID3D11Buffer** pIndexBuffer_;
	ID3D11Buffer* pConstantBuffer_;
	MATERIAL* pMaterialList_;
	vector <int> indexCount_;
	
	void InitVertex(fbxsdk::FbxMesh* mesh);
	void InitIndex(fbxsdk::FbxMesh* mesh);
	void IntConstantBuffer();
	void InitMaterial(fbxsdk::FbxNode* pNode);

	Texture* pToonTex_;
public:
	
	Fbx();
	HRESULT Load(std::string fileName);
	void    Draw(Transform& transform);
	void    Release();
};