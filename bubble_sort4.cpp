#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
//˫������
//void bubblesort04(int* arr, int n)
//{
	//for (int i = 0; i < n-1; i++)
	//{
	//	for (int j = 0; j < n-i-1; j++)
	//	{
	//		if (arr[j] < arr[j+1])
	//		{
	//			int temp = arr[j];
	//			arr[j] = arr[j + 1];
	//			arr[j + 1] = temp;
	//		}
	//	}
	//}
//}
//���������û��������麯��
//int* cre_arr(int size) 
//{
//	int* p = (int*)malloc(sizeof(int) * size);
//	if (!p) return NULL;
//
//	for (int i = 1; i <= size; i++)
//	{
//		printf("�������%d������:", i);
//		scanf("%d", &p[i - 1]);
//	}
//
//	return p;
//}
//
//int main() 
//{
//	int size;
//	printf("�����������С��");
//	scanf("%d", &size);
//
//	int* p = cre_arr(size);
//	if (!p) puts("�����쳣");
//
//	printf("�����������Ϊ��");
//	for (int i = 0; i < size; i++)
//	{
//		printf("%d ", p[i]);
//	}
//	puts("");
//
//	//����
//	bubblesort04(p, size);
//
//	printf("����������Ϊ��");
//	for (int i = 0; i < size; i++)
//	{
//		printf("%d ", p[i]);
//	}
//	puts("");
//
//	//�ͷſռ�
//	free(p);
//	p = NULL;
//
//	return 0;
//}

void bubblesort04(int* arr, int n)
{

	for (int i = 0; i < n - 1; i++)
	{
		for (int j = 0; j < n - i - 1; j++)
		{
			if (arr[j] < arr[j + 1])
			{
				int temp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = temp;
			}
		}
	}
}

int mainssss()
{
	int size;
	printf("�����������С��");
	scanf("%d", &size);

	int* p = (int*)malloc(sizeof(int) * size);
	if (!p)
	{
		puts("�����쳣");
		return -1;
	}

	for (int i = 1; i <= size; i++)
	{
		printf("�������%d������:", i);
		scanf("%d", &p[i - 1]);
	}
	printf("�����������Ϊ��");

	for (int i = 0; i < size; i++)
	{
		printf("%d ", p[i]);
	}
	puts("");

	//����
	bubblesort04(p, size);

	printf("����������Ϊ��");
	for (int i = 0; i < size; i++)
	{
		printf("%d ", p[i]);
	}
	puts("");

	free(p);
	p = NULL;

	return 0;
}