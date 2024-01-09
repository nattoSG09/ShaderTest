//───────────────────────────────────────
 // テクスチャ＆サンプラーデータのグローバル変数定義
//───────────────────────────────────────
Texture2D       g_texture : register(t0);   //テクスチャー
SamplerState    g_sampler : register(s0);   //サンプラー

Texture2D       g_toon_texture : register(t1);  //テクスチャー


//───────────────────────────────────────
// コンスタントバッファ
// DirectX 側から送信されてくる、ポリゴン頂点以外の諸情報の定義
//───────────────────────────────────────
cbuffer gmodel:register(b0)
{
    float4x4    matW;           //ワールド行列
    float4x4    matWVP;         //ワールドビュープロジェクション行列
    float4x4    matNormal;      //ノーマル
    float4      diffuseColor;   //マテリアルの色
    float4      ambientColor;   //環境光
    float4      specularColor;  //鏡面反射
    float       shininess;
    bool        isTextured;     //テクスチャの有無
};

cbuffer gmodel:register(b1)
{
    float4      lightPosition;
    float4      eyePosition;
};

//───────────────────────────────────────
// 頂点シェーダー出力＆ピクセルシェーダー入力データ構造体
//───────────────────────────────────────
struct VS_OUT
{
    float4 pos      : SV_POSITION;  //位置
    float2 uv       : TEXCOORD;     //UV座標
    float4 color    : COLOR;    //色（明るさ）
    float4 eyev     : POSITION;
    float4 normal   : NORMAL;
};

//───────────────────────────────────────
// 頂点シェーダ
//───────────────────────────────────────
VS_OUT VS(float4 pos : POSITION, float4 uv : TEXCOORD, float4 normal : NORMAL)
{
    //ピクセルシェーダーへ渡す情報
    VS_OUT outData;

    // ローカル座標に、ワールド・ビュー・プロジェクション行列をかけて
    // スクリーン座標に変換し、ピクセルシェーダーへ
    pos = pos + normal * 0.05f;
    outData.pos = mul(pos, matWVP);

    // そのまま
    outData.uv = uv;

    // ｗには０をいれて法線情報を渡す
    normal.w = 0;
    normal = mul(normal, matNormal);
    normal = normalize(normal);
    outData.normal = normal;

    // ライトポジションから原点へ向かう方向ベクトルを生成する
    float4 light = normalize(lightPosition);

    // ワールド座標をかけた頂点とカメラ位置を結んだ視線ベクトルを作成
    outData.color = saturate(dot(normal, light));
    float4 posw = mul(pos, matW);
    outData.eyev = eyePosition - posw;

    //まとめて出力
    return outData;
}


//───────────────────────────────────────
// ピクセルシェーダ
//───────────────────────────────────────
float4 PS(VS_OUT inData) : SV_Target
{
    //return float4(1,1,1,0);
    float2 uv;
    uv.x = inData.color.x;
    uv.y = 0.f;



    //視線ベクトルと面の法線の角度が９０度付近なら...
    float d = abs(dot(normalize(inData.eyev), inData.normal));
    if (abs(d) < 0.25f) {
        return float4(1, 1, 1, 1);
    }
    else
    return float4(0,0,0, 1);
}
