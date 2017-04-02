#pragma once
#include "GameObject.h"
class Cheesecake :
	public GameObject
{
public:
	static Cheesecake& Instance();
	Cheesecake(const Vector2i& _location = Vector2i::Zero);
	virtual ~Cheesecake();

	virtual GameObjectType GetType()
	{
		return egotCheesecake;
	}
	

	virtual void Save(std::ofstream& os);
	virtual void Load(std::ifstream& is);
	

protected:
	virtual void RenderInternal(Gdiplus::Graphics& canvas);

protected:
	int grossness;
};
#define ObjectInstance (Cheesecake::Instance())

