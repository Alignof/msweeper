#include "hangman.h"
#define TRY 7


void playgame(Words *words){
	int i;
	int remain;
	bool hit;
	char input=0;
	bool game_continue=true;
	bool used['z'-'a'+1]={0};
	Words *word;

	srand((unsigned int)time(NULL));

	while(game_continue){
		word=&(words[rand()%Wordsize]);
		if(word->is_correct) continue;

		remain=TRY;
		input=NULL;

		// initial
		display_data(word,used,input,&remain);
		while(remain>0){
			printf("input char>");
			do{
				input=getChar();
			}while(!('a'<=input && input<='z') || used[input-'a']);

			used[input-'a']=true;
			display_data(word,used,input,&remain);

			if(word->is_correct) break;
		}

		if(word->is_correct){
			printf("correct!\n");
		}else{
			printf("wrong...\n");
			word->is_wrong=true;
		}
		word->is_answered=true;

		printf("\ncontinue?[y/n]>");
		if(getChar()=='n') game_continue=false;

		memset(used,0,sizeof(used));
	}
	display_result(words);
}

