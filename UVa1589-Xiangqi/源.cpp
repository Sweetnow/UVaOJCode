/*UVa1589-Xiangqi*/
#include<iostream>
using namespace std;
enum CHESSMAN { _none, _horse, _chariot, _cannon, _redGeneral, _blackGeneral };//chariot³µ£¬cannonÅÚ
CHESSMAN chessboard[10][9];
class CChessman
{
public:
	int m_row;
	int m_column;
	CHESSMAN m_kind;
	CChessman() {};
	CChessman(int row, int column, CHESSMAN kind) :m_row(row), m_column(column), m_kind(kind) {};
	CChessman(int row, int column) :m_row(row), m_column(column), m_kind(_blackGeneral) {};
	bool isAttacked(CChessman);
};
int main()
{
	int n, row, column, kind, movedRow, movedColumn;
	bool isCheckmate[4];
	CChessman *red, black, movedBlack;
	memset(chessboard, _none, sizeof(chessboard));
	memset(isCheckmate, 0, sizeof(isCheckmate));
	cin >> n;
	red = new CChessman[n];
	cout << "Red general? row, column, kind:";
	cin >> row >> column;
	chessboard[row][column] = _redGeneral;
	red[0] = CChessman(row, column, _redGeneral);
	cout << "Black general? row, column, kind:";
	cin >> row >> column;
	chessboard[row][column] = _blackGeneral;
	black = CChessman(row, column);
	for (int i = 1; i < n; i++)
	{
		cout << "The No." << i << "chessman? row, column, kind:";
		cin >> row >> column >> kind;
		switch (kind)
		{
		case 1:
			chessboard[row][column] = _horse;
			red[i] = CChessman(row, column, _horse);
			break;
		case 2:
			chessboard[row][column] = _chariot;
			red[i] = CChessman(row, column, _chariot);
			break;
		case 3:
			chessboard[row][column] = _cannon;
			red[i] = CChessman(row, column, _cannon);
			break;
		}
	}
	//case 0
	movedRow = black.m_row + 1; movedColumn = black.m_column;
	if (movedRow >= 1 && movedRow <= 3 && movedColumn >= 4 && movedColumn <= 6)
	{
		bool flag = false;
		movedBlack = CChessman(movedRow, movedColumn);
		for (int i = 0; i < n && !flag; i++)
		{
			if (red[i].isAttacked(movedBlack))flag = true;
		}
		isCheckmate[0] = flag;
	}
	else isCheckmate[0] = true;
	//case 1
	movedRow = black.m_row - 1; movedColumn = black.m_column;
	if (movedRow >= 1 && movedRow <= 3 && movedColumn >= 4 && movedColumn <= 6)
	{
		bool flag = false;
		movedBlack = CChessman(movedRow, movedColumn);
		for (int i = 0; i < n && !flag; i++)
		{
			if (red[i].isAttacked(movedBlack))flag = true;
		}
		isCheckmate[1] = flag;
	}
	else isCheckmate[1] = true;
	//case 2
	movedRow = black.m_row; movedColumn = black.m_column + 1;
	if (movedRow >= 1 && movedRow <= 3 && movedColumn >= 4 && movedColumn <= 6)
	{
		bool flag = false;
		movedBlack = CChessman(movedRow, movedColumn);
		for (int i = 0; i < n && !flag; i++)
		{
			if (red[i].isAttacked(movedBlack))flag = true;
		}
		isCheckmate[2] = flag;
	}
	else isCheckmate[2] = true;
	//case 3
	movedRow = black.m_row; movedColumn = black.m_column - 1;
	if (movedRow >= 1 && movedRow <= 3 && movedColumn >= 4 && movedColumn <= 6)
	{
		bool flag = false;
		movedBlack = CChessman(movedRow, movedColumn);
		for (int i = 0; i < n && !flag; i++)
		{
			if (red[i].isAttacked(movedBlack))flag = true;
		}
		isCheckmate[3] = flag;
	}
	else isCheckmate[3] = true;
	bool result = true;
	for (int i = 0; i < 3; i++)
	{
		result = result && isCheckmate[i];
	}
	cout << (result ? "KILL" : "SURVIVE") << endl;
	delete[]red;
	system("pause");
	return 0;
}
bool CChessman::isAttacked(CChessman blackGeneral)
{
	int rowGap = m_row - blackGeneral.m_row, columnGap = m_column - blackGeneral.m_column;
	bool flag = true;
	int cannonFlag = 0;
	switch (m_kind)
	{
	case _horse:
		if (abs(rowGap) == 1 && columnGap == 2 && chessboard[m_row][m_column - 1] == _none)return true;
		else if (abs(rowGap) == 1 && columnGap == -2 && chessboard[m_row][m_column + 1] == _none)return true;
		else if (abs(columnGap) == 1 && rowGap == 2 && chessboard[m_row - 1][m_column] == _none)return true;
		else if (abs(columnGap) == 1 && rowGap == -2 && chessboard[m_row + 1][m_column] == _none)return true;
		else return false;
		break;
	case _chariot:
		if (m_row == blackGeneral.m_row)
		{
			if (m_column == blackGeneral.m_column)return false;
			else if (m_column > blackGeneral.m_column)
			{
				for (int i = blackGeneral.m_column + 1; i < m_column && flag; i++)if (chessboard[m_row][i] != _none)flag = false;
			}
			else
			{
				for (int i = blackGeneral.m_column - 1; i > m_column && flag; i--)if (chessboard[m_row][i] != _none)flag = false;
			}
			return flag;
		}
		else if (m_column == blackGeneral.m_column)
		{
			if (m_row == blackGeneral.m_row)return false;
			else if (m_row > blackGeneral.m_row)
			{
				for (int i = blackGeneral.m_row + 1; i < m_row && flag; i++)if (chessboard[i][m_column] != _none)flag = false;
			}
			else
			{
				for (int i = blackGeneral.m_row - 1; i > m_row && flag; i--)if (chessboard[i][m_column] != _none)flag = false;
			}
			return flag;
		}
		else return false;
		break;
	case _cannon:
		if (m_row == blackGeneral.m_row)
		{
			if (m_column > blackGeneral.m_column)
			{
				for (int i = blackGeneral.m_column + 1; i < m_column; i++)if (chessboard[m_row][i] != _none)++cannonFlag;
			}
			else
			{
				for (int i = blackGeneral.m_column - 1; i > m_column; i--)if (chessboard[m_row][i] != _none)++cannonFlag;
			}
		}
		else if (m_column == blackGeneral.m_column)
		{
			if (m_row > blackGeneral.m_row)
			{
				for (int i = blackGeneral.m_row + 1; i < m_row; i++)if (chessboard[i][m_column] != _none)++cannonFlag;
			}
			else
			{
				for (int i = blackGeneral.m_row - 1; i > m_row; i--)if (chessboard[i][m_column] != _none)++cannonFlag;
			}
		}
		else return false;
		if (cannonFlag == 1)return true;
		else return false;
		break;
	case _redGeneral:
		if (m_column == blackGeneral.m_column)
		{
			if (m_row > blackGeneral.m_row)
			{
				for (int i = blackGeneral.m_row + 1; i < m_row && flag; i++)if (chessboard[i][m_column] != _none)flag = false;
			}
			else
			{
				for (int i = blackGeneral.m_row - 1; i > m_row && flag; i--)if (chessboard[i][m_column] != _none)flag = false;
			}
			return flag;
		}
		else return false;
		break;
	}
	return false;
}