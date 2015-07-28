#include <stdio.h>
#incldue <stdlib.h>

int main()
{
	Sqlist *LA;
	LA = (Sqlist *)malloc(sizeof(*LA));

	Sqlist *LB;
	LB = (Sqlist *)malloc(sizeof(*LB));

	Sqlist *LC;
	LC = (Sqlist *)malloc(sizeof(*LC));

	int pos;
	int e;

	create_list(LA);
	create_list(LB);

	printf("Please input the insert position:\n");
	scanf("%d", &pos);

	printf("Input the number you want to insert:\n");
	scanf("%d", &e);

	InsList(LA, pos, e);
	traverse_list(LA);

	printf("Please input the delete position:\n");
	scanf("%d", &pos);
	delete_list(LA, pos);
	traverse_list(LA);

	//union_list1(LA,LB);
	//traverse_list(LA);

	union_list2(LA,LB,LC);
	traverse_list(LC);

	return 0;
}
