/*UVa1595-Symmetry*/
#include<iostream>
#include<algorithm>
using namespace std;
int iCount = 0;
const int MAX = 1000;
struct POINT
{
	double x;
	double y;
	bool operator<(const POINT &_Right)const
	{
		if (x < _Right.x)return true;
		else if (x == _Right.x&&y < _Right.y)return true;
		else return false;
	}
	bool operator==(const POINT &_Right)const
	{
		if (abs(x - _Right.x) <= 0.00000001&&abs(y - _Right.y) <= 0.00000001)return true;
		else return false;
	}
	bool operator!=(const POINT &_Right)const
	{
		return !(*this == _Right);
	}
}a[MAX], a_sym[MAX], point_sym(const POINT &,double);
int main()
{
	double x, y, axis_sym;
	bool flag = true;
	//输入
	while (cin >> x >> y)
	{
		a[iCount].x = x; a[iCount].y = y;
		++iCount;	
	}
	sort(a, a + iCount);
	//处理
	axis_sym = (a[0].x + a[iCount - 1].x) / 2;
	for (int i = 0; i < iCount; i++)
	{
		a_sym[i] = point_sym(a[i], axis_sym);
	}
	sort(a_sym, a_sym + iCount);
	for (int i = 0; i < iCount&&flag; i++)
	{
		if (a[i] != a_sym[i])flag = false;
	}
	//输出
	if (flag)cout << "The symmetrical axis is x=" << axis_sym << '.' << endl;
	else cout << "No symmetrical axis." << endl;
	system("pause");
	return 0;
}
POINT point_sym(const POINT &p,double axis_sym)
{
	POINT p_sym;
	p_sym.y = p.y;
	p_sym.x = 2 * axis_sym - p.x;
	return p_sym;
}