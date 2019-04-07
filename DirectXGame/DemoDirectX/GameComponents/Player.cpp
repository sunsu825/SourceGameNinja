#include "Player.h"

Player::Player()
{

}

Player::Player(const char* filePath, int totalFrame, int rows, int columns, float timePerFrame, D3DCOLOR colorKey)
{
	InitWithPlayer(filePath, totalFrame, rows, columns, timePerFrame, colorKey);
}

void Player::InitWithPlayer(const char* filePath, int totalFrame, int rows, int columns, float timePerFrame, D3DCOLOR colorKey)
{
	//GAMELOG("Player: frame: %d, row: %d, column: %d, time: %f", totalFrame, rows, columns, timePerFrame);
	this->InitWithSprite(filePath);
	mCurrentColumn = 0;
	mCurrentRow = 0;
	mTimePerFrame = timePerFrame;
	mTotalFrame = totalFrame;
	mRows = rows;
	mColumns = columns;

	//width - height luc nay la cua spritesheet
	mFrameWidth = GetWidth() / mColumns;
	mFrameHeight = GetHeight() / mRows;

	SetWidth(mFrameWidth);
	SetHeight(mFrameHeight);

	mRect.top = 0;
	mRect.left = 0;
	mRect.right = mFrameWidth;
	mRect.bottom = mFrameHeight;
	SetSourceRect(mRect);
}

Player::~Player()
{

}

void Player::Update(float dt)
{
	if (mTotalFrame <= 1)
		return;

	if (mCurrentTotalTime >= mTimePerFrame)
	{
		mCurrentTotalTime = 0;
		mCurrentIndex++;
		mCurrentColumn++;

		if (mCurrentIndex >= mTotalFrame)
		{
			mCurrentIndex = 0;
			mCurrentColumn = 0;
			mCurrentRow = 0;
		}

		if (mCurrentColumn >= mColumns)
		{
			mCurrentColumn = 0;
			mCurrentRow++;

			if (mCurrentRow >= mRows)
				mCurrentRow = 0;
		}

		mRect.left = mCurrentColumn * mFrameWidth;
		mRect.right = mRect.left + mFrameWidth;
		mRect.top = mCurrentRow * mFrameHeight;
		mRect.bottom = mRect.top + mFrameHeight;

		SetSourceRect(mRect);
	}
	else
	{
		mCurrentTotalTime += dt;
	}
}

void Player::Draw(D3DXVECTOR3 position, RECT sourceRect, D3DXVECTOR2 scale,
	D3DXVECTOR2 transform, float angle, D3DXVECTOR2 rotationCenter, D3DXCOLOR colorKey)
{

	Sprite::Draw(position, sourceRect, scale, transform, angle, rotationCenter, colorKey);
}