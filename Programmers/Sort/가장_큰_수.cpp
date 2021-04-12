#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

string solution(vector<int> numbers) 
{
    string answer = "";

    // 모든 숫자가 0 이면, "0" 반환
    if(all_of(numbers.begin(), numbers.end(), []
        (int i)
        {
            return i ==0;
        }))
        return "0";

    std::vector<string> strings;

    // 문자열 vector로 변경
    std::transform(numbers.begin(), numbers.end(), std::back_inserter(strings),
                    [](int n)
                    {
                        return to_string(n);
                    });
    
    // 정렬( s1 + s2 > s2 > s1 )
    std::sort(strings.begin(), strings.end(), [](const auto& s1, const auto& s2)
                                            {
                                                return s1 + s2 > s2 + s1;
                                            });

    for( const auto& i : strings)
        answer += i;

    return answer;
}

int main()
{
    vector<int> numbers{3, 30, 34, 5, 9};
    cout << solution(numbers) << endl;
    return 0;
}