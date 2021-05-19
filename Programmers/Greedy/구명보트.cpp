#include <string>
#include <vector>
#include <algorithm>
#include <functional>
using namespace std;

int solution(vector<int> people, int limit) 
{
	std::sort(people.begin(), people.end(), greater<>());

	const int N = static_cast<int>(people.size());
	std::vector<bool> checked(N, false);
	int answer = 0;

	auto start = people.begin();
	auto end = people.end() - 1;
	
	
	while (start <= end)
	{
		int load = limit;

		while (start <= end && *start <= load )
		{
			load = load - *start;
			start++;
		}
		while (start <= end && *end <= load)
		{
			load = load - *end;
			end--;
		}
		answer++;
	}
	
	return answer;
}

int main()
{
	vector<int> people{ 70, 80, 50 };

	int res = solution(people, 100);
}