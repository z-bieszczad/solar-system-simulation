#include "../math/Vector3d.h"
#include <string>
#include <iostream>

class CelestialBody{
public:
    
    CelestialBody()=default;
    CelestialBody(const std::string& name,
              double mass,
              double radius,
              const Vector3d& position,
              const Vector3d& linVelocity,
              const Vector3d& color,
              const Vector3d& rotAxis,
              double rotAngle,
    double angVelocity);   
              
    
    CelestialBody(const std::string& name,
              double mass,
              double radius,
              const Vector3d& position,
    const Vector3d& linVelocity = Vector3d(0,0,0));


    void addForce(const Vector3d& force);
    void resetForce();
    // void updatePosition(double dt);
    // void updateRotation(double dt);
    void computeMomentOfInertia();

    Vector3d getPosition()const;
    Vector3d getColor()const;
    Vector3d getForce()const;
    Vector3d getRotationAxis()const;
    double getRadius()const;
    double getMass()const;
    double getRotationAngle()const;
    double getMomentOfInertia()const;
    std::string getName()const;
    

    void setName(const std::string& name);
    void setMass(double mass);
    void setRadius(double radius);
    void setPosition(const Vector3d& position);
    void setLinearVelocity(const Vector3d& velocity);
    void setAngularVelocity(double angVelocity);
    void setRotationAxis(const Vector3d& axis);
    void setRotationAngle(double angle);
    void setColor(const Vector3d& color);


private:
    std:: string _name="unnamed";
    double _mass=1.0;
    double _radius=1.0;
    Vector3d _force=Vector3d(0,0,0);
    Vector3d _position=Vector3d(0,0,0);
    Vector3d _linVelocity=Vector3d(0,0,0);
    double _angVelocity=0.0;
    Vector3d _color=Vector3d(1,1,1);
    Vector3d _rotationAxis=Vector3d(0,1,0);
    double _rotationAngle=0.0;
    Vector3d _acceleration=Vector3d(0,0,0);
    double _momentOfInertia=2/5;

};
