#include "msweeper.h" 

void display_block(Block *block){
	// !debug: all block opend
	if(block->is_opend){
		switch(block->state){
			case MINE:
				printf("\e[31mM\e[39m");
				break;
			case HINT:
				printf("%d",block->hint);
				break;
			case NONE:
				printf(" ");
				break;
		}
	}else{
		printf("#");
	}
}

void display_field(){
	int i,j;
	int x,y;
	char c;

	//printf("\033c");
	printf("\033[1;1H");
	printf("\033[2J");


	printf("   ");
	for(c='a';c<'a'+field->size;c++)
		printf(" %c",c);
	printf("\n");

	printf("   ");
	for(i=0;i<field->size;i++)
		printf("--",i);
	printf("\n");

	for(y=0;y<field->size;y++){
		printf("%2d|",y+1);
		for(x=0;x<field->size;x++){
			if(x==field->cursor_x && y==field->cursor_y){
				printf(" \e[46m");
				display_block(&(field->matrix[x][y]));
				printf("\e[49m");
			}else{
				printf(" ");
				display_block(&(field->matrix[x][y]));
			}
		}
		printf("\n");
	}
}

void display_gameover(){
	int i;
	int x,y;
	char c;


	for(y=0;y<field->size;y++)
		for(x=0;x<field->size;x++)
			field->matrix[x][y].is_opend=true;

	display_field();
	printf("game over.\n");
}

void display_gameclear(){
	printf("game clear.\n");
}
