#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(int n, vector<int> lost, vector<int> reserve)
{
	vector<bool> found(n + 1, false);

	// �ƹ��� ���� ���� ���� ������ ��, ��� ���� n - lost.size()�̴�.
	int answer = n - static_cast<int>(lost.size());	

	// ���� ü������ ������ �л��� ���� ���� ���
	// �ڱ� �ڽſ��� �ش�. ��, �ٸ� �л����� ���� �� �� ����.
	for (auto it = reserve.begin(); it != reserve.end();)
	{
		if (find(lost.begin(), lost.end(), *it) != lost.end())
		{
			found[*it] = true;
			it = reserve.erase(it);

			// �ش� �л��� ���� ���� �����ϴ�.
			answer++;
		}
		else
			it++;
	}

	// ���� reserve���� ���������� �ʰ� ������ ���� ���� �л����� ��� �ִ�.
	// �ִ��� ���� �����ϱ� ���ؼ���:
	// (�̹� ���ĵǾ���) lost���� Ű�� ���� ������� ���� �ش�.
	for (int r : reserve)
	{
		// ������ ���� ������ �л� �տ� �ִ� �л��� ���� �Ҿ���ȴ��� üũ
		if (find(lost.begin(), lost.end(), r - 1) != lost.end() && found[r - 1] == false)
		{
			found[r - 1] = true;
			answer++;
		}

		// ������ ���� ������ �л� �ڿ� �ִ� �л��� ���� �Ҿ���ȴ��� üũ
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
