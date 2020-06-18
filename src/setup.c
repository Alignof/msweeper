#include "msweeper.h"

void get_field_size(){
	char level;
	do{
		printf("input field size[S:5*5 M:8*8 L:12*12]>>");
		scanf("%c",&level);

		switch(level){
			case 's':
			case 'S':
				field->size=5;
				field->mine_num=3;
				break;
			case 'm':
			case 'M':
				field->size=8;
				field->mine_num=4;
				break;
			case 'l':
			case 'L':
				field->size=12;
				field->mine_num=7;
				break;
			default:
				field->size=0;
		}
	}while(field->size==0);
}

void set_mine(){
	int x,y;
	int counter=0;

	srand((unsigned)time(NULL));

	while(counter < field->mine_num){
		x=rand()%field->size;
		y=rand()%field->size;

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
			if((0 <= x+i && x+i < field->size) && (0 <= y+j && y+j < field->size)){
				if(field->matrix[x+i][y+j].state==MINE) hint_num++;
			}
		}
	}

	return hint_num;
}

void set_hint(){
	int x,y;

	for(y=0;y<field->size;y++){
		for(x=0;x<field->size;x++){
			field->matrix[x][y].hint=check_around(x,y);
			if(field->matrix[x][y].hint>0 && field->matrix[x][y].state!=MINE) field->matrix[x][y].state=HINT;
		}
	}
}

void create_field(){
	int i;

	get_field_size();
	field->matrix=(Block **)calloc(field->size,sizeof(Block *));
	
	for(i=0;i<field->size;i++)
		field->matrix[i]=(Block *)calloc(field->size,sizeof(Block));

	set_mine();
	set_hint();
}
