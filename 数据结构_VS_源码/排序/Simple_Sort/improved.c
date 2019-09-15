//�ϸ��ӵ�����������
#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include"sort.h"


/*=====================��������================================*/
void Quick_Sort(pSqList psl)								//��װ������
{
	Qsort(psl->parr, 0, psl->length - 1);
}

/*��������ʹ�õľ��Ƿֶ���֮��˼�룺���õݹ鰴���Ὣ�������߷ֿ����ֱ��ٴεݹ�ʹ�ÿ�������*/
void Qsort(int* arr, int low, int high)
{
	int pivot;												//���᣺�������У��������ߵ�Ԫ�����ݶ�С������Ԫ�ص����ݣ���������ұ�Ԫ�ص����ݶ��������������
	if (low < high)
	{
		pivot = Partition(arr, low, high);					//����������±�
		Qsort(arr, low, pivot - 1);							//�ݹ��󲿷�
		//Qsort(arr, pivot + 1, high);						//�ݹ��Ҳ���
		low = pivot + 1;									//��һ������Կ�������������Ż��������ĺô����Ǽ����˵ݹ���ȣ������ϵͳ����
															//�����Ļ���ǰ��ĵݹ齫������벿�ֿ���������ɺ�low = pivot + 1;����ʹ���ٴν���ѭ������Ұ벿�ֵĿ���
	}
}

int Partition(int* arr, int low, int high)
{
	//int temp = arr[low];									//���������Ǹ÷�Χ�ε���Ԫ��
	int pos = Mid_of_Three(arr, low, high);
	int temp = arr[pos];									//����ȡ�з���ȷ���������и���ĸ���ȡ���м���
	while (low < high)
	{
		while (low < high && arr[high] >= temp)				//��high������С�����ᣬ�ͽ������ݸ����±�Ϊlow��Ԫ�أ�Ȼ��high�Լ�
			high--;											//ע�⣺��С�ڵ��ںţ����������˵�����Ϊ1��1��1��1��1��4��3���������������ƫ�����ƫ�ң�������������λ���м�
		arr[low] = arr[high];
		while (low < high && arr[low] <= temp)				//��low�����ݴ������ᣬ�ͽ������ݸ����±�Ϊhigh��Ԫ�أ�Ȼ��low����
			low++;
		arr[high] = arr[low];
															/*��Ȼ��low=high��Ȼ���˳�ѭ���壬��ʱ������Ԫ�����ݷŵ���low������high��λ��
															ʹ�������󲿷ֵ����ݶ�С�����ᣬ�в��ֵ����ݶ���������*/
	}
	arr[low] = temp;
	return low;
}

int Mid_of_Three(int* arr, int low, int high)
{
	int mid = low + (high - low) / 2;
	if (arr[low] > arr[high])						//��low��highλ���Ͻϴ�����ŵ�highλ����
		swap(arr, low, high);
	if (arr[mid] > arr[high])						//��mid��high�нϴ�����ŵ�highλ���ϣ���ʱhighλ���Ϸŵı�Ȼ���������м�������
		swap(arr, mid, high);
	if (arr[low] < arr[mid])						//��low��mid�нϴ�����ŵ�lowλ���ϣ�����lowλ���ϱ�Ȼ���������е��м�ֵ
		swap(arr, mid, low);
	return low;
}


/*==================================ϣ������===============================*/
void Shell_Sort(pSqList psl)
{
	int temp;
	int increment;
	for (increment = psl->length / 3 + 1; increment > 1; increment = increment / 3 + 1)					//����ϣ������D��k��=D��k+1��/3+1��
	{
		int i;
		for (i = increment; i < psl->length; i++)														//��ÿ��D��k����Ԫ�ؽ�������
		{
			temp = psl->parr[i];
			int pos;
			for (pos = i; pos >= increment && psl->parr[pos - increment] > temp; pos -= increment)		//����Ҫ��֤pos����increment����������ʹpos - increment�±��Ԫ����temp��
				psl->parr[pos] = psl->parr[pos - increment];											//���ڴ���tmep��Ԫ�أ���������ƶ�һ������λ
			psl->parr[pos] = temp;																		//��temp�ŵ�С������λ�ú���
		}
	}
	/*ֱ�Ӳ��������ʱ�临�Ӷ��������ݹ�ģ����������Ը����ĺ���T(N)=O(N+I)��
		ϣ���������ֱ�Ӳ���������Ż��棬����ֱ�Ӳ�������ÿһ�������ǻ���ǰ��Ԫ�������Ƚϣ�ÿһ�����ݽ�����ֻ�����һ������ԣ�
	������Ҫ����㷨Ч�ʣ��Ͳ��ò����������һ�����ݽ����о��ܹ����ٴ���һ��������ԣ�
		����ÿһ��ֱ�Ӳ��������ǻ��������Ƚϵģ���ô�ҿɲ�������ÿһ�ν��������Զ��Ԫ�أ�ʹÿһ�ν��������Զ��Ԫ�ؾ�����������һ���������
	��Ȼ����Ӧ�ļ���������ڵļ����ʹ��Ԫ��������ÿһ���������������ߣ������һ��֮ǰ�ﵽ�������������������ٵ�1���ͱ����ֱ�Ӳ������򡣴�ʱ��ֱ�Ӳ���
	������������Դ���ȼ��٣���������Ч��Ҳ�������ߡ�
	ϣ�������˼�룺
		1����ÿ���һ��������ԭʼ���н���ֱ�Ӳ������򡣱��磺9��8��7��6��5��4��3��2��1����ʱ�����������4��
			��ô�ȶ�9��6��������Ȼ���6��9��3�������򣬵�ע��ÿ�β��Ƕ�9��6��3����������ֱ�������꣬����ͬ��������һͬ����
			����Ҫ�ر������for (i = increment; i < psl->length; i++)Ϊʲô��i++������+=increment��
		2��Ȼ�����������С���ظ�1���Ĳ��裻
		3�����������ٵ�1ʱ���������ֱ�Ӳ������������һ�ֺ���ǽ���������
	*/
}


