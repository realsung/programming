#include <stdio.h>
 
void BubbleSort(int a[],int size);

int main()
{
    int arr[5] = { 15, 11, 1, 3, 8 };
    int i;
    BubbleSort(arr, 5);
    for (i = 0; i < 5; i++){
        printf("%d ", arr[i]);
    }
 
    return 0;
}
 
void BubbleSort(int a[],int size)
{
    int temp;
    int i, j;
    for (i = 0; i < size; i++){
        for (j = 0; j < size - 1 - i; j++){
            if (a[j]>a[j + 1]){ //부호만 반대로 바꾸면 역순
                temp = a[j];
                a[j] = a[j+ 1];
                a[j + 1] = temp;
            }
        }
    }
}