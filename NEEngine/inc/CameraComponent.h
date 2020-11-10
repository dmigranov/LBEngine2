#pragma once
#include "Component.h"
class CameraComponent :
    public Component
{
public:
	CameraComponent(bool isPerspective = true);
	CameraComponent(double nearPlane, double farPlane, double aspect = 1., double fovY = 90., bool isPerspective = true);
	const DirectX::XMMATRIX& GetProj();

	void SetFovY(double fovY);
	void SetAspect(double aspect);
	void SetOutputSize(double width, double height);

	void SetPerspective(bool isPerspective);
	void SetOrthogonalWidth(double width);
private:
	void RecalculateProj();

	double m_fovY;
	double m_nearPlane,  m_farPlane;
	double m_aspect;
	double m_width = -1, m_height = -1;
	double m_orthoWidth = 1;

	bool m_shouldRecalc;
	bool m_isPerspective;
	DirectX::SimpleMath::Matrix m_proj;
};

