#include <string>
#include <vector>
#include <queue>
#include <algorithm>
#include <iostream>

using namespace std;

struct ITEM
{
public:
    ITEM(int id, int priority)
    {
        this->id = id;
        this->priority = priority;
    }

    int id;
    int priority;
};

int solution(vector<int> priorities, int location)
{
    int answer = 0;

    queue<ITEM> queue;
    for (auto i = 0; i < priorities.size(); ++i)
        queue.push(ITEM(i, priorities[i]));

    sort(priorities.begin(), priorities.end());

    while (!queue.empty())
    {
        ITEM item = queue.front();
        queue.pop();

        if (item.priority == priorities.back())
        {
            answer++;
            priorities.pop_back();
            if (location == item.id)
                return answer;
        }
        else
            queue.push(item);
    }

    return answer;
}