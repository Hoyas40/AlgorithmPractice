#include <string>
#include <vector>

using namespace std;

// ū ���� �������, number[i] < number[i+1] �� i �� �ݺ��ؼ� ���� �� ������ �ָ� �ȴ�.
// �ش� solution �� O(N^2) �ε�, O(N) �� ���� �� ������ ���δ�.
string solution(string number, int k)
{
    string answer = number;
    for (int i = 0; i < k; ++i)
    {
        int pos = -1;
        for (auto j = 0; j < static_cast<int>(answer.size()) - 1; ++j)
        {
            if (answer[j] < answer[j + 1])
            {
                pos = j;
                break;
            }
        }

		// number[i] < number[i+1] �� ���� ���, ���������� ���ĵ� ����̹Ƿ�, ������ ���� ����
        if (pos == -1)
            answer.pop_back();
        else
            answer = answer.erase(pos, 1);
    }

    return answer;
}
