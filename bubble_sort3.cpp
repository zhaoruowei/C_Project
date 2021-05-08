#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

//字符串冒泡排序
void str_sort(char* str[], int size)
{
	for (int i = 0; i < size - 1; i++)
	{
		for (int j = 0; j < size - 1 - i; j++)
		{
			if (str[j][0] > str[j + 1][0])
			{
				char* temp = str[j];
				str[j] = str[j + 1];
				str[j + 1] = temp;
			}
		}
	}

}
int mainstrsort(void)
{

	char s1[] = "hello";
	char s2[] = "world";
	char s3[] = "python";
	char* str[3] = { s1, s2, s3 };
	printf("排序前：\n");
	for (int i = 0; i < 3; i++)
	{
		printf("%s\n", str[i]);
	}

	str_sort(str, 3);
	printf("排序后：\n");
	for (int i = 0; i < 3; i++)
	{
		printf("%s\n", str[i]);
	}

	return 0;
}

//数组冒泡排序
void BubbleSort(int* arr, int length)
{
	for (int i = 0; i < length-1; i++)
	{
		for (int j = 0; j < length-1-i; j++)
		{
			if (arr[j] > arr[j+1])
			{
				int temp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = temp;
			}
		}
	}
}


int mainbubble(void) 
{
	int size = 0;
	printf("请输入数组的大小：");
	scanf("%d", &size);
	
	srand((unsigned int)time(NULL));
	int arr[50];
	for (int i = 0; i < size; i++)
	{
		arr[i] = rand() % 101;
	}

	printf("排序前：\n");
	for (int i = 0; i < size; i++)
	{
		printf("%d \t",arr[i]);
	}
	puts("");

	BubbleSort(arr, size);
	printf("排序后：\n");
	for (int i = 0; i < size; i++)
	{
		printf("%d \t", arr[i]);
	}
	puts("");

	return 0;
}




