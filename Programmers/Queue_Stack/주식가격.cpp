#include <string>
#include <vector>
#include <queue>
using namespace std;

struct ITEM
{
    ITEM(int value, int id)
    {
        this->value = value;
        this->id = id;
    }
    int value;
    int id;
};

vector<int> solution(vector<int> prices)
{
    vector<int> answer(prices.size(), 0);

    auto comp = [](const ITEM& item1, const ITEM& item2)
    {
        return item1.value < item2.value;
    };
    
    priority_queue<ITEM, std::vector<ITEM>, decltype(comp)> pq(comp);

    for (auto i = 0; i < prices.size(); ++i)
    {
        // 현재 값보다 큰 값들을 pq 에서 pop 한다.
        // 현재 위치로부터 해당 ITEM의 위치를 계산하여 answer 를 업데이트 한다.
        int val = prices[i];
        while (!pq.empty() && val < pq.top().value)
        {
            ITEM item = pq.top();
            pq.pop();

            answer[item.id] = i - item.id;
        }

        pq.push(ITEM(prices[i], i));
    }

    // 마지막까지 남아 있는 ITEM 들을 처리한다.
    const int N = prices.size() - 1;
    while (!pq.empty())
    {
        ITEM item = pq.top();
        pq.pop();

        answer[item.id] = N - item.id;
    }

    return answer;
} 

vector<int> solution1(vector<int> prices) 
{
    
    vector<int> answer(prices.size(), 0);
    vector<bool> good(prices.size(), true);

    for (auto i = 1; i < prices.size(); ++i)
    {
        int refVal = prices[i];
        for (auto j = 0; j < i; ++j)
        {
            if (good[j])
                answer[j]++;

            if (prices[j] > refVal)
                good[j] = false;
        }
    }

    return answer; 

}

vector<int> solution2(vector<int> prices) {
    vector<int> answer(prices.size(), 0);

    for (auto i = 0; i < prices.size(); ++i)
    {
        int &ref = answer[i];
        for (auto j = i + 1; j < prices.size(); ++j)
        {
            ref++;
            if (prices[j] < prices[i])
                break;
        }
    }

    return answer;
}

int main()
{
    vector<int> res = solution({1, 2, 3, 2, 3});
}