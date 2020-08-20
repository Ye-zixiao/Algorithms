#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

typedef struct node {
	int data;
	struct node * pNext;
}NODE,*PNODE;

typedef struct Stack {
	PNODE pTop;
	PNODE pBottom;
}STACK,*PSTACK;

void init_Stack(PSTACK pS);                     //��ʼ��ջ
void push_Stack(PSTACK pS, int value);          //ѹջ
bool pop_Stack(PSTACK pS, int* value);          //��ջ����ջ��
void traverse_Stack(PSTACK pS);                 //����
bool is_empty(PSTACK pS);                       //���������Ƿ�Ϊ��
void clear_Stack(PSTACK pS);                    //����ջ��գ�ֻʣ��һ��ͷ���

int main(void)
{
	STACK S;
	int value;

	init_Stack(&S);
	push_Stack(&S, 1);
	push_Stack(&S, 2);
	push_Stack(&S, 3);
	push_Stack(&S, 4);
	push_Stack(&S, 5);
	push_Stack(&S, 6);
	traverse_Stack(&S);

	if (pop_Stack(&S, &value))
		printf("Pop success,and we pop the data %d.\n", value);
	else
		printf("Pop failed.\n");

	traverse_Stack(&S);

	clear_Stack(&S);
	free(S.pTop);                               //�ͷ�ͷ���

	return 0;
}

void init_Stack(PSTACK pS)
{
	pS->pTop = (PNODE)malloc(sizeof(NODE));              //����һ��ͷ��㣬����ʼ����ͷ���ĵ�ַ��ջ��ָ���ջ��ָ��
	if (pS->pTop == NULL)
	{
		fprintf(stderr,"Can't create stack.\n");
		exit(EXIT_FAILURE);
	}
	else
	{
		pS->pBottom = pS->pTop;
		pS->pTop->pNext = NULL;                          //������ͷ����ָ����Ϊ��ָ��
	}
}

void push_Stack(PSTACK pS, int value)
{
	PNODE pNew = (PNODE)malloc(sizeof(NODE));
	if (pNew == NULL)
	{
		fprintf(stderr, "Can't create a new node.\n");
		exit(EXIT_FAILURE);
	}
	else
	{
		pNew->data = value;
		pNew->pNext = pS->pTop;                          //ѹջ�����½��Ľ���ָ����ָ��ԭ����ջ�����
		pS->pTop = pNew;                                 //ʹ�¼ӵĽ���Ϊ��һ��ջ�����
	}
}

bool is_empty(PSTACK pS)
{
	if (pS->pTop == pS->pBottom)                         //��ջ��ָ���ջ��ָ�붼ָ��ͬһ��ͷ���ʱ����ʾ�ǿ�ջ
		return true;
	else
		return false;
}

bool pop_Stack(PSTACK pS, int* value)
{
	if (is_empty(pS))                                    //���ģ��
		return false;
	else
	{
		PNODE q = pS->pTop;                              //��ԭ����ջ�����ĵ�ַ�ݷŸ���һ��ָ�����ָ�룬Ȼ�����ջ��ָ�룬���ͷ����ԭ����ջ�������ڴ�
		*value = q->data;
		pS->pTop = q->pNext;
		free(q);
		return true;
	}
}

void traverse_Stack(PSTACK pS)
{
	PNODE p = pS->pTop;
	while (p != pS->pBottom)                             //ע�⣺ջ��ָ��ָ�����ͷ���
	{
		printf("%d ", p->data);
		p = p->pNext;
	}
	putchar('\n');
}

void clear_Stack(PSTACK pS)
{
	PNODE p = pS->pTop;
	while (p != pS->pBottom)                             //�ͷų�ͷ�����������н��Ķ�̬�ڴ�
	{
		PNODE q = p;
		p = p->pNext;
		free(q);
	}
}
