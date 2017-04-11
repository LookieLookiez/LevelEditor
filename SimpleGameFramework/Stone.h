#pragma once
#include "GameObject.h"
class Stone :
	public GameObject
{
public:
	Stone(const Vector2i& _location = Vector2i::Zero);

	virtual ~Stone();

	virtual GameObjectType GetType()
	{
		return egotBlueOrb;
	}

	virtual void Save(std::ofstream& os);
	virtual void Load(std::ifstream& is);


protected:
	virtual void RenderInternal(Gdiplus::Graphics& canvas);
	const char* Image1;

};
