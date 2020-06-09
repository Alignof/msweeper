#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<time.h>
#include<string.h>
#include<termio.h>

typedef struct{
	int len;
	char *str;
	bool is_wrong;
	bool is_correct;
	bool is_answered;
}Words;

int Wordsize;
int count_strlen(char *buffer);
void readfile(Words **words,int argc,char **argv);
void playgame(Words *words);
char getChar(void);
bool hint(Words *word,bool *used,char input);
void display_used(bool *used);
void display_result(Words *word);
int display_data(Words *word,bool *used,char input,int *remain);