/*========================================������===================================*/
void Heap_Sort(pSqList psl)
{
	int i;
	for (i = psl->length / 2 - 1; i >= 0; i--)						//��ԭʼ������������ѵ���ʽ
		Max_Heap_Adjust(psl->parr, i, psl->length);

	for (i = psl->length - 1; i >= 0; i--)
	{
		swap(psl->parr, 0, i);										//�������е���Ԫ�ص����ݺ͵�ǰ����Ϊi+1�����һ��Ԫ�أ��±�Ϊi����Ԫ�ؽ��н���
		Max_Heap_Adjust(psl->parr, 0, i);							//���������ѵ�Ԫ�س����Լ�һ����������Ԫ�ؽ��е���
	}
}

/*������������������ȫ�����������ʣ�ʹ��������������ʹ���˶���������ʽȥ��������������֯
�洢��ʽ�ϻ���ʹ�����������ʽȥ��ɡ�
		�㷨��ʽ��
			1�������鹹�������ѵ���ʽ��
			2��for��ÿһ����㣩
				{
					����ǰ���ѵĶѶ�Ԫ����ѵ����һ��Ԫ�ؽ��н�����
					���ѵĳ���-1��
					���¶����ѵĶѶ�Ԫ�ؽ��е�����
				}
			*/

void Max_Heap_Adjust(int* arr, int i, int length)
{
	int j=i;
	int temp = arr[i];											//����������Ԫ���±�Ϊi��������Ԫ�ص����ݽ����ݴ�

	for (j = 2 * i + 1; j <= length - 1; j = 2 * j + 1)			//�õ�����Ԫ�ص����ӵ��±�
	{
		if (j<length - 1 && arr[j + 1]>arr[j])					//�������������ֵܣ��Ƚ����ߣ������ֵܴ󣬾ͽ��±껻�����ֵܵ��±�
			j++;
		if (temp > arr[j])										//����ǰ�����������Ӷ�����С�����˳�ѭ����ʲôҲ����
			break;
		arr[i] = arr[j];										//������Ǻ�������һ���������������˫�׽�㣬�ͽ�������ֵ����˫�׽��
		i = j;													//Ȼ����������������ӽ��Ϊ��ǰѭ����Ҫ�жϵĽ��
	}
	arr[i] = temp;												//���ԭ������Ԫ�ص����ݲ��뵽˫�׽������������ӽڵ�С������λ��
}


/*====================================�鲢���򣨵ݹ鷽����====================================*/
void Merge_Sort(pSqList psl)
{
	int* ptemp= (int*)malloc(sizeof(int) * psl->length);		//����һ����ʱ�������Դ���м���������н��
	if (!ptemp)
		exit(-1);
	Msort(psl->parr, ptemp, 0, psl->length - 1);				//����Msort������psl->parr���������������Χ��0��psl->length - 1��tmep_arr����м���
	free(ptemp);
}

void Msort(int* arr, int* temp_arr, int low, int high)
{
	int mid;
	if (low == high)
		temp_arr[low] = arr[low];								//�������ֻʣ�µ���Ԫ��ʱ���ͽ���Ԫ�ش浽��ʱ���鵱��
	else
	{
		mid = (low + high) / 2;									//�����м���
		Msort(arr, temp_arr, low, mid);							//�ݹ���ô�����벿�֣�ʹ����ʱ�����Ŀ�������е����ݣ�ͬʱ������
		Msort(arr, temp_arr, mid + 1, high);					//�ݹ���ô����Ұ벿��
		Merge(temp_arr, arr, low, mid, high);					//����ʱ���������Ҹ�����������е����������Ŀ�����飬ʹ������low��high�ķ�Χ������
	}															//ע�⣺��ʱ�����������Χ��Ҳ��������
}

