#include "msweeper.h" 

void display_block(Block *block){
	// !debug: all block opend
	if(block->is_opened){
		switch(block->state){
			case MINE:
				printf("\e[31mM\e[39m");
				break;
			case HINT:
				printf("\e[43m%d\e[49m",block->hint);
				break;
			case NONE:
				printf("\e[43m \e[49m");
				break;
		}
	}else{
		printf("\e[42m \e[49m");
	}
}

void display_field(){
	int i,j;
	int x,y;
	char c;

	//printf("\033c");
	printf("\033[1;1H");
	printf("\033[2J");


	printf("\e[40m  \e[49m");
	for(i=0;i<field->size;i++)
		printf("\e[40m \e[49m");
	printf("\e[40m  \e[49m\n");

	for(y=0;y<field->size;y++){
		printf("\e[40m  \e[49m");
		for(x=0;x<field->size;x++){
			if(x==field->cursor_x && y==field->cursor_y){
				printf("\e[46m");
				display_block(&(field->matrix[x][y]));
				printf("\e[49m");
			}else{
				display_block(&(field->matrix[x][y]));
			}
		}
		printf("\e[40m  \e[49m\n");
	}

	printf("\e[40m  \e[49m");
	for(i=0;i<field->size;i++)
		printf("\e[40m \e[49m");
	printf("\e[40m  \e[49m\n");
}

void display_gameover(){
	int i;
	int x,y;
	char c;


	for(y=0;y<field->size;y++)
		for(x=0;x<field->size;x++)
			field->matrix[x][y].is_opened=true;

	display_field();
	printf("game over.\n");
}

void display_gameclear(){
	printf("game clear.\n");
}
