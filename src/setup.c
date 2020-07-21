#include "msweeper.h"

void get_field_size(){
	char level;
	do{
		printf("input field size[S:10*20 M:20*40 L:30*60]>>");
		scanf("%c",&level);

		switch(level){
			case 's':
			case 'S':
				field->size_y=10;
				field->mine_num=20;
				break;
			case 'm':
			case 'M':
				field->size_y=20;
				field->mine_num=80;
				break;
			case 'l':
			case 'L':
				field->size_y=30;
				field->mine_num=180;
				break;
			default:
				field->size_y=0;
		}
	}while(field->size_y==0);
	field->size_x=(field->size_y)*2;
	field->remain_flag=field->mine_num;
}

void set_mine(int first_x,int first_y){
	int x,y;
	int counter=0;

	srand((unsigned)time(NULL));

	while(counter < field->mine_num){
		x=rand()%(field->size_x);
		y=rand()%(field->size_y);

		if(x-1==first_x || x==first_x || x+1==first_x || y-1==first_y || y==first_y || y+1==first_y)
			continue;

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
			if((0 <= x+i && x+i < field->size_x) && (0 <= y+j && y+j < field->size_y)){
				if(field->matrix[x+i][y+j].state==MINE) hint_num++;
			}
		}
	}

	return hint_num;
}

void set_hint(){
	int x,y;

	for(y=0;y<field->size_y;y++){
		for(x=0;x<field->size_x;x++){
			field->matrix[x][y].hint=check_around(x,y);
			// NONE -> HINT
			if(field->matrix[x][y].hint>0 && field->matrix[x][y].state!=MINE) field->matrix[x][y].state=HINT;
		}
	}
}

void create_field(){
	int i;

	get_field_size();
	field->matrix=(Block **)calloc(field->size_x,sizeof(Block *));
	
	for(i=0;i<field->size_x;i++)
		field->matrix[i]=(Block *)calloc(field->size_y,sizeof(Block));

	field->cursor_x=0;
	field->cursor_y=0;
}
