#include "hangman.h" 

bool hint(Words *word,bool *used,char input){
	int i;
	bool hit=false;
	int counter=0;
	char output;

	printf("hint:");
	for(i=0;i<word->len;i++){
		output='-';
		if(used[word->str[i]-'a']){
			output=word->str[i];
			if(word->str[i]==input) hit=true;
			counter++;
		}
		printf("%c",output);
	}
	printf("\n");

	if(counter==word->len) word->is_correct=true;
	return hit;
}

void display_used(bool *used){
	char c;

	printf("================================\nused:");
	for(c='a';c<='z';c++){
		if(used[c-'a']){
			printf("\033[41m");
			printf("%c",c);
			printf("\033[49m");
		}else{
			printf("%c",c);
		}
	}
	printf("\n================================\n");
}

void display_remain(int remain){
	int i;

	printf("\033[42m");
	for(i=0;i<remain;i++){
		printf("  ");
	}
	printf("\033[49m");
	printf("\n");
}

int display_data(Words *word,bool *used,char input,int *remain){
	int hit;

	printf("\033c");
	//printf("\033[1;1H");
	//printf("\033[2J");
	
	//printf("word:%s\n",word->str);
	hit=hint(word,used,input);
	display_used(used);

	if(hit==0 && input!=0) (*remain)--;
	printf("remain[%d]:",*remain);
	display_remain(*remain);

	return hit;
}

void display_result(Words *words){
	int i;
	int correct=0;
	int wrong=0;

	// display wrong word
	printf("\n------wrong words------\n");
	for(i=0;i<Wordsize;i++){
		if(words[i].is_wrong){
			printf("%s\n",words[i].str);
			wrong++;
		}

		if(words[i].is_correct)
			correct++;
	}
	printf("-----------------------\n");
	printf("wrong:%2d\n",wrong);
	printf("correct:%2d\n",correct);
	printf("correct answer rate:%.2f%\n",(double)correct/(double)(wrong+correct)*100);

}
