#include "stdafx.h"
#include "Spikes.h"
#include "GameManager.h"
#include "GameFramework.h"

Spikes::Spikes(const Vector2i& _location)
{
	location = _location;
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

	const char* Image1 = "Image1";
	GameFrameworkInstance.LoadImageResource(AppConfigInstance.GetResourcePath("Images/spikes.png"), Image1);
	ImageWrapper* image1 = GameFrameworkInstance.GetLoadedImage(Image1);
	GameFrameworkInstance.DrawImage(canvas, Vector2i(-17, -16), image1);
}

