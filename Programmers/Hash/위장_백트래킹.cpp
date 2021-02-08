#include <string>
#include <vector>
#include <unordered_map>
#include <iostream>

using namespace std;

unordered_map<string, int> hash_map;
vector<int> vec;

int accumulate(const vector<int>& selected)
{
    if( selected.empty())
        return 0;

    int ret = 1;
    for(int j = 0; j < selected.size(); ++j)
        ret *= vec[selected[j]];
    return ret;
}
int getCombi(vector<int>& selected, const int N)
{
    if(selected.size() == N)
        return accumulate(selected);

    int ret = accumulate(selected);
    int start = selected.empty() ? 0 : selected.back() + 1;    
    for(int i = start; i < N; ++i)
    {
        selected.push_back(i);        
        ret += getCombi(selected, N);
        selected.pop_back();
    }
    
    return ret;
}

int solution(vector<vector<string>> clothes) 
{
    for(auto i = 0; i < clothes.size(); ++i)
    {
        if(hash_map.find(clothes[i][1]) == hash_map.end())
        {
            hash_map.insert({clothes[i][1], 1});
        }
        else
            hash_map[clothes[i][1]]++;
    }    
    
    for(const auto& elem : hash_map)
    {
        //cout << elem.second << endl;
        vec.push_back(elem.second);
    }
    
    vector<int> test;
    int answer = getCombi(test, vec.size());
    return answer;
}

int main()
{
    vector<vector<string>> input{{"yellow_hat", "headgear"}, {"blue_sunglasses", "eyewear"}, {"green_turban", "headgear"}};
    int sol = solution(input);
    cout << sol << endl;
}