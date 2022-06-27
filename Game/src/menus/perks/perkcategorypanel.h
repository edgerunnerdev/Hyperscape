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

#pragma once

#include <vector>
#include <string>

#include <gui/gui.h>

#include "menus/perks/perkpanel.h"
#include "gameevents.h"

namespace Hyperscape
{

class PerkCategoryPanel;

typedef std::vector< PerkCategoryPanel* > PerkCategoryPanelArray;


/////////////////////////////////////////////////////////////////////
// PerkCategoryPanel
// A panel for a single category of perks. Includes category title
// and any number of perk icons.
/////////////////////////////////////////////////////////////////////

class PerkCategoryPanel : public Genesis::Gui::Image, public GameEventHandler
{
public:
	PerkCategoryPanel();
	void Init( const std::string& category );
	void AddPerk( Perk perk, const std::string& name, const std::string& description, const std::string& icon, int cost );

	virtual void			Show( bool state ) override;
    virtual void            HandleGameEvent( GameEvent* pEvent ) override;

private:
	Genesis::Gui::Text*		m_pTitle;
	PerkPanelArray			m_Perks;
	bool					m_PreviousUnlocked;
};

}