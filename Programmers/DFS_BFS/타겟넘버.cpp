#include <string>
#include <vector>
#include <numeric>
#include <iostream>

using namespace std;

int recursive(const vector<int>& numbers, vector<int>& selected, const int target)
{   
    if(selected.size() == numbers.size())
    {
        if( std::accumulate(selected.begin(), selected.end(), 0) == target )
            return 1;
        else
            return 0;
    }

    int ret = 0;

    int value = numbers[selected.size()];
    if( value != 0)
    {
        for( int i = 0; i < 2; ++i)
        {
            if( i == 0 )
                selected.push_back(value);
            else
                selected.push_back(-value);

            ret += recursive(numbers, selected, target);

            selected.pop_back();
        }
    }
    else
    {
        selected.push_back(value);
        ret += recursive(numbers, selected, target);
        selected.pop_back();
    }

    return ret;
}


int solution(vector<int> numbers, int target) 
{
    vector<int> selected;

    int answer = recursive(numbers, selected, target);
    return answer;
}

int main()
{
    vector<int> numbers{0, 0, 1, 1, 1};
    cout << solution(numbers, 3);   
    return 0;
}