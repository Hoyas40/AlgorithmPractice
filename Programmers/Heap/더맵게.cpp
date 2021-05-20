#include <string>
#include <vector>
#include <iostream>
#include <queue>
#include <functional>
using namespace std;

// �ſ� ���� �����ϴ� Leo�� ��� ������ ���ں� ������ K �̻����� ����� �ͽ��ϴ�. 
// ���� : ���� ������ ���ں� ���� = ���� ���� ���� ������ ���ں� ���� + (�� ��°�� ���� ���� ������ ���ں� ���� * 2)

// Leo�� ���� ������ ���ں� ������ ���� �迭 scoville�� ���ϴ� ���ں� ���� K�� �־��� ��, 
// ��� ������ ���ں� ������ K �̻����� ����� ���� ����� �ϴ� �ּ� Ƚ���� return �ϵ��� solution �Լ��� �ۼ����ּ���.

int solution(vector<int> scoville, int K) 
{
	// �ø� ����
	std::priority_queue<int, std::vector<int>, std::greater<int>> q(scoville.begin(), scoville.end());
	int answer = 0;
	
	// ���� ���� ���� K �̻��� �� ������ ���´�.
	while (q.top() < K && q.size() >= 2)
	{
		answer++;
		int s1 = q.top(); q.pop();
		int s2 = q.top(); q.pop();
		q.push(s1 + s2 * 2);		
	}

	// �� �̻� ���� ���� ������ -1 return
	if (q.top() < K && q.size() < 2)
		return -1;
	
	return answer;
}


int main()
{
	vector<int> data = { 1, 2, 3, 9, 10, 12 };

	cout << solution(data, 7) << endl;	
}