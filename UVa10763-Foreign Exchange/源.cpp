/*UVa10763 - Foreign Exchange*/
#include<iostream>
const int max_school = 1003;
using namespace std;
int icount[max_school][max_school];
int main()
{
	int n, a, b;
	bool flag = true;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> a >> b;
		if (a > b)icount[a][b]++;
		else if (a == b)cout << "ERROR" << endl;
		else icount[b][a]--;
	}
	for (int a = 0; a < max_school&&flag; a++)
	{
		for (int b = 0; b < a&&flag; b++)
		{
			if (icount[a][b] != 0)flag = false;
		}
	}
	cout << (flag ? "OK" : "NO") << endl;
	system("pause");
	return 0;
}