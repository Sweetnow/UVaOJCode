/*UVa1593-Alignment of Code*/
#include<iostream>
#include<string>
#include<vector>
#include<iomanip>
using namespace std;
int main()
{
	size_t num_of_line, tmp_max_word = 0;
	string s;
	vector<vector<string>>text;
	vector<int>max_word_width;
	text.reserve(10);
	max_word_width.reserve(10);
	//输入
	while (getline(cin, s) && s != "")
	{
		int len = s.length(), left, right = 0, i = right;
		bool flag = true;
		vector<string>line;
		line.reserve(10);
		do
		{
			while (i < len && s[i] == ' ')++i;
			left = i;
			while (i < len && s[i] != ' ')++i;
			right = i;
			if (left == len)flag = false;//处理到字符串尾
			else
			{
				if (right == len)flag = false;
				line.push_back(s.substr(left, right - left));
			}
		} while (flag);
		text.push_back(line);
	}
	//获取格式输出信息
	num_of_line = text.size();
	for (size_t i = 0; i < num_of_line; i++)
	{
		if (text[i].size() > tmp_max_word)tmp_max_word = text[i].size();
	}
	for (size_t i = 0; i < tmp_max_word; i++)
	{
		size_t max_width = 0;
		for (size_t line = 0; line < num_of_line; line++)
		{
			if (i<text[line].size() && text[line][i].length()>max_width)max_width = text[line][i].length();
		}
		max_word_width.push_back(max_width);
	}
	//格式输出
	for (size_t line = 0; line < num_of_line; line++)
	{
		for (size_t i = 0; i < text[line].size(); i++)
		{
			if (i == 0)cout << left << setw(max_word_width[i]) << text[line][i];
			else cout << ' ' << left << setw(max_word_width[i]) << text[line][i];
		}
		cout << endl;
	}
	system("pause");
	return 0;
}