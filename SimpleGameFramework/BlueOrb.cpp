#include "stdafx.h"
#include "BlueOrb.h"
#include "GameManager.h"
#include "GameFramework.h"


BlueOrb::BlueOrb(const Vector2i & _location)
{
	location = _location;
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
	const char* Image1 = "Image1";
	GameFrameworkInstance.LoadImageResource(AppConfigInstance.GetResourcePath("Images/blueOrb.png"), Image1);
	ImageWrapper* image1 = GameFrameworkInstance.GetLoadedImage(Image1);
	GameFrameworkInstance.DrawImage(canvas, Vector2i(-18, -14), image1);
}
