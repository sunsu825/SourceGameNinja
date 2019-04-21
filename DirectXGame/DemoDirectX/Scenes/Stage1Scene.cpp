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
        sprite = new Sprite("imageGameNija/NinjaGaidenMapStage3-1BG.png");

        //add sprite vao vector
        mSprite.push_back(sprite);
	
	// load map 
	//mGameMap = new GameMap("Resources/mapNinjademo.tmx");

		// create Player with filePath, totalFrame, number row, number column, timePerFrame
		mPlayer = new Player("imageGameNija/RyuR.png", 1, 1, 1, 0.55);
		mPlayer->SetPosition(GameGlobal::GetWidth() / 3, 3.5*GameGlobal::GetHeight() / 5 + 25);
		mPlayer->SetScale(D3DXVECTOR2(2.5, 2.5));

		// create player 
		//player = new Player("imageGameNija/PlayerFrame.png", 3, 1, 3, 0.15);
		//player->SetPosition(GameGlobal::GetWidth() / 3, 3.5*GameGlobal::GetHeight() / 5 + 25);
		//player->SetScale(D3DXVECTOR2(2.5, 2.5));
    
}

void Stage1Scene::Update(float dt)
{
    //cong don thoi gian lai 60 FPS = 1 / 60 giay trong 1 lan goi update
    mTimeCounter += dt;
	
    //update sau 1 giay
    if (mTimeCounter >= 0.05f)
    {
		//sprite->SetPosition(sprite->GetWidth()*1.5, GameGlobal::GetHeight() / 2);
        for (Sprite *child : mSprite)
        {
            //set lai position random tu 0 -> 500 theo x va y cho moi sprite
            child->SetPosition(child->GetWidth()*1.5, GameGlobal::GetHeight() / 2);
        }
		
        //set lai counter
        mTimeCounter = 0;
		
    }
	
	mPlayer->Update(dt);

}

void Stage1Scene::Draw()
{
	
    //goi va draw cac sprite trong vector
    for (Sprite *child : mSprite)
    {
        child->Draw();
    }
	
	mPlayer->Draw();
}

void Stage1Scene::OnKeyDown(int keyCode)
{
	if (keyCode == VK_LEFT) {
		mPlayer->SetPosition(mPlayer->GetPosition() + D3DXVECTOR3(-10, 0, 0));
	}

	if (keyCode == VK_RIGHT) {
		mPlayer->SetPosition(mPlayer->GetPosition() + D3DXVECTOR3(10, 0, 0));
	}

	if (keyCode == VK_UP) {
		mPlayer->SetPosition(mPlayer->GetPosition() + D3DXVECTOR3(0, -50, 0));
	}

	if (keyCode == VK_DOWN) {
		mPlayer->SetPosition(mPlayer->GetPosition() + D3DXVECTOR3(0, 10, 0));
	}

}

void Stage1Scene::OnKeyUp(int keyCode)
{
	if (keyCode == VK_UP) {
		mPlayer->SetPosition(mPlayer->GetPosition() + D3DXVECTOR3(0, 50, 0));
		
		
	}
}

