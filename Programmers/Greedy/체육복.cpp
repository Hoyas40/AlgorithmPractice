#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(int n, vector<int> lost, vector<int> reserve)
{
	int answer = n - static_cast<int>(lost.size());
	vector<bool> found(n + 1, false);

	for (auto it = reserve.begin(); it != reserve.end();)
	{
		if (find(lost.begin(), lost.end(), *it) != lost.end())
		{
			found[*it] = true;
			it = reserve.erase(it);

			answer++;
		}
		else
			it++;
	}

	for (int r : reserve)
	{
		if (find(lost.begin(), lost.end(), r - 1) != lost.end() && found[r - 1] == false)
		{
			found[r - 1] = true;
			answer++;
		}

		else if (find(lost.begin(), lost.end(), r + 1) != lost.end() && found[r + 1] == false)
		{
			found[r + 1] = true;
			answer++;
		}
	}

	return answer;
}

int main()
{
	vector<int> lost{ 2,3,4 };
	vector<int> reserve{ 1,2,3};

	int ret = solution(5, lost, reserve);
	return 0;
}
