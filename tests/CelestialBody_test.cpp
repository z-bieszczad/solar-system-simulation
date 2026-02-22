#include <iostream>
#include "../core/CelestialBody.h"
#include "../math/Vector3d.h"

int main() {
    
    CelestialBody earth(
        "Earth",
        5.972e24,
        6371.0,
        Vector3d(1e8, 0, 0),
        Vector3d(0, 29.78, 0),
        Vector3d(0, 0, 1),     
        Vector3d(0,1,0),
        0.0,
        0.000072921
    );

    
    std::cout<< "Name: "<< earth.getName()<<"\n";
    std::cout<< "Mass: "<< earth.getMass()<<"\n";
    std::cout<< "Radius: "<< earth.getRadius()<<"\n";
    std::cout<< "Position: "<< earth.getPosition()<<"\n";
    std::cout<< "Force: "<< earth.getForce()<<"\n";


    earth.addForce(Vector3d(1e20, 0, 0));
    earth.addForce(Vector3d(0, 2e20, 0));
    std::cout<<"Force after adding: "<<earth.getForce()<<"\n";

    
    earth.resetForce();
    std::cout<<"Force after reset: "<<earth.getForce()<<"\n";

    
    earth.computeMomentOfInertia();
    std::cout<<"Moment of inertia: "<<earth.getMomentOfInertia()<<"\n";

    
    earth.setMass(1e25);
    earth.setRadius(7000.0);
    earth.setRotationAxis(Vector3d(1,1,0));
    std::cout<<"Updated mass: "<<earth.getMass()<<"\n";
    std::cout<<"Updated radius: "<<earth.getRadius()<<"\n";
    std::cout<<"Updated rotation axis: "<<earth.getRotationAxis()<<"\n";

    return 0;
}