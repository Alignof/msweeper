#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<time.h>
#include<string.h>
#include<termio.h>
#include<curses.h>

typedef struct{
	bool is_opend;
	int mine_num;
	enum {MINE, HINT, NONE} state;
}Block;

typedef struct{
	int size;
	Block **matrix;
}Field;

Field *field;

// setup.c
void create_field();

// display.c
void display_field();
void display_block(Block *block);

// playgame.c
void playgame();
