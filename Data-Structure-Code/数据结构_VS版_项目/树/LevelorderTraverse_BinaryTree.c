#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
int i = 1;

typedef struct btnode {									//���������Ľṹ
	char data;
	struct btnode* lchild;
	struct btnode* rchild;
}BTNODE ,*PBTNODE;

typedef struct node {									//����������н��Ľṹ
	PBTNODE pbtnode;
	struct node* pNext;
}NODE,*PNODE;

typedef struct LinkedQueue {							//�������ԵĶ�ͷָ��Ͷ�βָ��
	PNODE front;
	PNODE rear;
}LINKEDQUEUE,*PLINKEDQUEUE;

void init_LinkedQueue(PLINKEDQUEUE pLQ);				//��ʼ������
void enqueue(PLINKEDQUEUE pLQ, PBTNODE pT);				//���
PBTNODE dequeue(PLINKEDQUEUE pLQ);						//����
bool is_emptyqueue(PLINKEDQUEUE pLQ);					//�ж������Ƿ�Ϊ��
void destroy_queue(PLINKEDQUEUE pLQ);					//��������

PBTNODE Create_BinaryTree(void);						//����������ķ�ʽ����������
void LevelorderTraverse_BTree(PBTNODE pT);				//�������
void Destroy_BinaryTree(PBTNODE pT);					//���ٶ�����

int main(void)
{
	PBTNODE pT = Create_BinaryTree();
	LevelorderTraverse_BTree(pT);
	Destroy_BinaryTree(pT);

	return 0;
}

void init_LinkedQueue(PLINKEDQUEUE pLQ)
{
	pLQ->front = (PNODE)malloc(sizeof(NODE));
	if (!pLQ->front)
		exit(-1);
	else
	{
		pLQ->rear = pLQ->front;
		pLQ->front->pNext = NULL;
	}
}

void enqueue(PLINKEDQUEUE pLQ, PBTNODE pT)
{
	PNODE p = (PNODE)malloc(sizeof(NODE));
	if (!p)
		exit(-1);
	else
	{
		p->pbtnode = pT;								//������������ĵ�ַ
		p->pNext = pLQ->rear->pNext;
		pLQ->rear->pNext = p;							//��ԭ���Ķ�βָ������������ɽ��ĵ�ַ
		pLQ->rear = p;									//�ı��βָ��
	}
}

bool is_emptyqueue(PLINKEDQUEUE pLQ)
{
	if (pLQ->front == pLQ->rear)
		return true;
	else
		return false;
}

PBTNODE dequeue(PLINKEDQUEUE pLQ)
{
	if (is_emptyqueue(pLQ))
		return NULL;
	else
	{
		PNODE qtemp = pLQ->front->pNext;
		PBTNODE q = qtemp->pbtnode;
		pLQ->front->pNext = qtemp->pNext;

		if (pLQ->rear == qtemp)							//����ʱ������Ҫ����ͷָ��ָ�����¸���㣬���һ�Ҫ������Ҫ���ӵĽ���ǲ��Ƕ�β��
			pLQ->rear = pLQ->front;						//����ǣ�Ϊ�˱����ͷ��ڴ��βָ�벻֪��ָ����ʲô�ط�������Ҫ�ر�����
		free(qtemp);
		return q;
	}
}

void destroy_queue(PLINKEDQUEUE pLQ)
{
	PNODE p = pLQ->front->pNext;
	while (p != NULL)
	{
		PNODE q = p;
		p = p->pNext;
		free(q);
	}
}

PBTNODE Create_BinaryTree(void)										//��չ�������ķ�ʽ��������������
{
	char data;
	PBTNODE NewNode = NULL;
	printf("Enter character %d: ", i++);
	data = getchar();
	while (getchar() != '\n')										//������뻺�����س���ǰ����ַ�
		continue;

	if (data == '#')												//һ���ڵ������뾮�ŷ��ؿ�ָ��
		return NULL;
	else
	{
		NewNode = (PBTNODE)malloc(sizeof(BTNODE));					//�����½��Ķ�̬�ڴ�
		if (NULL == NewNode)
		{
			fprintf(stderr, "Can't create a new tree node.\n");
			exit(EXIT_FAILURE);
		}
		NewNode->data = data;
		NewNode->lchild = Create_BinaryTree();						//���ӵݹ鴴��
		NewNode->rchild = Create_BinaryTree();						//�Һ��ӵݹ鴴��

		return NewNode;												//�����£���Ч�����ĵ�ַ
	}
}

void Destroy_BinaryTree(PBTNODE pT)
{
	//PBTNODE p = pT;
	if (pT == NULL)
		return;
	else
	{
		Destroy_BinaryTree(pT->lchild);
		Destroy_BinaryTree(pT->rchild);
		free(pT);								//�����ҵݹ飨ɾ����������Ȼ���ͷű����Ķ�̬�ڴ档
	}											//Ϊ���Ǳ�֤��ǰ�������Һ��Ӻ�������ڴ涼��֮ǰ���ͷ���
}

void LevelorderTraverse_BTree(PBTNODE pT)
{
	/*����������㷨��⣺
		�Ƚ������ĵ�ַ��ӣ�Ȼ��ֻҪ���Բ�Ϊ�գ�����Ϊ��˵���Ѿ�������ɣ�����ѭ��
			1���Ӷ�����ȡ��һ��Ԫ�أ�ָ���������ָ�룩��
			2�����ʸ�Ԫ����ָ�Ľ�㣨��ӡ����
			3������Ԫ����ָ�Ľ������Һ��ӷǿգ��������Һ��ӵ�ָ��˳����ӡ�
	*/
	if (!pT)
		return;
	LINKEDQUEUE LQ;
	init_LinkedQueue(&LQ);
	enqueue(&LQ, pT);
	while (!is_emptyqueue(&LQ))
	{
		PBTNODE p = dequeue(&LQ);
		printf("%c ", p->data);
		if (p->lchild)
			enqueue(&LQ, p->lchild);
		if (p->rchild)
			enqueue(&LQ, p->rchild);
	}
	putchar('\n');
	destroy_queue(&LQ);
}