#include "stdafx.h"
#include "DirtGrass.h"
#include "GameManager.h"
#include "GameFramework.h"

ImageWrapper* image5;
DirtGrass::DirtGrass(const Vector2i& _location)
{
	Image1 = "Image1";
	location = _location;
	GameFrameworkInstance.LoadImageResource(AppConfigInstance.GetResourcePath("Images/grassDirtBlock.png"), Image1);
	image5 = GameFrameworkInstance.GetLoadedImage(Image1);
}


DirtGrass::~DirtGrass()
{
}

void DirtGrass::Save(std::ofstream & os)
{
	GameObject::Save(os);


	os << location.X << std::endl;
	os << location.Y << std::endl;
}

void DirtGrass::Load(std::ifstream & is)
{
	GameObject::Load(is);


	is >> location.X;
	is >> location.Y;
}



void DirtGrass::RenderInternal(Gdiplus::Graphics & canvas)
{
	GameFrameworkInstance.DrawImage(canvas, Vector2i(-16, -16), image5);
}
