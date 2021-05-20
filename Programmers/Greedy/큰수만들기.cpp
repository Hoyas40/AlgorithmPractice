#include <string>
#include <vector>

using namespace std;

// 큰 수를 만드려면, number[i] < number[i+1] 인 i 를 반복해서 여러 번 삭제해 주면 된다.
// 해당 solution 은 O(N^2) 인데, O(N) 도 가능 할 것으로 보인다.
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

		// number[i] < number[i+1] 이 없는 경우, 내림순으로 정렬된 경우이므로, 마지막 숫자 제거
        if (pos == -1)
            answer.pop_back();
        else
            answer = answer.erase(pos, 1);
    }

    return answer;
}
