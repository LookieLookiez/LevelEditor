#include "stdafx.h"
#include "GameManager.h"
#include "Coin.h"
#include "BlueOrb.h"
#include "Stone.h"
#include "Dirt.h"
#include "DirtGrass.h"
#include "Heart.h"
#include "Leaves.h"
#include "Sky.h"
#include "Spikes.h"

GameManager& GameManager::Instance()
{
	static GameManager instance;

	return instance;
}

GameManager::GameManager()
{
}

GameManager::~GameManager()
{
}



const char* Image1 = "Image1";
const char* Image2 = "Image2";
const char* Image3 = "Image3";
const char* Image4 = "Image4";
const char* Image5 = "Image5";
const char* Image6 = "Image6";
const char* Image7 = "Image7";
const char* Image8 = "Image8";
const char* Image9 = "Image9";

void GameManager::BeginPlay()
{
	// Load the image file Untitled.png from the Images folder. Give it the unique name of Image1
	GameFrameworkInstance.LoadImageResource(AppConfigInstance.GetResourcePath("Images/blueOrb.png"), Image1);
	GameFrameworkInstance.LoadImageResource(AppConfigInstance.GetResourcePath("Images/coin.png"), Image2);
	GameFrameworkInstance.LoadImageResource(AppConfigInstance.GetResourcePath("Images/darkStoneBlock.png"), Image3);
	GameFrameworkInstance.LoadImageResource(AppConfigInstance.GetResourcePath("Images/dirtBlock.png"), Image4);
	GameFrameworkInstance.LoadImageResource(AppConfigInstance.GetResourcePath("Images/grassDirtBlock.png"), Image5);
	GameFrameworkInstance.LoadImageResource(AppConfigInstance.GetResourcePath("Images/heart.png"), Image6);
	GameFrameworkInstance.LoadImageResource(AppConfigInstance.GetResourcePath("Images/leavesBlock.png"), Image7);
	GameFrameworkInstance.LoadImageResource(AppConfigInstance.GetResourcePath("Images/skyBlock.png"), Image8);
	GameFrameworkInstance.LoadImageResource(AppConfigInstance.GetResourcePath("Images/spikes.png"), Image9);

	screenDimensions.X = AppConfigInstance.GetConfig<int>("Width");
	screenDimensions.Y = AppConfigInstance.GetConfig<int>("Height");

	// Load the image file Untitled.png from the Images folder. Give it the unique name of Image1
	 image1 = GameFrameworkInstance.GetLoadedImage(Image1);

	
	gameObjects.push_back(new Coin(Vector2i(300, 300)));
	gameObjects.push_back(new Coin(Vector2i(100, 100)));
	gameObjects.push_back(new Player());

	playerPtr = dynamic_cast<Player*>(gameObjects.back());

	std::ofstream saveFile("level.txt");

	GameObject::SaveObjects(saveFile, gameObjects);

	saveFile.close();

	// free up the game objects
	for (GameObject* objectPtr : gameObjects)
	{
		delete objectPtr;
	}
	gameObjects.clear();

	std::ifstream loadFile("level.txt");

	gameObjects = GameObject::LoadObjects(loadFile);

	// find the player
	for (GameObject* objectPtr : gameObjects)
	{
		playerPtr = dynamic_cast<Player*>(objectPtr);

		if (playerPtr)
			break;
	}

	loadFile.close();
}

void GameManager::EndPlay()
{
	// free up the game objects
	for (GameObject* objectPtr : gameObjects)
	{
		delete objectPtr;
	}
}

void GameManager::Update(double deltaTime)
{

}

void GameManager::Render(Gdiplus::Graphics& canvas, const CRect& clientRect)
{
	////////////////////////////////////////////////////////////////////////////////
	// Begin example code

	// Save the current transformation of the scene
	Gdiplus::Matrix transform;
	canvas.GetTransform(&transform);
	
	// Offset by the negative of the player direction
	canvas.TranslateTransform(-(Gdiplus::REAL)playerPtr->location.X, -(Gdiplus::REAL)playerPtr->location.Y);
	
	int numRows = clientRect.Height() / CellSize +2;
	int numCols = clientRect.Width() / CellSize * 10;

	// draw horizontal lines
	for (int row = 0; row < numRows; ++row)
	{
		Vector2i start = Vector2i(0, row * CellSize);
		Vector2i end = Vector2i(clientRect.Width() * 10, row * CellSize);
		GameFrameworkInstance.DrawLine(canvas,
			start,
			end,
			Gdiplus::Color::HotPink);
	}

	// draw vertical lines
	for (int col = 0; col < numCols; ++col)
	{
		Vector2i start = Vector2i(col * CellSize,0);
		Vector2i end = Vector2i(col * CellSize, clientRect.Height());
		GameFrameworkInstance.DrawLine(canvas,
			start,
			end,
			Gdiplus::Color::DeepPink);
	}

	// Draw all of the objects
	for (GameObject* objectPtr : gameObjects)
	{
		objectPtr->Render(canvas);
	}
	
	//Image following the mouse
	GameFrameworkInstance.DrawImage(canvas, Vector2i(mousePos.X - 16, mousePos.Y - 16), image1);

	// Restore the transformation of the scene
	canvas.SetTransform(&transform);
}

