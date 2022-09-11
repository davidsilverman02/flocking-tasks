#include "WindRule.h"
#include <imgui.h>
#include "../gameobjects/Boid.h"
#include "../gameobjects/World.h"
#include <cmath>

Vector2 WindRule::computeForce(const std::vector<Boid*>& neighborhood, Boid* boid) {
    
    Vector2 vent = Vector2(cos(windAngle), sin(windAngle));

    return vent;
}

bool WindRule::drawImguiRuleExtra() {
    ImGui::SetCurrentContext(world->engine->imGuiContext);
    bool valueHasChanged = false;

    if (ImGui::SliderAngle("Wind Direction", &windAngle, 0)) {
        valueHasChanged = true;
    }

    return valueHasChanged;
}