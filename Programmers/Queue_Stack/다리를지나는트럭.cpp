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
    
    int weight;     // Ʈ���� ����    
    int endTime;    // Ʈ���� �ٸ� ���� �����ϴ� �ð�
};

int solution(int bridge_length, int weight, vector<int> truck_weights)
{
    queue<ITEM> q;
    int t = 0;      // current time
    int w = weight; // currently available weight

    for (auto i = 0; i < truck_weights.size(); ++i)
    {
        // �̹� �ٸ��� �� ���� Ʈ������ queue ���� pop
        while (!q.empty() && t >= q.front().endTime)
        {
            ITEM item = q.front();
            q.pop();
            w += item.weight;
        }
        
        // (�ٸ� Ʈ���� �ٸ��� �ִµ�) �߰��� ���� ���� t �� 1�� ���Ѵ�.
        // queue �� ������� ���� ����.( �� : ù ��° ����)
        if (!q.empty() && w >= truck_weights[i])
            t += 1;            
        else
        {
            // Ʈ���� �� ��������, ���� �� �� ���� �� ���� �ٸ��� �ִ� Ʈ������ ��ٸ���.
            while (w < truck_weights[i])
            {
                ITEM item = q.front();
                q.pop();

                // t = ���ο� Ʈ���� ��� �� �� �ִ� ���� ( �ٸ��� weight �� ������Ű�� ������ Ʈ���� ������ ����)
                t = item.endTime;
                w += item.weight;
            }
        }

        // ���� ������ queue �� �߰� �Ѵ�.
        w -= truck_weights[i];
        q.push(ITEM(truck_weights[i], t + bridge_length));
    }
    
    // 1 �� ������ ���� ��ü�� �ٸ��� ���� ���� ���� �ʿ��� �ð�
    t = q.back().endTime + 1;

    return t;
}

int main()
{
    vector<int> weights = { 2, 2, 2, 2, 1, 1, 1, 1, 1 };
    int res = solution(5, 5, weights);
}