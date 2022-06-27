// Copyright 2016 Pedro Nunes
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

#include <algorithm>

#include "requests/defendrequestinfo.h"

#include "fleet/fleetbehaviour.h"
#include "fleet/fleet.h"
#include "requests/defendrequest.h"
#include "requests/requestmanager.h"
#include "faction/faction.h"
#include "hexterminate.h"


namespace Hyperscape
{

ImperialRequestSharedPtr DefendRequestInfo::TryInstantiate( RequestManager* pRequestManager ) const
{
	if ( CommonInstantiationChecks( pRequestManager ) == false )
		return ImperialRequestSharedPtr();

	SectorInfo* pSectorInfo = FindSector();
	if ( pSectorInfo && IsDuplicateSector( pRequestManager, pSectorInfo ) == false )
	{
		return std::make_shared<DefendRequest>( pRequestManager, pSectorInfo );
	}
	else
	{
		return ImperialRequestSharedPtr();
	}
}

SectorInfo* DefendRequestInfo::FindSector() const
{
	Faction* pEmpireFaction = g_pGame->GetFaction( FactionId::Empire );
	const SectorInfoVector& controlledSectors = pEmpireFaction->GetControlledSectors();
	SectorInfoVector hostileBorderingSectors;
	for ( auto& pSectorInfo : controlledSectors )
	{
		auto contestedFleets = pSectorInfo->GetContestedFleets();
		for ( auto& contestedFleet : contestedFleets )
		{
			FleetSharedPtr pFleet = contestedFleet.lock();
			if ( pFleet != nullptr && pFleet->IsEngaged() && Faction::sIsEnemyOf( pFleet->GetFaction(), pEmpireFaction ) )
			{
				return pSectorInfo;
			}
		}
	}

	return nullptr;
}

}
