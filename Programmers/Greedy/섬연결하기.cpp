#include <string>
#include <vector>
#include <algorithm>
using namespace std;

// ���� ������ ���� �ٸ� group�̶�� ���� �Ѵ�.
// �� �� ���̰� ���� ª�� ������ ���� �ϸ�, ���� �� ������ ���� �׷����� assign �ȴ�.
// ������ ���� �� ��, �翬�� ���� �ٸ� group�鸸 ���� �ǵ��� �Ѵ�.


// group ID ã��
// group�� tree �����̹Ƿ�, root �� group ID �� �ȴ�.
int getRoot(vector<int> & parents, int id)
{
	int tmp = id;
	while (parents[tmp] != -1)
	{
		tmp = parents[tmp];
	}
	if (id != tmp)
		parents[id] = tmp;

	return tmp;
}

int solution(int n, vector<vector<int>> costs) 
{
	vector<int> parents(n, -1);

	// �Ÿ��� �������� ���� ����
	sort(costs.begin(), costs.end(), [](const auto & p1, const auto & p2)
	{
		return p1[2] < p2[2];
	});

	int answer = 0;

	for (const auto & cost : costs)
	{
		int root1 = getRoot(parents, cost[0]);
		int root2 = getRoot(parents, cost[1]);

		// �׷� id �� �ٸ� ��쿡�� �����Ѵ�.
		if (root1 != root2)
		{
			answer += cost[2];

			// �׷� ID �� 2�� �߿� ���� ����, ID �� ���� ���� parent �� �Ѵ�.
			if (root1 < root2)
				parents[root2] = root1;
			else
				parents[root1] = root2;
		}
	}	

	return answer;
}


int main()
{
	vector<vector<int>> costs = { {0,1,1}, {0,2,2}, {1, 2, 5}, {1,3,1}, {2,3,8} };

	int res = solution(5, costs);
}