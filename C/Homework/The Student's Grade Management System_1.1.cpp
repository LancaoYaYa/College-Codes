
//2024.11.05
//结构体修改为链表
//将数据输入编写成input()函数，脱离主函数
//以链表的形式输入数据
//将list()函数使用链表的形式输出


#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <process.h>
#include <Windows.h>

struct student//结构体
{
	int num;
	int score;
	struct student* next;
}stu[50];

void list(int amount, struct student* point, struct student* head, struct student* tail)
{
	point = head->next;
	while (point != NULL)
	{
		printf("%d   %d\n", point->num, point->score);
		point = point->next;
	}
}

void percent(int* A, int* B, int* C, int* D, int* E,int amount, struct student* p)//人数和占比
{
	
	double p_a, p_b, p_c, p_d, p_e;
	for (int i = 0; i < amount; i++)
	{
		if ((p + i)->score >= 90)(*A)++;
		else if ((p + i)->score >= 80)(*B)++;
		else if ((p + i)->score >= 70)(*C)++;
		else if ((p + i)->score >= 60)(*D)++;
		else (*E)++;
	}
	p_a = double(((double)*A / (double)amount)*100.0);
	p_b = double(((double)*B / (double)amount)*100.0);
	p_c = double(((double)*C / (double)amount)*100.0);
	p_d = double(((double)*D / (double)amount)*100.0);
	p_e = double(((double)*E / (double)amount)*100.0);

	printf("A:%d %.2lf%%  B:%d %.2lf%%  C:%d %.2lf%%  D:%d %.2lf%%  E:%d %.2lf%%\n", *A, p_a, *B, p_b, *C, p_c, *D, p_d, *E, p_e);
}

void search(struct student* p, int amount, int input_num)//学号查成绩
{
	int number = 0;
	int flag = 0;
	for (int i = 0; i < amount - 1; i++)//排名
	{
		for (int j = 0; j < amount - i - 1; j++)
		{
			if ((p + j)->score < (p + j + 1)->score)
			{
				int temp_score = (p + j)->score;
				int temp_num = (p + j)->num;

				(p + j)->score = (p + j + 1)->score;
				(p + j)->num = (p + j + 1)->num;

				(p + j + 1)->num = temp_num;
				(p + j + 1)->score = temp_score;
			}
		}
		
	}

	for (int i = 0; i < amount; i++)
	{
		if (input_num == (p + i)->num)
		{
			number = i + 1;
			flag = 1;
			break;
		}
	}
	if (flag == 0)
	{
		printf("fail to found!\n");

	}
	if (flag == 1)
	{
		printf("Place:%d  %d\n", number, (p + number - 1)->score);
	}
}

void sort_score(struct student* p, int amount)//成绩高到低排序（冒泡）
{
	for (int i = 0; i < amount - 1; i++)
	{
		for (int j = 0; j < amount - i - 1; j++)
		{
			if ((p + j)->score < (p + j + 1)->score)
			{
				int temp_score = (p + j)->score;
				int temp_num = (p + j)->num;
				
				(p + j)->score = (p + j + 1)->score;
				(p + j)->num = (p + j + 1)->num;

				(p + j + 1)->num = temp_num;
				(p + j + 1)->score = temp_score;
			}
		}
	}

	for (int i = 0; i < amount; i++)
	{
		printf("%d %d\n", (p + i)->num,(p + i)->score);
	}
	
}

void sort_num(struct student* p, int amount)//学号小到大排序（冒泡）
{
	for (int i = 0; i < amount - 1; i++)
	{
		for (int j = 0; j < amount - i - 1; j++)
		{
			if ((p + j)->num > (p + j + 1)->num)
			{
				int temp_score = (p + j)->score;
				int temp_num = (p + j)->num;

				(p + j)->score = (p + j + 1)->score;
				(p + j)->num = (p + j + 1)->num;

				(p + j + 1)->num = temp_num;
				(p + j + 1)->score = temp_score;
			}
		}
	}
	
		for (int i = 0; i < amount; i++)
		{
			printf("%d %d\n", (p + i)->num,(p + i)->score);
		}
}

double ave(int* score, int amount)//求平均值
{
	double tot = 0;
	for (int i = 0; i < amount; i++)
	{
		tot = tot + *(score + i);
	}

	return tot / (double)amount;
}

void input(struct student* head,struct student* tail,struct student* point, int amount)
{
	printf("Please enter NO. and score one by one:\n");
	for (int i = 0; i < amount; i++)
	{
		point = (struct student*)malloc(sizeof(struct student));
		scanf("%d %d", &point->num,&point->score);
		tail->next = point;
		tail = point;
		tail->next = NULL;
	}
	printf("The data were updated successfully!");
	Sleep(1000);
	system("cls");
}

int main()
{
	//chain
	typedef struct student STU;
	STU* point, * head, * tail;
	point = (struct student*)malloc(sizeof(struct student));
	head = point;
	tail = point;
	point->next = NULL;


	int A = 0, B = 0, C = 0, D = 0, E = 0;
	int input_num;
	int tot = 0;
	int n=0;
	double average = 0;
	struct student* p;

	p = &stu[0];
	while (true)
	{
		//-------------------------------------------------DRAW----------------------------------------------


		printf("                        The Student's Grade Management System\n");
		printf("*****************************************Menu********************************************\n");
		printf("*1.Enter record                                   2.Caculate total & average score      *\n");
		printf("*3.Sort in descending order by score              4.Sort in ascending order by number   *\n");
		printf("*5.Search by number                               6.Stattistical analysis               *\n");
		printf("*7.List record                                    0.Exit                                *\n");
		printf("*****************************************************************************************\n");
		//---------------------------------------------------------------------------------------------------------------------

		//---------------------------------------------CHOOSE---------------------------------------------

		int choose;
		int* scores;
		scanf("%d", &choose);
		switch (choose)
		{
		case 1:
				printf("Please enter the amount of student：");
				scanf("%d", &n);
				if (n > 50)
				{
					printf("error!");
					Sleep(1000);
					system("cls");
					break;
				}
				input(head, tail, point, n);
				break;
		case 2:
			scores = (int*)malloc(n * sizeof(int));//average
			for (int i = 0; i < n; i++)
			{
				scores[i] = stu[i].score;
				tot = tot + stu[i].score;
			}
			average = ave(scores, n);
			free(scores);
			printf("The average is:%.2lf   the total is %d", average, tot);
			break;
		case 3:
			sort_score(p, n);
			break;
		case 4:
			sort_num(p, n);
			break;
		case 5:
			printf("Please entry NO.:");
			scanf("%d", &input_num);//sreach
			search(p, n, input_num);
			break;
		case 6:
			percent(&A, &B, &C, &D, &E, n, p);
			break;
		case 7:
			list(n, point, head, tail);
			break;
		case 0:
			return 0;

		}










		//Debug


			//percent(&A,&B,&C,&D,&E,n, p);//人数和占比
			/*
			scanf("%d", &input_num);//sreach
			search(p, n, input_num);
			*/

			//sort_num(p, n);//学号低到高排序（冒泡）
			// 
			//sort_score(p, n);//成绩高到低排序（冒泡）
			// 
			//printf("%lf", average);//求average

		/*	for (int i = 0; i < n; i++)
			{
				printf("%d\n", (p+i)->score);
			}
		*/


		
	}
	return 0;
}
