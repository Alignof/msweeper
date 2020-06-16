#include "msweeper.h" 

void display_block(Block *block){
	if(block->is_opend){
		switch(block->state){
			case MINE:
				printf("\e[31m M\e[39m");
				break;
			case HINT:
				printf("%d",block->mine_num);
				break;
			case NONE:
				printf("  ");
				break;
		}
	}else{
		printf(" #");
	}
}

void display_field(){
	int i,j;
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

	for(i=0;i<field->size;i++){
		printf("%2d|",i+1);
		for(j=0;j<field->size;j++)
			display_block(&(field->matrix[i][j]));
		printf("\n");
	}
}
