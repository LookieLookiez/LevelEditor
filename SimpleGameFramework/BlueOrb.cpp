#include "stdafx.h"
#include "BlueOrb.h"
#include "GameManager.h"
#include "GameFramework.h"

ImageWrapper* image1;
BlueOrb::BlueOrb(const Vector2i & _location)
{
	Image1 = "Image1";
	location = _location;
	GameFrameworkInstance.LoadImageResource(AppConfigInstance.GetResourcePath("Images/blueOrb.png"), Image1);
	image1 = GameFrameworkInstance.GetLoadedImage(Image1);
}


BlueOrb::~BlueOrb()
{
}

void BlueOrb::Save(std::ofstream & os)
{
	GameObject::Save(os);

	os << location.X << std::endl;
	os << location.Y << std::endl;
}

void BlueOrb::Load(std::ifstream & is)
{
	GameObject::Load(is);

	is >> location.X;
	is >> location.Y;
}

void BlueOrb::RenderInternal(Gdiplus::Graphics & canvas)
{
	
	GameFrameworkInstance.DrawImage(canvas, Vector2i(-18, -14), image1);
}
