#include "AlignmentRule.h"
#include "../gameobjects/Boid.h"

Vector2 AlignmentRule::computeForce(const std::vector<Boid*>& neighborhood, Boid* boid) {
    Vector2 averageVelocity = Vector2::zero();
    Vector2 aligned = Vector2::zero();

    // todo: add your code here to align each boid in a neighborhood
    // hint: iterate over the neighborhood

    if (!neighborhood.empty())
    {

        for (int i = 0; i < neighborhood.size(); i++)
        {
            aligned += neighborhood[i]->getTransform().rotation;

            //averageVelocity += neighborhood[i]->getVelocity();
        }

        //averageVelocity.x /= neighborhood.size();
        //averageVelocity.y /= neighborhood.size();

        aligned.x /= neighborhood.size();
        aligned.y /= neighborhood.size();

        return Vector2::normalized(aligned);
    }

    return aligned;
}