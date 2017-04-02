#include "stdafx.h"
#include "GameManager.h"
#include "Cheesecake.h"

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

	gameObjects.push_back(new Cheesecake(Vector2i(300, 300)));
	gameObjects.push_back(new Cheesecake(Vector2i(100, 100)));
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
	
	int numRows = clientRect.Height() / CellSize;
	int numCols = clientRect.Width() / CellSize;

	// draw horizontal lines
	for (int row = 0; row < numRows; ++row)
	{
		Vector2i start = Vector2i(0, row * CellSize);
		Vector2i end = Vector2i(clientRect.Width(), row * CellSize);
		GameFrameworkInstance.DrawLine(canvas,
			start,
			end,
			Gdiplus::Color::HotPink);
	}

	// draw vertical lines
	for (int col = 0; col < numCols; ++col)
	{
		Vector2i start = Vector2i(col * CellSize, 0);
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

	// Render method demonstration (You can remove all of this code)
	GameFrameworkInstance.DrawLine(canvas, Vector2i(200, 200), Vector2i(400, 200), Gdiplus::Color::White);

	GameFrameworkInstance.DrawRectangle(canvas, AABBi(Vector2i(10, 110), Vector2i(100, 200)), false, Gdiplus::Color::White);
	GameFrameworkInstance.DrawRectangle(canvas, AABBi(Vector2i(200, 110), Vector2i(300, 200)), true, Gdiplus::Color::White);

	//// restore the transform
	//canvas.SetTransform(&transform);

	GameFrameworkInstance.DrawCircle(canvas, Vector2i(200, 200), 50, false, Gdiplus::Color::White);
	GameFrameworkInstance.DrawCircle(canvas, Vector2i(400, 200), 50, true, Gdiplus::Color::White);

	GameFrameworkInstance.DrawText(canvas, Vector2i(10, 300), 12, "Arial", "Hello World!", Gdiplus::Color::White);

	
	//GameFrameworkInstance.DrawImage(canvas, Vector2i(400, 400), image1);

	//Image following the mouse
	GameFrameworkInstance.DrawImage(canvas, Vector2i(mousePos.X - 16, mousePos.Y - 16), image1);

	// Restore the transformation of the scene
	canvas.SetTransform(&transform);

	// End example code
	////////////////////////////////////////////////////////////////////////////////
}

void GameManager::ChangeSelection(int selection)
{
	switch (selection)
	{
	case 1: 
		image1 = GameFrameworkInstance.GetLoadedImage(Image1);
		break;

	case 2:
		image1 = GameFrameworkInstance.GetLoadedImage(Image2);
		break;
		
	case 3:
		image1 = GameFrameworkInstance.GetLoadedImage(Image3);
		break;
		
	case 4:
		image1 = GameFrameworkInstance.GetLoadedImage(Image4);
		break;
		
	case 5:
		image1 = GameFrameworkInstance.GetLoadedImage(Image5);
		break;
		
	case 6:
		image1 = GameFrameworkInstance.GetLoadedImage(Image6);
		break;
		
	case 7:
		image1 = GameFrameworkInstance.GetLoadedImage(Image7);
		break;
		
	case 8:
		image1 = GameFrameworkInstance.GetLoadedImage(Image8);
		break;
		
	case 9:
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

	//Instantiate a new cheesecake where we clicked

	Cheesecake* newObject = new Cheesecake(gridBounds.Centre());
	gameObjects.push_back(newObject);
}

void GameManager::OnMouseRClick(const Vector2i & location)
{
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

