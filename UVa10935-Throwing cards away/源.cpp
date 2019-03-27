#include<iostream>
#include<deque>
#include<algorithm>
using namespace std;

int main()
{
	deque<int>cardheap;
	int n;
	cin >> n;
	for (int i = 0; i < n; i++)cardheap.push_back(i + 1);
	while (cardheap.size() >= 2U)
	{
		cout << cardheap.front() << endl;
		cardheap.pop_front();
		cardheap.push_back(cardheap.front());
		cardheap.pop_front();
	}
	for_each(cardheap.begin(), cardheap.end(), [](int x)->void {cout << x << endl; });
	system("pause");
	return 0;
}