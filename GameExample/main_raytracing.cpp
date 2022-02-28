#pragma once

#include "main.h"

using namespace DirectX;
using namespace DirectX::SimpleMath;

//xyzw
XMFLOAT3 GetSphericalFromCartesian(float x4, float x3, float x2, float x1)
{
    float x42 = x4 * x4;
    float x22 = x2 * x2;
    float x32 = x3 * x3;

    float a1 = acosf(x1);
    if (x2 == 0 && x3 == 0 && x4 == 0)
        if (x1 > 0)
            return Vector3(a1, 0, 0);
        else
            return Vector3(a1, XM_PI, XM_PI);

    float a2 = acosf(x2 / sqrtf(x22 + x32 + x42));
    if (x3 == 0 && x4 == 0)
        if (x2 > 0)
            return Vector3(a1, a2, 0);
        else
            return Vector3(a1, a2, XM_PI);

    float a3;
    if (x4 >= 0)
        a3 = acosf(x3 / sqrtf(x32 + x42));
    else
        a3 = XM_2PI - acosf(x3 / sqrtf(x32 + x42));

    return XMFLOAT3(a1, a2, a3);
}


double RayTraceSpherePos(DirectX::SimpleMath::Vector4 sphericalPosition, DirectX::SimpleMath::Vector3 rayStart, 
    DirectX::SimpleMath::Vector3 direction, 
    DirectX::SimpleMath::Matrix view, DirectX::SimpleMath::Matrix proj, double r_projected_sq) {
    auto pos_world = sphericalPosition;
    auto pos = Vector4::Transform(pos_world, view); //pos_view

    if (pos.z < 0)
        return -1;

    auto pos_w = pos.w;
    //auto posProj_4D = Vector4(pos.x / pos_w, pos.y / pos_w, pos.z / pos_w, 1.f);
    //auto posProj = Vector3(pos.x / pos_w, pos.y / pos_w, pos.z / pos_w);

    auto posProj_4D = Vector4::Transform(pos, proj);
    auto posProj = Vector3(posProj_4D.x / posProj_4D.w, posProj_4D.y / posProj_4D.w, posProj_4D.z / posProj_4D.w);

    Vector3 centerToBeginning = posProj - rayStart; // rayStart = 0, so centerToBeginning = posProj
    double lenToCenterOfSphere_sq = pow(centerToBeginning.x, 2) + pow(centerToBeginning.y, 2) + pow(centerToBeginning.z, 2);
    
    // inside this sphere
    if (lenToCenterOfSphere_sq < r_projected_sq) 
    {
        return -1;   //camera is inside of this sphere so no need
    }

    // ray starts outside this sphere
    float lenClosestPoint = centerToBeginning.Dot(direction);  //���������� �� ������ ���� �� ��������� � ������ ����� ����� ����
    if (lenClosestPoint < 0)
    {
        return -1; //ray doesn't intersect
    }

    //todo: ���������� ������ ������
    double thc_sq = r_projected_sq - lenToCenterOfSphere_sq + lenClosestPoint * lenClosestPoint;
    if (thc_sq < 0)
    {
        return -1; //ray doesn't intersect
    }


    double thc = sqrt(thc_sq);
    double t = lenClosestPoint - thc; //t is the distance to the intersection point
    return t;
}


double RayTraceSphereNeg(DirectX::SimpleMath::Vector4 sphericalPosition, DirectX::SimpleMath::Vector3 rayStart, DirectX::SimpleMath::Vector3 direction, DirectX::SimpleMath::Matrix view, double r_projected_sq) {
    auto pos_world = sphericalPosition;
    auto pos = Vector4::Transform(pos_world, view); //pos_view
    auto pos_w = -pos.w;
    auto posProj_4D = Vector4(pos.x / pos_w, pos.y / pos_w, pos.z / pos_w, 1.f);
    auto posProj = Vector3(pos.x / pos_w, pos.y / pos_w, pos.z / pos_w);

    Vector3 centerToBeginning = posProj - rayStart; // rayStart = 0, so centerToBeginning = posProj
    double lenToCenterOfSphere_sq = pow(centerToBeginning.x, 2) + pow(centerToBeginning.y, 2) + pow(centerToBeginning.z, 2);

    // inside this sphere
    if (lenToCenterOfSphere_sq < r_projected_sq)
    {
        std::cout << "inside" << std::endl;
        return -1;   //camera is inside of this sphere so no need
    }

    // ray starts outside this sphere
    float lenClosestPoint = centerToBeginning.Dot(direction);  //���������� �� ������ ���� �� ��������� � ������ ����� ����� ����
    //std::cout << lenClosestPoint << std::endl;
    if (lenClosestPoint < 0)
    {
        return -1; //ray doesn't intersect
    }

    double thc_sq = r_projected_sq - lenToCenterOfSphere_sq + lenClosestPoint * lenClosestPoint;
    if (thc_sq < 0)
    {
        return -1; //ray doesn't intersect
    }

    double thc = sqrt(thc_sq);
    double t = lenClosestPoint - thc; //t is the distance to the intersection point
    return t;
}

