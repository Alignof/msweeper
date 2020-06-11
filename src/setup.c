#include "msweeper.h"

void create_field(){
	int i;
	char level;

	do{
		printf("input field size[S:5*5 M:8*8 L:12*12]>>");
		scanf("%c",&level);

		switch(level){
			case 's':
			case 'S':
				field.size=5;
				break;
			case 'm':
			case 'M':
				field.size=8;
				break;
			case 'l':
			case 'L':
				field.size=12;
				break;
			default:
				field.size=0;
		}
	}while(field.size==0);

	
	field.matrix=(Block **)calloc(field.size,sizeof(Block *));
	
	for(i=0;i<field.size;i++)
		field.matrix[i]=(Block *)calloc(field.size,sizeof(Block));
}
