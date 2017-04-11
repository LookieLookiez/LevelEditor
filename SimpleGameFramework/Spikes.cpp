#include "stdafx.h"
#include "Spikes.h"
#include "GameManager.h"
#include "GameFramework.h"

ImageWrapper* image9;
Spikes::Spikes(const Vector2i& _location)
{
	Image1 = "Image1";
	location = _location;
	GameFrameworkInstance.LoadImageResource(AppConfigInstance.GetResourcePath("Images/spikes.png"), Image1);
	image9 = GameFrameworkInstance.GetLoadedImage(Image1);
}


Spikes::~Spikes()
{
}

void Spikes::Save(std::ofstream & os)
{
	GameObject::Save(os);


	os << location.X << std::endl;
	os << location.Y << std::endl;
}

void Spikes::Load(std::ifstream & is)
{
	GameObject::Load(is);


	is >> location.X;
	is >> location.Y;
}



void Spikes::RenderInternal(Gdiplus::Graphics & canvas)
{

	GameFrameworkInstance.DrawImage(canvas, Vector2i(-17, -16), image9);
}

