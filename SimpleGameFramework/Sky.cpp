#include "stdafx.h"
#include "Sky.h"
#include "GameManager.h"
#include "GameFramework.h"

Sky::Sky(const Vector2i& _location)
{
	location = _location;
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

	const char* Image1 = "Image1";
	GameFrameworkInstance.LoadImageResource(AppConfigInstance.GetResourcePath("Images/skyBlock.png"), Image1);
	ImageWrapper* image1 = GameFrameworkInstance.GetLoadedImage(Image1);
	GameFrameworkInstance.DrawImage(canvas, Vector2i(-16, -16), image1);
}

