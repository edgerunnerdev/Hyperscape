// Copyright 2014 Pedro Nunes
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

#include <colour.h>
#include "trail/trailpointdata.h"

namespace Hyperscape
{

class Trail
{
public:
								Trail( float initialWidth, float decay, const Genesis::Colour& colour );
								~Trail() {};

	void						AddPoint( const glm::vec3& position );
	const TrailPointDataList&	GetData() const;
	float						GetInitialWidth() const;
	void						SetInitialWidth( float value );
	const Genesis::Colour&		GetColour() const;
	void						Update( float delta );	
	void						SetOrphan();
	bool						IsOrphan() const;
	int							GetActivePoints() const;

private:
	TrailPointDataList			m_Data;
	float						m_InitialWidth;
	float						m_Decay;
	Genesis::Colour				m_Colour;
	bool						m_IsOrphan;
	int							m_ActivePoints;
};

inline const TrailPointDataList& Trail::GetData() const
{
	return m_Data;
}

inline float Trail::GetInitialWidth() const
{
	return m_InitialWidth;
}

inline void Trail::SetInitialWidth( float value )
{
	m_InitialWidth = value;
}

inline const Genesis::Colour& Trail::GetColour() const
{
	return m_Colour;
}

inline void Trail::SetOrphan()
{
	m_IsOrphan = true;
}

inline bool Trail::IsOrphan() const
{
	return m_IsOrphan;
}

inline int Trail::GetActivePoints() const
{
	return m_ActivePoints;
}

}
