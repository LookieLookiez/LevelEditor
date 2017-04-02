#include "stdafx.h"
#include "Dirt.h"
#include "GameManager.h"
#include "GameFramework.h"

Dirt::Dirt(const Vector2i& _location)
{
	location = _location;
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

	const char* Image1 = "Image1";
	GameFrameworkInstance.LoadImageResource(AppConfigInstance.GetResourcePath("Images/dirtBlock.png"), Image1);
	ImageWrapper* image1 = GameFrameworkInstance.GetLoadedImage(Image1);
	GameFrameworkInstance.DrawImage(canvas, Vector2i(-16, -16), image1);
}
