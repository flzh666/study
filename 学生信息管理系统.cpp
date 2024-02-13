#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define MAX 60 // ����MAX���ֵΪ60
int num = 0;
struct student
{
	char name[20];
	int age;
	int id;
	int optional_course;   /*ѡ�޿�*/
	int laboratory_course; /*ʵ���*/
	int required_course;   /*���޿�*/
};
struct class_room
{
	struct student st[MAX]; // ������ѧ��
	int n;					// ��ǰ�༶������
};
void printf_menu() // ��ӡ���˵�����
{
	printf("        ѧ���ɼ�����ϵͳ        \n");
	printf("----------------------------\n");
	printf("|1�����ѧ����Ϣ            |\n");
	printf("|2����ʾ����ѧ����Ϣ        |\n");
	printf("|3����ѯѧ����Ϣ            |\n");
	printf("|4��ɾ��ѧ����Ϣ            |\n");
	printf("|5���޸�ѧ����Ϣ            |\n");
	printf("|6���˳�                    |\n");
	printf("----------------------------\n");
	printf("��������Ӧ�����ѡ��!       \n");
}
void add_student(struct class_room *WLW) // ���ѧ����Ϣ������struct class_room *WLWΪ�ṹ��ָ��
{
	printf("������ѧ����������\n");
	scanf("%s", WLW->st[WLW->n].name); // �����������׵�ַ
	printf("������ѧ�������䣺\n");
	scanf("%d", &WLW->st[WLW->n].age); // ȡ�����ĵ�ַ
	printf("������ѧ����id��\n");
	scanf("%d", &WLW->st[WLW->n].id);
	printf("������ѧ����ѡ�޿γɼ���\n");
	scanf("%d", &WLW->st[WLW->n].optional_course);
	printf("������ѧ����ʵ��γɼ���\n");
	scanf("%d", &WLW->st[WLW->n].laboratory_course);
	printf("������ѧ���ı��޿γɼ���\n");
	scanf("%d", &WLW->st[WLW->n].required_course);
	WLW->n++; // �༶������һ
	system("pause");
	system("cls");
}
void show_student(struct class_room *WLW) // ��ʾ����ѧ����Ϣ
{
	for (int i = 0; i < WLW->n; i++) // WLW->nΪ��ǰ�༶������
	{

		printf("�� %d ����ѧ���������� %s\n", i + 1, WLW->st[i].name); // ��һ��ѧ��
		printf("�� %d ����ѧ���������� %d\n", i + 1, WLW->st[i].age);
		printf("�� %d ����ѧ����id��%d\n", i + 1, WLW->st[i].id);
		printf("�� %d ����ѧ����ѡ�޿εĳɼ��� %d\n", i + 1, WLW->st[i].optional_course);
		printf("�� %d ����ѧ����ʵ��εĳɼ��� %d\n", i + 1, WLW->st[i].laboratory_course);
		printf("�� %d ����ѧ���ı��޿εĳɼ��� %d\n", i + 1, WLW->st[i].required_course);
	}
	system("pause");
	system("cls");
}
int find_student(struct class_room *WLW) // ����ָ��ѧ��
{
	int i, id;
	printf("������Ҫ���ҵ�ѧ��id��\n");
	scanf("%d", &id);
	for (i = 0; i < WLW->n; i++)
	{
		if (id == WLW->st[i].id)
		{
			printf("��ѧ������!\n");
			printf("�� %d ����ѧ���������� %s\n", i + 1, WLW->st[i].name);
			printf("�� %d ����ѧ���������� %d\n", i + 1, WLW->st[i].age);
			printf("�� %d ����ѧ����id�� %d\n", i + 1, WLW->st[i].id);
			printf("�� %d ����ѧ����ѡ�޿εĳɼ��� %d\n", i + 1, WLW->st[i].optional_course);
			printf("�� %d ����ѧ����ʵ��εĳɼ��� %d\n", i + 1, WLW->st[i].laboratory_course);
			printf("�� %d ����ѧ���ı��޿εĳɼ��� %d\n", i + 1, WLW->st[i].required_course);
			return i;
		}
	}
	printf("��ѧ��������!\n");
	return -1;
	system("pause");
	system("cls");
}
void delete_student(struct class_room *WLW) // ɾ��ָ��ѧ��
{
	int ret, i;
	ret = find_student(WLW);
	if (ret != -1)
	{
		for (i = ret; i < WLW->n - 1; i++)
		{
			strcpy(WLW->st[i].name, WLW->st[i + 1].name); // �������ַ������͸���ʹ��ͷ�ļ�string.h�е�strcpy���ƺ���
			WLW->st[i].age = WLW->st[i + 1].age;
			WLW->st[i].id = WLW->st[i + 1].id;
			WLW->st[i].optional_course = WLW->st[i + 1].optional_course;
			WLW->st[i].laboratory_course = WLW->st[i + 1].laboratory_course;
			WLW->st[i].required_course = WLW->st[i + 1].required_course;
		}
		WLW->n--;
	}
	printf("��ѧ���Ѿ�ɾ���ɹ���\n");
	system("pause");
	system("cls");
}
void change_student(struct class_room *WLW) // �޸�ѧ����Ϣ
{
	int ret, choose;
	ret = find_student(WLW);
	if (ret != -1)
	{
	loop1:
		printf("�޸�ѧ����Ϣ����һ�\n");
		printf("1������\n");
		printf("2������\n");
		printf("3��id\n");
		printf("4��ѡ�޿γɼ�\n");
		printf("5��ʵ��γɼ�\n");
		printf("6�����޿γɼ�\n");
		scanf("%d", &choose);

		switch (choose)
		{
		case 1:
			printf("�������µ�ѧ��������\n");
			scanf("%s", WLW->st[ret].name); // ����Ĵ����׵�ַ�����Բ���Ҫ&ȡ��ַ
			break;
		case 2:
			printf("�������µ�ѧ�����䣺\n");
			scanf("%d", &WLW->st[ret].age);
			break;
		case 3:
			printf("�������µ�ѧ��id��\n");
			scanf("%d", &WLW->st[ret].id);
			break;
		case 4:
			printf("�������µ�ѧ��ѡ�޿γɼ���\n");
			scanf("%d", &WLW->st[ret].optional_course);
			break;
		case 5:
			printf("�������µ�ѧ��ʵ��γɼ���\n");
			scanf("%d", &WLW->st[ret].laboratory_course);
			break;
		case 6:
			printf("�������µ�ѧ�����޿γɼ���\n");
			scanf("%d", &WLW->st[ret].required_course);
			break;
		default:
			printf("����������������룡\n");
			goto loop1;
		}
	}
	system("pause");
	system("cls");
}
int main()
{
	struct class_room WLW; // ����һ���༶ΪWLW�洢ѧ��
	WLW.n = 0;			   // ��ʼ����ѧ������Ϊ0
	while (1)			   // ����ѭ��
	{
	loop:
		printf_menu(); // �������˵�����������˵�
		int choose;	   // ����һ�����
		scanf("%d", &choose);
		switch (choose)
		{
		case 1:
			add_student(&WLW); // ���ѧ��
			break;
		case 2:
			show_student(&WLW); // ��ʾѧ��
			break;
		case 3:
			find_student(&WLW); // ��ѯѧ��
			break;
		case 4:
			delete_student(&WLW); // ɾ��ѧ��
			break;
		case 5:
			change_student(&WLW); // �޸�ѧ��
			break;
		case 6:
			return 0; // �˳�����
		default:	  // ������������ţ�����ת���������
			printf("����������������룡\n");
			goto loop;
		}
	}
	return 0;
}