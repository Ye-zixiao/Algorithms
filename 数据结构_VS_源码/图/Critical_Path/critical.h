#pragma once
#ifndef CRITICAL_H_
#define CRITICAL_H_
#define MAXVER 20

/*----------������ṹ-------*/
typedef struct node {
	int data;
	struct node* pNext;
}NODE, * PNODE;

/*----------��ջ�ṹ-----------*/
typedef struct Stack {
	PNODE pTop;
	PNODE pBottom;
}STACK, * PSTACK;

/*----------���нṹ-----------*/
typedef struct Linkqueue {									//��ʽ����
	PNODE front, rear;
}L_QUEUE, * P_QUEUE;

typedef struct edgenode {									//�߱���ṹ
	int adjvertex;											//Я���ڽӵ������鵱�е��±�
	int weight;												//�ߵ�Ȩ��
	struct edgenode* pNext;
}EdgeNode, * PEdgeNode;

typedef struct vertexnode {									//��������ṹ
	int indegree;
	char data;
	PEdgeNode firstedge;									//ָ��ͷһ���ٽ����±�
}VerNode[MAXVER];

typedef struct lgragh {										//ͼ�Ľṹ
	VerNode adjlist;										//����һ�������ͷָ�������
	int num_ver;											//��������
	int num_edge;											//�ߵ�����
}LGragh, * PLgragh;

void init_Stack(PSTACK pS);									//��ʼ��ջ
void push_Stack(PSTACK pS, int value);						//ѹջ
bool pop_Stack(PSTACK pS, int* value);						//��ջ����ջ��
bool is_emptystack(PSTACK pS);									//���������Ƿ�Ϊ��
void destroy_Stack(PSTACK pS);								//����ջ��գ�ֻʣ��һ��ͷ���

void create_AdjListGragh(PLgragh LG);						//��������һ���ڽӱ�
void clear_input(void);										//������뻺�����е�����
void destroy_LGragh(PLgragh LG);							//�ͷ��ڽӱ��е��ڽ������еĽ��Ķ�̬�ڴ�

#endif