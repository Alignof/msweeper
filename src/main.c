#include "hangman.h"

int main(int argc,char *argv[]){
	Words *words;

	readfile(&words,argc,argv);
	playgame(words);

	return 0;
}
