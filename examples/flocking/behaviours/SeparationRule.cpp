#include "SeparationRule.h"
#include "../gameobjects/Boid.h"
#include "../gameobjects/World.h"
#include <iostream>

Vector2 SeparationRule::computeForce(const std::vector<Boid*>& neighborhood, Boid* boid) {
    //Try to avoid boids too close
    Vector2 centerOfMass = Vector2::zero();
    Vector2 separatingForce = Vector2::zero();
    Vector2 direction = Vector2::zero();
    Vector2 effectiveDirection = Vector2::zero();
    float effectiveDistance = 0;
    float maxAcelera = 10000;
    int countCloseFlockmates = 0;
    Vector2 position = boid->transform.position;
    float desiredDistance = desiredMinimalDistance;

    // todo: implement a force that if neighbor(s) enter the radius, moves the boid away from it/them
    if (!neighborhood.empty()) {
        

        for (int i = 0; i < neighborhood.size(); i++)
        {
            direction = position - neighborhood[i]->transform.position;
            effectiveDistance = direction.getMagnitude();

            if (effectiveDistance < desiredDistance)
            {
                countCloseFlockmates++;
                centerOfMass += neighborhood[i]->getPosition();
            }

        }
    }

    if (countCloseFlockmates > 0)
    {
        centerOfMass /= countCloseFlockmates;
        effectiveDirection = position - centerOfMass;
        float effectiveMagnitude = effectiveDirection.getMagnitude();
        
        if (effectiveMagnitude < 0.01)
            effectiveMagnitude = 0.01;

        Vector2 effectiveForce = effectiveDirection / effectiveMagnitude;

        return Vector2::normalized(effectiveForce);

    }

    return Vector2::zero();
}

bool SeparationRule::drawImguiRuleExtra() {
    ImGui::SetCurrentContext(world->engine->imGuiContext);
    bool valusHasChanged = false;

    if (ImGui::DragFloat("Desired Separation", &desiredMinimalDistance, 0.05f)) {
        valusHasChanged = true;
    }

    return valusHasChanged;
}
