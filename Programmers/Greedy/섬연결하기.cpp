#include <string>
#include <vector>
#include <algorithm>
using namespace std;

// 먼저 섬들을 각각 다른 group이라고 가정 한다.
// 이 후 길이가 가장 짧은 섬들을 연결 하며, 연결 한 섬들은 같은 그룹으로 assign 된다.
// 섬들을 연결 할 때, 당연히 서로 다른 group들만 연결 되도록 한다.


// group ID 찾기
// group은 tree 구조이므로, root 가 group ID 가 된다.
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

	// 거리를 기준으로 내림 정렬
	sort(costs.begin(), costs.end(), [](const auto & p1, const auto & p2)
	{
		return p1[2] < p2[2];
	});

	int answer = 0;

	for (const auto & cost : costs)
	{
		int root1 = getRoot(parents, cost[0]);
		int root2 = getRoot(parents, cost[1]);

		// 그룹 id 가 다른 경우에만 연결한다.
		if (root1 != root2)
		{
			answer += cost[2];

			// 그룹 ID 를 2개 중에 고르기 위해, ID 가 작은 것을 parent 로 한다.
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