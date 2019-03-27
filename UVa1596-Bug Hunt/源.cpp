/*UVa1596-Bug Hunt*/
#include<iostream>
#include<map>
#include<string>
bool bug = false;
int exp10[] = { 1,10,100,1000,10000,100000,1000000 };
class Array
{
protected:
	int m_size;
	int *m_arr=NULL;
	bool *m_isInit=NULL;
public:
	Array() :m_size(0) {}
	Array(int size) :m_size(size)
	{
		m_arr = new int[m_size];
		memset(m_arr, 0, sizeof(int)*m_size);
		m_isInit = new bool[m_size];
		memset(m_isInit, false, sizeof(bool)*m_size);
	}
	Array(const Array &x) :m_size(x.m_size)
	{
		m_arr = new int[m_size];
		memcpy(m_arr, x.m_arr, sizeof(int)*m_size);
		m_isInit = new bool[m_size];
		memcpy(m_isInit, x.m_isInit, sizeof(bool)*m_size);
	}
	Array operator=(const Array &&x)
	{
		m_size = x.m_size;
		m_arr = new int[m_size];
		memcpy(m_arr, x.m_arr, sizeof(int)*m_size);
		m_isInit = new bool[m_size];
		memcpy(m_isInit, x.m_isInit, sizeof(bool)*m_size);
		return *this;
	}
	~Array()
	{
		if (m_arr != NULL)
		{
			delete[] this->m_isInit; 
			delete[] this->m_arr;
			m_isInit = NULL; m_arr = NULL;
		}
	}
	int size() { return m_size; }
	int operator[](int _pos)
	{
		if (_pos >= m_size || !m_isInit[_pos])
		{
			bug = true;
			return 0;
		}
		else return m_arr[_pos];
	}
	void Init(int _pos, int _value)
	{
		if (_pos >= m_size)
		{
			bug = true;
			return;
		}
		else
		{
			m_arr[_pos] = _value;
			m_isInit[_pos] = true;
			return;
		}
	}
};
int find_index(std::string), find_value(std::string);
std::map<std::string, Array>test;
int main()
{
	std::string s;
	int kase = 0;
	while (!bug && std::getline(std::cin, s) && s != "")
	{
		bool equal = false;
		size_t i = 0;
		++kase;
		for (; i < s.length() && !equal; i++)
		{
			if (s[i] == '=')equal = true;
		}
		if (equal)//a[index]=?
		{
			int value, index, _left = 0;
			--i;
			value = find_value(s.substr(i + 1));
			index = find_index(s.substr(0, i));
			while (s[_left] != '[')++_left;
			test[s.substr(0, _left)].Init(index, value);
		}
		else//a[size]
		{
			int _left = 0;
			while (s[_left] != '[')++_left;
			test[s.substr(0, _left)] = Array(find_index(s));
		}
	}
	if (bug)std::cout << "Bug at line" << kase << std::endl;
	else std::cout << "Well" << std::endl;
	system("pause");
	return 0;
}
int find_index(std::string text)
{
	int _left = 0, _right = text.length() - 1;
	while (text[_left] != '['&&_left < (int)text.length())++_left;
	while (text[_right] != ']'&&_right >= 0)--_right;
	if (_left == text.length() || _right == -1)
	{
		std::cout << "There is no []" << std::endl;
		system("pause");
		exit(1);
	}
	else
	{
		bool isNumber = true;
		int sum = 0, digit = 0;
		if (_left < _right)
		{
			for (int i = _right - 1; i > _left && isNumber; i--)//检查是否是数字，是则计算index，否则递归处理
			{
				if (text[i] >= '0'&&text[i] <= '9')sum += (text[i] - '0')*exp10[digit++];
				else isNumber = false;
			}
			if (isNumber)return sum;
			else
			{
				int _left2 = _left + 1;
				while (text[_left2] != '[')++_left2;
				return test[text.substr(_left + 1, _left2 - _left - 1)][find_index(text.substr(_left + 1, _right - _left - 1))];
			}
		}
		else
		{
			std::cout << "There is no []" << std::endl;
			system("pause");
			exit(1);
		}
	}
}
int find_value(std::string text)
{
	bool isNumber = true;
	int sum = 0, digit = 0;
	for (int i = text.length() - 1; i >= 0 && isNumber; i--)//检查是否是数字，是则计算index，否则递归处理
	{
		if (text[i] >= '0'&&text[i] <= '9')sum += (text[i] - '0')*exp10[digit++];
		else isNumber = false;
	}
	if (isNumber)return sum;
	else
	{
		int _left2 = 0;
		while (text[_left2] != '[')++_left2;
		return test[text.substr(0, _left2)][find_index(text)];
	}
}