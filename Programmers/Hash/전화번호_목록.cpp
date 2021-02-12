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