#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>

#define SUCCESS 1
#define FAILED 0

typedef struct word{
    char eng[0x100];
    char kor[0x100];
    struct word *next;
}Word;

Word *init();
int getDic(Word *word);
void printList(Word *word);
void sortWord(Word *word);
int game(Word *word);

int main(){
    int score = 0;
    char input[0x20];
    Word *word = init();

    if(!getDic(word)){
        perror("ERROR");
    }
    sortWord(word);

    while(1){
        printf("1) 영어 단어 맞추기\n2) 프로그램 종료\n>> ");
        scanf("%s", input);
        if(!strcmp(input,"1")){
            // printList(word);
            score = game(word);
            printf("점수 : %d\n",score);
        }else if(!strcmp(input,"2")){
            sleep(0.5);
            system("clear");
            break;
        }else{
            puts("다시 선택");
        }
    }
}

Word *init(){
    Word *new = (Word *)malloc(sizeof(Word));
    new->next = NULL;
    return new;
}

int getDic(Word *word){
    FILE *fp;
    Word *p = word;
    char eng[0x100] = {0, };
    char kor[0x100] = {0, };

    if((fp = fopen("dic.txt","r")) == NULL){
        return FAILED;
    }
    if(fscanf(fp,"%s %[^\n]\n",eng,kor) != EOF){
        strcpy(word->eng,eng);
        strcpy(word->kor,kor);
        word->next = NULL;
    }
    while(fscanf(fp,"%s %[^\n]\n",eng,kor) != EOF){
        p->next = (Word *)malloc(sizeof(Word));
        p = p->next;
        strcpy(p->eng,eng);
        strcpy(p->kor,kor);
        p->next = NULL;
    }

    return SUCCESS;
}

void printList(Word *word){
    Word *p = word;
    while(p != NULL){
        printf("%s %s\n",p->eng,p->kor);
        p = p->next;
    }
}

void sortWord(Word *word){
    Word *tmp = (Word *)malloc(sizeof(Word));
    for(Word *i = word; i!=NULL; i=i->next){
        for(Word *j = i->next; j!=NULL; j=j->next){
            if(strcmp(i->eng, j->eng)>0){
                strcpy(tmp->eng, j->eng);
                strcpy(tmp->kor, j->kor);
                strcpy(j->eng, i->eng);
                strcpy(j->kor, i->kor);
                strcpy(i->eng, tmp->eng);
                strcpy(i->kor, tmp->kor);
            }
        }
    }
}

int game(Word *word){
    int score = 0, stage = 1;
    char input[0x100];
    Word *p = word;
    while(p != NULL){
        printf("[Stage %d] %s : ",stage++, p->kor);
        scanf("%s",input);
        if(!strcmp(input, p->eng)){
            score++;
            puts("correct!");
        }else if(!strcmp(input, ".quit")){
            return score;
        }else{
            puts("incorrect!");
        }
        p = p->next;
    }
    return score;
}