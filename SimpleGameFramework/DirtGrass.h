#pragma once
#include "GameObject.h"
class DirtGrass :
	public GameObject
{
public:
	DirtGrass(const Vector2i& _location = Vector2i::Zero);
	virtual ~DirtGrass();

	virtual GameObjectType GetType()
	{
		return egotDirtGrass;
	}


	virtual void Save(std::ofstream& os);
	virtual void Load(std::ifstream& is);


protected:
	virtual void RenderInternal(Gdiplus::Graphics& canvas);
	const char* Image1;

};

