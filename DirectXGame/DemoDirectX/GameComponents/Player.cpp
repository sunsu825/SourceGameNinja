#include "Player.h"

Player::Player()
{
}

Player::~Player()
{
	delete mSprite;
}

Player::Player(const char * filepath, int totalFrame, int rows, int columns, float timePerFrame, D3DCOLOR colorKey)
{
	InitWithPlayer(filepath, totalFrame, rows, columns, timePerFrame, colorKey);
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

		mSprite->SetSourceRect(mRect);
	}
	else
	{
		mCurrentTotalTime += dt;
	}
}

void Player::Draw(D3DXVECTOR3 position, RECT sourceRect, D3DXVECTOR2 scale, 
	D3DXVECTOR2 transform, float angle, D3DXVECTOR2 rotationCenter, D3DXCOLOR colorKey)
{
	mSprite->Draw(position, sourceRect, scale, transform, angle, rotationCenter, colorKey);
}

void Player::SetPosition(D3DXVECTOR3 pos)
{
	mSprite->SetPosition(pos);
}

void Player::SetPosition(float x, float y)
{
	SetPosition(D3DXVECTOR3(x, y, 0));
}

void Player::SetPosition(D3DXVECTOR2 pos)
{
	SetPosition(D3DXVECTOR3(pos));
}

D3DXVECTOR2 Player::GetScale()
{
	return mSprite->GetScale();;
}

void Player::SetScale(D3DXVECTOR2 scale)
{
	mSprite->SetScale(scale);
}

float Player::GetRotation()
{
	return mSprite->GetRotation();
}

void Player::SetRotation(float rotation)
{
	mSprite->SetRotation(rotation);
}

D3DXVECTOR2 Player::GetRotationCenter()
{
	return mSprite->GetRotationCenter();
}

void Player::SetRotationCenter(D3DXVECTOR2 rotationCenter)
{
	mSprite->SetRotationCenter(rotationCenter);
}

void Player::SetFlipVertical(bool flag)
{
	mSprite->FlipVertical(flag);
}

void Player::SetFlipHorizontal(bool flag)
{
	mSprite->FlipHorizontal(flag);
}

D3DXVECTOR2 Player::GetTranslation()
{
	return mSprite->GetTranslation();
}

void Player::SetTranslation(D3DXVECTOR2 translation)
{
	mSprite->SetTranslation(translation);
}

void Player::InitWithPlayer(const char * filePath, int totalFrame, int rows, int columns, float timePerFrame, D3DCOLOR colorKey)
{
	mSprite = new Sprite(filePath);
	mCurrentColumn = 0;
	mCurrentRow = 0;
	mTimePerFrame = timePerFrame;
	mTotalFrame = totalFrame;
	mRows = rows;
	mColumns = columns;

	//width - height luc nay la cua spritesheet
	mFrameWidth = mSprite->GetWidth() / mColumns;
	mFrameHeight = mSprite->GetHeight() / mRows;

	//set lai cho size cua sprite bang dung size cua frame de tranh bi lech vi tri
	mSprite->SetWidth(mFrameWidth);
	mSprite->SetHeight(mFrameHeight);

	mRect.top = 0;
	mRect.left = 0;
	mRect.right = mFrameWidth;
	mRect.bottom = mFrameHeight;
	mSprite->SetSourceRect(mRect);
}
