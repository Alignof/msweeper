#include "msweeper.h"

void get_command(){
	char command;

	do{
		display_field();
		display_prompt();
		command=getChar();

		switch(command){
			case 'o':
				block_open(field->cursor_x,field->cursor_y);
				break;
			case 'f':
				raise_your_flag(&(field->matrix[field->cursor_x][field->cursor_y]));
				break;
			case 'h':
				if(0 < field->cursor_x)
					(field->cursor_x)--;
				break;
			case 'j':
				if(field->cursor_y < field->size_y-1)
					(field->cursor_y)++;
				break;
			case 'k':
				if(0 < field->cursor_y)
					(field->cursor_y)--;
				break;
			case 'l':
				if(field->cursor_x < field->size_x-1)
					(field->cursor_x)++;
				break;
			case '^':
				field->cursor_x=0;
				break;
			case '$':
				field->cursor_x=field->size_x-1;
				break;
			case 'g':
				field->cursor_y=0;
				break;
			case 'G':
				field->cursor_y=field->size_y-1;
				break;
			default:
				command=0;
		}
	}while(command==0);
}

void raise_your_flag(Block *block){
	if(block->is_opened==false){
		block->raise_flag=!(block->raise_flag);

		if(block->raise_flag)
			field->remain_flag--;
		else
			field->remain_flag++;
	}
}

void open_automatically(int x,int y){
	int i,j;

	if(field->matrix[x][y].state==HINT && !(field->matrix[x][y].is_opened)){
		field->matrix[x][y].is_opened=true;
		field->opened_block++;
		return;
	}

	if(field->matrix[x][y].is_opened==false){
		field->matrix[x][y].is_opened=true;
		field->opened_block++;
	}

	if(0<=x-1 && field->matrix[x-1][y].is_opened==false)
		open_automatically(x-1,y);
	if(x+1<field->size_x && field->matrix[x+1][y].is_opened==false)
		open_automatically(x+1,y);
	if(0<=y-1 && field->matrix[x][y-1].is_opened==false)
		open_automatically(x,y-1);
	if(y+1<field->size_y && field->matrix[x][y+1].is_opened==false)
		open_automatically(x,y+1);
}

void block_open(int x,int y){
	static bool is_first=true;
	Block *block=&(field->matrix[x][y]);
	int to_clear=(field->size_x*field->size_y)-field->mine_num;

	if(is_first){
		set_mine(x,y);
		set_hint();
		is_first=false;
	}

	if(block->is_opened || block->raise_flag)
		return;

	block->is_opened=true;
	field->opened_block++;

	if(block->state==NONE)
		open_automatically(x,y);


	if(block->state==MINE)
		gameover=true;

	if(field->opened_block==to_clear)
		gameclear=true;

	printf("\nto_clear:%d\n",to_clear);
	printf("opened_block:%d\n",field->opened_block);
}

void playgame(){
	int x,y;
	gameover=false;
	gameclear=false;

	struct timeval start, end;
	gettimeofday(&start, NULL);

	while(1){
		get_command();
		if(gameover | gameclear) break;
	}

	gettimeofday(&end, NULL);
	double seconds=(end.tv_sec-start.tv_sec);
	double micros=((seconds*1000000)+end.tv_usec)-(start.tv_usec);

	if(gameover) display_gameover();
	if(gameclear) display_gameclear();

	printf("time:%.2f\n", micros/1000000);
}
