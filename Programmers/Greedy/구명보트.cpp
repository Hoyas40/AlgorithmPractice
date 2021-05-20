#include <string>
#include <vector>
#include <algorithm>
#include <functional>
using namespace std;

// �պ� ���ڸ� �ִ��� ���̷���
//  limit ���� ���� �� load �� ū ������� ���� ��, �� �������� �ݴ�� limit �� ���� load �� ���� ������� ������ �ȴ�.
// �� : 60, 50, 50, 40 �� limit �� 100 �� ��� 2 ���� ���� �� �ִ�.
int solution(vector<int> people, int limit) 
{
	// ���� �� ����
	std::sort(people.begin(), people.end(), greater<>());

	int answer = 0;

	// start �� vector[0]�� ����Ŵ
	// end �� vector[N-1]�� ����Ŵ
	auto start = people.begin();
	auto end = people.end() - 1;	
	
	while (start <= end)
	{
		int load = limit;

		// ���� load�� ū �� �ƴ´�.
		while (start <= end && *start <= load )
		{
			load = load - *start;
			start++;
		}
		// �� �� load�� ���� �� �ƴ´�.
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