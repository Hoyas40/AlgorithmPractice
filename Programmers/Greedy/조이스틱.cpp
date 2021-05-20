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

    if (costLeft < costRight)
    {
        return pair<int, int>(posLeft, costLeft);
    }
    else
    {
        return pair<int, int>(posRight, costRight);
    }
}

int solution(string name)
{
    std::vector<int> row;
    row.reserve(name.size());

    std::transform(name.cbegin(), name.cend(), back_inserter(row),
        [](unsigned char c) -> int {return std::min(c - 'A', 'Z' - c + 1); }
    );

    int pos = 0;
    int answer = 0;
    while (true)
    {
        pair<int, int> res = findNextPosition(pos, row);
        if (res.first == -1)
            break;
        else
        {
            pos = res.first;
            answer += res.second + row[pos];
            row[pos] = 0;
        }
    }


    return answer;
}
