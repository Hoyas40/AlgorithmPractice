#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

int GetNumberOfCorrectAnswer(const vector<int> & answers, const vector<int>& pattern)
{
    int res = 0;
    for( auto i = 0; i < answers.size(); ++i )
    {
        auto j = i % pattern.size();
        if( answers[i] == pattern[j] )
            res++;
    }

    return res;
}

vector<int> solution(vector<int> answers) 
{
    vector<int> pattern1{1,2,3,4,5};
    vector<int> pattern2{2,1,2,3,2,4,2,5};
    vector<int> pattern3{3,3,1,1,2,2,4,4,5,5};
    
    // 각 학생의 점수 계산
    vector<int> temp;
    temp.push_back(GetNumberOfCorrectAnswer(answers, pattern1));
    temp.push_back(GetNumberOfCorrectAnswer(answers, pattern2));
    temp.push_back(GetNumberOfCorrectAnswer(answers, pattern3));
    
    // 최대 점수 계산
    vector<int> answer;
    auto it = max_element(std::begin(temp), std::end(temp));
    int maxValue = *it;

    // 최대 점수를 가진 학생들 계산
    // 학생의 id는 1부터 시작
    for( int i = 0; i < temp.size(); ++i)
    {
        if(temp[i] == maxValue)
            answer.push_back(i+1);
    }
    return answer;
}

int main()
{
    vector<int> answers{1,3,2,4,2};
    vector<int> res = solution(answers);

    for( auto i : res)
        cout << i << endl;
    return 0;
}