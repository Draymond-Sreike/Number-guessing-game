#include <stdio.h>
#include <stdlib.h>

void menu();
void game();

int main()
{
	srand((unsigned int)time(NULL));//拿时间戳来生成随机数起点
	int chose;
	do 
	{
		menu();//展示游戏选择目录
		scanf("%d", &chose);//输入对游戏模式的选择，1表示开始游戏，0表退出游戏
		switch(chose)//根据选择进行相应功能处理
		{
		case 1:
			printf("开始游戏！\n");
			game();//猜数字游戏函数
			break;
		case 0:
			printf("退出游戏！\n");
			break;
		default:
			printf("选择有误，请重新输入！\n");
			break;
		}
	} while (chose);//只有当chose输入0时会退出循环，若是输入1，则会在开始游戏，并在游戏结束后再进行一次游戏选择

	return 0;
}

void menu()
{
	printf("*************************************\n");
	printf("***********1.Play  0.Exit************\n");
	printf("*************************************\n");
	printf("输入“1”开始游戏，输入“0”退出游戏\n");
	printf("您的选择是>:");
}

void game()
{
	int randomNum, guess;
	randomNum = ((rand()%100)+1);//使得这个随机数在0-100之间，并再每次游戏时产生一个赋给randomNum;
	//printf("%d\n", randomNum);
	printf("请猜一个数（0-100）>:");
	while (1)
	{	
		scanf("%d", &guess);
		if (guess > randomNum)
		{
			printf("您猜大了\n");
			printf("请再猜一个数>:");
		}
		else if (guess < randomNum)
		{
			printf("您猜小了\n");
			printf("请再猜一个数>:");
		}
		else
		{
			printf("您猜对了，这个数就是：randomNum = %d\n", randomNum);
			break;
		}
	}
}
