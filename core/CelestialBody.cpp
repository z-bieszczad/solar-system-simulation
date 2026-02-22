#include <iostream>
#include "../math/Vector3d.h"
#include "CelestialBody.h"
#include <cmath>
#include <ostream>

CelestialBody::CelestialBody(const std::string& name,
                             double mass,
                             double radius,
                             const Vector3d& position,
                             const Vector3d& linVelocity,
                             const Vector3d& color,
                             const Vector3d& rotAxis,
                             double rotAngle,
                             double angVelocity)
    : _name(name),
      _mass(mass),
      _radius(radius),
      _force(0.0,0.0,0.0),
      _position(position),
      _linVelocity(linVelocity),
      _angVelocity(angVelocity),
      _color(color),
      _rotationAxis(rotAxis.normalize()),
      _rotationAngle(rotAngle),
      _acceleration(0.0,0.0,0.0),
      _momentOfInertia(2.0/5.0*mass*radius*radius)
{}

CelestialBody::CelestialBody(const std::string& name,
                             double mass,
                             double radius,
                             const Vector3d& position,
                            const Vector3d& linVelocity)
    : _name(name),
      _mass(mass),
      _radius(radius),
      _position(position),
      _linVelocity(linVelocity)
  
{}

void CelestialBody:: addForce(const Vector3d& force){
    _force=_force+force;
}

void CelestialBody::resetForce(){
    _force=Vector3d(0,0,0);
}



void CelestialBody::computeMomentOfInertia() {
    _momentOfInertia =(2.0 / 5.0)*_mass*_radius*_radius;
}


Vector3d CelestialBody::getPosition()const{
    return _position;
}

Vector3d CelestialBody::getColor()const{
    return _color;
}

Vector3d CelestialBody::getForce()const{
    return _force;
}

Vector3d CelestialBody::getRotationAxis()const{
    return _rotationAxis;
}

double CelestialBody::getRadius()const{
    return _radius;
}

double CelestialBody::getMass()const{
    return _mass;
}

double CelestialBody::getRotationAngle()const{
    return _rotationAngle;
}

double CelestialBody::getMomentOfInertia()const{
    return _momentOfInertia;
}
std::string CelestialBody::getName()const{
    return _name;
}

// setters 

void CelestialBody::setName(const std::string& name) {
    _name= name;
}

void CelestialBody::setMass(double mass) {
    _mass= mass;
    computeMomentOfInertia(); 
}

void CelestialBody::setRadius(double radius) {
    _radius= radius;
    computeMomentOfInertia(); 
}

void CelestialBody::setPosition(const Vector3d& position) {
    _position=position;
}

void CelestialBody::setLinearVelocity(const Vector3d& velocity) {
    _linVelocity=velocity;
}

void CelestialBody::setAngularVelocity(double angVelocity) {
    _angVelocity=angVelocity;
}

void CelestialBody::setRotationAxis(const Vector3d& axis) {
    _rotationAxis=axis.normalize();
}

void CelestialBody::setRotationAngle(double angle) {
    _rotationAngle=angle;
}

void CelestialBody::setColor(const Vector3d& color) {
    _color=color;
}