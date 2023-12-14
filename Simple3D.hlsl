//������������������������������������������������������������������������������
 // �e�N�X�`�����T���v���[�f�[�^�̃O���[�o���ϐ���`
//������������������������������������������������������������������������������
Texture2D		g_texture : register(t0);	//�e�N�X�`���[
SamplerState	g_sampler : register(s0);	//�T���v���[

//������������������������������������������������������������������������������
// �R���X�^���g�o�b�t�@
// DirectX �����瑗�M����Ă���A�|���S�����_�ȊO�̏����̒�`
//������������������������������������������������������������������������������
cbuffer gmodel:register(b0)
{
	float4x4	matW;			//���[���h�s��
	float4x4	matWVP;			//���[���h�r���[�v���W�F�N�V�����s��
	float4x4	matNormal;		//�m�[�}��
	float4		diffuseColor;	//�}�e���A���̐F
	float4		ambientColor;	//����
	float4		specularColor;	//���ʔ���
	float		shininess;
	bool		isTextured;		//�e�N�X�`���̗L��
};

cbuffer gmodel:register(b1)
{
	float4		lightPosition;
	float4		eyePosition;
};

//������������������������������������������������������������������������������
// ���_�V�F�[�_�[�o�́��s�N�Z���V�F�[�_�[���̓f�[�^�\����
//������������������������������������������������������������������������������
struct VS_OUT
{
	float4 pos		: SV_POSITION;	//�ʒu
	float2 uv		: TEXCOORD;		//UV���W
	float4 color	: COLOR;	//�F�i���邳�j
	float4 eyev		: POSITION;
	float4 normal	: NORMAL;
};

//������������������������������������������������������������������������������
// ���_�V�F�[�_
//������������������������������������������������������������������������������
VS_OUT VS(float4 pos : POSITION, float4 uv : TEXCOORD, float4 normal : NORMAL)
{
	//�s�N�Z���V�F�[�_�[�֓n�����
	VS_OUT outData;

	// ���[�J�����W�ɁA���[���h�E�r���[�E�v���W�F�N�V�����s���������
	// �X�N���[�����W�ɕϊ����A�s�N�Z���V�F�[�_�[��
	outData.pos = mul(pos, matWVP);
	
	// ���̂܂�
	outData.uv = uv;

	// ���ɂ͂O������Ė@������n��
	normal.w = 0;
	normal = mul(normal, matNormal);
	normal = normalize(normal);
	outData.normal = normal;

	// ���C�g�|�W�V�������猴�_�֌����������x�N�g���𐶐�����
	float4 light = normalize(lightPosition);
	
	// ���[���h���W�����������_�ƃJ�����ʒu�����񂾎����x�N�g�����쐬
	outData.color = saturate(dot(normal, light));
	float4 posw = mul(pos, matW);
	outData.eyev = eyePosition - posw;

	//�܂Ƃ߂ďo��
	return outData;
}

//������������������������������������������������������������������������������
// �s�N�Z���V�F�[�_
//������������������������������������������������������������������������������
float4 PS(VS_OUT inData) : SV_Target
{
    float4 lightSource = float4(1.0, 1.0, 1.0, 1.0);	//���ˌ��̋��� & �F	Iin
    //float4 ambientSource = float4(0.2, 0.2, 0.2, 1.0);	//�����W��		Ka
    float4 diffuse;
    float4 ambient;

	//���ʔ��˓K�p����
	float4 NL = dot(inData.normal, normalize(lightPosition));
	//float4 reflect = normalize(2 * NL * inData.normal - normalize(lightPosition));
	float4 r = reflect(normalize(-lightPosition), inData.normal);
	float4 specular = pow(saturate(dot(r, normalize(inData.eyev))), shininess) * specularColor;

    if (isTextured == false)
    {
        diffuse = lightSource * diffuseColor * inData.color;
        ambient = lightSource * diffuseColor * ambientColor;
    }
    else
    {
        diffuse = lightSource * g_texture.Sample(g_sampler, inData.uv) * inData.color;
        ambient = lightSource * g_texture.Sample(g_sampler, inData.uv) * ambientColor;
    }
    
    return  ambient + diffuse + specular;
}