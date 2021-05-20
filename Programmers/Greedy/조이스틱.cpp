// Greedy.cpp : Defines the entry point for the console application.
//

#include <string>
#include <vector>
#include <iterator>
#include <algorithm>
using namespace std;

pair<int, int> findNextPosition(int pos, const vector<int>& row)
{
    if (row[pos] != 0)
        return pair<int, int>(pos, 0);

    const int N = static_cast<int>(row.size());

    // left direction
    int posLeft = pos;
    int costLeft = 0;
    while (row[posLeft] == 0)
    {
        if (posLeft > 0)
            posLeft--;
        else
            posLeft = N - 1;

        costLeft++;

		// 값이 모두 0 인 경우, 모든 문자열을 변경하였다.
        if (posLeft == pos)
            return pair<int, int>(-1, 0);
    }

    // right direction
    int posRight = pos;
    int costRight = 0;
    while (row[posRight] == 0)
    {
        if (posRight < N - 1)
            posRight++;
        else
            posRight = 0;

        costRight++;
    }

	// 두 방향 중 더 적은 수로 움직일 수 있는 방향을 return 한다.
    if (costLeft < costRight)
        return pair<int, int>(posLeft, costLeft);
    else
        return pair<int, int>(posRight, costRight);
}

int solution(string name)
{
	// row 는 문자들이 A 에서 해당 문자들로 바꾸기 위한 step 수가 담겨 있다.
	// 예 : "BAC" 의 경우 row = {1, 0, 2};
    std::vector<int> row;
    row.reserve(name.size());

    std::transform(name.cbegin(), name.cend(), back_inserter(row),
        [](unsigned char c) -> int {return std::min(c - 'A', 'Z' - c + 1); }
    );

	// 계산 중인 위치
    int pos = 0;
    int answer = 0;

    while (true)
    {
		// 현재 위치에서 다음 위치( left or right) 의 위치와 그 위치로 이동하기 위한 입력 갯수를 반환한다.
        pair<int, int> res = findNextPosition(pos, row);
        if (res.first == -1)
            break;
        else
        {
			// 그 위치로 가기 위한 step 과 그 위치의 character를 'A' 로 만들기 위한 값을 더해 준다.
            pos = res.first;
            answer += res.second + row[pos];
            row[pos] = 0;
        }
    }


    return answer;
}
