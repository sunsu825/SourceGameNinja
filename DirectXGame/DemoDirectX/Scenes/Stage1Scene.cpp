#include "Stage1Scene.h"
#include "../GameComponents/GameGlobal.h"

Stage1Scene::Stage1Scene()
{
    LoadContent();
}

void Stage1Scene::LoadContent()
{
    //set time counter = 0
    mTimeCounter = 0;

    //set mau backcolor cho scene o day la mau xanh
    mBackColor = 000000;

   
        //tao nhung normalbrick tu hinh anh theo duong dan
        Sprite *sprite = new Sprite("imageGameNija/NinjaGaidenMapStage3-1BG.png");

        //set random position cho cac sprite tu 0 -> 500 theo x, y
        //sprite->SetPosition(rand() % 500, rand() % 500);

        //add sprite vao vector
        mSprite.push_back(sprite);

		// create player 
		player = new Player("imageGameNija/PlayerFrame.png", 3, 1, 3, 0.5);
		player->SetPosition(GameGlobal::GetWidth() / 3, 4*GameGlobal::GetHeight() / 5);
		player->SetScale(D3DXVECTOR2(2, 2));
    
}

void Stage1Scene::Update(float dt)
{
    //cong don thoi gian lai 60 FPS = 1 / 60 giay trong 1 lan goi update
    mTimeCounter += dt;
	
    //update sau 1 giay
    if (mTimeCounter >= 1.0f)
    {
		
        for (Sprite *child : mSprite)
        {
            //set lai position random tu 0 -> 500 theo x va y cho moi sprite
            child->SetPosition(child->GetWidth()*1.5, GameGlobal::GetHeight() / 2);
        }
		
        //set lai counter
        mTimeCounter = 0;
    }
	player->Update(dt);
}

void Stage1Scene::Draw()
{
	
    //goi va draw cac sprite trong vector
    for (Sprite *child : mSprite)
    {
        child->Draw();
    }
	player->Draw();
}