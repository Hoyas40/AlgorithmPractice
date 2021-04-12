#include <string>
#include <vector>
#include <iostream>

using namespace std;
vector<int> visited;

int dfs(int n, int id, const vector<vector<int>>& computers)
{
    if(visited[id] == 0)
    {
        visited[id] = 1;
        
        for(auto i = 0; i < computers[id].size(); ++i)
        {
            if(computers[id][i] == 1)
                dfs(n, i, computers);
        }

        return true;
    }
    return false;
}

int solution(int n, vector<vector<int>> computers) 
{
    visited = vector<int>(n, 0);
    int answer = 0;
    for(int i = 0; i < n; ++i)
    {
        if( dfs(n, i, computers) )
            answer++;
    }
    return answer;
}

//int main()
//{
//    vector<vector<int>> data{{1, 1, 0}, {1, 1, 1}, {0, 1, 1}};
//    cout << solution( data.size(), data) << endl;
//}