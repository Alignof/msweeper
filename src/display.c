#include "msweeper.h" 

void display_block(Block *block){
	switch(block->state){
		case MINE:
			printf("  #");
			break;
		case HINT:
			printf("%3d",block->mine_num);
			break;
		case NONE:
			printf("   ");
			break;
	}
}

void display_field(){
	int i,j;

	//printf("\033c");
	printf("\033[1;1H");
	printf("\033[2J");
	

	printf("    ");
	for(i=0;i<field.size;i++)
		printf("%3d",i);
	printf("\n");

	printf("    ");
	for(i=0;i<field.size;i++)
		printf("---",i);
	printf("\n");

	for(i=0;i<field.size;i++){
		printf("%3d|",i);
		for(j=0;j<field.size;j++)
			display_block(&(field.matrix[i][j]));
		printf("\n");
	}
}
