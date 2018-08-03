package remindPractice;
import java.util.Scanner;

public class RemindPractice_박성준 {

	static Scanner input;
	
	public static void main(String[] args) {
	
		input =  new Scanner(System.in);
		
		practice1();
				
		practice3();
		
		practice4();
		
		practice5();

		practice6();
		
		practice7();

		practice8();		

		input.close();	
		
	}

	//사용자로부터 양의 정수를 입력 받아 그 수 만큼
	//Have a nice day를 출력하는 프로그램
	public static void practice1()
	{
		System.out.printf(" Have a niceday를 출력하고 싶은 횟수를 입력하세요\n");
		
		int numberYouWant =  input.nextInt();
		
		for( int i = 0 ; i< numberYouWant ; i++)
		{	
			System.out.printf("%d번째 :  Have a niceday\n",i+1);
			
		}
		
	}
	
	
	
	//사용자로부터 1~9까지의 숫자를 입력받아 구구단을 출력하는 프로그램
	// 
	// 9 X 1 = 9 
	// 9 X 2 = 18
	// ...
	public static void practice3()
	{
		
		System.out.printf("출력하고 싶은 구구단의 단를 입력하세요\n");
		
		int numberYouWant =  input.nextInt();		
		
		for(int i = 1 ; i <= 9 ; i++)
		{
			System.out.printf(" %d X %d = %d\n",numberYouWant , i,  numberYouWant*i);
			
		}
		
	}
	

	// 중첩 반복문을 사용하여 다음을 출력할 것 
	// [0,0] [0,1] [0,2] [0,3] [0,4] 
	// [1,0] [1,1] [1,2] [1,3] [1,4] 
	// [2,0] [2,1] [2,2] [2,3] [2,4] 	
	// [3,0] [3,1] [3,2] [3,3] [3,4] 
	// [4,0] [4,1] [4,2] [4,3] [4,4] 
	public static void practice4()
	{
	
		for(int i = 0 ; i < 5 ; i++)
		{
			for(int j = 0 ; j < 5 ; j++)
			{
				System.out.printf("[%d,%d] ", i, j);		
			}
			System.out.println();
		}
		System.out.println();
		
	}
	
	// 중첩 반복문을 사용하여 다음을 출력할 것 
	// [0@0] [0,1] [0,2] [0,3] [0,4] 
	// [1,0] [1@1] [1,2] [1,3] [1,4] 
	// [2,0] [2,1] [2@2] [2,3] [2,4] 	
	// [3,0] [3,1] [3,2] [3@3] [3,4] 
	// [4,0] [4,1] [4,2] [4,3] [4@4] 
	public static void practice5()
	{

		for(int i = 0 ; i < 5 ; i++)
		{
			for(int j = 0 ; j < 5 ; j++)
			{
				if( i == j)
					System.out.printf("[%d@%d] ", i, j);							
				else
					System.out.printf("[%d,%d] ", i, j);		
			}
			System.out.println();
		}		
		System.out.println();		
	}	
	
