cbuffer PerApplication : register(b0)
{
	matrix projectionMatrixFront;
	matrix projectionMatrixBack;
	double density;
	double radius;
}

cbuffer PerFrame : register(b1)
{
	matrix viewMatrixFront;
}

cbuffer PerObject : register(b2)
{
	matrix worldMatrix;
}

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
	float4 position : SV_POSITION;
};

float SphericalDistance(float4 vec1, float4 vec2, float radius)
{
	float chordLength = distance(vec1, vec2); //����� �����
	return 2 * radius * asin(chordLength / (2.f * radius)); //���� - 2arcsin(L/2R), ����� ���� = ���� * R
}

//entry point
VertexShaderOutput main(VertexShaderInput IN, uint instanceID : SV_InstanceID)
{
	matrix viewMatrixBack = -viewMatrixFront;
	VertexShaderOutput OUT;
 
	matrix viewMatrix, projectionMatrix;


	if (instanceID % 2 == 0)
	{
		projectionMatrix = projectionMatrixFront;
		viewMatrix = viewMatrixFront;
	}
	else if (instanceID % 2 == 1)
	{
		projectionMatrix = projectionMatrixBack;
		viewMatrix = viewMatrixBack;
	}
	
	//IN.position: ������ ������ � ����� 1!
	matrix viewWorld = mul(viewMatrix, worldMatrix);

	float4 position1 = normalize(IN.position); //��������������� ����������: ����� �� ��������� ����������
	float4 objectCenter1 = float4(0, 0, 0, 1); //���������� ������ ������� ��� ��������� ���������� � ����������� world
	float distanceFromPointToCenter = SphericalDistance(position1, objectCenter1, 1); //must stay the same!
	float w_new = radius * (1 - 2 * pow(sin(distanceFromPointToCenter / (2 * radius)), 2));

	float4 position = radius * position1; 	//todo: ���������� ������� (��� �����������: �� ����������� �������, ������ � �������)

	float4 cameraSpacePosition = mul(viewWorld, position);
	//float chordLength = distance(float4(0, 0, 0, radius), cameraSpacePosition); //����� �����
	//float distance = 2 * radius * asin(chordLength / (2. * radius));
	float distance = SphericalDistance(float4(0, 0, 0, radius), cameraSpacePosition, radius);
	
	OUT.position = mul(projectionMatrix, cameraSpacePosition);
	OUT.tex = IN.tex;

	OUT.fogFactor = saturate(exp(-density * distance));
	
	return OUT;
}