//������������
#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include"sort.h"

/*=========================�򵥽�������==============================*/
void Swap_Sort(pSqList psl)
{
	int i, j;
	for (i = 0; i < psl->length - 1; i++)					//��ķ���
		for (j = i + 1; j < psl->length; j++)
			if (psl->parr[i] > psl->parr[j])
				swap(psl->parr, i, j);
}


/*========================ð������=======================================*/
void Bubble_Sort(pSqList psl)
{															/*ð�������㷨��
																���µ��������ȽϽ����ߵĽ�Сֵ���ηŵ����棬ÿһ��jѭ���ɽ���Сֵ�ҳ��ŵ����αȽϷ�Χ��������*/
	int i, j;
	for (i = 0; i < psl->length; i++)
		for (j = psl->length - 1; j > i; j--)
			if (psl->parr[j - 1] > psl->parr[j])			//ǰ�ߴ��ں��߾ͽ�������
				swap(psl->parr, j - 1, j);

}

void Bubble_Sort_Improved(pSqList psl)
{
	int i, j;
	bool flag = true;

	for (i = 0; flag && i < psl->length; i++)					//������һ�ֺ��־λ��Ȼ��false˵���Ѿ��������
	{
		flag = false;										//����һ����־λ�����һ��ѭ�������������н������ݵĹ���˵�������ڽ�������֮ǰ��û���ź���
		for (j = psl->length - 1; j > i; j--)
			if (psl->parr[j - 1] > psl->parr[j])
			{
				swap(psl->parr, j - 1, j);
				flag = true;
			}
	}
}


/*================================ѡ������====================================*/
void Selection_Sort(pSqList psl)
{															/*ѡ�������㷨˼·��
																������low��high֮���ҳ���Сֵ��������low�±걾���Ǹ���������ô�������Сֵ��
																low�±��Ԫ�ؽ������ݣ�Ȼ��low�Լ�1��С�Ƚ�����Χ*/
	int i, j;
	for (i = 0; i < psl->length; i++)
	{
		int min = Find_Min(psl->parr, i, psl->length - 1);
		if (i != min)
			swap(psl->parr, i, min);
	}
}

int Find_Min(int* arr, int low, int high)					//������low��high��Χ���ҳ���Сֵ�����������±�
{
	int i;
	int min = low;
	for (i = low + 1; i <= high; i++)
		if (arr[i] < arr[min])
			min = i;
	return min;
}


/*================================ֱ�Ӳ�������=====================================*/
void Insertion_Sort(pSqList psl)
{																		/*ֱ�Ӳ����������˼�룺
																			����һ������ӵڶ���Ԫ�ؿ�ʼ����һ��Ԫ����Ϊ�Ѿ����򣬶�ǰ����Ԫ������ȼ���
																		���ڶ���Ԫ�ز��뵽ǰһ��Ԫ�ص�ĳһ��λ�ã�ǰ��󣩣�ʹ֮�������򣻶�ǰ����Ԫ������ȼ���
																		��������Ԫ�ز��뵽ǰ2��Ԫ�ص�ĳһ��λ�ã�ʹ֮�������򣻡�������*/
	int i;
	int temp;

	for (i = 1; i < psl->length; i++)
	{
		if (psl->parr[i - 1] > psl->parr[i])							/*���жϾ��Ŀ�ľ��ǣ����⵱ǰn��Ԫ���Ѿ�����ʱ�������n+1��Ԫ�������Ԫ�ش���ǰһ��������ǰ�����е�����
																			ʱ�����������������Ĳ������磺1��2��3��Ҫ����4*/
		{
			temp = psl->parr[i];
			int pos;

			for (pos = i; pos >=1 && psl->parr[pos - 1] > temp; pos--)	//�����n����С��ǰ��������ͽ�ǰ�����������һ�������λ
				psl->parr[pos] = psl->parr[pos - 1];
			psl->parr[pos] = temp;										//Ȼ����������뵽ֱ��С������������
		}
	}
}
