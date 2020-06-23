#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<time.h>
#include<string.h>
#include<termio.h>
#include<curses.h>

typedef struct{
	bool is_opened;
	int hint;
	enum {NONE, HINT, MINE, FLAG} state;
}Block;

typedef struct{
	int size;
	int mine_num;
	int cursor_x;
	int cursor_y;
	int opened_block;
	Block **matrix;
}Field;

Field *field;

// setup.c
void create_field();
void get_field_size();

// display.c
void display_field();
void display_block(Block *block);
void display_gameover();
void display_gameclear();

// playgame.c
bool gameover;
bool gameclear;
void playgame();
void get_command();
void block_open(int x,int y);
void open_automatically(int x,int y);

// getChar.c
void getChar();

