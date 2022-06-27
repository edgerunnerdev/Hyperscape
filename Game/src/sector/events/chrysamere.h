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

#include "sector/events/sectorevent.h"

namespace Hyperscape
{

class Ship;

class SectorEventChrysamere : public SectorEvent
{
public:
					SectorEventChrysamere();

	virtual bool	IsAvailableAt( const SectorInfo* pSectorInfo ) const override;
	virtual void	OnPlayerEnterSector() override;
	virtual void	OnShipDestroyed( Ship* pShip ) override;

private:
	Ship*			m_pChrysamere;
};

}