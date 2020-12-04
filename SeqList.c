#include "SeqList.h"
//初始化
void SeqListInit(SeqList* ps)
{
	//s.size = 0;
	//s.a = NULL;
	//s.capacity = 0;

	ps->a= (SLDateType*)malloc(sizeof(SLDateType) * 4);
	if (ps->a == NULL)
	{
		printf("申请内存失败\n");
		exit(-1);//直接结束掉程序
	}
	ps->size = 0;
	ps->capacity = 4;
}
//打印
void SeqListPrint(SeqList* ps)
{
	int i = 0;
	for (i = 0; i < ps->size; i++)
	{
		printf("%d ", ps->a[i]);
	}
	printf("\n");
}
//检查容量
void SeqListCheckCapacity(SeqList* ps)
{
	assert(ps);
	//增容
	if (ps->size >= ps->capacity)
	{
		ps->capacity *= 2;
		ps->a = (SLDateType*)realloc(ps->a, sizeof(SLDateType) * ps->capacity);
		if (ps->a == NULL)
		{
			printf("扩容失败\n");
			exit(-1);//很暴力，一般情况下是不建议这样的。
		}
	}
}
//尾插
void SeqListPushBack(SeqList* ps, SLDateType x)
{
	assert(ps);
	SeqListCheckCapacity(ps);
	ps->a[ps->size] = x; //因为ps->size 是从0开始初始化的  尾插：是从最后一个有效位的后面插入数值
	ps->size++;
}
//尾删
void SeqListPopBack(SeqList* ps)
{
	assert(ps);
	//ps->a[ps->size - 1] = 0; // 
	ps->size--;
}
//头插
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

//头删
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

//任意位置的插入
void SeqListInsert(SeqList* ps, int pos, SLDateType x)
{

}

//在任意位置删除（直接找到那个位置，然后让后面的数据往前覆盖）
void SeqListErase(SeqList* ps, int pos)
{
	
}