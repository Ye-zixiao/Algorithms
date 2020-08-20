//									��ŵ����Ϸ
#include<stdio.h>

void tower_of_hanoi(int n, char A, char B, char C);

int main(void)
{
	int n;
	printf("������A���Ϸŵ�������: ");
	scanf("%d", &n);

	tower_of_hanoi(n, 'A', 'B', 'C');

	return 0;
}

void tower_of_hanoi(int n, char A, char B, char C)
{
	/*
	���A������ֻ��һ������n
		�ͽ�����n��Aֱ�ӷŵ�C��
	����
		�Ƚ�n-1�����Ӵ�A����C�ŵ�B��
		Ȼ��A�е�����ֱ�ӷŵ�C��
		���B�е�n-1�����ӽ���A�ŵ�C��
	*/
	if (1 == n)
		printf("������%d������%c�ŵ�����%c\n", n, A, C);
	else
	{
		tower_of_hanoi(n - 1, A, C, B);
		printf("������%d������%c�ŵ�����%c\n", n, A, C);
		tower_of_hanoi(n - 1, B, A, C);
	}
}

/*
ԭ��
��A�����е�n�����ӽ���C�����Ƶ�B�����е�ԭ��ͱ��ʺ�
��A�����е�n-1�����ӽ���C�����ƶ���B�����е�ԭ��ͱ�����һ�µģ�
		������Ĺ�ģȴ���ڲ��ϼ�С�ġ�
*/
