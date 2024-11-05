
//2024.11.05
//看网课教学学习的链表，差不多理解了吧

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#define  N 5


struct student
{
	int number;
	int score;
	struct student* next;
};
typedef struct student stu;
int main()
{
	
	stu* p, * head, * tail;

	p = (struct student*)malloc(sizeof(struct student));

	head = p;
	tail = p;
	head->next = NULL;

	for (int i = 0; i < N; i++)
	{
		p = (struct student*)malloc(sizeof(struct student));
		scanf("%d", &p->number);
		scanf("%d", &p->score);
		tail->next = p;
		tail = p;
		tail->next = NULL;
	}
	p = head->next;
	while (p != NULL)
	{
		printf("%d %d\n", p->number, p->score);
		p = p->next;
	}

	return 0;
}
