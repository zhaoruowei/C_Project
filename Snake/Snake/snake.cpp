#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<Windows.h>
#include<conio.h>
#include"snake.h"
/*
1.定义蛇的结构体
2.初始化蛇和食物
3.开始游戏
	蛇和墙
	蛇和食物
		重新随机食物
		蛇身体增长
		分数增长
	方向键控制
4.游戏结束
*/

//创建光标结构体对象
COORD coord;

void InitSnake(void)
{
	snake.size = 2;
	snake.body[0].X = ROWS / 2;
	snake.body[0].Y = COLS / 2;
	snake.body[1].X = ROWS / 2 - 1;
	snake.body[1].Y = COLS / 2;
}

void InitFood(void)
{
	f.X = rand() % (ROWS-1) +1;
	f.Y = rand() % (COLS-1) +1;
	//定义超级食物
	int pro = rand() % 1000; //超级食物出现概率1/1000
	if (pro == 999)
	{
		f.fscore = 50;
	}
	else
	{
		f.fscore = 10;
	}
}

void InitWall(void)
{
	for (size_t i = 0; i <= COLS; i++)
	{
		for (size_t j = 0; j <= ROWS; j++)
		{
			if (i == COLS || j == ROWS || i == 0 || j == 0)
			{
				printf("=");
			}
			else
			{
				printf(" ");
			}
		}
		printf("\n");
	}
}

void ShowUI(void)
{
	//消除拖影
	coord.X = lX;
	coord.Y = lY;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
	putchar(' ');
	//定位光标输出蛇身体
	for (size_t i = 1; i < snake.size; i++)
	{
		coord.X = snake.body[i].X;
		coord.Y = snake.body[i].Y;
		SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
		putchar('*');
	}

	//定位光标输出蛇头
	coord.X = snake.body[0].X;
	coord.Y = snake.body[0].Y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
	putchar('@');

	//定位光标输出食物
	coord.X = f.X;
	coord.Y = f.Y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
	putchar('#');

}

void PlayGame(void)
{
	//判断蛇是否撞墙
	while (snake.body[0].X< ROWS && snake.body[0].Y < COLS && snake.body[0].X > 0 && snake.body[0].Y > 0)
	{
		//接收键盘输入
		if (_kbhit())
		{
			opt = _getch();
		}

		switch (opt)
		{
		case'w': case'W':dX = 0; dY = -1; break;
		case'a': case'A':dX = -1; dY = 0; break;
		case's': case'S':dX = 0; dY = 1; break;
		case'd': case'D':dX = 1; dY = 0; break;
		}
		//判断蛇是否碰到身体
		for (size_t i = snake.size - 1; i > 0; i--)
		{
			if (snake.body[0].X == snake.body[i].X && snake.body[0].Y == snake.body[i].Y)
			{
				return;
			}
		}

		//判断蛇是否吃到食物
		if (snake.body[0].X == f.X && snake.body[0].Y == f.Y)
		{
			
			InitFood();
			snake.size++;
			score += f.fscore;
		}
		//记录蛇最后一节位置
		lX = snake.body[snake.size - 1].X;
		lY = snake.body[snake.size - 1].Y;

		//蛇身体位移
		for (size_t i = snake.size-1; i > 0; i--)
		{
			snake.body[i].X = snake.body[i - 1].X;
			snake.body[i].Y = snake.body[i - 1].Y;
		}
		//蛇头位移
		snake.body[0].X += dX;
		snake.body[0].Y += dY;

		Sleep(300);
		ShowUI();
	}

}

int main(void)
{
	//产生随机种子
	srand((size_t)time(NULL));
	//去除光标
	CONSOLE_CURSOR_INFO cci;
	cci.dwSize = sizeof(cci);
	cci.bVisible = FALSE;
	SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &cci);
	//初始化蛇
	InitSnake();
	//初始化食物
	InitFood();
	//初始化墙体
	InitWall();
	PlayGame();

	
	system("cls");
	printf("您的得分为:%d\n", score);
	system("pause");
	return 0;
}


