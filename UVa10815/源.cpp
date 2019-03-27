/*UVa156-Ananagrams*/
#include<iostream>
#include<string>
#include<map>
#include<algorithm>
using namespace std;
struct CHARACTER
{
	int letter_num[26];
	bool isSame;
	CHARACTER()
	{
		memset(letter_num, 0, sizeof(letter_num));
		isSame = false;
	}
	bool operator==(CHARACTER _Right)
	{
		bool flag = true;
		for (int i = 0; i < 26 && flag; i++)
		{
			if (letter_num[i] != _Right.letter_num[i])flag = false;
		}
		return flag;
	}
};
int main()
{
	map<string, CHARACTER>text;
	string s;
	CHARACTER *info = NULL;
	do
	{
		cin >> s;
		if (s != "#")
		{
			info = new CHARACTER;
			for (auto i = s.begin(); i != s.end(); i++)
			{
				if (*i>='A'&&*i<='Z')++info->letter_num[*i - 'A'];
				else if (*i >= 'a'&&*i <= 'z')++info->letter_num[*i - 'a'];
			}
			sort(info->letter_num, info->letter_num + 26);
			text[s] = *info;
			delete info;
			info = NULL;
		}
	} while (s != "#");
	for (auto i = text.begin(); i != text.end(); i++)
	{
		if (!i->second.isSame)
		{
			auto j = i;
			while (++j != text.end())
			{
				if (!j->second.isSame && i->second == j->second)
				{
					i->second.isSame = true; j->second.isSame = true;
				}
			}
		}
	}
	for (auto i = text.begin(); i != text.end(); i++)
	{
		if (!i->second.isSame)cout << i->first << ' ';
	}
	system("pause");
	return 0;
}