#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include"topsort.h"

void init_LinkQueue(P_QUEUE pP)
{
	pP->rear = (PNODE)malloc(sizeof(NODE));
	if (pP->rear == NULL)
	{
		fprintf(stderr, "Can't create dynamic memory for node.\n");
		exit(EXIT_FAILURE);
	}
	else
	{
		pP->front = pP->rear;											//��ʼ����ʹ�ö��еĶ�β�Ͷ�ͷ��ָ�붼ָ��ͷ���
		pP->rear->pNext = NULL;
	}
}

void en_queue(P_QUEUE pP, int value)
{
	PNODE p = (PNODE)malloc(sizeof(NODE));
	if (!p)
	{
		fprintf(stderr, "Can't create dynamic memory for this node.\n");
		exit(EXIT_FAILURE);
	}
	else
	{
		p->data = value;												//��Ӳ���ֻ�������ĩβ��ӽ��
		p->pNext = pP->rear->pNext;										//��ʵ��һ������дp->pNext=NULL;
		pP->rear->pNext = p;
		pP->rear = p;													//Ȼ���µĽ��ĵ�ַ������βָ��
	}
}

bool de_queue(P_QUEUE pP, int* pvalue)
{
	if (is_emptyqueue(pP))
		return false;
	else
	{
		PNODE q = pP->front->pNext;
		*pvalue = q->data;
		pP->front->pNext = q->pNext;

		if (pP->rear == q)												//�ڳ�����һ������Ҫע����ǣ��ر�ĵ�������ֻ��һ����ЧԪ��ʱ����Ҫ�ڳ��Ӻ�
			pP->rear = pP->front;										//�ر�Ľ���βָ������ָ���ͷ���
		free(q);
		return true;
	}
}

bool is_emptyqueue(P_QUEUE pP)
{
	if (pP->front == pP->rear)
		return true;
	else
		return false;
}

void destroy_queue(P_QUEUE pP)												//�����free_queue�ǽ������е����н����ڴ�ȫ���ͷ�
{
	PNODE p = pP->front;
	while (p != NULL)
	{
		PNODE q = p;
		p = p->pNext;
		free(q);
	}
}