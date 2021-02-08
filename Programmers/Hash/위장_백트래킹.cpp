#include <string>
#include <vector>
#include <unordered_map>
#include <iostream>

using namespace std;

unordered_map<string, int> hash_map;

// count of clothes in each type.
vector<int> countEachType;

// compute multiplication of cloth count in selected
int accumulateMultiply(const vector<int>& selected)
{
    if(selected.empty())
        return 0;

    int ret = 1;
    for(int j = 0; j < selected.size(); ++j)
        ret *= countEachType[selected[j]];
    return ret;
}


int computeOneStep(vector<int>& selected, const int N)
{
    if(selected.size() == N)
        return accumulateMultiply(selected);

    int ret = accumulateMultiply(selected);
    int start = selected.empty() ? 0 : selected.back() + 1;    
    for(int i = start; i < N; ++i)
    {
        selected.push_back(i);        
        ret += computeOneStep(selected, N);
        selected.pop_back();
    }
    
    return ret;
}

int solution(vector<vector<string>> clothes) 
{
    // calculate number of clothes for each type
    for(auto i = 0; i < clothes.size(); ++i)
    {
        if(hash_map.find(clothes[i][1]) == hash_map.end())
            hash_map.insert({clothes[i][1], 1});
        else
            hash_map[clothes[i][1]]++;
    }
    
    // make a vector having cloth count in each type.
    for(const auto& elem : hash_map)
        countEachType.push_back(elem.second);
    
    vector<int> selected;
    int answer = computeOneStep(selected, countEachType.size());
    return answer;
}

// int main()
// {
//     vector<vector<string>> input{{"yellow_hat", "headgear"}, {"blue_sunglasses", "eyewear"}, {"green_turban", "headgear"}};
//     int sol = solution(input);
//     cout << sol << endl;
// }