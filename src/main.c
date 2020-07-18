#include "msweeper.h"

int main(int argc,char *argv[]){
	field=calloc(1,sizeof(Field));

	create_field();
	playgame();

	return 0;
}
