#pragma once
//定义游戏窗口大小
#define COLS 20
#define ROWS 60


//定义蛇结构体
//蛇身体结构体，x，y表示坐标
typedef struct snake_body
{
	int X;
	int Y;
}s_b;
//蛇身体个数结构体
typedef struct snake_size
{
	int size;
	s_b body[ROWS*COLS];
}s_s;
//定义食物结构体
struct food
{
	//坐标
	int X;
	int Y;
	//分数
	int fscore;
};
//定义用户输入
char opt = 'd';
//定义得分
int score = 0;
//定义蛇位移偏移量
int dX = 0;
int dY = 0;
//定义蛇末尾坐标
int lX = 0;
int lY = 0;

//创建蛇
s_s snake;
//创建食物
food f;

//初始化蛇
void InitSnake(void);
//初始化食物
void InitFood(void);
//初始化墙
void InitWall(void);
//刷新界面
void ShowUI(void);
//开始游戏
void PlayGame(void);
