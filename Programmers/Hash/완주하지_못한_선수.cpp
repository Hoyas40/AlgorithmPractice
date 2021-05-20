//	문제 설명 
//	    단 한 명의 선수를 제외하고는 모든 선수가 마라톤을 완주하였습니다.
//	    마라톤에 참여한 선수들의 이름이 담긴 배열 participant와 완주한 선수들의 이름이 담긴 배열 completion이 주어질 때, 
//	    완주하지 못한 선수의 이름을 return 하도록 solution 함수를 작성해주세요

//	문제 해결
//	    두 vector를 정렬 후, index 를 비교해서 다른 element 찾기


#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

string solution(vector<string> participant, vector<string> completion) 
{
    sort(participant.begin(), participant.end());
    sort(completion.begin(),  completion.end());
    
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