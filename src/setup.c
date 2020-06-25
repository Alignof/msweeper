#include "msweeper.h"

void get_field_size(){
	char level;
	do{
		printf("input field size[S:5*5 M:8*8 L:12*12]>>");
		scanf("%c",&level);

		switch(level){
			case 's':
			case 'S':
				field->size_x=10;
				field->mine_num=3;
				break;
			case 'm':
			case 'M':
				field->size_x=20;
				field->mine_num=80;
				break;
			case 'l':
			case 'L':
				field->size_x=30;
				field->mine_num=180;
				break;
			default:
				field->size_x=0;
		}
	}while(field->size_x==0);
	field->size_y=(field->size_x)*2;
}

void set_mine(){
	int x,y;
	int counter=0;

	srand((unsigned)time(NULL));

	while(counter < field->mine_num){
		x=rand()%(field->size_y);
		y=rand()%(field->size_x);

		if(field->matrix[x][y].state==MINE)
			continue;

		field->matrix[x][y].state=MINE;
		counter++;
	}
}

int check_around(int x,int y){
	int i,j;
	int hint_num=0;

	for(i=-1;i<=1;i++){
		for(j=-1;j<=1;j++){
			if((0 <= x+i && x+i < field->size_y) && (0 <= y+j && y+j < field->size_x)){
				if(field->matrix[x+i][y+j].state==MINE) hint_num++;
			}
		}
	}

	return hint_num;
}

void set_hint(){
	int x,y;

	for(y=0;y<field->size_x;y++){
		for(x=0;x<field->size_y;x++){
			field->matrix[x][y].hint=check_around(x,y);
			// NONE -> HINT
			if(field->matrix[x][y].hint>0 && field->matrix[x][y].state!=MINE) field->matrix[x][y].state=HINT;
		}
	}
}

void create_field(){
	int i;

	get_field_size();
	field->matrix=(Block **)calloc(field->size_y,sizeof(Block *));
	
	for(i=0;i<field->size_y;i++)
		field->matrix[i]=(Block *)calloc(field->size_x,sizeof(Block));

	set_mine();
	set_hint();

	field->cursor_x=0;
	field->cursor_y=0;
}
