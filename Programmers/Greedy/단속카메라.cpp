#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int solution(vector<vector<int>> routes) 
{
	sort(routes.begin(), routes.end(), [](const auto & p1, const auto &p2)
	{
		return p1[1] < p2[1];
	});


	int answer = 0;

	for (auto i = 0; i < routes.size();)
	{
		answer++;
		int end = routes[i][1];

		auto j = i+1;
		for (; j < routes.size(); ++j)
		{
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