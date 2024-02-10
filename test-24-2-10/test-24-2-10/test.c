#define _CRT_SECURE_NO_WARNINGS

#include<stdio.h>
#include<string.h>

struct User
{
	char accountnumber[20];
	char password[20];

};

struct Connact
{
	struct User user[1000];
	int size;
};

void menu()
{
	printf("******************************\n");
	printf("*********    menu    *********\n");
	printf("*********  1.log in  *********\n");
	printf("********* 2.register *********\n");
	printf("*********   0.exit   *********\n");
	printf("******************************\n");
}

void Initconnact(struct Connact* ps)
{
	memset(ps->user, 0, sizeof(ps->user));
	ps->size = 0;
}

void Login(struct Connact* ps)
{
	int i = 0;
	int a = 0;
	char useraccountnumber[20];
	char userpassword[20];
	printf("请输入您的账号=>\n");
	scanf("%s", &useraccountnumber);
	printf("请输入您的密码=>\n");
	scanf("%s", &userpassword);
	for (i = 0; i < (ps->size); i++)
	{
		if (strcmp(useraccountnumber, ps->user[i].accountnumber) == 0 && strcmp(userpassword, ps->user[i].password) == 0)
		{
			a++;
		}
	}
	if (a == 0)
	{
		printf("登录失败\n");
	}
	else
	{
		printf("登录成功\n");
	}
}

void Register(struct Connact* ps)
{
	printf("请输入您想要注册的账号=>\n");
	scanf("%s", ps->user[ps->size].accountnumber);
	printf("请输入您想要注册的密码=>\n");
	scanf("%s", ps->user[ps->size].password);
	ps->size++;
}

int main()
{
	int input = 1;
	struct User user[1000];
	struct Connact connact;
	Initconnact(&connact);
	do
	{
		menu();
		scanf("%d", &input);
		switch (input)
		{
			case 1:
			{
				Login(&connact);
				break;
			}
			case 2:
			{
				Register(&connact);
				break;
			}
			case 0:
			{
				printf("正在退出\n");
				break;
			}
			default:
			{
				printf("输入错误，请重新输入\n");
				break;
			}
		}
	} while (input);
	return 0;
}
