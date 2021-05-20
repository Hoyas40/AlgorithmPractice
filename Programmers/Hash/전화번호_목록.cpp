//	문제 설명 
//	    전화번호부에 적힌 전화번호 중, 한 번호가 다른 번호의 접두어인 경우가 있는지 확인하려 합니다.
//      전화번호가 다음과 같을 경우, 구조대 전화번호는 영석이의 전화번호의 접두사입니다.
//      구조대 : 119
//      박준영 : 97 674 223
//      지영석 : 11 9552 4421

//	문제 해결
//	    모든 번호를 hash_map 에 집어 넣고
//      각 phone의 substring이 hash_map에 있는 지 찾는다.

#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

bool solution(vector<string> phone_book) 
{
    bool answer = true;

    // dict 은 모든 전화 번호 목록을 가진다.
    unordered_map<string, int> dict;
    for(const auto& number : phone_book)
        dict.insert({number, 1});
    
    // 각 번호의 sub-string이 dict 안에 있는 지 확인.
    for(const auto& number : phone_book)
    {
        for( auto i = 1; i < number.size(); ++i)
        {
            if(dict.find(number.substr(0, i)) != dict.end())
            {
                answer = false;
                break;
            }    
        }        
    }
    
    return answer;
}

int main()
{
    return 0;
}