#include "stdafx.h"
#include "GameObject.h"
#include "Coin.h"
#include "Player.h"
#include "BlueOrb.h"
#include "Stone.h"
#include "Dirt.h"
#include "DirtGrass.h"
#include "Heart.h"
#include "Leaves.h"
#include "Sky.h"
#include "Spikes.h"

GameObject::GameObject()
{
}


GameObject::~GameObject()
{
	
}

void GameObject::Render(Gdiplus::Graphics & canvas)
{
	// Save the current transformation of the scene
	Gdiplus::Matrix transform;
	canvas.GetTransform(&transform);

	canvas.TranslateTransform((Gdiplus::REAL)location.X,
		(Gdiplus::REAL)location.Y);
	canvas.RotateTransform(rotation);

	RenderInternal(canvas);

	// Restore the transformation of the scene
	canvas.SetTransform(&transform);
}

std::list<GameObject*> GameObject::LoadObjects(std::ifstream & is)
{
	std::list<GameObject*> loadedObjects;

	int numObjects;
	is >> numObjects;

	for (int index = 0; index < numObjects; ++index)
	{
		int dummyInt;
		is >> dummyInt;

		GameObjectType objectType = static_cast<GameObjectType>(dummyInt);

		GameObject* objectPtr = nullptr;

		if (objectType == egotCoin)
		{
			objectPtr = new Coin();
		}
		if (objectType == egotPlayer)
		{
			objectPtr = new Player();
		}
		if (objectType == egotBlueOrb)
		{
			objectPtr = new BlueOrb();
		}
		if (objectType == egotCoin)
		{
			objectPtr = new Coin();
		}
		if (objectType == egotStone)
		{
			objectPtr = new Stone();
		}
		if (objectType == egotDirt)
		{
			objectPtr = new Dirt();
		}
		if (objectType == egotDirtGrass)
		{
			objectPtr = new DirtGrass();
		}
		if (objectType == egotHeart)
		{
			objectPtr = new Heart();
		}
		if (objectType == egotLeaves)
		{
			objectPtr = new Leaves();
		}
		if (objectType == egotSky)
		{
			objectPtr = new Sky();
		}
		if (objectType == egotSpikes)
		{
			objectPtr = new Spikes();
		}

		// did we create something
		if (objectPtr)
		{
			objectPtr->Load(is);
			loadedObjects.push_back(objectPtr);
		}
	}

	return loadedObjects;
}

void GameObject::SaveObjects(std::ofstream & os, std::list<GameObject*>& objects)
{
	// output the number of objects
	os << objects.size() << std::endl;

	// save all of the objects
	for (GameObject* objectPtr : objects)
	{
		objectPtr->Save(os);
	}
}

void GameObject::Save(std::ofstream & os)
{
	os << (int) GetType() << std::endl;

	os << name << "," << location.X << "," << location.Y << "," << rotation << std::endl;
}

void GameObject::Load(std::ifstream & is)
{
	char dummyChar;

	std::getline(is, name, ',');

	is >> location.X;
	is >> dummyChar;

	is >> location.Y;
	is >> dummyChar;

	is >> rotation;
}