void GameManager::ChangeSelection(int selection)
{
	switch (selection)
	{
	case 1: 
		whichToPlace = 1;
		image1 = GameFrameworkInstance.GetLoadedImage(Image1);
		break;

	case 2:
		whichToPlace = 2;
		image1 = GameFrameworkInstance.GetLoadedImage(Image2);
		break;
		
	case 3:
		whichToPlace = 3;
		image1 = GameFrameworkInstance.GetLoadedImage(Image3);
		break;
		
	case 4:
		whichToPlace = 4;
		image1 = GameFrameworkInstance.GetLoadedImage(Image4);
		break;
		
	case 5:
		whichToPlace = 5;
		image1 = GameFrameworkInstance.GetLoadedImage(Image5);
		break;
		
	case 6:
		whichToPlace = 6;
		image1 = GameFrameworkInstance.GetLoadedImage(Image6);
		break;
		
	case 7:
		whichToPlace = 7;
		image1 = GameFrameworkInstance.GetLoadedImage(Image7);
		break;
		
	case 8:
		whichToPlace = 8;
		image1 = GameFrameworkInstance.GetLoadedImage(Image8);
		break;
		
	case 9:
		whichToPlace = 9;
		image1 = GameFrameworkInstance.GetLoadedImage(Image9);
		break;
	}
}

void GameManager::SetPlayerInput(const Vector2i& newInput)
{
	playerInput = newInput;

	// move the player
	playerPtr->location += playerInput;
}

void GameManager::OnMouseLClick(const Vector2i & loc)
{
	Vector2i location = loc + playerPtr->location;
	GameObject* toDelete = nullptr;

	//Convert the pixle coordinates to the grid cell coordinates
	int gridX = (location.X - (location.X % CellSize)) / CellSize;
	int gridY = (location.Y - (location.Y % CellSize)) / CellSize;

	Vector2i boxMin = Vector2i(gridX * CellSize, gridY * CellSize);
	Vector2i boxMax = boxMin + Vector2i(CellSize, CellSize);

	AABBi gridBounds = AABBi(boxMin, boxMax);

	for (GameObject* objectPtr : gameObjects)
	{
		GameObject& objectRef = *objectPtr;

		AABBi bounds(objectRef.location - Vector2i(16, 16),
			objectRef.location + Vector2i(16, 16));

		// clicked on this game object?
		if (bounds.Contains(location))
		{
			toDelete = objectPtr;
		}
	}

	if (toDelete)
	{
		gameObjects.erase(std::find(gameObjects.begin(), gameObjects.end(), toDelete));
		delete toDelete;
	}

		//GameFrameworkInstance.DrawImage(canvas, gridBounds.Centre(), GameFrameworkInstance.GetLoadedImage(SkyBlockIMG));

	//Instantiate a new Coin where we clicked
	switch (whichToPlace)
	{
	case 1:
	{
		BlueOrb* newObject = new BlueOrb(gridBounds.Centre());
		gameObjects.push_back(newObject);
	}
		break;

	case 2:
	{
		Coin* newObject = new Coin(gridBounds.Centre());
		gameObjects.push_back(newObject);
	}
		break;
	
	case 3:
	{
		Stone* newObject = new Stone(gridBounds.Centre());
		gameObjects.push_back(newObject);
	}
		break;

	case 4:
	{
		Dirt* newObject = new Dirt(gridBounds.Centre());
		gameObjects.push_back(newObject);
	}
		break;

	case 5:
	{
		DirtGrass* newObject = new DirtGrass(gridBounds.Centre());
		gameObjects.push_back(newObject);
	}
		break;

	case 6:
	{
		Heart* newObject = new Heart(gridBounds.Centre());
		gameObjects.push_back(newObject);
	}
		break;

	case 7:
	{
		Leaves* newObject = new Leaves(gridBounds.Centre());
		gameObjects.push_back(newObject);
	}
		break;

	case 8:
	{
		Sky* newObject = new Sky(gridBounds.Centre());
		gameObjects.push_back(newObject);
	}
		break;

	case 9:
	{
		Spikes* newObject = new Spikes(gridBounds.Centre());
		gameObjects.push_back(newObject);
	}
		break;
		
	}
	
}

void GameManager::OnMouseRClick(const Vector2i & loc)
{
	Vector2i location = loc + playerPtr->location;
	GameObject* toDelete = nullptr;

	for (GameObject* objectPtr : gameObjects)
	{
		GameObject& objectRef = *objectPtr;

		AABBi bounds(objectRef.location - Vector2i(16, 16),
			objectRef.location + Vector2i(16, 16));

		// clicked on this game object?
		if (bounds.Contains(location))
		{
			toDelete = objectPtr;
		}
	}

	if (toDelete)
	{
		gameObjects.erase(std::find(gameObjects.begin(), gameObjects.end(), toDelete));
		delete toDelete;
	}
}

void GameManager::OnMouseMove(const Vector2i & location)
{
	mousePos = location + playerPtr->location;
}

