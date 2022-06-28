// Copyright 2022 Pedro Nunes
//
// This file is part of Hyperscape.
//
// Hyperscape is free software: you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.
//
// Hyperscape is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
// GNU General Public License for more details.
//
// You should have received a copy of the GNU General Public License
// along with Hyperscape. If not, see <http://www.gnu.org/licenses/>.

#pragma once

// clang-format off
#include <externalheadersbegin.hpp>
#include <imgui/imgui.h>
#include <glm/vec2.hpp>
#include <externalheadersend.hpp>
// clang-format on

#include "system/system.fwd.hpp"

namespace Hyperscape
{

GENESIS_DECLARE_SMART_PTR(Orbit);

class AstronomicalObject
{
public:
    AstronomicalObject(SystemRandomEngine& randomEngine, const glm::vec2& coordinates);
    AstronomicalObject(SystemRandomEngine& randomEngine, OrbitUniquePtr pOrbit, float theta);
    virtual ~AstronomicalObject();

    virtual void DebugRender(const ImVec2& canvasTopLeft, const ImVec2& canvasBottomRight);

    const glm::vec2& GetCoordinates() const;

private:
    glm::vec2 m_Coordinates;
    OrbitUniquePtr m_pOrbit;
};

} // namespace Hyperscape