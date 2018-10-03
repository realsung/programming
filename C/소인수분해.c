#include <stdio.h>

int main( )
{
    int i, j;
    int input, origin;
    int arr[100];

    printf( "0 이하를 입력하면 종료\n\n" );

    while( 1 )
    {
        printf( "수를 입력하세요 : " );
        scanf( "%d", &input );
        if( input <= 0 )    return 0;

        origin = input;

        i = 2;
        j = 0;

        //수인수분해 부분
        while( input>1 )
        {
            if( input%i == 0 )
            {
                input = input/i;
                arr[j] = i;
                ++j;
            }           
            if( input%i != 0 )  i++;            
        }

        //출력
        if( origin != 1 )
        {
            printf( "소인수분해 결과 : " );

            for( i=0 ; i<j ; i++ )
            {
                printf( "%d", arr[i] );         
                if( i<j-1 )     printf( " x " );
                if( j-1 == i )  printf( " = %d", origin );
            }
        }
        if( origin==1 ) printf( "2이상을 입력" );

        printf( "\n\n" );
    }

    return 0;
}