#include <stdio.h>
#include "Sqlist.h"

int destroy(Sqlist * L)
{
	free(L);
	return 0;
}
int is_empty(Sqlist * L)
{
	if (L->last == 0)
		return 0;
	return -1;
}
void set_empty(Sqlist * L)
{
	L->last = 0;
}
int get_length(Sqlist * L)
{
	return L->last;
}
int find_list(Sqlist * L,int e)
{
	int i;

	if (is_empty(L) == 0)
		return -1;

	for (i = 0; i < L->last; i ++)
		if (e == L->elem[i])
		return 0;
	return -2;	
}
void delete_list(Sqlist * L, int i)
{
	if (i < 1 || i > L->last){
		fprintf(stderr, "Wrong position!\n");
		exit(-1);
	}
	for (int j = i; j < L->last; j++)
		L->elem[j - 1] = L->elem[j];
	L->last -= 1;
}
int Locate(Sqlist * L,int e)
{
	int i = 0; //counter
	while ( (i < L->last) && (e != L->elem[i]) )
		i ++;
	if (i < L->last)
		return i + 1;
	else
		return -1;
}
/*
Another method
int Locate(Sqlist * L, int e)
{
	for (int i = 0; i < L->last; ++i)
	{
		if (L->elem[i] == e)
			return i + 1;
	}

	//A macro
	return NOT_FIND;
}*/
void traverse_list(Sqlist * L)
{
	if (L->last == 0)
		return;
	for (int i = 0; i < L->last; i++)
		printf("%d ", L->elem[i]);
	printf("\n");
}
Sqlist * create_list(Sqlist * L)
{
	printf("Please input the length of the Sqlist:\n");
	scanf("%d", &L->last);
	if (L->last > MAX)
		exit(-1);
	printf("Please input the Sqlist:\n");
	for (int i = 0; i < L->last; i++)
	{
		scanf("%d", &L->elem[i]);
	}
	return L;
}
int InsList(Sqlist * L, int i, ElemType e)
{
	//插入算法
	//i的取值范围：0 < i <= L->last + 1;
	int j;
	//考虑第一种表满的情况
	if (L->last == MAX)
		return -1;
	//考虑第二种插入位置非法
	if (i < 1 || i > L->last + 1)
		return -2;
	/*for (j = L->last - 1; j >= i - 1; j--)
		L->elem[j + 1] = L->elem[j];
	*/
	for (j = L->last; j >= i; --j)
		L->elem[j] = L->elem[j-1];
	L->elem[i - 1] = e;
	L->last += 1;
	return 0;


}
int union_list1(Sqlist * L1,Sqlist * L2)
{
	int i;
	int j=0;

	for (i = 0;i < L2->last; i ++)
		if (find_list(L1,L2->elem[i]) < 0)
			InsList(L1,L1->last+1,L2->elem[i]);

}
int union_list2(Sqlist * LA,Sqlist * LB,Sqlist * LC)
{
	//Define two assist-pointer i,j 
	int i = 0;
	int j = 0;
	//represent the length of the Sqlist LC
	int k = 0;

	while (i < LA->last && j < LB->last)
	{
		if (LA->elem[i] < LB->elem[j]){	

			LC->elem[k] = LA->elem[i];
			i ++;
			k ++;
		}
		else
		{
			
			LC->elem[k] = LB->elem[j];
			j ++;
			k ++;
		}
	}
	while (i < LA->last)
	{
		
		LC->elem[k] = LA->elem[i];
		i ++;
		k ++;
	}
	while (j < LB->elem[j])
	{
		LC->elem[k] = LB->elem[j];
		j ++;
		k ++;
	}
	LC->last = LA->last + LB->last;

}
