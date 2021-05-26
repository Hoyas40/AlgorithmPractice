#include <string>
#include <vector>
#include <queue>
using namespace std;

struct ITEM
{
    ITEM(int weight, int endTime)
    {
        this->weight = weight;
        this->endTime = endTime;
    }
    
    int weight;     // 트럭의 무게    
    int endTime;    // 트럭이 다리 끝에 도착하는 시간
};

int solution(int bridge_length, int weight, vector<int> truck_weights)
{
    queue<ITEM> q;
    int t = 0;      // current time
    int w = weight; // currently available weight

    for (auto i = 0; i < truck_weights.size(); ++i)
    {
        // 이미 다리를 다 지난 트럭들은 queue 에서 pop
        while (!q.empty() && t >= q.front().endTime)
        {
            ITEM item = q.front();
            q.pop();
            w += item.weight;
        }
        
        // (다른 트럭이 다리에 있는데) 추가로 들어가는 차는 t 에 1을 더한다.
        // queue 가 비어있을 때는 제외.( 예 : 첫 번째 차량)
        if (!q.empty() && w >= truck_weights[i])
            t += 1;            
        else
        {
            // 트럭이 못 지나가면, 지나 갈 수 있을 때 까지 다리에 있는 트럭들을 기다린다.
            while (w < truck_weights[i])
            {
                ITEM item = q.front();
                q.pop();

                // t = 새로운 트럭이 들어 올 수 있는 시점 ( 다리에 weight 를 충족시키는 마지막 트럭이 도착한 시점)
                t = item.endTime;
                w += item.weight;
            }
        }

        // 현재 차량을 queue 에 추가 한다.
        w -= truck_weights[i];
        q.push(ITEM(truck_weights[i], t + bridge_length));
    }
    
    // 1 은 마지막 차의 전체가 다리를 지나 가기 위해 필요한 시간
    t = q.back().endTime + 1;

    return t;
}

int main()
{
    vector<int> weights = { 2, 2, 2, 2, 1, 1, 1, 1, 1 };
    int res = solution(5, 5, weights);
}