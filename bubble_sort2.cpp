#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#define SIZE 10
//bubble_sort2
int bubble_sort2(void)
{
	//���������
	srand((unsigned int)time(NULL));
	//��������
	int arr[SIZE];
	//�����鸳ֵ
	for (int i = 0; i < SIZE; i++)
	{
		arr[i] = rand() % 100;
	}
	
	//��ӡ����ǰ����
	for (int i=0; i < SIZE; i++)
	{
		printf("%d\t",arr[i]);
	}
	printf("\n");

	//���ѭ��������
	//���ִ��Ԫ�ظ���-1��
	for (int n = 0; n < SIZE-1; n++)
	{
		//�ڲ�ѭ��������
		//�ڲ�ִ��Ԫ�ظ���-1-ִ�д�����
		for (int m = 0; m < SIZE-n-1; m++)
		{
			//��ʱΪ���򣬿����ж���������������
			if (arr[m]>arr[m+1])
			{
				int tmp = arr[m];
				arr[m] = arr[m + 1];
				arr[m + 1] = tmp;
			}
		}
	}

	//��ӡ���������
	for (int i = 0; i < SIZE; i++)
	{
		printf("%d\t", arr[i]);
	}

	return 0;
}