void Merge(int* temp_arr, int* arr, int low, int mid, int high)
{
	int i, j;
	int k;
	for (i = low, j = mid + 1, k=low; i <= mid && j <= high;k++)
	{															/*������������ÿһ��ѭ���У�ȡ������С�����ŵ�Ŀ�������У�Ȼ��ȡ����������
																���±�λ��������Ȼ���ʣ�µ�����һ������Ѿ��Ž�ȥ�����ݴ�			*/
		if (temp_arr[i] < temp_arr[j])
			arr[k] = temp_arr[i++];
		else
			arr[k] = temp_arr[j++];
	}

	while (i <= mid)											//�����������ѭ������һ�����黹������û�д�Ž�Ŀ�����飨��һ���Ȼ�Ѿ�ȫ���Ž�ȥ�ˣ�����ô��ʣ�µķŽ�Ŀ������
	{
		arr[k] = temp_arr[i++];
		k++;
	}
	while (j <= high)
	{
		arr[k] = temp_arr[j++];
		k++;
	}

	for (k = low; k <= high; k++)								//��Ŀ����������󣬽�����������ݸ��Ƹ���ʱ���飬Ŀ����Ϊ�˵ݹ���������һ���ĺ���ʹ��
		temp_arr[k] = arr[k];
														/*���ַ���ʹ�ù鲢����ʱÿ�εݹ�ʱ�������´���һ����ʱ����������м��������ǲ��ɱ����ʱ��Ч���½��˲��٣�
														��������ʱ�临�Ӷȣ�����ȡ�ռ临�Ӷȵ���ߣ����ÿһ�εݹ�ʱ������һ����ʱ�������м������ȵ��ݹ������
														�ͷţ������Ļ����ݹ���Ȳ������ʱ���ڴ��е�ջ�ռ�Ҳ�ᱻ���Ĳ��٣�����ʱ��Ч��ȴ����˲��١����ַ���������
														�ռ临�ӶȻ�ȡ��ʱ�临�Ӷȵ���ߡ�������ͬ�α�������
														*/
}


/*=====================================�鲢���򣨷ǵݹ鷽����================================*/
void Merge_Sort_nonrecursion(pSqList psl)
{
	int* ptemp = (int*)malloc(sizeof(int) * psl->length);
	if (!ptemp)
		exit(-1);
	int k = 1;
	while (k < psl->length)
	{																			/*�Ȱ��ն��������Գ���Ϊ1���������鲢��Ȼ���������г���Ϊ2���������鲢
																					Ȼ���ճ���Ϊ4�������鲢��������ֱ�������г��ȱ�ñ��������鳤�ȴ�ʱ�˳�*/
		k_length_Seqmerge(psl->parr, ptemp, k, psl->length);					//�Ƚ�ԭʼ�������������г���Ϊk�����鲢����ʱ���鵱��
		k *= 2;
		k_length_Seqmerge(ptemp, psl->parr, k, psl->length);					//�ٽ���ʱ�������������г���Ϊ2k�����鲢��ԭʼ���鵱��
		k *= 2;
	}
	free(ptemp);
}

void k_length_Seqmerge(int* source_arr, int* target_arr, int k, int length)
{
	int i;
	for (i = 0; i + 2 * k <= length; i += 2 * k)							//i + 2 * k <= length����˵��ԭʼ������������鲢
		Merge2(source_arr, target_arr, i, i + k - 1, i + 2 * k - 1);

	if (i + k < length)														//�鲢ʣ�µ����������У�����һ�������г��Ȳ���k��
		Merge2(source_arr, target_arr, i, i + k-1, length - 1);
	else
		for (; i < length; i++)												//��ʣ�µ�������ֻ��һ�������У����Ȳ���k��ʱ��ֱ�ӽ�������и��Ƶ�Ŀ�����鵱��
			target_arr[i] = source_arr[i];
}

void Merge2(int* source_arr, int* target_arr, int low, int mid, int high)
{																			//��low��mid��mid+1��high�����������й鲢���ŵ�Ŀ�����鵱�У�ԭ���鲻��Ķ��������ݹ�ʱ�ĺ�����ͬ��
	int i, j;																
	int k;
	for (i = low, j = mid + 1, k = low; i <= mid && j <= high; k++)
	{
		if (source_arr[i] < source_arr[j])
			target_arr[k] = source_arr[i++];
		else
			target_arr[k] = source_arr[j++];
	}

	while (i <= mid)
		target_arr[k++] = source_arr[i++];
	while (j <= high)
		target_arr[k++] = source_arr[j++];
}