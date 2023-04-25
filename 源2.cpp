#include<cstdio>
#include<cmath>
#include<algorithm>
#include<stack>
#include<iostream>
#include<iomanip>
#include<cstring>
#include <unordered_map>//���� map ����

using namespace std;

const double PI = atan(1.0) * 4;

static int cunt1 = 0, cunt2 = 0;//����

void judge1(int n)//������
{
	int cunt_judge = 0;
	if (n >= 2)
	{
		cunt1 += 1;
		cout << 2 << endl;
	}
	
	for (int i = 3; i <= n; i++)
	{
		int flag = 1;
		for (int j = 2; j*j <= i; j++)
		{
			cunt_judge++;//��������
			if (i % j == 0)
			{
				flag = 0;
			}
		}
		if (flag)
		{
			cout << i << endl;
			cunt1++;
		}
	}
	cout << n << "��������" << cunt1 << "��" << endl;
	cout << "��������������ִ��" << cunt_judge << "��" << endl;
}

void judge2(int n)//����ɸ��
{
	bool num[100];
	int cunt_judge = 0;
	for (int i = 0; i < n; i++)
	{
		num[i] = 1;
	}
	num[0] = num[1] = 0;
	for (int i = 2; i < n; i++)
	{
		if (num[i])
		{
			for (int j = i + i; j < n; j += i)
			{
				cunt_judge++;//��������
				num[j] = 0;
			}
		}
	}
	for (int i = 0; i < n; i++)
	{
		if (num[i])
		{
			cunt2++;
			cout << i << endl;
		}
	}
	cout << n << "��������" << cunt2 << "��" << endl;
	cout << "����ɸ����������ִ��" << cunt_judge << "��" << endl;
}

int main()
{
	judge1(25);
	judge2(25);
	return 0;
}