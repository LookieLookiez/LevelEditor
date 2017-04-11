#pragma once

#include "GameObject.h"

class Spikes :
	public GameObject
{
public:
	Spikes(const Vector2i& _location = Vector2i::Zero);
	virtual ~Spikes();

	virtual GameObjectType GetType()
	{
		return egotSpikes;
	}


	virtual void Save(std::ofstream& os);
	virtual void Load(std::ifstream& is);


protected:
	virtual void RenderInternal(Gdiplus::Graphics& canvas);
	const char* Image1;

};

