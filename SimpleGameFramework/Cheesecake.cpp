#include "stdafx.h"
#include "Cheesecake.h"
#include "GameManager.h"
#include "GameFramework.h"


Cheesecake & Cheesecake::Instance()
{
	static Cheesecake instance;

	return instance;
}

Cheesecake::Cheesecake(const Vector2i& _location)
{
	location = _location;
}


Cheesecake::~Cheesecake()
{
}

void Cheesecake::Save(std::ofstream & os)
{
	GameObject::Save(os);

	os << grossness << std::endl;
	os << location.X << std::endl;
	os << location.Y << std::endl;
}

void Cheesecake::Load(std::ifstream & is)
{
	GameObject::Load(is);

	is >> grossness;
	is >> location.X;
	is >> location.Y;
}



void Cheesecake::RenderInternal(Gdiplus::Graphics & canvas)
{
	
	//GameFrameworkInstance.DrawImage(canvas, Vector2i(location.X - 16, location.Y - 16), GameManager::image1);
	GameFrameworkInstance.DrawRectangle(canvas,
		AABBi(Vector2i(-16, -16), Vector2i(16, 16)),
		true, Gdiplus::Color::Chartreuse);
}
