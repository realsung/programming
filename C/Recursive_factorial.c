
#include <stdio.h>

int f(int count)
{
    if(count==1)
        return 1;
    else
        return count * f(count-1);
}

int main()
{
    int input;
    printf("팩토리얼 : ");
    scanf("%d",&input);
    printf("%d! = %d",input,f(input));
}