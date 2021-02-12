#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

int solution(vector<int> citations) {
    
    sort(citations.begin(), citations.end(), greater<>());
    int answer = 0;
    
    for( auto i = 0; i < citations.size(); ++i)
    {
        if( citations[i] >= i + 1)
            answer = i + 1;
        else
            break;
    }
    return answer;
}

int main()
{
    vector<int> citations{6, 5, 4, 1, 3};
    cout << solution(citations) << endl;
    return 0;
}