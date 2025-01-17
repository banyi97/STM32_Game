/*
 * Blocks.h
 *
 *  Created on: Dec 1, 2019
 *      Author: atbar
 */

#ifndef CONTROLS_BLOCKS_H_
#define CONTROLS_BLOCKS_H_

#include "BasicControls.h"

#define BULLET_A 6
#define NUM_OF_ROWS 10			//sorok száma
#define NUM_OF_COLS 8			//oszlopok száma
#define BLOCK_HEIGHT 10			//blokkok magassága (blokkok 175-275-ig)
#define BLOCK_WIDTH 30			//blokkok szélessége (0 - 240)
#define TOP_LINE 275			//blokkok teteje
#define BOTTOM_LINE 175			//blokkok alja
#define BAR_LENGTH 60
#define BAR_HEIGHT 25
#define AREA_HEIGHT 300
#define AREA_WIDTH 240

typedef struct
{
	uint32_t	color;
	uint8_t		isActive;
} Block;

typedef enum{
	none,
	fromBottom,
	fromTop,
	fromLeft,
	fromRight
} Collision;

typedef struct
{
	int16_t 	speed_X;
	int16_t		speed_Y;
} Speed;

typedef struct
{
	uint8_t		NeedToDraw;
	Event 		OnNewData;
	//Data
	uint8_t		Remaining;
	uint8_t		IsGameOver;
	Block		Blocks[NUM_OF_COLS][NUM_OF_ROWS];
	Pixel		BulletPosition;
	Speed		BulletSpeed;
	Pixel		BarPosition;
	Speed		BarSpeed;
	uint32_t 	Tik;
	//Appearance
	Pixel		Position;
	Pixel		Size;
} Blockgame;

void InitBlockGame(Blockgame* c);

void DrawBlockGame(Blockgame* c);

void UpdateBlockGameData(Blockgame* c, int32_t val);

Collision checkCollision(Blockgame* game);

uint8_t collideFromBottom(Blockgame* game);
uint8_t collideFromTop(Blockgame* game);
uint8_t collideFromLeft(Blockgame* game);
uint8_t collideFromRight(Blockgame* game);
void collideWithHorizontal(Blockgame* game);
void collideWithVertical(Blockgame* game);
void collideWithBar(Blockgame* game);

#endif /* CONTROLS_BLOCKS_H_ */
