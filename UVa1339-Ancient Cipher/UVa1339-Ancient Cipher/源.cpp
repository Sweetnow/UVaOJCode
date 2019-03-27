/* UVa1339-Ancient Cipher */
/* ������������һ���Ҳ�����100���ַ������ж��Ƿ��ܰ�����һ���ַ����ĸ�����ĸ���ţ�֮���26����ĸ��һ��һһӳ�䣬ʹ�������ַ�����ͬ
���磬JWPUDJSTVP���ź���Եõ�WJDUPSJPVT��֮���ÿ����ĸӳ�䵽����ǰ��һ����ĸ���õ�VICTORIOUS�����������ַ��������YES����NO */
#include<iostream>
#include<algorithm>
const int MAX_LENGTH = 105;
int cmp(const void *a, const void *b)
{
	return *(int *)a - *(int *)b;
}
int main()
{
	char cTextA[MAX_LENGTH], cTextB[MAX_LENGTH];
	int iCountTextA[26], iCountTextB[26];
	int iLenTextA, iLenTextB;
	memset(cTextA, 0, sizeof(cTextA));
	memset(cTextB, 0, sizeof(cTextB));
	memset(iCountTextA, 0, sizeof(iCountTextA));
	memset(iCountTextB, 0, sizeof(iCountTextB));
	std::cout << "String 1:";
	std::cin >> cTextA;
	std::cout << "String 2:";
	std::cin >> cTextB;
	iLenTextA = strlen(cTextA);
	iLenTextB = strlen(cTextB);
	if (iLenTextA == iLenTextB)
	{
		bool flag = true;
		for (int i = 0; i < iLenTextA; i++)++iCountTextA[cTextA[i] - 'A'];
		for (int i = 0; i < iLenTextB; i++)++iCountTextB[cTextB[i] - 'A'];
		std::sort(iCountTextA, iCountTextA + 26);
		std::sort(iCountTextB, iCountTextB + 26);
		for (int i = 0; i < 26 && flag; i++)
		{
			if (iCountTextA[i] != iCountTextB[i])
				flag = false;
		}
		std::cout << (flag ? "YES" : "NO") << std::endl;
	}
	else std::cout << "ERROR!" << std::endl;
	system("pause");
	return 0;
}