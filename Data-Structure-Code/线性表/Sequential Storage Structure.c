/*----------˳��洢�ṹ-���Ա�------*/
#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<malloc.h>

typedef struct Arr {                                            //��typedef����һ���ṹ����
	int* pArray;
	int len;
	int cnt;
}SqList;

void init_arr(SqList* pArr,int size);                           //˳��洢��ʼ����Ϊ������䶯̬�ڴ�
bool append_arr(SqList* pArr,int value);                        //׷��ģʽ��������ĺ������һ������
bool insert_arr(SqList* pArr, int i,int value);                 //����ģʽ
bool delete_arr(SqList* pArr, int i, int* Back_value);          //ɾ��������������Back_value
bool Getelem(SqList* pArr, int i,int *Back_value);              //���Ҳ���
bool is_empty(SqList* pArr);                                    //�ж������Ƿ�����
bool is_full(SqList* pArr);                                     //�ж������Ƿ�Ϊ��
void show_arr(SqList* pArr);                                    //��ʾ�������
void sort_arr(SqList* pArr);                                    //�������е�Ԫ�ؽ�������
void inverse_arr(SqList* pArr);                                 //�������е�Ԫ�ؽ��е���
void free_arr(SqList* pArr);                                    //�Ƿ���ǰ��Ϊ�������Ķ�̬�ڴ�

int main(void)
{
	SqList arr;
	int value;

	init_arr(&arr,6);                                           //��ʼ��
	show_arr(&arr);

	append_arr(&arr, 1);                                        //����ĩβ׷���ĸ�����
	append_arr(&arr, 2);
	append_arr(&arr, 3);
	append_arr(&arr, 4);
	show_arr(&arr);

	insert_arr(&arr, 3, 88);                                    //�ڵ�����λ�ò���һ��Ԫ��
	show_arr(&arr);
	if (Getelem(&arr, 4, &value))                               //���ҵ��ĸ�Ԫ�أ������ؽ��������
		printf("I get a element %d\n", value);
	else
		printf("No data gets.\n");
	inverse_arr(&arr);                                          //�����ݵ���
	show_arr(&arr);

	sort_arr(&arr);                                             //�����ݽ�������
	show_arr(&arr);
	if (delete_arr(&arr, 3, &value))                            //ɾ��������Ԫ��
		printf("I deletes a element %d.\n", value);
	else
		printf("No data deletes.\n");
	show_arr(&arr);

	free_arr(&arr);                                                 //�ͷ��ڴ�
	return 0;
}

void init_arr(SqList* pArr,int size)
{
	pArr->pArray = (int *)malloc(size*sizeof(int));
	if (!pArr->pArray)
	{
		printf("Can't assign dynamic memory for this program.\n");
		exit(EXIT_FAILURE);
	}
	else                                                        //�ڴ����ɹ��Ϳ��Գ�ʼ�������Ľṹ��Ա
    {
        pArr->cnt=0;
        pArr->len=size;
    }
}

void show_arr(SqList* pArr)
{
	if (is_empty(pArr))                                         //��������Ƿ�Ϊ��
		printf("There is no data in the array.\n");
	else
	{
		int i;
		for (i = 0; i < pArr->cnt; i++)
			printf("%d ", pArr->pArray[i]);
		putchar('\n');
	}
	return;
}

void free_arr(SqList* pArr)
{
    free(pArr->pArray);
	printf("Free the memory.\n");
}

bool is_full(SqList* pArr)
{
	if (pArr->cnt == pArr->len)
	    return true;
	else
        return false;
}

bool is_empty(SqList* pArr)
{
	if (pArr->cnt == 0)
		return true;
	else
		return false;
}

bool append_arr(SqList* pArr, int value)
{
	if (is_full(pArr)==true)                                    //��׷��ǰ��������Ƿ�����
        return false;
	else
	{
		pArr->pArray[pArr->cnt] = value;                        //ע�⣺׷���Ǹ����һ��Ԫ�ص���һ�����е�Ԫ��ֵ
		(pArr->cnt)++;                                          //������cnt
		return true;
	}
}

bool Getelem(SqList* pArr, int i,int *Back_value)
{
	if (i<1 || i>pArr->cnt)                                     //����������
	{
		printf("Error in getting data.\n");
		return false;
	}
	else
	{
		*Back_value = pArr->pArray[i - 1];                      //��ָ���������������ز��ҵ�����
		return true;
	}

}

bool insert_arr(SqList* pArr, int i, int value)
{
	if (i<1 || i>pArr->cnt+1)                                   //�ڲ���֮ǰ��Ҫ������Ƿ��ڴ������
	{
		printf("Error in inserting.\n");
		return false;
	}
	if (is_full(pArr))
	{
		printf("There is no room for storing data.\n");
		return false;
	}
	int j;
	for (j = pArr->cnt-1; j >=i-1; j--)                         //ע�⣺�����Ǵ�ʵ�ʵ������±�cnt-1��ʼ�ģ������һ��Ԫ��
		pArr->pArray[j+1] = pArr->pArray[j];
	pArr->pArray[i-1] = value;
	pArr->cnt++;
	return true;
}

bool delete_arr(SqList* pArr, int i, int* Back_value)
{
	if (i<1 || i>pArr->cnt)
	{
		printf("Error in deleting data.\n");
		return false;
	}
	if (is_empty(pArr))
	{
		printf("There is no data in the array.\n");
		return false;
	}
	int j;
	*Back_value = pArr->pArray[i - 1];                          //������ǰ�Ƚ����ݸ������ص�ָ�������ָ�ı���
	for (j = i ; j < pArr->cnt; j++)                            //ע�⣺j�ʼ�ļ���ֵ����i
		pArr->pArray[j] = pArr->pArray[j+1];
	pArr->cnt--;
	return true;
}

void sort_arr(SqList* pArr)									    //����ð�ݷ�������������
{
	int top, seek;
	for(top=0;top<pArr->cnt-1;top++)
		for(seek=top+1;seek<pArr->cnt;seek++)
			if (pArr->pArray[top] > pArr->pArray[seek])
			{
				int temp = pArr->pArray[top];
				pArr->pArray[top] = pArr->pArray[seek];
				pArr->pArray[seek] = temp;
			}
}

void inverse_arr(SqList* pArr)
{
	int i;
	for (i = 0; i < pArr->cnt / 2; i++)                         //���ó���ȷ������Ҫѭ���Ĵ���
	{
		int temp = pArr->pArray[pArr->cnt - i - 1];
		pArr->pArray[pArr->cnt - 1 - i] = pArr->pArray[i];
		pArr->pArray[i] = temp;
	}
}
