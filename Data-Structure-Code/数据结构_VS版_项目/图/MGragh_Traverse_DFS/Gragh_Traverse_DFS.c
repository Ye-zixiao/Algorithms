//																������ȱ����ڽӾ���
#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

#define MAXVER 20
#define INF 65535												//INF��ʾ���������û�ñ�

typedef struct mgrgh {											//�����ڽӾ���Ľṹ��������
	char data[MAXVER];
	int arc[MAXVER][MAXVER];
	int num_vertex;
	int num_edge;
}MGragh,*PMgragh;

void create_gragh(PMgragh G);									//��������������ڽӾ���
void DFS(PMgragh G, int i, bool* visited);						//��ĳһ������ȱ�������������ͨ�������ԣ����������������㣬ʹ�õݹ��ܹ���������/���Ƕ��ڷ���ͨͼ���Ծ���Ҫ�������и���
void DFS_Traverse(PMgragh G);									//��ȱ�������
void clear_inputIO(void);										//��ձ�׼�������еĻ�������

int main(void)
{
	MGragh G;
	create_gragh(&G);
	DFS_Traverse(&G);

	return 0;
}

void clear_inputIO(void)
{
	while (getchar() != '\n')
		continue;
}

void create_gragh(PMgragh G)
{
	int i,j,k;
	printf("Enter the numbers of the vertex and edge:\n");		//���붥�����ͱߵ�����
	scanf("%d %d", &G->num_vertex, &G->num_edge);
	clear_inputIO();
	printf("Enter the data of the vertexs:\n");					//����ѭ�����붥���ϵ�����
	for (i = 0; i < G->num_vertex; i++)
	{
		scanf("%c", &G->data[i]);
		clear_inputIO();
	}

	for(i=0;i<G->num_vertex;i++)								//�ȳ�ʼ�����ڽӾ���Ĭ��Ϊȫ���߶�û�н�������
		for (j = 0; j < G->num_vertex; j++)
			G->arc[i][j] = INF;

	printf("Enter the edge and the its weight:\n");
	for (k = 0; k < G->num_edge; k++)							//ѭ������ߵ����ݣ�������������ͼ
	{
		int weight;
		if (k == 0)
			printf("Enter the (Vi,Vj) and Weight:");
		scanf("%d %d %d", &i, &j, &weight);
		G->arc[i][j] = weight;
		G->arc[j][i] = weight;
		if(k<G->num_edge)
			printf("Keep entering:");
	}
	putchar('\n');
}

void DFS(PMgragh G, int i,bool *visited)
{
	int j;
	visited[i] = true;											//��visited�����е�ǰ��Ԫ������Ϊtrue��ʾ������Ѿ������ʹ���
	printf("%c", G->data[i]);									//���ʴ�ӡ
	//putchar('\n');
	for (j = 0; j < G->num_vertex; j++)							//forΪ�����ҳ���ǰ����������ڽӶ���
	{
		if (G->arc[i][j] != INF && !visited[j])					
			DFS(G, j, visited);									//�ݹ���������ڽӶ���
	}
}

void DFS_Traverse(PMgragh G)
{
	int i;
	bool visited[MAXVER];

	for (i = 0; i < MAXVER; i++)
		visited[i] = false;
	for (i = 0; i < G->num_vertex; i++)							//forѭ��������Ϊ�˷�ֹͼ�д��ڷ���ͨ�����ݹ鲻�ܷ���ȫ�����ݶ�׼����
	{
		if (!visited[i])										//����û�ɷ��ʹ��Ķ���͵��ú������з���
			DFS(G, i, visited);
	}
	putchar('\n');
}