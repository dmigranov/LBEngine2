cbuffer PerApplication : register(b0)
{
	matrix projectionMatrixFront;
	matrix projectionMatrixBack;
	double density;
	double radius;
	double radiusOld;
	double deltaTime;
}

cbuffer PerFrame : register(b1)
{
	matrix viewMatrixFront;
}

cbuffer PerObject : register(b2)
{
	matrix worldMatrix;
}

const float epsilon = 0.001;

//POSITION and COLOR are semantics that are used to link vs variables to ps variables
struct VertexShaderInput
{
	float4 position : POSITION;
	float2 tex : TEXCOORD0;
};

struct VertexShaderOutput
{
	float2 tex : TEXCOORD0;
	float fogFactor : FOG_FACTOR;
	float velocity : VELOCITY;
	float4 position : SV_POSITION;
};

float SphericalDistance(float4 vec1, float4 vec2, float radius)
{
	float chordLength = distance(vec1, vec2); //????? ?????
	return 2 * radius * asin(chordLength / (2.f * radius)); //???? - 2arcsin(L/2R), ????? ???? = ???? * R
}

//entry point
VertexShaderOutput main(VertexShaderInput IN, uint instanceID : SV_InstanceID)
{
	matrix viewMatrixBack = -viewMatrixFront;
	VertexShaderOutput OUT;
 
	matrix viewMatrix, projectionMatrix;

	//PROJECTION ? ??? ????!
	if (instanceID == 0)
	{
		projectionMatrix = projectionMatrixFront;
		viewMatrix = viewMatrixFront;
	}
	else if (instanceID == 1)
	{
		projectionMatrix = projectionMatrixBack;
		viewMatrix = viewMatrixBack;
	}
	
	//IN.position: sum of squares must be 1!

	matrix viewWorld = mul(viewMatrix, worldMatrix);

	float4 position; //???????? ???????
	float4 position1 = normalize(IN.position); //??????????????? ??????????: ????? ?? ????????? ??????????
	if (abs(position1.w - 1) < 0.00001)
		position = position1 * radius;
	else
	{
		float4 objectCenter1 = float4(0, 0, 0, 1); //?????????? ?????? ??????? ??? ????????? ?????????? ? ??????????? world
		float distanceFromPointToCenter = SphericalDistance(position1, objectCenter1, 1.); //must stay the same!
	
		float w_new = radius * (1 - 2 * pow(sin(distanceFromPointToCenter / (2 * radius)), 2));
		float lambda = sqrt((position1.x * position1.x + position1.y * position1.y + position1.z * position1.z) / (radius * radius - w_new * w_new));
		float x_new = position1.x / lambda, y_new = position1.y / lambda, z_new = position1.z / lambda;
		position = float4(x_new, y_new, z_new, w_new);
	}


	float4 cameraSpacePosition = mul(viewWorld, position);
	float distance = SphericalDistance(float4(0, 0, 0, radius), cameraSpacePosition, radius);
	
	OUT.position = mul(projectionMatrix, cameraSpacePosition);
	OUT.tex = IN.tex;

	OUT.fogFactor = saturate(exp(-density * distance));

	double distanceCenter; //?????????? ?? ??????????? ?? ?????? ???????, ????? ??? ???? ??? ????? ???? ????????? (????? ???? ?????? - ????? distance)
	distanceCenter = SphericalDistance(float4(0, 0, 0, radius), mul(viewWorld, float4(0, 0, 0, radius)), radius);
	double distDiff = distanceCenter * (1. - radiusOld / radius);
	OUT.velocity = distDiff / deltaTime; //?????? ??? ?????? ????? ???????!
	
	return OUT;
}