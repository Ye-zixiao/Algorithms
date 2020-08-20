#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#define MAXSIZE 10

typedef struct Queue {												//ѭ������
	int* parr;
	int front;														//��ͷ
	int rear;														//��β
}QUEUE, * PQUEUE;

void init_Queue(PQUEUE pQ);											//��ʼ������
bool is_empty(PQUEUE pQ);											//�ж϶����Ƿ�Ϊ��
bool is_full(PQUEUE pQ);											//�ж϶����Ƿ�����
bool en_Queue(PQUEUE pQ, int value);								//���
bool de_Queue(PQUEUE pQ, int* pvalue);								//����
void traverse_Queue(PQUEUE pQ);										//����
int length_Queue(PQUEUE pQ);										//������г���

int main(void)
{
	QUEUE Q;
	int value;

	init_Queue(&Q);
	en_Queue(&Q, 1);
	en_Queue(&Q, 2);
	en_Queue(&Q, 3);
	en_Queue(&Q, 4);
	en_Queue(&Q, 5);
	en_Queue(&Q, 6);
	en_Queue(&Q, 7);
	en_Queue(&Q, 8);
	en_Queue(&Q, 9);
	en_Queue(&Q, 10);
	en_Queue(&Q, 11);
	traverse_Queue(&Q);

	if (de_Queue(&Q, &value))
		printf("You dequeue the number %d.\n", value);
	else
		printf("Dequeue failed.\n");
	traverse_Queue(&Q);

	printf("Now the length of queue is %d.\n", length_Queue(&Q));

	free(Q.parr);															//�ͷ�����Ķ�̬�ڴ�

	return 0;
}

void init_Queue(PQUEUE pQ)
{
	pQ->parr = (int*)malloc(sizeof(int) * MAXSIZE);
	if (pQ->parr == NULL)
	{
		fprintf(stderr, "Error in creating dynamic memory for array.\n");
		exit(EXIT_FAILURE);
	}
	else
	{
		pQ->front = 0;													//����ͷ�Ͷ�β����ʼ��Ϊ0��ͬʱҲ�ڱ�ʾ����Ϊ��
		pQ->rear = 0;
	}
}

bool is_empty(PQUEUE pQ)
{
	if (pQ->front == pQ->rear)											//����ͷ���ڶ�βʱ����ʾ����Ϊ��
		return true;
	else
		return false;
}

bool is_full(PQUEUE pQ)
{
	if ((pQ->rear + 1) % MAXSIZE == pQ->front)							//��βָ�����һ����ЧԪ�ص���һ��Ԫ�أ��������Ԫ���ǲ��ܴ�����ݵģ����Գ���Ϊmaxsize
		return true;													//������ֻ��ʹ��maxsize-1��Ԫ�ء�������ѭ���б��е���β����1ȡ���鳤�ȵ�ģ���ڶ�ͷʱ��ʾ����
	else
		return false;
}

bool en_Queue(PQUEUE pQ, int value)
{
	if (is_full(pQ))												//���ģ��
		return false;
	else
	{
		pQ->parr[pQ->rear] = value;
		pQ->rear = (pQ->rear + 1) % MAXSIZE;						//��β+1��ȡ���鳤�ȵ�ģ�����µĶ�β
		return true;
	}
}

bool de_Queue(PQUEUE pQ, int* pvalue)
{
	if (is_empty(pQ))												//���ģ��
		return false;
	else
	{
		*pvalue = pQ->parr[pQ->front];
		pQ->front = (pQ->front + 1) % MAXSIZE;						//��ͷ+1��ȡ���鳤�ȵ�ģ�����µĶ�ͷ
		return true;
	}
}

void traverse_Queue(PQUEUE pQ)
{
	int p = pQ->front;
	while (p != pQ->rear)											//��λ��ָʾ��ָ�򵽶�βʱ��ʾ�������
	{
		printf("%d ", pQ->parr[p]);
		p = (p + 1) % MAXSIZE;
	}
	putchar('\n');
}

int length_Queue(PQUEUE pQ)
{
	int len = 0;
	int q = pQ->front;
	while (q != pQ->rear)											//����������ķ�����ͬ
	{
		len++;
		q = (q + 1) % MAXSIZE;
	}
	return len;
}
