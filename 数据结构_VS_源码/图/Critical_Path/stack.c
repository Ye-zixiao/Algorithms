#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include"critical.h"

void init_Stack(PSTACK pS)
{
	pS->pTop = (PNODE)malloc(sizeof(NODE));              //����һ��ͷ��㣬����ʼ����ͷ���ĵ�ַ��ջ��ָ���ջ��ָ��
	if (pS->pTop == NULL)
	{
		fprintf(stderr, "Can't create stack.\n");
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

bool is_emptystack(PSTACK pS)
{
	if (pS->pTop == pS->pBottom)                         //��ջ��ָ���ջ��ָ�붼ָ��ͬһ��ͷ���ʱ����ʾ�ǿ�ջ
		return true;
	else
		return false;
}

bool pop_Stack(PSTACK pS, int* value)
{
	if (is_emptystack(pS))                                    //���ģ��
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

void destroy_Stack(PSTACK pS)
{
	PNODE p = pS->pTop;
	while (p != NULL)                             //�ͷų�ͷ�����������н��Ķ�̬�ڴ�
	{
		PNODE q = p;
		p = p->pNext;
		free(q);
	}
}
