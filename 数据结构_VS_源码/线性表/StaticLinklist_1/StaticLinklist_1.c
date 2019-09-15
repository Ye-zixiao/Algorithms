#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#define MAXSIZE 20																	/*��̬�����и������ҷ��־��ǣ�����̬������ʱ�Ƚ��鷳������Ҳû����ϸ��˵��*/
																					//���Ծ�����Ҫ������ĳ��ȴ�һ��
typedef struct node {
	int data;
	int cur;
}StaticLinklist[MAXSIZE];

void create_StaticLinklist(StaticLinklist arr);										//������̬������Ҫ����������
int length_StaticLinklist(StaticLinklist arr);										//����������
bool is_empty(StaticLinklist arr);													//�ж������Ƿ�Ϊ��
bool is_full(StaticLinklist arr);													//�ж������Ƿ�Ϊ��
bool insert_StaticLinklist(StaticLinklist arr, int pos, int value);					//����һ����ֵ��������
bool delete_StaticLinklist(StaticLinklist arr, int pos, int* value);				//ɾ��һ������Ԫ�أ��������ݷ��ص�ָ��value����
int malloc_node(StaticLinklist arr);												//��һ������������һ����������Ԫ�أ��Ľ����䵽���������С� **������������ϵĲ�ͬ
void free_node(StaticLinklist arr, int k);											//��һ��ѡ�е����������㴦������������
void sort_StaticLinklist(StaticLinklist arr);										//ʹ��ѡ������������������������
void show_StaticLinklist(StaticLinklist arr);										//��ӡ��������е�����Ԫ��
int Getelem_StaticLinklist(StaticLinklist arr, int pos);							//��ȡһ�����������е�����

int main(void)
{
	StaticLinklist arr;																//������һ���ṹ���飬�����arr���ǽṹ����������ʵ����һ��ָ�루���˼��⣩
	int value;

	create_StaticLinklist(arr);														//���������ľ��Ǵ����˽ṹ�����ָ��
	printf("You enter a static linked list:\n");
	show_StaticLinklist(arr);

	if (insert_StaticLinklist(arr, 2, 34))
		printf("Inserting success.\n");
	else
		printf("Error in inserting.\n");
	if(insert_StaticLinklist(arr, 1, 99))
		printf("Inserting success.\n");
	else
		printf("Error in inserting.\n");
	printf("After inserting: \n");
	show_StaticLinklist(arr);

	printf("After deleting:\n");
	if (delete_StaticLinklist(arr, 4, &value))
		printf("You deletes member %d and its value is %d.\n", 4, value);
	else
		printf("No data deletes.\n");
	show_StaticLinklist(arr);

	sort_StaticLinklist(arr);
	printf("After sorting:\n");
	show_StaticLinklist(arr);
	printf("The value of member %d is %d\n", 3, Getelem_StaticLinklist(arr, 3));

	return 0;
}

void create_StaticLinklist(StaticLinklist arr)
{
	int len;
	int i;

	printf("Enter the length of Static Link list: ");
	scanf("%d", &len);
	if (len > MAXSIZE - 2)											//���ģ��,���Ҳ���Ҿ�������ľ��Ǻ���̬�����ֻ������MAXSIZE-2������
	{
		printf("No enough room to put data.\n");
		exit(EXIT_FAILURE);
	}

	for (i = 0; i < MAXSIZE - 1; i++)								//�Ƚ������е�����Ԫ�ص��α�����Ϊ�ձ�ʱ��״̬
		arr[i].cur = i + 1;
	arr[MAXSIZE - 1].cur = 0;										//�������һ���α�Ҫ����Ϊ0����ʾ��ǰΪ�ձ�

	for (i = 1; i <= len; i++)										//�����û����뻷��
	{
		printf("Enter the data for member %d: ", i);
		scanf("%d", &arr[i].data);
	}
	arr[MAXSIZE - 1].cur = 1;										//��ʼ��ʱ������������һ��Ԫ�ص��α�ָ�����������һ��Ԫ�ص��±�
	arr[i - 1].cur = 0;												//���һ������������α�Ҫ����Ϊ0
	arr[0].cur = i;													//�����һ��Ԫ�ص��α�����Ϊ��������ĵ�һԪ�ص��±�
}

int length_StaticLinklist(StaticLinklist arr)
{
	int len = 0;
	int i = arr[MAXSIZE - 1].cur;

	while (i)														//��û��������̬�����е����һ��Ԫ�ص�0�α�֮ǰ������ѭ������while��
	{
		i = arr[i].cur;
		len++;
	}
	return len;
}

bool is_empty(StaticLinklist arr)
{
	if (arr[MAXSIZE - 1].cur == 0)									//�ж��������һ��Ԫ�ص��α��Ƿ�Ϊ0
		return true;
	else
		return false;
}

bool is_full(StaticLinklist arr)
{
	if (length_StaticLinklist(arr)>=MAXSIZE-2)						//�ж��������Ƿ�ΪMAXSIZE-1���������ô��������
		return true;
	else
		return false;
}

