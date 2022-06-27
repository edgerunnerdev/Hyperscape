#pragma once

#include <list>
#include "ship/ship.h"
#include "serialisable.h"

namespace Hyperscape
{

class Inventory;
class Perks;

class Player: public Serialisable
{
public:
	Player();
	Player( const ShipCustomisationData& shipCustomisationData);
	~Player();

	Ship*					CreateShip( float spawnPointX, float spawnPointY );

	ShipCustomisationData&	GetShipCustomisationData()	{ return m_ShipCustomisationData; }
	Ship*					GetShip() const				{ return m_pShip; }
	void					UnassignShip()				{ m_pShip = nullptr; }
	Inventory*				GetInventory() const		{ return m_pInventory; }
	Perks*					GetPerks() const			{ return m_pPerks; }
	int						GetInfluence() const;
	void					SetInfluence( int value );
	int						GetPerkPoints() const;
	void					SetPerkPoints( int value );
	int						GetPerkPointsParts() const;
	void					SetPerkPointsParts( int value );
    unsigned int            GetFleetMaxShips() const;

	// Serialisable
	virtual bool			Write( tinyxml2::XMLDocument& xmlDoc, tinyxml2::XMLElement* pRootElement ) override;
	virtual bool			Read( tinyxml2::XMLElement* pRootElement ) override;
	virtual int				GetVersion() const override { return 2; }
	virtual void			UpgradeFromVersion( int version ) override {}

private:
	void					AssembleDefaultInventory();

	ShipCustomisationData	m_ShipCustomisationData;
	Ship*					m_pShip;
	Perks*					m_pPerks;
	Inventory*				m_pInventory;
	int						m_Influence;
	int						m_PerkPoints;
	int						m_PerkPointsParts;
};

inline int Player::GetInfluence() const
{
	return m_Influence;
}

inline void Player::SetInfluence( int value ) 
{
    // The amount of influence units the player can have is capped in order to fit the user interface
	m_Influence = std::min( m_Influence, 999999 );
}

inline int Player::GetPerkPoints() const
{
	return m_PerkPoints;
}

inline void Player::SetPerkPoints( int value )
{
	m_PerkPoints = value;
}

inline int Player::GetPerkPointsParts() const
{
	return m_PerkPointsParts;
}

inline void Player::SetPerkPointsParts( int value )
{
	m_PerkPointsParts = value;
}

}
