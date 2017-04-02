#include "stdafx.h"
#include "Coin.h"
#include "GameManager.h"
#include "GameFramework.h"

Coin::Coin(const Vector2i& _location)
{
	location = _location;
}


Coin::~Coin()
{
}

void Coin::Save(std::ofstream & os)
{
	GameObject::Save(os);

	
	os << location.X << std::endl;
	os << location.Y << std::endl;
}

void Coin::Load(std::ifstream & is)
{
	GameObject::Load(is);

	
	is >> location.X;
	is >> location.Y;
}



void Coin::RenderInternal(Gdiplus::Graphics & canvas)
{
	
	const char* Image1 = "Image1";
	GameFrameworkInstance.LoadImageResource(AppConfigInstance.GetResourcePath("Images/coin.png"), Image1);
	ImageWrapper* image1 = GameFrameworkInstance.GetLoadedImage(Image1);
	GameFrameworkInstance.DrawImage(canvas, Vector2i(-13, -15), image1);
}
