#pragma once
//������Ϸ���ڴ�С
#define COLS 20
#define ROWS 60


//�����߽ṹ��
//������ṹ�壬x��y��ʾ����
typedef struct snake_body
{
	int X;
	int Y;
}s_b;
//����������ṹ��
typedef struct snake_size
{
	int size;
	s_b body[ROWS*COLS];
}s_s;
//����ʳ��ṹ��
struct food
{
	//����
	int X;
	int Y;
	//����
	int fscore;
};
//�����û�����
char opt = 'd';
//����÷�
int score = 0;
//������λ��ƫ����
int dX = 0;
int dY = 0;
//������ĩβ����
int lX = 0;
int lY = 0;

//������
s_s snake;
//����ʳ��
food f;

//��ʼ����
void InitSnake(void);
//��ʼ��ʳ��
void InitFood(void);
//��ʼ��ǽ
void InitWall(void);
//ˢ�½���
void ShowUI(void);
//��ʼ��Ϸ
void PlayGame(void);
