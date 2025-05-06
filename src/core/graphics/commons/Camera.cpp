#include "Camera.hpp"
#include "../../math/Vectors.hpp"
#include "../../math/Matrixes.hpp"
#include "../../math/math.hpp"
#include "../../window/Window.hpp"

using namespace core;
using namespace math;

void Camera::update()
{
	this->up = Vector3(rot * Vector4(this->startUP, 1));
	this->target = Vector3(rot * Vector4(this->startTARGET, 1));
}

Camera::Camera(float posX, float posY, float posZ, float fov, float distance) :
	distance(distance), mode(STATIC), startUP(Vector3(0, 1, 0)), startTARGET(Vector3(0, 0, -1)),
	pos(Vector3(posX, posY, posZ)), fov(radians(fov))
{ 
	this->update();
}

Camera::Camera(Vector3 pos, float fov, float distance) :
	distance(distance), mode(STATIC), startUP(Vector3(0, 1, 0)), startTARGET(Vector3(0, 0, -1)),
	pos(pos), fov(radians(fov))
{ 
	this->update();
}

void Camera::setMode(CAM_MODE mode)
{
	this->mode = mode;
}

void Camera::setFov(float fov)
{
	this->fov = radians(fov);
}

void Camera::setDistance(float distance)
{
	this->distance = distance;
}

void Camera::rotate(float x, float y, float z)
{
	this->rot = Matrix4::getRotate(radians(x), Vector3(1, 0, 0), this->rot);
	this->rot = Matrix4::getRotate(radians(y), Vector3(0, 1, 0), this->rot);
	this->rot = Matrix4::getRotate(radians(z), Vector3(0, 0, 1), this->rot);
	this->update();
}

void Camera::resetRotate()
{
	this->rot = Matrix4(1.0f);
}

void Camera::move(float x, float y, float z)
{
	this->pos.x += x;
	this->pos.y += y;
	this->pos.z += z;
}

void Camera::setPos(float x, float y, float z)
{
	this->pos.x = x;
	this->pos.y = y;
	this->pos.z = z;
}

void Camera::setPos(const Vector3& pos)
{
	this->setPos(pos.x, pos.y, pos.z);
}

void Camera::setTarget(float x, float y, float z)
{
	this->target.x = x;
	this->target.y = y;
	this->target.z = z;
}

void Camera::setTarget(const Vector3 &target)
{
	this->setTarget(target.x, target.y, target.z);
}

void Camera::getPos(float& x, float& y, float& z) const
{
	x = this->pos.x;
	y = this->pos.y;
	z = this->pos.z;
}

void Camera::getPos(Vector3& pos) const
{
	pos.x = this->pos.x;
	pos.y = this->pos.y;
	pos.z = this->pos.z;
}

void Camera::getTarget(float& x, float& y, float& z) const
{
	x = this->startTARGET.x;
	y = this->startTARGET.y;
	z = this->startTARGET.z;
}

void Camera::getTarget(math::Vector3& target) const
{
	target.x = this->startTARGET.x;
	target.y = this->startTARGET.y;
	target.z = this->startTARGET.z;
}

Matrix4 Camera::getProj(int width, int height) const
{
	float aspect = (float)width / (float)height;
	return Matrix4::getPerspective(this->fov, aspect, 0.01, this->distance);
}

Matrix4 Camera::getView()
{
	if (this->mode == DYNAMIC)
	{
		return Matrix4::getLookAt(this->pos, this->target, this->up);
	}
		
	return Matrix4::getLookAt(this->pos, this->pos + this->target, this->up);
}