double RayTraceSphereMouse(double mouseX, double mouseY, SphericalTransformComponent* pSphericalTransform, DirectX::SimpleMath::Matrix view, DirectX::SimpleMath::Matrix proj, double r_sphere, double w_sphere)
{
    const auto& world = pSphericalTransform->GetWorld();
    auto sphericalPosition = pSphericalTransform->GetSphericalPosition();
    auto pos_world = sphericalPosition;
    auto pos = Vector4::Transform(pos_world, view); //pos_view

    //if (pos.z < 0)  //todo: ������ ���������
    //    return -1;

    auto radius = SphericalEffect::GetRadius();

    Matrix matrixPosRadiusY(1, 0, 0, 0, 0, w_sphere, 0, r_sphere, 0, 0, 1, 0, 0, -r_sphere, 0, w_sphere);
    Matrix matrixNegRadiusY(1, 0, 0, 0, 0, w_sphere, 0, -r_sphere, 0, 0, 1, 0, 0, r_sphere, 0, w_sphere);
    Matrix matrixPosRadiusX(w_sphere/ radius, 0, 0, r_sphere/ radius,  0, 1, 0, 0, 0, 0, 1, 0, -r_sphere/radius, 0, 0, w_sphere/ radius);
    Matrix matrixNegRadiusX(w_sphere/ radius, 0, 0, -r_sphere/ radius, 0, 1, 0, 0, 0, 0, 1, 0, r_sphere/ radius, 0, 0, w_sphere/ radius);

    Vector4 viewRadiusVectorX1 = Vector4::Transform(pos, matrixPosRadiusX), viewRadiusVectorX2 = Vector4::Transform(pos, matrixNegRadiusX);
    Vector4 projectedRadiusVectorX1 = Vector4::Transform(viewRadiusVectorX1, proj), projectedRadiusVectorX2 = Vector4::Transform(viewRadiusVectorX2, proj);
    if (projectedRadiusVectorX1.w == 0 || projectedRadiusVectorX2.w == 0)
        return -1;
    projectedRadiusVectorX1 /= projectedRadiusVectorX1.w;
    projectedRadiusVectorX2 /= projectedRadiusVectorX2.w;
    auto distSqX = (projectedRadiusVectorX1.x - projectedRadiusVectorX2.x) / 2;
    distSqX = distSqX * distSqX;

    Vector4 viewRadiusVectorY1 = Vector4::Transform(pos, matrixPosRadiusY), viewRadiusVectorY2 = Vector4::Transform(pos, matrixNegRadiusY);
    Vector4 projectedRadiusVectorY1 = Vector4::Transform(viewRadiusVectorY1, proj), projectedRadiusVectorY2 = Vector4::Transform(viewRadiusVectorY2, proj);
    if (projectedRadiusVectorY1.w == 0 || projectedRadiusVectorY2.w == 0)
        return -1;
    projectedRadiusVectorY1 /= projectedRadiusVectorY1.w;
    projectedRadiusVectorY2 /= projectedRadiusVectorY2.w;
    auto distSqY = (projectedRadiusVectorY1.y - projectedRadiusVectorY2.y) / 2;
    distSqY = distSqY * distSqY;

    double distSq = max(distSqX, distSqY);

    auto posProj_4D = Vector4::Transform(pos, proj);
    if (posProj_4D.w == 0)
        return -1;
    auto posProj = Vector3(posProj_4D.x / posProj_4D.w, posProj_4D.y / posProj_4D.w, posProj_4D.z / posProj_4D.w);
   
    auto distFromCursorToCenterSq = pow(posProj.x - mouseX, 2) + pow(posProj.y - mouseY, 2);
    if (distFromCursorToCenterSq > distSq)
        return -1;

    //unproject after projecting? 
    //Viewport::Unproject;
    //Viewport::Project;

    //std::cout << projectedRadiusVectorY1.x << " " << projectedRadiusVectorY1.y << " " << projectedRadiusVectorY1.z << std::endl;
    //std::cout << projectedRadiusVectorY2.x << " " << projectedRadiusVectorY2.y << " " << projectedRadiusVectorY2.z << std::endl;
    //std::cout << posProj.z << " " << pos.z << std::endl;

    if (pos.z < 0)
        return posProj.z + 1;
    return posProj.z; 
}

// todo: ����: ��� ������������� ������������ ������ view - ������������ view �� �������, ������������� � (����� - ������ �������� �� z) � �������
// ��� ����� �������� �������� w 

// ����: ����� ���� �� ���� �������� (����� ��������� ��� � ������������� z ����� ���������� view, � �����, �� ���� - ����� ���� ����� ��������)
// ������������ �������������, � ��������� �������� ������ �� ��������� ��������� �������� �����. ������������ �������� - ���������� ������ ������ �������������
// (����������� � RayTraceSphereMouse)

// todo: ��� ��������� � ����������� ����? ��������� ������ ���������� rayDirection; ��� ����� ������� � �� ���������� ��������