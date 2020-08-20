//						KMP�㷨
#include<stdio.h>
#include<string.h>
#define MAXSIZE 30

void get_next(char* st, int* next);									//����next����
int KMP_match(char* S, char* T);									//����ƥ�䣬����ƥ�������ĸλ�÷��ظ���������

int main(void)
{
	char st1[MAXSIZE] = "abcxagh";
	char st2[MAXSIZE] = "agh";
	int value;

	printf("the start number of string 2 in the string 1 is ");
	if ((value = KMP_match(st1, st2)) > 0)
		printf("%d\n", value);
	else
		printf("not found.\n");

	return 0;
}

void get_next(char* st, int* next)
{
	int tlen = strlen(st);
	int j, k;
	next[0] = -1;
	j = 0;					//��׺
	k = -1;					//ǰ׺

	while (j < tlen - 1)
	{
		if (k == -1 || st[j] == st[k])				//��ǰ׺λ����-1������ǰ׺���ں�׺����ô���Ե�����ȥʶ����һλ
		{
			j++;
			k++;
			next[j] = k;							//j��k�����󣬱�ʾ�����j���ַ�ǰ���ǰ׺��׺����Ԫ�س���Ϊk
		}
		else
			k = next[k];							//���ǰ׺��׺������ͬ����ôk����next[k]��λ�ü�����st[j]ȥƥ�䣬�����Ч����ģʽ��������ƥ��
	}
}

int KMP_match(char* S, char* T)
{
	int next[MAXSIZE];
	get_next(T, next);
	int slen = strlen(S);
	int tlen = strlen(T);
	int i = 0;										//S�������������±�λ�ã�ֻ������
	int j = 0;										//T�����Ӵ���ģʽ�������±�λ��

	while (i < slen && j < tlen)
	{
		if (j == -1 || S[i] == T[j])				//���������ģʽ����һ���ַ�ƥ�����ģʽ�����ַ�λ����-1����ô�Ͷ�����
		{
			i++;
			j++;
		}
		else
			j = next[j];							//ʧ��ʱ����j����next[j]��λ�ü���������ƥ��
	}
	if (j == tlen)
		return i - j + 1;							//����1����Ϊ�˲��������±���һ��ɵĲ�Э��
	else
		return -1;
}
