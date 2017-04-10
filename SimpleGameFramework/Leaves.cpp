#include "stdafx.h"
#include "Leaves.h"
#include "GameManager.h"
#include "GameFramework.h"

Leaves::Leaves(const Vector2i& _location)
{
	location = _location;
}


Leaves::~Leaves()
{
}

void Leaves::Save(std::ofstream & os)
{
	GameObject::Save(os);


	os << location.X << std::endl;
	os << location.Y << std::endl;
}

void Leaves::Load(std::ifstream & is)
{
	GameObject::Load(is);


	is >> location.X;
	is >> location.Y;
}



void Leaves::RenderInternal(Gdiplus::Graphics & canvas)
{

	const char* Image1 = "Image1";
	GameFrameworkInstance.LoadImageResource(AppConfigInstance.GetResourcePath("Images/leavesBlock.png"), Image1);
	ImageWrapper* image1 = GameFrameworkInstance.GetLoadedImage(Image1);
	GameFrameworkInstance.DrawImage(canvas, Vector2i(-16, -16), image1);
}
