#include "stdafx.h"
#include "Heart.h"
#include "GameManager.h"
#include "GameFramework.h"

ImageWrapper* image6;
Heart::Heart(const Vector2i& _location)
{
	Image1 = "Image1";
	location = _location;
	GameFrameworkInstance.LoadImageResource(AppConfigInstance.GetResourcePath("Images/heart.png"), Image1);
	image6 = GameFrameworkInstance.GetLoadedImage(Image1);
}


Heart::~Heart()
{
}

void Heart::Save(std::ofstream & os)
{
	GameObject::Save(os);


	os << location.X << std::endl;
	os << location.Y << std::endl;
}

void Heart::Load(std::ifstream & is)
{
	GameObject::Load(is);


	is >> location.X;
	is >> location.Y;
}



void Heart::RenderInternal(Gdiplus::Graphics & canvas)
{
	GameFrameworkInstance.DrawImage(canvas, Vector2i(-15, -18), image6);
}
