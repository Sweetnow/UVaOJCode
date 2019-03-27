/*UVa1590-IP Networks*/
/*输入num个ipv4地址，输出最小网络地址和子网掩码*/
#include<iostream>
#pragma warning(disable:4996)
using namespace std;
const int num = 3;
union IP
{
	struct { unsigned __int8 a4, a3, a2, a1; }part;//x86小端对齐
	unsigned __int32 ip;
};
int main()
{
	int a1, a2, a3, a4, digit = 0;
	IP input[num], host, mask;
	mask.ip = 0xffffffff;
	bool flag;
	for (int i = 0; i < num; i++)
	{
		scanf("%d.%d.%d.%d", &a1, &a2, &a3, &a4);
		input[i].part.a1 = (unsigned __int8)a1;
		input[i].part.a2 = (unsigned __int8)a2;
		input[i].part.a3 = (unsigned __int8)a3;
		input[i].part.a4 = (unsigned __int8)a4;
	}
	do
	{
		flag = false;
		int tmp = input[0].ip >> digit;
		for (int i = 1; i < num; i++)
		{
			if (input[i].ip >> digit != tmp)flag = true;
		}
		++digit;
	} while (flag);
	--digit;
	host.ip = input[0].ip >> digit << digit;
	mask.ip = mask.ip >> digit << digit;
	cout << (int)host.part.a1 << '.' << (int)host.part.a2 << '.' << (int)host.part.a3 << '.' << (int)host.part.a4 << endl;
	cout << (int)mask.part.a1 << '.' << (int)mask.part.a2 << '.' << (int)mask.part.a3 << '.' << (int)mask.part.a4 << endl;
	system("pause");
	return 0;
}