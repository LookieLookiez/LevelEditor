#pragma once

#include "GameFramework.h"
#include "Player.h"

#include <list>
#include <string>

const int CellSize = 32;

class GameManager
{
public:
	static GameManager& Instance();

	/** BeginPlay is called when the game first launches. It is only called once per launch. */
	void BeginPlay();

	/** EndPlay is called when the game is closing down. It is only called once and only on exit. */
	void EndPlay();

	/**
	 * Update is called every frame. Update is always called before render
	 *
	 * @param deltaTime The time in seconds since Update was last called.
	 */
	void Update(double deltaTime);

	/**
	 * Render is called every frame after Update is called. All drawing must happen in render.
	 *
	 * @param [in,out] canvas The canvas.
	 * @param clientRect	  The rectangle representing the drawable area.
	 */
	

	void Render(Gdiplus::Graphics& canvas, const CRect& clientRect);

	void ChangeSelection(int selection);

	void SetPlayerInput(const Vector2i& newInput);
	void OnMouseLClick(const Vector2i& loc);
	void OnMouseRClick(const Vector2i& loc);
	void OnMouseMove(const Vector2i& location);
	
	const Vector2i& GetScreenDimensions() const
	{
		//const_cast<GameManager*>(this)->dontChangeThis = true;
		//dontChangeThis = true;
		return screenDimensions;
	}
	ImageWrapper* image1;
	int whichToPlace = 1;
	
private:
	class myClass;
	GameManager();
	~GameManager();

	Vector2i playerInput;

	std::list<GameObject*> gameObjects;
	//std::list<std::string*> imageIdentifier;
	Vector2i mousePos;
	Player* playerPtr;

	Vector2i screenDimensions;
	bool dontChangeThis = false;

	int selectionID = 0;

	
};

/**
 * Retrieves the GameManagerInstance for the game.
 *
 * @return The game manager instance
 */
#define GameManagerInstance (GameManager::Instance())
