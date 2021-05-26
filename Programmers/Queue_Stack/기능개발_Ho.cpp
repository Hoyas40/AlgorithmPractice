#include <string>
#include <vector>
#include <queue>
#include <cmath>
#include <iostream>

using namespace std;

struct Item
{
    Item(int progress, int speed)
        : progress(progress)
        , speed(speed)
    {}
    int progress;
    int speed;
};

vector<int> solution(vector<int> progresses, vector<int> speeds) 
{   
    vector<int> answer;
    
    queue<Item> q;
    for (auto i = 0; i < progresses.size(); ++i)
        q.push({progresses[i], speeds[i]});    
    
    while (!q.empty())
    {        
        Item item = q.front();
        q.pop();
        
        int count = 1;
        
        int dayToRelease = ceil((100.0f - item.progress) / item.speed);
        while (!q.empty() && q.front().progress + q.front().speed * dayToRelease >= 100)
        {
            q.pop();
            count++;
        }
        
        answer.push_back(count);
    }
    
    return answer;
}