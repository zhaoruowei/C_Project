#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<Windows.h>
#include<conio.h>
#include"snake.h"
/*
1.�����ߵĽṹ��
2.��ʼ���ߺ�ʳ��
3.��ʼ��Ϸ
	�ߺ�ǽ
	�ߺ�ʳ��
		�������ʳ��
		����������
		��������
	���������
4.��Ϸ����
*/

//�������ṹ�����
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
	//���峬��ʳ��
	int pro = rand() % 1000; //����ʳ����ָ���1/1000
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
	//������Ӱ
	coord.X = lX;
	coord.Y = lY;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
	putchar(' ');
	//��λ������������
	for (size_t i = 1; i < snake.size; i++)
	{
		coord.X = snake.body[i].X;
		coord.Y = snake.body[i].Y;
		SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
		putchar('*');
	}

	//��λ��������ͷ
	coord.X = snake.body[0].X;
	coord.Y = snake.body[0].Y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
	putchar('@');

	//��λ������ʳ��
	coord.X = f.X;
	coord.Y = f.Y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
	putchar('#');

}

void PlayGame(void)
{
	//�ж����Ƿ�ײǽ
	while (snake.body[0].X< ROWS && snake.body[0].Y < COLS && snake.body[0].X > 0 && snake.body[0].Y > 0)
	{
		//���ռ�������
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
		//�ж����Ƿ���������
		for (size_t i = snake.size - 1; i > 0; i--)
		{
			if (snake.body[0].X == snake.body[i].X && snake.body[0].Y == snake.body[i].Y)
			{
				return;
			}
		}

		//�ж����Ƿ�Ե�ʳ��
		if (snake.body[0].X == f.X && snake.body[0].Y == f.Y)
		{
			
			InitFood();
			snake.size++;
			score += f.fscore;
		}
		//��¼�����һ��λ��
		lX = snake.body[snake.size - 1].X;
		lY = snake.body[snake.size - 1].Y;

		//������λ��
		for (size_t i = snake.size-1; i > 0; i--)
		{
			snake.body[i].X = snake.body[i - 1].X;
			snake.body[i].Y = snake.body[i - 1].Y;
		}
		//��ͷλ��
		snake.body[0].X += dX;
		snake.body[0].Y += dY;

		Sleep(300);
		ShowUI();
	}

}

int main(void)
{
	//�����������
	srand((size_t)time(NULL));
	//ȥ�����
	CONSOLE_CURSOR_INFO cci;
	cci.dwSize = sizeof(cci);
	cci.bVisible = FALSE;
	SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &cci);
	//��ʼ����
	InitSnake();
	//��ʼ��ʳ��
	InitFood();
	//��ʼ��ǽ��
	InitWall();
	PlayGame();

	
	system("cls");
	printf("���ĵ÷�Ϊ:%d\n", score);
	system("pause");
	return 0;
}


