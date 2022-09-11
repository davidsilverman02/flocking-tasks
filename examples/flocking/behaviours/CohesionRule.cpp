#include "CohesionRule.h"
#include "../gameobjects/Boid.h"

Vector2 CohesionRule::computeForce(const std::vector<Boid*>& neighborhood, Boid* boid) {
    Vector2 cohesionForce;
    Vector2 centerOfMass;

    // todo: add your code here to make a force towards the center of mass
    // hint: iterate over the neighborhood

    //centerOfMass = boid->transform.position;

    for (int i = 0; i < neighborhood.size(); i++) 
    {
        centerOfMass += neighborhood[i]->getPosition();
    }

    centerOfMass.x /= (neighborhood.size());
    centerOfMass.y /= (neighborhood.size());

    cohesionForce = (centerOfMass - boid->transform.position).normalized();

    return cohesionForce;
}