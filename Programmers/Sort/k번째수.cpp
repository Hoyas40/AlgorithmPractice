#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

vector<int> solution(vector<int> array, vector<vector<int>> commands) 
{
    vector<int> answer;
    answer.reserve(commands.size());
    
    for( auto i = 0; i < commands.size(); ++i)
    {   
        auto tempArray = array;
        auto begin = tempArray.begin() + commands[i][0] - 1;
        auto end = tempArray.begin() + commands[i][1];
        sort(begin, end);
       
        answer.push_back(*(begin + commands[i][2]-1));
    }   
    
    
    return answer;
}

int main()
{
    vector<int> array{1,5,2,6,3,7,4};
    vector<vector<int>> commands{{2,5,3},{4,4,1},{1,7,3}};
    // vector<vector<int>> commands{{4,4,1}};
    auto res = solution(array,commands);
    for(auto i : res)
        cout << i << endl;
}