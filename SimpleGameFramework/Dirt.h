#pragma once
#include "GameObject.h"
class Dirt :
	public GameObject
{
public:
	Dirt(const Vector2i& _location = Vector2i::Zero);
	virtual ~Dirt();

	virtual GameObjectType GetType()
	{
		return egotDirt;
	}


	virtual void Save(std::ofstream& os);
	virtual void Load(std::ifstream& is);


protected:
	virtual void RenderInternal(Gdiplus::Graphics& canvas);

};

