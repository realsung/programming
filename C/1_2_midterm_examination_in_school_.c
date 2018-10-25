#include <stdio.h>

int f(int n){
    if(n==0 | n==1)
        return n;
    else
        return f(n-1) + f(n-2);
}
int main()
{
    int a;
    scanf("%d",&a);
    printf("%d",f(a));
}




/*
구조체 함수
#include <stdio.h>

struct people{
    char *name;
    int age;
};

void display_val(struct people p){
    printf("%s %d\n",p.name,p.age);
    p.name = "벨류";
    p.age = 100;
}
void display_ref(struct people *p){
    printf("%s %d\n",p->name,p->age);
    p->name = "레퍼런스";
    p->age = 18;
}
int main(){
    struct people person = {"홍길동",20};
    
    display_val(person);
    printf("%s %d\n", person.name,person.age);

    display_ref(&person);
    printf("%s %d\n", person.name,person.age);
}
*/



/*
구조체 함수
#include <stdio.h>

struct people{
    char *name;
    int age;
};

struct people make_member(char *name ,int age){
    struct people p;
    p.name = name;
    p.age = age;
    return(p);
};

int main(){
    struct people member;
    char *name = "박성준";
    int age = 17;
    member = make_member(name,age);
    printf("멤버 이름 : %s\n",member.name);
    printf("멤버 나이 : %d\n",member.age);
}
*/



/*구조체 배열
#include <stdio.h>

struct date{
    int year;
    int month;
    int day;
};

struct date d_day[3];

int main(){
    struct date d_day[3] = {{1986,1,5},{1976,2,13},{1988,11,3}};
    struct date *ptr;
    ptr = d_day;
    for(int i=0; i<3; i++){
        printf("%2d년 %2d월 %2d일\n",ptr->year,ptr->month,ptr->day);
        ++ptr;
    }

}
*/



/*
구조체 포인터
#include <stdio.h>

struct Date{
    int year;
    int month;
    int day;
};

int main(){
    struct Date today;
    struct Date *date_ptr;
    date_ptr = &today;
    printf("년 : "); scanf("%d", &date_ptr->year);
    printf("월 : "); scanf("%d", &date_ptr->month);
    printf("일 : "); scanf("%d", &date_ptr->day);

    printf("결과\n");
    printf("%d년 %d월 %d일\n", date_ptr->year,date_ptr->month,date_ptr->day);

}
*/



/*
구조체 배열
#include <stdio.h>

struct student{
    char name[20];
    int num;
    int age;
};
int main()
{
    struct student mem[3];
    for(int i=0; i<3; i++){
        printf("[%d]이름 : ",i); scanf("%s", mem[i].name);
        printf("[%d]학번 : ",i); scanf("%d", &mem[i].num);
        printf("[%d]나이 : ",i); scanf("%d", &mem[i].age);
    }

    for(int i=0; i<3; i++){
        printf("[%d]이름 : %s\n",i,mem[i].name);
        printf("[%d]학번 : %d\n",i,mem[i].num);
        printf("[%d]나이 : %d\n",i,mem[i].age); 
    }

}
*/