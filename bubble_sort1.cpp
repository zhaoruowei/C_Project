#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<Windows.h>
#define SIZE 10
#define MAX(a,b) (a)>(b)?(a):(b)
#define MIN(a,b) (a)<(b)?(a):(b)

int bubble_sort1(void) 
{
	//����0-99�����
	srand((unsigned int)time(NULL));
	//����10����������
	int arr[SIZE];
	//ѭ����������
	for (int n = 0; n < SIZE; n++)
	{
		int i = rand() % 100;
		arr[n] = i;
		printf("%d\t",arr[n]);
	}
	printf("\n");
	//ð������
	int max;
	int min;
	
	for (int j = 1; j < SIZE; j++)
	{
		for (int m = 0; m < SIZE - j; m++)
		{
			max = MAX(arr[m], arr[m + 1]);
			min = MIN(arr[m], arr[m + 1]);
			arr[m] = min;
			arr[m + 1] = max;
		}
		if (j == SIZE-1)
		{
			for (int k = 0; k < SIZE; k++)
			{
				printf("%d\t", arr[k]);
			}
		}
	}

	return 0;
}

