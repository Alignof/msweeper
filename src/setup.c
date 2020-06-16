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

void create_field(){
	int i;

	get_field_size();
	field->matrix=(Block **)calloc(field->size,sizeof(Block *));
	
	for(i=0;i<field->size;i++)
		field->matrix[i]=(Block *)calloc(field->size,sizeof(Block));

	set_mine();
}
