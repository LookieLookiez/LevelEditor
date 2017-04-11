#pragma once

#include "GameObject.h"

class Heart :
	public GameObject
{
public:
	Heart(const Vector2i& _location = Vector2i::Zero);
	virtual ~Heart();

	virtual GameObjectType GetType()
	{
		return egotHeart;
	}


	virtual void Save(std::ofstream& os);
	virtual void Load(std::ifstream& is);


protected:
	virtual void RenderInternal(Gdiplus::Graphics& canvas);
	const char* Image1;

};

