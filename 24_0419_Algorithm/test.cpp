#include<iostream>
#include<vector>
#include<queue>
#include<utility>
using namespace std;

class Solution
{
	int m, n;
	int dx[4] = { 0,0,1,-1 };
	int dy[4] = { 1,-1,0,0 };
	bool vis[1010][1010] = { 0 };

public:
	int rotApple(vector<vector<int>>& grid)
	{
		m = grid.size(), n = grid[0].size();
		//1�����ȱ��������ҵ����е�Դ�ڵ㣬����Դ�ڵ�������
		queue<pair<int, int>> q;
		for (int i = 0; i < m; i++)
		{
			for (int j = 0; j < n; j++)
			{
				if (grid[i][j] == 2)
				{
					q.push({ i,j });
				}
			}
		}
		//2����Դ�ڵ㿪ʼBFS,���Ҷ��Ѿ�̽�����Ľ��б��
		int ret = 0;
		while (q.size())
		{
			ret++;
			int sz = q.size();
			//����൱����һ��
			while (sz--)
			{
				int a = q.front().first; int b = q.front().second;
				q.pop();
				for (int i = 0; i < 4; i++)
				{
					int x = a + dx[i], y = b + dy[i];
					//������̽��
					if (x >= 0 && x < m && y >= 0 && y < n && grid[x][y] == 1 && vis[x][y] == false)
					{
						vis[x][y] = true;
						//�ѵڶ�����������
						q.push({ x,y });
					}
				}
			}
		}

		//3��ѭ������֮�󣬽����ж��Ƿ���û�б�ǣ�ͬʱ����1������
		for (int i = 0; i < m; i++)
		{
			for (int j = 0; j < n; j++)
			{
				if (grid[i][j] == 1 && vis[i][j] == false)
				{
					return -1;
				}
			}
		}
		return ret - 1;
	}
};

int main()
{
	vector<vector<int>> grid;
	grid.push_back({ 2,1,1 });
	grid.push_back({ 1,0,1 });
	grid.push_back({ 1,1,1 });

	Solution s1;
	cout << s1.rotApple(grid);
	return 0;
}