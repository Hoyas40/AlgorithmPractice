#include <string>
#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;

struct genreItem
{
    int total{0};
    int first{-1}, second{-1};
    int firstNum{-1}, secondNum{-1};
    
    // 앨범 정보 추가(id, num)
    void Set(int id, int num)
    {
        total += num;
        
        // genre당 best 2장이 앨범을 계산.
        if(num > firstNum)
        {
            second = first;
            secondNum = firstNum;
            first = id;
            firstNum = num;
        }
        else if(num > secondNum)
        {
            second = id;
            secondNum = num;
        }
    }
};


vector<int> solution(vector<string> genres, vector<int> plays) 
{
    unordered_map<string, genreItem> genreMap;
    
    for(auto i = 0; i < genres.size(); ++i)
    {
        // genre가 없으면 추가
        if(genreMap.find(genres[i]) == genreMap.end())        
            genreMap.insert({genres[i], genreItem()});
        
        // genre에 앨범 추가
        genreMap[genres[i]].Set(i, plays[i]);
    }    
    
    // genre 를 판매 수대로 정렬
    vector<pair<string, genreItem>> elems(genreMap.begin(), genreMap.end());
    sort(elems.begin(), elems.end(), 
        [](auto & i, auto & j)
        {
            return !(i.second.total < j.second.total);
        });
    
    vector<int> answer;
    answer.reserve(elems.size() * 2);
    
    // 결과 저장
    for(auto i = 0; i < elems.size();++i)
    {
        if(elems[i].second.first != -1)
            answer.push_back(elems[i].second.first);
        if(elems[i].second.second != -1)
            answer.push_back(elems[i].second.second);
    }
    
    return answer;
}