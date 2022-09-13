#include "CohesionRule.h"
#include "../gameobjects/Boid.h"

Vector2 CohesionRule::computeForce(const std::vector<Boid*>& neighborhood, Boid* boid) {
    Vector2 centerOfMass = Vector2::zero();
    Vector2 separatingForce = Vector2::zero();
    Vector2 direction = Vector2::zero();
    Vector2 effectiveDirection = Vector2::zero();
    float effectiveDistance = 0;
    float maxAcelera = 10000;
    int countCloseFlockmates = 0;
    Vector2 position = boid->transform.position;

    // todo: implement a force that if neighbor(s) enter the radius, moves the boid away from it/them
    if (!neighborhood.empty()) {

        for (int i = 0; i < neighborhood.size(); i++)
        {
            direction = position - neighborhood[i]->transform.position;
            effectiveDistance = direction.getMagnitude();

            centerOfMass += neighborhood[i]->getPosition();

        }

        centerOfMass /= neighborhood.size();
        effectiveDirection = centerOfMass - position;
        float effectiveMagnitude = effectiveDirection.getMagnitude();

        Vector2 effectiveForce = effectiveDirection / effectiveMagnitude;

        return Vector2::normalized(effectiveForce);
    }

    return Vector2::zero();
    
    /*
    Vector2 cohesionForce;
    Vector2 centerOfMass;

    if (neighborhood.empty() == false)
    {
        for (int i = 0; i < neighborhood.size(); i++)
        {
            centerOfMass += neighborhood[i]->getPosition();
        }

        centerOfMass.x /= (neighborhood.size());
        centerOfMass.y /= (neighborhood.size());

    }

    cohesionForce = (centerOfMass - boid->transform.position).normalized();

    return cohesionForce;
    */
}