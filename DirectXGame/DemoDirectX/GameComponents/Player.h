#ifndef __ANIMATION__
#define __ANIMATION__

#include <Windows.h>
#include <d3dx9.h>
#include <d3d9.h>
#include <vector>
#include "Sprite.h"

// use frame by frame to create player and inherit sprite
class Player : public Sprite {
public:
	
	Player();
	~Player();
	Player(const char* filepath, int totalFrame, int rows, int columns, float timePerFrame = 0.1f, D3DCOLOR colorKey=NULL);
	virtual void Update(float dt);
	void Draw(D3DXVECTOR3 position = D3DXVECTOR3(), RECT sourceRect = RECT(), D3DXVECTOR2 scale = D3DXVECTOR2(), D3DXVECTOR2 transform = D3DXVECTOR2(), float angle = 0, D3DXVECTOR2 rotationCenter = D3DXVECTOR2(), D3DXCOLOR colorKey = D3DCOLOR_XRGB(255, 255, 255));

	virtual void SetPosition(D3DXVECTOR3 pos);
	virtual void SetPosition(float x, float y);
	virtual void SetPosition(D3DXVECTOR2 pos);

	D3DXVECTOR2 GetScale();
	void SetScale(D3DXVECTOR2 scale);

	float GetRotation();
	void SetRotation(float rotation); // by radian

	D3DXVECTOR2 GetRotationCenter();
	void SetRotationCenter(D3DXVECTOR2 rotationCenter);

	void SetFlipVertical(bool flag);
	void SetFlipHorizontal(bool flag);

	D3DXVECTOR2 GetTranslation(); // phep tinh tien tu world position -> view position
	void SetTranslation(D3DXVECTOR2 translation); // phep tinh tien: tu the world position -> view position


protected:
	//su dung cho ke thua
	void InitWithPlayer(const char* filePath, int totalFrame, int rows, int columns, float timePerFrame = 0.1f, D3DCOLOR colorKey = NULL);

	int         mRows, //so hang cua animation
		mColumns, //so cot cua animation
		mCurrentIndex, //gia tri frame hien tai - bat dau tu 0 -> tong so frame - 1
		mCurrentRow, // hang hien tai
		mCurrentColumn, // cot hien tai
		mFrameWidth, // chieu rong cua 1 frame 
		mFrameHeight, // chieu dai cua 1 frame
		mTotalFrame;  //tong so frame


	float       mTimePerFrame, //thoi gian luan chuyen 1 frame
		mCurrentTotalTime; //tong thoi gian hien tai de thuc hien timeperframe

	Sprite      *mSprite;

	RECT        mRect;

};
#endif