int malloc_node(StaticLinklist arr)									//�ӱ���������ȡ��һ������Ԫ���Ա��洢����ʹ��
{
	int i = arr[0].cur;

	if (!is_full(arr))												//����ǰ�ȼ�������Ƿ����ˣ�������˾Ͳ�����ռ��ˡ�   //�ϰ汾�ǣ�if(i)
	{
		arr[0].cur = arr[i].cur;									//������пռ���ô�ͽ����������һԪ�ص��±ָ꣨����һ����������Ԫ�أ����������һԪ�ص��±�
		return i;
	}
	else
		return 0;
}

void free_node(StaticLinklist arr, int k)
{
	arr[k].cur = arr[0].cur;										//��ԭ�ȱ�������ĵ�һ��Ԫ�ص��±긳����������������ɾ����Ԫ�ص��α꣬
	arr[0].cur = k;													//ʹɾ��Ԫ�س�Ϊ�����������Ԫ��
}

bool insert_StaticLinklist(StaticLinklist arr, int pos, int value)
{
	int i, k;
	k = MAXSIZE - 1;
	if (pos<1 || pos>length_StaticLinklist(arr) + 1)				//���ģ�飬ע�����ǿ�����ĩβ�����
		return false;

	int j = malloc_node(arr);
	if (j)															//�鿴���������Ƿ��пռ��Թ�ʹ��,����������˾Ͳ����ٲ�����
	{
		for (i = 1; i < pos; i++)									//�ҳ�����λ�õ�ǰһ��Ԫ�أ�����
			k = arr[k].cur;

		arr[j].data = value;										//�ȸ������Ԫ��������ֵ
		arr[j].cur = arr[k].cur;									//ʹ����Ԫ�ص��α긳����һ��Ԫ�ص��α꣬ʹ�����ָ��ձ�����Ԫ�أ�ԭ���ĵ�posλ��
		arr[k].cur = j;												//�������Ԫ�ص��±긳����һ��Ԫ�ص��α�
		return true;
	}
	else
		return false;
}

bool delete_StaticLinklist(StaticLinklist arr, int pos, int* value)
{
	int i, j, k;
	k = MAXSIZE - 1;
	if (pos<1 || pos>length_StaticLinklist(arr))
		return false;

	for (i = 1; i < pos; i++)										//�ҳ�����λ�õ�ǰһ��Ԫ�أ�����
		k = arr[k].cur;
	j = arr[k].cur;													//ע�⣺��pos��Ԫ�ص�λ�ò�һ��������������ĵ�pos��λ���ϡ�  �ҳ���pos��Ԫ�ص��±�
	*value = arr[j].data;											//����ɾ��ֵ
	arr[k].cur = arr[j].cur;										//����һ��Ԫ�ظ����±����һ��Ԫ�ص��α�
	free_node(arr, j);												//����ʹɾ��Ԫ�ط��䵽����������
	return true;
}

void sort_StaticLinklist(StaticLinklist arr)
{
	int top, seek;
	int i, j;

	for (top = 0, i = arr[MAXSIZE - 1].cur; top < length_StaticLinklist(arr) - 1; top++, i = arr[i].cur)			//ѡ�������������У��������붯̬������˳��洢�ṹ���㷨һ��
		for (seek = top + 1, j = arr[i].cur; seek < length_StaticLinklist(arr); seek++, j = arr[j].cur)		//��ֻ����ϸ�������ڴ洢��ʽ��ͬ�����˲����Ĳ�ͬ
			if (arr[i].data > arr[j].data)
			{
				int temp = arr[i].data;
				arr[i].data = arr[j].data;
				arr[j].data = temp;
			}
}

void show_StaticLinklist(StaticLinklist arr)
{
	int k = arr[MAXSIZE - 1].cur;																//Ϊʲô��̬��������Ҫ��arr[MAXSIZE-1].cur��ʼ��
	//printf("k=%d\n", k);																		//��Ϊarr�ṹ���飨����˵������ģ����һ��Ԫ�ؾ��Ǿ�̬�����ͷ���
	while (k)
	{
		printf("%d ", arr[k].data);
		k = arr[k].cur;
	}
	putchar('\n');
}

int Getelem_StaticLinklist(StaticLinklist arr, int pos)
{
	int i, k;
	k = MAXSIZE - 1;
	if (pos<1 || pos>length_StaticLinklist(arr) + 1)
		return -1;

	for (i = 1; i <= pos; i++)
		k = arr[k].cur;
	return arr[k].data;
}

//������ĳ����֪������һ���ṹ�������ͣ������ṹ���͵ı�����	function(StaticLinklist arr)����ʽ���ṹ����Ĵ��룬
//�����Ͽ�������ǽṹ�����������ʵ��ʵ�ϴ������һ��ָ��ṹ�����ָ��arr

/*
#include<stdio.h>

typedef struct node{
	int data;
	int cur;
}StaticLinklist[3];

int sum(struct node arr[],int n);
int main(void)
{
	StaticLinklist arr = {
		{1,2},{3,4},{5,6}
	};
	printf("The sum of arr data is %d\n", sum(arr, 3));

	return 0;
}

int sum(struct node arr[], int n)//StaticLinklist���������鴫�뵽��������һ��ָ������ָ�루��������
{
	int i;
	int sum = 0;

	for (i = 0; i < n; i++)
		sum += arr[i].data;
	return sum;
}
*/