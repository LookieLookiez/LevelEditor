#pragma once
#include "GameObject.h"
class BlueOrb :
	public GameObject
{
public:
	BlueOrb(const Vector2i& _location = Vector2i::Zero);

	virtual ~BlueOrb();

	virtual GameObjectType GetType()
	{
		return egotBlueOrb;
	}

	virtual void Save(std::ofstream& os);
	virtual void Load(std::ifstream& is);


protected:
	virtual void RenderInternal(Gdiplus::Graphics& canvas);

};

