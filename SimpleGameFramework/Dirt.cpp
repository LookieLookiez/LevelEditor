#include "stdafx.h"
#include "Dirt.h"
#include "GameManager.h"
#include "GameFramework.h"

ImageWrapper* image4;
Dirt::Dirt(const Vector2i& _location)
{
	Image1 = "Image1";
	location = _location;
	GameFrameworkInstance.LoadImageResource(AppConfigInstance.GetResourcePath("Images/dirtBlock.png"), Image1);
	image4 = GameFrameworkInstance.GetLoadedImage(Image1);
}


Dirt::~Dirt()
{
}

void Dirt::Save(std::ofstream & os)
{
	GameObject::Save(os);


	os << location.X << std::endl;
	os << location.Y << std::endl;
}

void Dirt::Load(std::ifstream & is)
{
	GameObject::Load(is);


	is >> location.X;
	is >> location.Y;
}



void Dirt::RenderInternal(Gdiplus::Graphics & canvas)
{

	GameFrameworkInstance.DrawImage(canvas, Vector2i(-16, -16), image4);
}
