// Copyright 2020 Pedro Nunes
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

#include <memory>
#include <vector>

#include <gui/gui.h>
#include "ship/moduleinfo.h"

namespace Genesis
{
class ResourceSound;
}

namespace Hyperscape
{

class Table;
class TableRow;
class FleetStatus;
class Ship;

using FleetStatusUniquePtr = std::unique_ptr< FleetStatus >;

class FleetStatus
{
public:
	FleetStatus();
	virtual ~FleetStatus();
	void Update();

	void AddShip( Ship* pShip );

private:
	void AddFleetRows();
	Genesis::Colour GetShipIntegrityColour( int integrity ) const;

	Genesis::Gui::Panel* m_pMainPanel;
	Table* m_pTable;

	struct Entry
	{
		TableRow* m_pRow;
		Ship* m_pShip;
		bool m_Destroyed;
	};
	using EntryVector = std::vector< Entry >;
	EntryVector m_Entries;
	Genesis::ResourceSound* m_pShipLostSFX;
};

}
