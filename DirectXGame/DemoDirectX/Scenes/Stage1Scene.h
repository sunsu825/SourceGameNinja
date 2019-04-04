#pragma once

//#include <math.h>
#include <vector>
#include <d3dx9.h>
#include <d3d9.h>

#include "../GameComponents/Player.h"
#include "../GameComponents/Scene.h"
#include "../GameComponents/Sprite.h"

class Stage1Scene : public Scene
{
public:
	Stage1Scene();

    void Update(float dt);
    void LoadContent();
    void Draw();

protected:
    std::vector<Sprite*> mSprite;
	Player *player;

    float mTimeCounter;
};

