#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

int CountDiff(const string& s1, const string& s2)
{
    int count = 0;
    for(auto i = 0; i < s1.size(); ++i)
    {
        if(s1[i] != s2[i])
            count++;
        if( count > 1)
            break;
    }
    return count;
}
bool IsNewWord(int id, const vector<int>& selected)
{
    if( find(selected.begin(), selected.end(), id) == selected.end())
        return true;
    else
        return false;
}

int DFS(const string& begin, const string& target, const vector<string> &words,
        vector<int>& selected)
{
    if(begin == target)
        return selected.size();

    int ret = 987654321;
    for(auto i = 0; i < words.size(); ++i)
    {
        if( IsNewWord(i, selected) && CountDiff(begin, words[i]) == 1)
        {
            selected.push_back(i);
            ret = std::min(ret, DFS(words[i], target, words, selected));
            selected.pop_back();
        }
    }

    return ret;    
}


int solution(string begin, string target, vector<string> words) 
{
    vector<int> selected;
    if( std::find(words.begin(), words.end(), target) == words.end() )
        return 0;

    int answer = 987654321;

    for(auto i = 0; i < words.size(); ++i)
    {
        if( CountDiff(begin, words[i]) == 1)
            answer = std::min(answer, DFS(begin, target, words, selected));
    }

    if( answer == 987654321 )
        answer = 0;

    return answer;
}


int main()
{
    string begin{"hit"};
    string target{"cog"};

    vector<string> words{"hot", "dot", "dog", "lot", "log", "cog"};

    cout << solution(begin, target, words) << endl;
}