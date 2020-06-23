#include "msweeper.h"

void get_command(){
	char command;

	do{
		printf("[o:open f:flag or h,j,k,l]>>");
		command=getChar();

		switch(command){
			case 'o':
				block_open(field->cursor_x,field->cursor_y);
				break;
			case 'h':
				(field->cursor_x)--;
				break;
			case 'j':
				(field->cursor_y)++;
				break;
			case 'k':
				(field->cursor_y)--;
				break;
			case 'l':
				(field->cursor_x)++;
				break;
			default:
				command=0;
		}
	}while(!((0 <= field->cursor_y && field->cursor_y < field->size) && (0 <= field->cursor_x && field->cursor_x < field->size)) || command==0);
}

void open_automatically(int x,int y){
	int i,j;

	if(field->matrix[x][y].state==HINT){
		field->matrix[x][y].is_opened=true;
		return;
	}

	field->matrix[x][y].is_opened=true;
	field->opened_block++;


	for(i=-1;i<=1;i++){
		for(j=-1;j<=1;j++){
			if((0 <= x+i && x+i < field->size) && (0 <= y+j && y+j < field->size)){
				if(field->matrix[x+i][y+j].is_opened==false){
					open_automatically(x+i,y+j);
				}
			}
		}
	}
}

void block_open(int x,int y){
	int to_clear=(field->size*field->size)-field->mine_num;

	field->matrix[x][y].is_opened=true;
	field->opened_block++;

	if(field->matrix[x][y].state==NONE)
		open_automatically(x,y);


	if(field->matrix[x][y].state==MINE)
		gameover=true;

	if(field->opened_block==to_clear)
		gameclear=true;
}

void playgame(){
	int x,y;
	char command;
	gameover=false;
	gameclear=false;

	while(1){
		display_field();

		get_command();

		if(gameover | gameclear) break;
	}

	if(gameover) display_gameover();
	if(gameclear) display_gameclear();
}
