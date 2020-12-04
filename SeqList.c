#include "SeqList.h"
//��ʼ��
void SeqListInit(SeqList* ps)
{
	//s.size = 0;
	//s.a = NULL;
	//s.capacity = 0;

	ps->a= (SLDateType*)malloc(sizeof(SLDateType) * 4);
	if (ps->a == NULL)
	{
		printf("�����ڴ�ʧ��\n");
		exit(-1);//ֱ�ӽ���������
	}
	ps->size = 0;
	ps->capacity = 4;
}
//��ӡ
void SeqListPrint(SeqList* ps)
{
	int i = 0;
	for (i = 0; i < ps->size; i++)
	{
		printf("%d ", ps->a[i]);
	}
	printf("\n");
}
//�������
void SeqListCheckCapacity(SeqList* ps)
{
	assert(ps);
	//����
	if (ps->size >= ps->capacity)
	{
		ps->capacity *= 2;
		ps->a = (SLDateType*)realloc(ps->a, sizeof(SLDateType) * ps->capacity);
		if (ps->a == NULL)
		{
			printf("����ʧ��\n");
			exit(-1);//�ܱ�����һ��������ǲ����������ġ�
		}
	}
}
//β��
void SeqListPushBack(SeqList* ps, SLDateType x)
{
	assert(ps);
	SeqListCheckCapacity(ps);
	ps->a[ps->size] = x; //��Ϊps->size �Ǵ�0��ʼ��ʼ����  β�壺�Ǵ����һ����Чλ�ĺ��������ֵ
	ps->size++;
}
//βɾ
void SeqListPopBack(SeqList* ps)
{
	assert(ps);
	//ps->a[ps->size - 1] = 0; // 
	ps->size--;
}
//ͷ��
void SeqListPushFront(SeqList* ps, SLDateType x)
{
	assert(ps);
	SeqListCheckCapacity(ps);
	int end = ps->size - 1;
	while (end >= 0)
	{
		ps->a[end + 1] = ps->a[end];
		end--;
	}
	ps->a[0] = x;
	ps->size++;
}

//ͷɾ
void SeqListPopFront(SeqList* ps)
{
	assert(ps);
	int start = 0;
	while (start < ps->size - 1)
	{
		ps->a[start] = ps->a[start + 1];
		start++;
	}
	ps->size--;
}

//����λ�õĲ���
void SeqListInsert(SeqList* ps, int pos, SLDateType x)
{

}

//������λ��ɾ����ֱ���ҵ��Ǹ�λ�ã�Ȼ���ú����������ǰ���ǣ�
void SeqListErase(SeqList* ps, int pos)
{
	
}