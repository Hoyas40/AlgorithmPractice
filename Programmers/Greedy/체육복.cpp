#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(int n, vector<int> lost, vector<int> reserve)
{
	vector<bool> found(n + 1, false);

	// 아무도 빌려 주지 않은 상태일 때, 출발 값은 n - lost.size()이다.
	int answer = n - static_cast<int>(lost.size());	

	// 여벌 체육복을 가져온 학생이 도난 당한 경우
	// 자기 자신에게 준다. 즉, 다른 학생에게 빌려 줄 수 없다.
	for (auto it = reserve.begin(); it != reserve.end();)
	{
		if (find(lost.begin(), lost.end(), *it) != lost.end())
		{
			found[*it] = true;
			it = reserve.erase(it);

			// 해당 학생은 수업 참여 가능하다.
			answer++;
		}
		else
			it++;
	}

	// 이제 reserve에는 도난당하지 않고 여분의 옷을 가진 학생들이 들어 있다.
	// 최대한 많이 참석하기 위해서는:
	// (이미 정렬되어진) lost들을 키가 작은 순서대로 빌려 준다.
	for (int r : reserve)
	{
		// 여분의 옷을 가져온 학생 앞에 있는 학생이 옷을 잃어버렸는지 체크
		if (find(lost.begin(), lost.end(), r - 1) != lost.end() && found[r - 1] == false)
		{
			found[r - 1] = true;
			answer++;
		}

		// 여분의 옷을 가져온 학생 뒤에 있는 학생이 옷을 잃어버렸는지 체크
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
	vector<int> lost{ 2, 3, 4 };
	vector<int> reserve{ 1, 2, 4 };

	int ret = solution(5, lost, reserve);

	return 0;
}
