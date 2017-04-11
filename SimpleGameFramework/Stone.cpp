#include "stdafx.h"
#include "Stone.h"
#include "GameManager.h"
#include "GameFramework.h"

ImageWrapper* image3;
Stone::Stone(const Vector2i & _location)
{
	Image1 = "Image1";
	location = _location;
	GameFrameworkInstance.LoadImageResource(AppConfigInstance.GetResourcePath("Images/darkStoneBlock.png"), Image1);
	image3 = GameFrameworkInstance.GetLoadedImage(Image1);
}


Stone::~Stone()
{
}

void Stone::Save(std::ofstream & os)
{
	GameObject::Save(os);

	os << location.X << std::endl;
	os << location.Y << std::endl;
}

void Stone::Load(std::ifstream & is)
{
	GameObject::Load(is);

	is >> location.X;
	is >> location.Y;
}

void Stone::RenderInternal(Gdiplus::Graphics & canvas)
{

	GameFrameworkInstance.DrawImage(canvas, Vector2i(-16, -16), image3);
}
