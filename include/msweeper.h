#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<time.h>
#include<string.h>
#include<termio.h>
#include<curses.h>

typedef struct{
	int mine_num;
	enum {MINE, HINT, NONE} state;
}Block;

typedef struct{
	int size;
	Block **matrix;
}Field;

Field field;

void create_field();
void display_field();
