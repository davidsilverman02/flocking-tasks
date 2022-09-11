#include "SeparationRule.h"
#include "../gameobjects/Boid.h"
#include "../gameobjects/World.h"

Vector2 SeparationRule::computeForce(const std::vector<Boid*>& neighborhood, Boid* boid) {
    //Try to avoid boids too close
    
    Vector2 separatingForce = Vector2::zero();
    float effectiveForce = 0;
    Vector2 direction = Vector2::zero();
    float effectiveDistance = 0;
    float maxAcelera = 1000;

    float desiredDistance = desiredMinimalDistance;

    // todo: implement a force that if neighbor(s) enter the radius, moves the boid away from it/them
    if (!neighborhood.empty()) {
        Vector2 position = boid->transform.position;
        int countCloseFlockmates = 0;

        for (int i = 0; i < neighborhood.size(); i++)
        {
            direction = neighborhood[i]->transform.position - position;
            effectiveDistance = direction.getMagnitude();

            if (effectiveDistance < desiredDistance)
            {
                effectiveForce = weight / (effectiveDistance * effectiveDistance);

                if (effectiveForce > maxAcelera)
                    effectiveForce = maxAcelera;

                direction = Vector2::normalized(direction);

                separatingForce += effectiveForce * direction;
            }

        }
    }

    return separatingForce;

    

    //Vector2 cohesionForce;
    //Vector2 centerOfMass;

    // todo: add your code here to make a force towards the center of mass
    // hint: iterate over the neighborhood

    //centerOfMass = boid->transform.position;

    /*
    for (int i = 0; i < neighborhood.size(); i++)
    {
        centerOfMass += neighborhood[i]->getPosition();
    }

    centerOfMass.x /= (neighborhood.size());
    centerOfMass.y /= (neighborhood.size());

    cohesionForce = (boid->transform.position - centerOfMass).normalized() * weight;

    return cohesionForce;

    */
}

bool SeparationRule::drawImguiRuleExtra() {
    ImGui::SetCurrentContext(world->engine->imGuiContext);
    bool valusHasChanged = false;

    if (ImGui::DragFloat("Desired Separation", &desiredMinimalDistance, 0.05f)) {
        valusHasChanged = true;
    }

    return valusHasChanged;
}
