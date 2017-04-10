#pragma once

#include "GameObject.h"

class Leaves :
	public GameObject
{
public:
	Leaves(const Vector2i& _location = Vector2i::Zero);
	virtual ~Leaves();

	virtual GameObjectType GetType()
	{
		return egotLeaves;
	}


	virtual void Save(std::ofstream& os);
	virtual void Load(std::ifstream& is);


protected:
	virtual void RenderInternal(Gdiplus::Graphics& canvas);

};


