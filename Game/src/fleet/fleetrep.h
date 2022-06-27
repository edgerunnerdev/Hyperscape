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

#include <resources/resourceshader.hpp>
#include <scene/layer.h>
#include <scene/sceneobject.h>

#include "menus/pointofinterest.h"

namespace Genesis
{
class Layer;
class ResourceImage;
}

namespace Hyperscape
{

class Fleet;

class FleetRep: public Genesis::SceneObject, public PointOfInterestTarget
{
public:
								FleetRep( Fleet* pFleet );
	virtual						~FleetRep();

	void						Initialise();

	virtual void				Update( float delta );
	virtual void				Render();

	void						Show( bool state );
	void						RemoveFromScene();

private:
	void						DrawChevron();

	Fleet*						m_pFleet;
	bool						m_Show;

	Genesis::ResourceImage*		m_pImage;
	Genesis::ResourceImage*		m_pImageFlagship;
	Genesis::ResourceShader*	m_pShader;
	Genesis::ShaderUniformSharedPtr	m_pDiffuseSampler;
	Genesis::VertexBuffer*		m_pVertexBuffer;

	Genesis::LayerSharedPtr		m_pLayer;

	float						m_OffsetX;
	float						m_OffsetY;
	float						m_Angle;

	float						m_BlinkTimer;
	bool						m_DisplayFlagship;
};

}