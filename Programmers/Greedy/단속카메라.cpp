#include <string>
#include <vector>
#include <algorithm>
using namespace std;

// 1. 구간들을 끝나는 지점을 기준으로 올림 정렬 한다.
// 2. 처리되지 않은 구간 중 첫 번째로 끝나는 구간을 선택 하고,
// 3. 이 구간의 끝나는 지점 보다 먼저 시작된 구간들은 제외 시킨다.
// 4. 반복한다.


int solution(vector<vector<int>> routes) 
{
	// 끝나는 지점 기준으로 올림 정렬.
	sort(routes.begin(), routes.end(), [](const auto & p1, const auto &p2)
	{
		return p1[1] < p2[1];
	});

	int answer = 0;

	
	for (auto i = 0; i < routes.size();)
	{
		answer++;

		// 단계 2.
		int end = routes[i][1];

		auto j = i+1;
		for (; j < routes.size(); ++j)		
		{
			// 단계 3.
			if (routes[j][0] > end)
				break;
		}

		i = j;
	}

	return answer;
}


int main()
{
	vector<vector<int>> routes = { {-20, 15}, {-14, -5}, {-18, -13}, {-5, -3} };
	int res = solution(routes);
}