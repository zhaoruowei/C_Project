#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
//双函数版
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
//创建接收用户输入数组函数
//int* cre_arr(int size) 
//{
//	int* p = (int*)malloc(sizeof(int) * size);
//	if (!p) return NULL;
//
//	for (int i = 1; i <= size; i++)
//	{
//		printf("请输入第%d个数字:", i);
//		scanf("%d", &p[i - 1]);
//	}
//
//	return p;
//}
//
//int main() 
//{
//	int size;
//	printf("请输入数组大小：");
//	scanf("%d", &size);
//
//	int* p = cre_arr(size);
//	if (!p) puts("程序异常");
//
//	printf("您输入的数组为：");
//	for (int i = 0; i < size; i++)
//	{
//		printf("%d ", p[i]);
//	}
//	puts("");
//
//	//排序
//	bubblesort04(p, size);
//
//	printf("排序后的数组为：");
//	for (int i = 0; i < size; i++)
//	{
//		printf("%d ", p[i]);
//	}
//	puts("");
//
//	//释放空间
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
	printf("请输入数组大小：");
	scanf("%d", &size);

	int* p = (int*)malloc(sizeof(int) * size);
	if (!p)
	{
		puts("程序异常");
		return -1;
	}

	for (int i = 1; i <= size; i++)
	{
		printf("请输入第%d个数字:", i);
		scanf("%d", &p[i - 1]);
	}
	printf("您输入的数组为：");

	for (int i = 0; i < size; i++)
	{
		printf("%d ", p[i]);
	}
	puts("");

	//排序
	bubblesort04(p, size);

	printf("排序后的数组为：");
	for (int i = 0; i < size; i++)
	{
		printf("%d ", p[i]);
	}
	puts("");

	free(p);
	p = NULL;

	return 0;
}