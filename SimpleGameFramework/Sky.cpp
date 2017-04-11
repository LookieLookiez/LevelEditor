#include "stdafx.h"
#include "Sky.h"
#include "GameManager.h"
#include "GameFramework.h"

ImageWrapper* image8;
Sky::Sky(const Vector2i& _location)
{
	Image1 = "Image1";
	location = _location;
	GameFrameworkInstance.LoadImageResource(AppConfigInstance.GetResourcePath("Images/skyBlock.png"), Image1);
	image8 = GameFrameworkInstance.GetLoadedImage(Image1);
}


Sky::~Sky()
{
}

void Sky::Save(std::ofstream & os)
{
	GameObject::Save(os);


	os << location.X << std::endl;
	os << location.Y << std::endl;
}

void Sky::Load(std::ifstream & is)
{
	GameObject::Load(is);


	is >> location.X;
	is >> location.Y;
}



void Sky::RenderInternal(Gdiplus::Graphics & canvas)
{

	GameFrameworkInstance.DrawImage(canvas, Vector2i(-16, -16), image8);
}

