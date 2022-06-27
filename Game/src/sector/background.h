// Copyright 2015 Pedro Nunes
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

#include <string>
#include <resources/resourceshader.hpp>
#include <scene/sceneobject.h>

namespace Genesis
{
	class VertexBuffer;
}

namespace Hyperscape
{

class BackgroundInfo;
class StarInfo;

///////////////////////////////////////////////////////////////////////////////
// Background
///////////////////////////////////////////////////////////////////////////////

class Background : public Genesis::SceneObject
{
public:
								Background( const BackgroundInfo* pBackgroundInfo, StarInfo* pStarInfo );
	virtual						~Background() override;
    virtual void                Update( float delta ) override;
	virtual void				Render() override;

    const glm::vec4&            GetAmbientColour() const;

private:
	void						CreateGeometry();

	Genesis::ResourceShader*	m_pShader;
	const BackgroundInfo*		m_pBackgroundInfo;
	Genesis::VertexBuffer*		m_pVertexBuffer;
    StarInfo*                   m_pStarInfo;
    Genesis::ShaderUniformSharedPtr m_pStarOffset;
    glm::vec4                   m_AmbientColour;
};

inline const glm::vec4& Background::GetAmbientColour() const
{
    return m_AmbientColour;
}

}