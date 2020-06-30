#include "msweeper.h" 

void display_prompt(){
	printf("remain mine:%d\n",field->remain_flag);
	printf("[o:open f:flag or h,j,k,l]>>");
}

void display_block(Block *block,int x,int y){
	// !debug: all block opend
	
	if(x==field->cursor_x && y==field->cursor_y)
		printf("\e[45m");
	else if(block->is_opened)
		printf("\e[43m");
	else
		printf("\e[42m");

	if(block->is_opened){
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
		if(block->raise_flag)
			printf("\e[31mF\e[39m");
		else
			printf(" ");
	}

	printf("\e[49m");
}

void display_field(){
	int i,j;
	int x,y;
	char c;

	//printf("\033c");
	printf("\033[1;1H");
	printf("\033[2J");


	printf("\e[40m  ");
	for(i=0;i<field->size_y;i++)
		printf(" ");
	printf("  \e[49m\n");

	for(y=0;y<field->size_x;y++){
		printf("\e[40m  \e[49m");
		for(x=0;x<field->size_y;x++){
			display_block(&(field->matrix[x][y]),x,y);
		}
		printf("\e[40m  \e[49m\n");
	}

	printf("\e[40m  ");
	for(i=0;i<field->size_y;i++)
		printf(" ");
	printf("  \e[49m\n");
}

void display_gameover(){
	int i;
	int x,y;
	char c;

	for(y=0;y<field->size_x;y++)
		for(x=0;x<field->size_y;x++)
			field->matrix[x][y].is_opened=true;

	display_field();
	printf("game over.\n");
}

void display_gameclear(){
	printf("game clear.\n");
}
