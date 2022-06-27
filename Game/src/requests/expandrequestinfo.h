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

#include "requests/imperialrequestinfo.h"

namespace Hyperscape
{

class SectorInfo;

class ExpandRequestInfo : public ImperialRequestInfo
{
public:
	virtual ImperialRequestType			GetType() const override						{ return ImperialRequestType::Expand; }
	virtual int							GetMaximumRequests() const override				{ return 2; }
	virtual float						GetMinimumTimeBetweenRequests() const override	{ return 45.0f; }		
    virtual float                       GetMinimumTimeBeforeRequest() const override { return 30.0f; }

	virtual ImperialRequestSharedPtr	TryInstantiate( RequestManager* pRequestManager ) const override;

private:
	SectorInfo*							FindSector() const;
};

}
