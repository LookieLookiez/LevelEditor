#pragma once

#include "GameObject.h"

class Sky :
	public GameObject
{
public:
	Sky(const Vector2i& _location = Vector2i::Zero);
	virtual ~Sky();

	virtual GameObjectType GetType()
	{
		return egotSky;
	}


	virtual void Save(std::ofstream& os);
	virtual void Load(std::ifstream& is);


protected:
	virtual void RenderInternal(Gdiplus::Graphics& canvas);
	const char* Image1;

};

