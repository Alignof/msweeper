#include "msweeper.h"

void get_open_block(int *x,int *y){
	char yin;
	int xin;

	do{
		printf("Input open block[a 1]>>");
		scanf(" %c%d",&yin,&xin);
		*y=yin-'a';
		*x=xin-1;
	}while(!((0 <= *y && *y < field->size) && (0 <= *x && *x < field->size)));
}

void playgame(){
	int x,y;

	while(1){
		display_field();

		get_open_block(&x,&y);
		field->matrix[x][y].is_opend=true;
	}
}
