//	문제 설명 
//      스트리밍 사이트에서 장르 별로 가장 많이 재생된 노래를 두 개씩 모아 베스트 앨범을 출시하려 합니다.
//      노래는 고유 번호로 구분하며, 노래를 수록하는 기준은 다음과 같습니다.

//      1. 속한 노래가 많이 재생된 장르를 먼저 수록합니다.
//      2. 장르 내에서 많이 재생된 노래를 먼저 수록합니다.
//      3. 장르 내에서 재생 횟수가 같은 노래 중에서는 고유 번호가 낮은 노래를 먼저 수록합니다.

//	문제 해결
//	    genreItem ->  각 장르별로 재생 된 횟수, 가장 많이 재생된 노래 2개를 계산한다.

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