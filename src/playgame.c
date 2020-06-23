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

void open_safety_block(int x,int y){
	int i,j;

	if(field->matrix[x][y].state==HINT){
		field->matrix[x][y].is_opend=true;
		return;
	}

	field->matrix[x][y].is_opend=true;
	field->opend_block++;


	for(i=-1;i<=1;i++){
		for(j=-1;j<=1;j++){
			if((0 <= x+i && x+i < field->size) && (0 <= y+j && y+j < field->size)){
				if(field->matrix[x+i][y+j].is_opend==false){
					open_safety_block(x+i,y+j);
				}
			}
		}
	}
}

void playgame(){
	int x,y;
	int to_clear=(field->size*field->size)-field->mine_num;
	bool gameover=false;
	bool gameclear=false;

	while(1){
		display_field();

		get_open_block(&x,&y);
		field->matrix[x][y].is_opend=true;

		if(field->matrix[x][y].state==MINE){
			gameover=true;
			break;
		}

		if(field->matrix[x][y].state==NONE) open_safety_block(x,y);

		field->opend_block++;

		if(field->opend_block==to_clear){
			gameclear=true;
			break;
		}
	}

	if(gameover) display_gameover();
	if(gameclear) display_gameclear();
}
