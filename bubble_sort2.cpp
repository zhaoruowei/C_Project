#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#define SIZE 10
//bubble_sort2
int bubble_sort2(void)
{
	//产生随机数
	srand((unsigned int)time(NULL));
	//定义数组
	int arr[SIZE];
	//给数组赋值
	for (int i = 0; i < SIZE; i++)
	{
		arr[i] = rand() % 100;
	}
	
	//打印排序前数组
	for (int i=0; i < SIZE; i++)
	{
		printf("%d\t",arr[i]);
	}
	printf("\n");

	//外层循环控制行
	//外层执行元素个数-1次
	for (int n = 0; n < SIZE-1; n++)
	{
		//内层循环控制列
		//内层执行元素个数-1-执行次数次
		for (int m = 0; m < SIZE-n-1; m++)
		{
			//此时为升序，控制判断条件调整升降序
			if (arr[m]>arr[m+1])
			{
				int tmp = arr[m];
				arr[m] = arr[m + 1];
				arr[m + 1] = tmp;
			}
		}
	}

	//打印排序后数组
	for (int i = 0; i < SIZE; i++)
	{
		printf("%d\t", arr[i]);
	}

	return 0;
}