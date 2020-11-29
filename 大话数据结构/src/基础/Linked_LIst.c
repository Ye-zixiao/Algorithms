#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

typedef struct Node {
	int data;
	struct Node* pNext;
}NODE,*PNODE;

PNODE create_Linklist(void);											//��������
void traverse_Linklist(PNODE pHead);									//��������
void Empty_Linklist(PNODE pHead);										//�ͷ������ȫ���ڴ�
int length_List(PNODE pHead);											//��������ĳ���
bool is_empty(PNODE pHead);												//�ж������Ƿ�Ϊ��
bool insert_Linklist(PNODE pHead,int pos,int value);					//����һ����㵽������
bool delete_Linklist(PNODE pHead,int pos,int *value);					//ɾ��һ����㣬��������ֵvalue��ָ����ʽ���ص�������������
void sort_Linklist(PNODE pHead);										//����ѡ�����򷨽����������������

int main(void)
{
	PNODE pHead;
	int value;
	int len;

	pHead = create_Linklist();											//����������Ҫ������ֵ
	printf("The linkedlist shows at follow:\n");
	traverse_Linklist(pHead);											//������ӡ�������е�����
	len = length_List(pHead);
	printf("The length of linked List is %d.\n", len);

	insert_Linklist(pHead, 4, 33);										//����һ������
	insert_Linklist(pHead, 4, 98);
	printf("After inserting:\n");
	traverse_Linklist(pHead);

	sort_Linklist(pHead);												//����
	printf("After sorting:\n");
	traverse_Linklist(pHead);

	if (delete_Linklist(pHead, 2, &value))								//ɾ��һ������
		printf("You delete node %d,and its data is %d.\n", 2, value);
	else
		printf("Error in deleting node %d.\n", 2);
	printf("After deleting:\n");
	traverse_Linklist(pHead);

	Empty_Linklist(pHead);												//�������±�ɿձ�
	free(pHead);														//�����ͷ�ȫ���Ķ�̬�ڴ棨��һ��ֻ�ͷ���ͷ���Ķ�̬�ڴ棩

	return 0;
}

PNODE create_Linklist(void)
{
	PNODE pHead,pTemp;
	pHead = (PNODE)malloc(sizeof(NODE));								//����ͷ���
	if (pHead == NULL)
	{
		printf("Can't assign dynamic memory for this program.\n");
		exit(EXIT_FAILURE);
	}
	pTemp = pHead;														//����һ����ʱָ����������һ�����Ľṹָ�룬������Ϊ�յ�ʱ��ͷ���������һ�����
	int Node_num;														//�������
	int i;
	int value;

	printf("Enter numbers of Node that you want to create: ");
	scanf("%d", &Node_num);
	for (i = 0; i < Node_num; i++)
	{
		printf("Enter the value for member %d: ", i + 1);
		scanf("%d", &value);
		PNODE p = (PNODE)malloc(sizeof(NODE));							//�����µĽ��
		if (p == NULL)
		{
			printf("Can't assign dynamic memory for this Node.\n");
			exit(EXIT_FAILURE);
		}
		p->data = value;
		pTemp->pNext = p;												//β�巨���������ɵĽ��ĵ�ַ����һ��β����ָ�������ʱ�ṹָ��pTemp
		pTemp = p;														//Ȼ��������ʱָ��ָ�����һ�����
	}
	pTemp->pNext = NULL;												//���˳�ѭ����ʱ��β����ָ������ΪNULL

	return pHead;
}

void traverse_Linklist(PNODE pHead)
{
	PNODE p;
	p = pHead->pNext;
	while (p != NULL)
	{
		printf("%d ", p->data);
		p = p->pNext;
	}
	putchar('\n');
}

void Empty_Linklist(PNODE pHead)
{
	PNODE p = pHead->pNext;
	while (p != NULL)
	{
		PNODE q = p;
		p = p->pNext;
		free(q);
	}
	pHead->pNext = NULL;												//��������Ϊ�ձ�ʹͷ����ָ������ΪNULL
}

bool is_empty(PNODE pHead)
{
	if (pHead->pNext == NULL)
		return true;
	else
		return false;
}

int length_List(PNODE pHead)
{
	int length = 0;
	PNODE p = pHead->pNext;
	while (p != NULL)
	{
		length++;
		p = p->pNext;
	}

	return length;
}

bool insert_Linklist(PNODE pHead, int pos, int value)
{
	PNODE p = pHead;
	int j;
	j = 1;

	while (j < pos && p != NULL)							//�ҵ���pos-1�����.p!=NULL��Ҫ��Ϊ���ڴ������������Ŵ������Ա���ʱ��ʱ����
	{
		p = p->pNext;
		j++;
	}
	if (j > pos || p == NULL)								//j>pos��Ϊ���ų����븺����ŵĴ��������������
		return false;

	PNODE pNew = (PNODE)malloc(sizeof(NODE));
	pNew->data = value;
	pNew->pNext = p->pNext;
	p->pNext = pNew;

	return true;
}

bool delete_Linklist(PNODE pHead, int pos, int* value)
{
	PNODE p = pHead;
	int j;
	j = 1;

	while (p->pNext != NULL && j < pos)						//�ҵ���pos-1�����.p->pNext ��Ҫ��Ϊ���жϵ�pos-1��������һ����㣨����pos������Ƿ���ڣ�
	{
		p = p->pNext;
		j++;
	}
	if (p->pNext == NULL || j > pos)						//����pos�����Ϊ�ջ��߳������븺����ŵ�����·��س���
		return false;

	PNODE q = p->pNext;
	*value = q->data;
	p->pNext = q->pNext;
	free(q);												//�ͷŶ�̬�ڴ�

	return true;
}

void sort_Linklist(PNODE pHead)								//ѡ�����򷨣�����
{
	int top, seek;
	int length = length_List(pHead);

	PNODE q, p;
	for(top=0,q=pHead->pNext;top<length-1;top++,q=q->pNext)			//�����ϴ����˼·��˳��洢�ṹ��ѡ�����򷨻�������ͬ
		for(seek=top+1,p=q->pNext;seek<length;seek++,p=p->pNext)
			if (q->data > p->data)
			{
				int temp = q->data;
				q->data = p->data;
				p->data = temp;
			}
}

/*
ʲô���㷨��
	������㷨�������ݵĴ洢��ʽ������أ�
	������㷨�������ݵĴ洢��ʽ�޹صġ�

	���ͣ�����ĳ�ּ����ﵽ��Ч�����ǣ���ͬ�����ݴ洢��ʽ��ִ�еĲ�������ͬ��

	���Ǽ������ѵļ����Ҿ��û�����
	1�����������Ĳ�ͬ�������㷨���߼�����һ���ģ������������Ĵ洢��ʽ��һ�����������㷨��ʵ�־Ͳ�ͬ��
	2��������ʵ�ֵ��㷨˼���Ϻ͹�����һ�����������㷨������ʵ�ֵĲ��費һ����

	�±���ʦ���ᵽ��C++�ϵĺ������ط���������˼�롣

	��������͹���ı�����Ƿ��ͱ����Ҫ�о��ġ�
	�ں�۲����ϣ���ͨ����Ա�ڱ��ʱ�õ���װ�˵ĺ������ڱ�̵Ĺ����ио�����ͬ�ı������֮���ʵ�����ƺ�����ͬ�ģ�
	�����ڵײ��ʵ��ϸ���ϲ�ͬ���ܵı�����Ժ����ϻ���ͬ���ڲ��������Ƶĺ���ʵ�����ǲ�ͬ��
	*/
