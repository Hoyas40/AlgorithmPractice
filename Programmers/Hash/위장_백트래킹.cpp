//	문제 설명 
//      스파이들은 매일 다른 옷을 조합하여 입어 자신을 위장합니다.
//      예를 들어 스파이가 가진 옷이 아래와 같고 오늘 스파이가 동그란 안경, 긴 코트, 파란색 티셔츠를 입었다면 
//      다음날은 청바지를 추가로 입거나 동그란 안경 대신 검정 선글라스를 착용하거나 해야 합니다.

//	문제 해결
//	    모든 조합을 백트랙킹으로 찾는다!.  --> 무식한 생각!! +_+;;


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

    // 현재 조합으로 가능한 갯수
    int ret = accumulateMultiply(selected);
    int start = selected.empty() ? 0 : selected.back() + 1;    
    for(int i = start; i < N; ++i)
    {
        selected.push_back(i);  
        // 하나를 추가 했으면, 가능한 조합이 더 늘어 난다!
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

int main()
{
    vector<vector<string>> input{{"yellow_hat", "headgear"}, {"blue_sunglasses", "eyewear"}, {"green_turban", "headgear"}};
    int sol = solution(input);
    cout << sol << endl;
}