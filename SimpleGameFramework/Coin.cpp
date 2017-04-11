#include "stdafx.h"
#include "Coin.h"
#include "GameManager.h"
#include "GameFramework.h"


	
	ImageWrapper* image2;
Coin::Coin(const Vector2i& _location)
{
	Image1 = "Image1";
	location = _location;
	GameFrameworkInstance.LoadImageResource(AppConfigInstance.GetResourcePath("Images/coin.png"), Image1);
	image2 = GameFrameworkInstance.GetLoadedImage(Image1);
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
	GameFrameworkInstance.DrawImage(canvas, Vector2i(-13, -15), image2);
}
