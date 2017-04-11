#pragma once
#include "GameObject.h"
class Coin :
	public GameObject
{
public:
	Coin(const Vector2i& _location = Vector2i::Zero);
	virtual ~Coin();

	virtual GameObjectType GetType()
	{
		return egotCoin;
	}
	

	virtual void Save(std::ofstream& os);
	virtual void Load(std::ifstream& is);


protected:
	virtual void RenderInternal(Gdiplus::Graphics& canvas);
	const char* Image1;
};


