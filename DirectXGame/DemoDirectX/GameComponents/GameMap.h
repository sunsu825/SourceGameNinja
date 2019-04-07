#pragma once
#ifndef __GAME_MAP__
#define __GAME_MAP__

#include <d3dx9.h>
#include <d3d9.h>
#include <vector>

#include "Sprite.h"
#include "../MapReader/Tmx.h.in"
#include "GameGlobal.h"

class GameMap
{
public:
	GameMap(char* filePath);

	Tmx::Map* GetMap();

	int GetWidth();
	int GetHeight();
	int GetTileWidth();
	int GetTileHeight();

	void Draw();

	~GameMap();

private:
	void LoadMap(char* filePath);

	Tmx::Map                        *mMap;
	std::map<int, Sprite*>          mListTileset;
};

#endif

