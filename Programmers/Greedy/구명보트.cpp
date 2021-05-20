#include <string>
#include <vector>
#include <algorithm>
#include <functional>
using namespace std;

// 왕복 숫자를 최대한 줄이려면
//  limit 보다 작은 한 load 가 큰 순서대로 실은 후, 그 다음에는 반대로 limit 를 까지 load 가 작은 순서대로 실으면 된다.
// 예 : 60, 50, 50, 40 을 limit 가 100 인 경우 2 번에 끝낼 수 있다.
int solution(vector<int> people, int limit) 
{
	// 내림 순 정렬
	std::sort(people.begin(), people.end(), greater<>());

	int answer = 0;

	// start 는 vector[0]을 가리킴
	// end 는 vector[N-1]을 가리킴
	auto start = people.begin();
	auto end = people.end() - 1;	
	
	while (start <= end)
	{
		int load = limit;

		// 먼저 load가 큰 걸 싣는다.
		while (start <= end && *start <= load )
		{
			load = load - *start;
			start++;
		}
		// 이 후 load가 작은 걸 싣는다.
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