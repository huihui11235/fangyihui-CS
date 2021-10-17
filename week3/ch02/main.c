#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#pragma warning(disable:4996)
struct student {
	int number;
	char name[100];
	char sex[100];
	int year;
	int class;
	int score1;
	int score2;
	struct student* next;
};
void fun1(struct student* head)
{
	struct student *p;
	struct student* o;
	o = head;
	p = (struct student*)malloc(sizeof(struct student));
	p->next = NULL;
	if (head->next != NULL)
	{
		printf("输入学号 姓名 性别 年龄 班级 成绩1 成绩2\n");
		scanf_s("%d%s%s%d%d%d%d", &p->number, &p->name, &p->sex, &p->year, &p->class, &p->score1, &p->score2);
		printf("你想加在哪个学生后面，请输入学号：");
			int n;
			scanf_s("&d", &n);
			while (o->next != NULL)
			{
				o = o->next;
				if (o->number == n)
				{
					n = 100; break;
				}
			}
			if (n == 100)
			{
				p->next = o->next;
				o->next = p;
			}
			head = head->next;
			if (n != 100)
				printf("学号错误\n");
			printf("遍历结束\n");
			while (head != NULL)
			{
				printf("%d %s %s %d %d %d %d\n", head->number, head->name, head->sex, head->year, head->class, head->score1, head->score2);
				head = head->next;
			}
	}
	else if (head->next = NULL)

	{
		printf("输入学号 姓名 性别 年龄 班级 成绩1 成绩2\n");
		scanf_s("%d%s%s%d%d%d", &p->number, &p->name, &p->sex, &p->year, &p->class, &p->score1, &p->score2);
		head = head->next;
		printf("遍历结果\n");
		while (head != NULL)
		{
			printf("%d %s %s %d %d %d %d\n", head->number, head->name, head->sex, head->year, head->class, head->score1, head->score2);
			head = head->next;
		}
	}

}
void fun2(struct student* head)
{
	printf("输入你希望删除的成员学号：");
	int a; struct student* p; struct student* o;
	scanf_s("%d", &a); o = head;
	while (o != NULL)
	{

		if (o->number == a)
		{
			p->next = o->next;
			break;
		}
		p = o;
		o = o->next;
	}head = head->next;
	printf("遍历结果\n");
	if (head != NULL)
	{
		while (head != NULL)
		{
			printf("%d  %s  %s  %d  %d  %d %d\n", head->number, head->name, head->sex, head->year, head->class, head->score1, head->score2);
			head = head->next;
		}
	}
	else
		printf("           无信息\n");
}
void fun3(struct student* head)
{
	int n;
	printf("输入你希望查找的成员学号：");
	scanf_s("%d", &n);
	printf("\n");
	while (head != NULL)
	{
		if (head->number == n)
		{
			printf("学生姓名是：%s\n", head->name);
		}
		head = head->next;
	}
}
void fun4(struct student* head)
{
	int n;
	printf("输入你希望修改的成员学号：");
	scanf_s("%d", &n); struct student* o; o = head;
	while (o != NULL)
	{
		if (o->number == n)
		{
			break;
		}
		o = o->next;
	}int x; char ace[50];
	printf("输入你希望修改的东西  学号 1；姓名 2；性别 3；年龄 4；班级 5；成绩1 6；成绩2 7；   :");
	scanf_s("%d", &n);
	if (n == 1)
	{
		printf("输入修改后的学号  :");
		scanf_s("%d", &x);
		o->number = x;
	}
	else if (n == 3)
	{
		printf("输入修改后的性别  ：");
		scanf_s("%s", ace, sizeof(ace));
		strcpy(o->sex, ace);
	}
	else if (n == 2)
	{
		printf("输入修改后的姓名  ：");
		scanf_s("%s", ace,sizeof(ace));
		strcpy(o->name, ace);
	}
	else if (n == 4)
	{
		printf("输入修改后的年龄  :");
		scanf_s("%d", &x);
		o->year = x;
	}
	else if (n == 5)
	{
		printf("输入修改后的班级  ：");
		scanf_s("%d", &x);
		o->class = x;
	}
	else if (n == 6)
	{
		printf("输入修改后的成绩1 ：");
		scanf_s("%d", &x);
		o->score1 = x;
	}
	else if (n == 7)
	{
		printf("输入修改后的成绩2 ：");
		scanf_s("%d", &x);
		o->score2 = x;
	}
	printf("遍历结果\n");
	head = head->next;
	while (head != NULL)
	{
		printf("%d  %s  %s  %d  %d  %d %d\n", head->number, head->name, head->sex, head->year, head->class, head->score1, head->score2);
		head = head->next;
	}
}
int main()
{
	int n;
	struct student *p, *head, *q;
	printf("输入学生个数:");
	scanf_s("%d", &n);
	head = (struct student*)malloc(sizeof(struct student));
	head->next = NULL;
	int i;
	printf("输入学号 姓名 性别 年龄 班级 成绩1 成绩2\n");
	for (i = 0; i < n; i++)
	{
		p = (struct student*)malloc(sizeof(struct student));
		scanf_s("%d%s%s%d%d%d%d", &p->number, &p->name, &p->sex, &p->year, &p->class, &p->score1, &p->score2);
		if (head->next == NULL)
		{
			head->next = p;
		}
		else
		{
			q->next = p;
		}
		q = p;
	}
	q->next = NULL;
	int x = 1;
	while (x)
	{
		printf("输入下一步的功能：增加 1; 删除 2; 查找 3; 修改 4; 退出：0 \n");
		scanf_s("%d", &x);
		switch (x)
		{
		case 1:
			fun1(head);
			break;
		case 2:
			fun2(head);
			break;
		case 3:
			fun3(head);
			break;
		case 4:
			fun4(head);
			break;
		case 0:
			break;
		}
	}
	return 0;
}
