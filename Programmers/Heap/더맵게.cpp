#include <string>
#include <vector>
#include <iostream>
#include <queue>
#include <functional>
using namespace std;

// 매운 것을 좋아하는 Leo는 모든 음식의 스코빌 지수를 K 이상으로 만들고 싶습니다. 
// 수식 : 섞은 음식의 스코빌 지수 = 가장 맵지 않은 음식의 스코빌 지수 + (두 번째로 맵지 않은 음식의 스코빌 지수 * 2)

// Leo가 가진 음식의 스코빌 지수를 담은 배열 scoville과 원하는 스코빌 지수 K가 주어질 때, 
// 모든 음식의 스코빌 지수를 K 이상으로 만들기 위해 섞어야 하는 최소 횟수를 return 하도록 solution 함수를 작성해주세요.

int solution(vector<int> scoville, int K) 
{
	// 올림 정렬
	std::priority_queue<int, std::vector<int>, std::greater<int>> q(scoville.begin(), scoville.end());
	int answer = 0;
	
	// 가장 낮은 값이 K 이상이 될 때까지 섞는다.
	while (q.top() < K && q.size() >= 2)
	{
		answer++;
		int s1 = q.top(); q.pop();
		int s2 = q.top(); q.pop();
		q.push(s1 + s2 * 2);		
	}

	// 더 이상 섞을 수가 없으면 -1 return
	if (q.top() < K && q.size() < 2)
		return -1;
	
	return answer;
}


int main()
{
	vector<int> data = { 1, 2, 3, 9, 10, 12 };

	cout << solution(data, 7) << endl;	
}