	// 중첩 반복문을 사용하여 다음을 출력할 것 
	// [0,0] [0,1] [0,2] [0,3] [0@4] 
	// [1,0] [1,1] [1,2] [1@3] [1,4] 
	// [2,0] [2,1] [2@2] [2,3] [2,4] 	
	// [3,0] [3@1] [3,2] [3,3] [3,4] 
	// [4@0] [4,1] [4,2] [4,3] [4,4] 
	public static void practice6()
	{

		for(int i = 0 ; i < 5 ; i++)
		{
			for(int j = 0 ; j < 5 ; j++)
			{
				if( i + j == 4)
					System.out.printf("[%d@%d] ", i, j);							
				else
					System.out.printf("[%d,%d] ", i, j);		
			}
			System.out.println();
		}				
		
	}	
	
	
	// 사용자로부터 학생의 점수를 입력 받아 Grade가 출력되는 프로그램
	// 점수 기준
	//	100 - 90  A
	//	89  - 80  B
	//	79  - 70  C
	//	69  - 60  D
	//	59  - 0   F
	//  이외의 값 입력오류 출력
	//  if, else if, else 사용
	public static void practice7()
	{
		System.out.printf("학생의 점수를 입력하세요 \n");
		
		int numberYouWant =  input.nextInt();
		
		if( numberYouWant >= 90 && numberYouWant <=100)
		{
			System.out.printf("학생의 점수는 A 입니다 \n");
			
		}
		else if( numberYouWant >= 80 && numberYouWant <=89)
		{
			System.out.printf("학생의 점수는 B 입니다 \n");
			
		}
		else if( numberYouWant >= 70 && numberYouWant <=79)
		{
			System.out.printf("학생의 점수는 C 입니다 \n");
			
		}
		else if( numberYouWant >= 60 && numberYouWant <=69)
		{
			System.out.printf("학생의 점수는 D 입니다 \n");
			
		}		
		else if( numberYouWant >= 0 && numberYouWant <=59)
		{
			System.out.printf("학생의 점수는 F 입니다 \n");
			
		}
		else
		{
			System.out.printf("입력 오류 입니다 \n");
			
		}	

    //사용자로부터 양의 정수를 입력 받는다.
	//5로 나눈 나머지를 출력하고, 
	//5의 배수이면 “hello”를 출력
	//5n +1 이면(5로 나누어 나머지가 1이면) “world”
	//5n +2 이면(5로 나누어 나머지가 2이면)  “everbody”
	//나머지는  “good luck”을 출력하기
	//[switch 문을 이용]
	public static void practice8()
	{

		System.out.printf("양의 정수 하나를 입력하세요 \n");
		
		int numberYouWant =  input.nextInt();	
		
		int modResult = numberYouWant % 5;
		
		System.out.printf("5로 나눈 나머지는 %d \n",modResult);		
		
		switch(modResult)
		{
		case 0: 
			System.out.printf("hello\n");
			break;
		
		case 1: 
			System.out.printf("world\n");			
			break;
		
		case 2: 
			System.out.printf("everybody\n");						
			break;
			
		default:
			System.out.printf("good luck\n");						
			break;						
		}	
	}	

  	public static void practice9()
	{
		int count = 0;
		System.out.printf("홀수 또는 5의 배수이며 7로는 나누어 떨어지지 않는 수\n");		
		
		for( int i= 1; i <= 100 ; i++)
		{
			if( (( i % 2 !=0 ) || ( i % 5 ==0 )) && !( i % 7 ==0) )
			{
				System.out.printf(" %d\n", i);
				count++;
			}
				
		}
		
		System.out.printf("총 %d 개 입니다\n\n",count);		
		
	}	
	
	//사용자로부터 두 점의 좌표를 입력 받아 두 점이 이루는 직사각형의 넓이를
	//계산하는 프로그램
	//(좌표는 정수로 존재)
	// 입력예제
	// 첫번째 위치의 X좌표를 입력하세요
	// 5
	// 첫번째 위치의  Y좌표를 입력하세요
	// 7
	// 두번째 위치의 X좌표를 입력하세요
	// 16
	// 두번째 위치의 Y좌표를 입력하세요
	// 7
	// 넓이는=>
	public static void practice10()
	{
		System.out.printf("첫번째 위치의 X좌표를 입력하세요 \n");
		
		int pos1X =  input.nextInt();

		System.out.printf("첫번째 위치의  Y좌표를 입력하세요 \n");
		
		int pos1Y =  input.nextInt();

		System.out.printf("두번째 위치의 X좌표를 입력하세요 \n");
		
		int pos2X =  input.nextInt();

		System.out.printf("두번째 위치의 Y좌표를 입력하세요\n");
		
		int pos2Y =  input.nextInt();	
		
		
		System.out.printf("좌표는 [%d,%d]  [%d,%d]", pos1X, pos1Y, pos2X, pos2Y);

		int width = pos2X - pos1X;

		int height = pos2Y - pos1Y;

		if (width < 0)
			width *= -1;

		if (height < 0)
			height *= -1;

		System.out.printf(" width = %d, height = %d \n", width, height);

		if ((width == 0) || (height == 0))
		{
			System.out.printf("[ERROR]  width or height == 0 \n");
		}

		int area = (width) * (height);		
		
		
		System.out.printf("넓이는 %d\n", area);
		
	}		
	
	//사용자로부터 양의 두 정수를 입력받아 두 수의 공약수를 출력
	public static void practice11()
	{
		System.out.printf("공약수를 구하기 위한 양의 정수 하나를 입력하세요 \n");
		
		int numberYouWant1 =  input.nextInt();			
		
		System.out.printf("공약수를 구하기 위한 양의 정수 다른 하나를 입력하세요 \n");
		
		int numberYouWant2 =  input.nextInt();			
		
		int smaller;
		
		if(numberYouWant1 < numberYouWant2)
			smaller = numberYouWant1; 
		else
			smaller = numberYouWant2;
		
		for( int i = 1 ; i <= smaller ; i++)
		{
			if( (numberYouWant1 % i ==0) && (numberYouWant2 % i ==0))
			{
				System.out.printf("%d는 공약수 입니다 \n" , i);
				
			}
		}
		
	}			
	
	//사용자로부터 두 수를 입력받아 두 수의 최대공약수를 출력
	public static void practice12()
	{

		System.out.printf("최대공약수를 구하기 위한 양의 정수 하나를 입력하세요 \n");
		
		int numberYouWant1 =  input.nextInt();			
		
		System.out.printf("최대공약수를 구하기 위한 양의 정수 다른 하나를 입력하세요 \n");
		
		int numberYouWant2 =  input.nextInt();			
		
		int smaller;
		
		if(numberYouWant1 < numberYouWant2)
			smaller = numberYouWant1; 
		else
			smaller = numberYouWant2;
		
		int GCD = 1;
		
		for( int i = 1 ; i <= smaller ; i++)
		{
			if( (numberYouWant1 % i ==0) && (numberYouWant2 % i ==0))
			{
				
				System.out.printf("%d는 공약수 입니다 \n" , i);
				
				if( i > GCD )
					GCD = i;
			}
			
		}		

		System.out.printf("최대 공약수는 %d입니다 \n" ,GCD);
		
	}	
	
	//사용자로부터 초를 입력받아
	//이를 시간 분 초로 출력하기
	//예
	// 초를 입력하세요 
	// 9500
	// [2] 시간 [38]분  20[초]
	public static void practice13()
	{
		System.out.printf("초[sec]를 입력하세요  \n");
		
		int numberYouWant =  input.nextInt();			
		
		int hour = numberYouWant / 3600;
		
		int numberForMin = numberYouWant % 3600;
		
		int minute =  numberForMin / 60;
		
		int sec = numberYouWant % 60;
		
		System.out.printf("[%d]시간 [%d]분  [%d]초 입니다 \n", hour, minute, sec);
		
		
	}	
	
	//사용자로부터 몇 개의 정수를 입력받을지 입력받음
	//배열을 선언하여 사용자가 입력한 수를 모두 기억해야 함.
	//
	//입력한 수의 합과 평균을 출력
	
	public static void practice14()
	{
		System.out.printf("입력할 정수의 갯수를 알려주세요  \n");
		
		int numberYouWant =  input.nextInt();
		
		int[] numbers =  new int[numberYouWant];
		
		int i;
		for(i = 0 ; i<numberYouWant ;i++ )
		{
			System.out.printf("%d 번째 정수를 입력하주세요  \n", i+1);			
			numbers[i] =  input.nextInt();
		}
		
		int sum = 0;
		double avg = 0.0;
		
		for(i = 0 ; i<numberYouWant ;i++ )
		{
			sum += numbers[i];
		}
		
		if(numberYouWant != 0)
			avg = (double)sum / (double)numberYouWant;
		
		System.out.printf("합은 = %d 평균은 =%f 입니다  \n", sum, avg);			
		
	}	
	
	//사용자로부터 몇 개의 정수를 입력받을지 입력받음
	//배열을 선언하여 사용자가 입력한 수를 모두 기억해야 함.
	//
	//입력한 수의 합과 평균을 출력하되
	// getSum,  getAvg 라는 method를 정의하여 사용할 것.
	// getSum 과 getAvg에 각각 배열을 parameter를 전달할 것.
	public static void practice15()
	{
		
		System.out.printf("입력할 정수의 갯수를 알려주세요  \n");
		
		int numberYouWant =  input.nextInt();
		
		int[] numbers =  new int[numberYouWant];
		
		int i;
		for(i = 0 ; i<numberYouWant ;i++ )
		{
			System.out.printf("%d 번째 정수를 입력하주세요  \n", i+1);			
			numbers[i] =  input.nextInt();
		}		
		
		System.out.printf("합은 = %d 평균은 =%f 입니다  \n", getSum(numbers), getAvg(numbers));			
		
	}		
	
	
	
	public static int getSum(int[] numbers)
	{
		int sum = 0;
		
		for(int i = 0 ; i<numbers.length ;i++ )
		{
			sum += numbers[i];
		}
		
		return sum;
	}
	
	
	
	public static double getAvg(int[] numbers)
	{
		int sum = 0;	
		
		double avg = 0;
		
		if(numbers.length == 0)
		{
			System.out.printf("[ERROR] numbers length == 0");
			return -1;
		}
		
		for(int i = 0 ; i<numbers.length ;i++ )
		{
			sum += numbers[i];
		}
		avg = (double)sum / (double)numbers.length;
		
		return avg;
	  }
	  
	}