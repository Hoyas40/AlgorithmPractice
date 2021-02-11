#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

string solution(vector<string> participant, vector<string> completion) 
{
    sort(participant.begin(), participant.end());
    sort(completion.begin(), completion.end());
    
    const auto N = completion.size();
    for( auto i = 0; i < N; ++i)
    {
        if(participant[i] != completion[i])
            return participant[i];            
    }
    return participant[N];
}

int main()
{
    vector<string> participant{"c0", "c1", "c2", "c3"};
    vector<string> completion{"c0", "c2", "c3"};
    cout << solution(participant, completion);    
}