/*UVa679-Dropping Balls*/
#include<iostream>
using std::cin;
using std::cout;
using std::endl;
int main()
{
	int depth, number, l, ball;
	bool *swi;
	cin >> depth >> l;
	number = pow(2, depth);
	swi = new bool[number];
	memset(swi, false, number);
	for (int i = 0; i < l; i++)
	{
		ball = 1;
		do
		{
			if (!swi[ball])
			{
				swi[ball] = !swi[ball];
				ball = 2 * ball;
			}
			else
			{
				swi[ball] = !swi[ball];
				ball = 2 * ball + 1;
			}
		} while (ball < number / 2);
	}
	cout << ball << endl;
	delete[] swi;
	swi = NULL;
	system("pause");
	return 0;
}