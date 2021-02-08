#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

int solution(vector<vector<string>> clothes) 
{    
    unordered_map<string, int> hash_map;
    
    // calculate number of clothes for each type
    for(auto i = 0; i < clothes.size(); ++i)
    {
        if(hash_map.find(clothes[i][1]) == hash_map.end())
            hash_map.insert({clothes[i][1], 1});
        else
            hash_map[clothes[i][1]]++;
    }
    
    int answer = 1;
    
    // total number is (x1 + 1) * (x2 + 1) * ... *(Xn + 1) - 1
    // Plus 1 is to count the case where the type of cloth is not worn.
    // the term -1 at the end is to remove a case where nothing is worn.
    for(const auto& elem : hash_map)    
        answer *= elem.second + 1;    
    
    return answer - 1;
}