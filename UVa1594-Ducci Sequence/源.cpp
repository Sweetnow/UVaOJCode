/*UVa1594-Ducci Sequence*/
#include<iostream>
#include<vector>
#include<numeric>
using namespace std;
int main()
{
	int n, count = 0;
	bool flag = true;
	vector<int>ducci, tmp;
	ducci.reserve(15); tmp.reserve(15);
	while (cin >> n)ducci.push_back(n);
	do
	{
		++count;
		tmp.clear();
		flag = (bool)accumulate(ducci.begin(), ducci.end(), 0);
		for (unsigned i = 0; i < ducci.size(); i++)
		{
			if (i != ducci.size() - 1)tmp.push_back(abs(ducci[i] - ducci[i + 1]));
			else tmp.push_back(abs(ducci[i] - ducci[0]));
		}
		copy(tmp.begin(), tmp.end(), ducci.begin());
	} while (flag&&count<1000);
	if (!flag)cout << 0 << endl;
	else cout << "LOOP" << endl;
	system("pause");
	return 0;
}