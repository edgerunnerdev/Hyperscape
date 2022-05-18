// Copyright 2017 Pedro Nunes
//
// This file is part of Hexterminate.
//
// Hexterminate is free software: you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.
//
// Hexterminate is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
// GNU General Public License for more details.
//
// You should have received a copy of the GNU General Public License
// along with Hexterminate. If not, see <http://www.gnu.org/licenses/>.

#pragma once

#include <memory>

namespace Genesis
{
namespace Gui
{
	class Image;
	class Text;
}
}
	
namespace Hexterminate
{

class PanelDocking
{
public:
	PanelDocking();
	~PanelDocking();

	void Show( bool state );

private:
	Genesis::Gui::Image* m_pBackground;
	Genesis::Gui::Text*	m_pDockingText;
};

typedef std::unique_ptr<PanelDocking> PanelDockingUniquePtr;

};
