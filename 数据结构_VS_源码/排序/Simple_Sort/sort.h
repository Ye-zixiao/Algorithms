#pragma once
#ifndef SORT_H_
#define SORT_H_

typedef struct sqlist {										//����ʹ�ýṹ��һ����ͨ��˳���
	int* parr;
	int length;
}SqList, * pSqList;

void Create_SqList(pSqList psl);							//Ϊ�ṹ�е�������������
void swap(int* arr, int i, int j);							//������������Ԫ�ص�����
void show_data(pSqList psl);

void Swap_Sort(pSqList psl);								//��ͨ��������
void Bubble_Sort(pSqList psl);								//ð������
void Bubble_Sort_Improved(pSqList psl);						//�Ż����ð�������㷨:������Ѿ��ź���������ظ��Ƚ�����
int Find_Min(int* arr, int low, int high);					//������������low������high֮�����Сֵ�±�
void Selection_Sort(pSqList psl);							//��ѡ������
void Insertion_Sort(pSqList psl);							//ֱ�Ӳ�������Ҳ���Ż����룩

void Quick_Sort(pSqList psl);								//��װ�õĿ�������
void Qsort(int* arr, int low, int high);					//�����Կ������������õĺ��������ڵݹ�ʹ��
int Partition(int* arr, int low, int high);					//���������±꣬ͬʱҲ�������������
int Mid_of_Three(int* arr, int low, int high);				//����ȡ�к���

void Shell_Sort(pSqList psl);								//ϣ������
void Heap_Sort(pSqList psl);								//������
void Max_Heap_Adjust(int* arr, int i,int length);			//���ѵ���

void Merge_Sort(pSqList psl);									//�鲢���򣨵ݹ飩
void Msort(int* arr, int *temp_arr, int low, int high);			//ר�����ڵݹ�ʹ�õĹ鲢������
void Merge(int* temp_arr, int* arr, int low, int mid, int high);//���������й鲢���鲢���ԭ�������ʱ���鶼����

void Merge_Sort_nonrecursion(pSqList psl);										//�鲢���򣨷ǵݹ飩
void k_length_Seqmerge(int* source_arr,int *target_arr,int k, int length);		//�Գ���Ϊk�������������鲢��Ŀ�����鵱��
void Merge2(int* source_arr, int* target_arr, int low, int mid, int high);		//��low��mid��mid+1��high�����������й鲢���ŵ�Ŀ�����鵱�У�ԭ���鲻��Ķ��������ݹ�ʱ�ĺ�����ͬ��

#endif