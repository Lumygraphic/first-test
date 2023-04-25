#include<cstdio>
#include<cmath>
#include<algorithm>
#include<stack>
#include<iostream>
#include<iomanip>
#include<cstring>
#include <unordered_map>//无序 map 容器

using namespace std;

const double PI = atan(1.0) * 4;

static int cunt1 = 0, cunt2 = 0;//计数

void judge1(int n)//蛮力法
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
			cunt_judge++;//基本操作
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
	cout << n << "中质数共" << cunt1 << "个" << endl;
	cout << "蛮力法基本操作执行" << cunt_judge << "次" << endl;
}

void judge2(int n)//埃氏筛法
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
				cunt_judge++;//基本操作
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
	cout << n << "中质数共" << cunt2 << "个" << endl;
	cout << "埃氏筛法基本操作执行" << cunt_judge << "次" << endl;
}

int main()
{
	judge1(25);
	judge2(25);
	return 0;
}