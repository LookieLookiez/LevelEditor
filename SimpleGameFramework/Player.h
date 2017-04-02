#pragma once

#include "GameObject.h"

class Player : public GameObject
{
public:
	static Player& Instance();
	Player();
	virtual ~Player();

	virtual GameObjectType GetType()
	{
		return egotPlayer;
	}

	virtual void Save(std::ofstream& os);
	virtual void Load(std::ifstream& is);

	int playerMoveSpeed = 5;
protected:
	virtual void RenderInternal(Gdiplus::Graphics& canvas);

protected:
	int health;
};
#define PlayerInstance (Player::Instance())
