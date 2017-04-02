#include "stdafx.h"
#include "DirtGrass.h"
#include "GameManager.h"
#include "GameFramework.h"

DirtGrass::DirtGrass(const Vector2i& _location)
{
	location = _location;
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

	const char* Image1 = "Image1";
	GameFrameworkInstance.LoadImageResource(AppConfigInstance.GetResourcePath("Images/grassDirtBlock.png"), Image1);
	ImageWrapper* image1 = GameFrameworkInstance.GetLoadedImage(Image1);
	GameFrameworkInstance.DrawImage(canvas, Vector2i(-16, -16), image1);
}
