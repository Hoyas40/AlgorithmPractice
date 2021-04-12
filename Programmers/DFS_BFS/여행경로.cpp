#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int N;
vector<string> sol;

template<class T>
bool has(const vector<T>& vec, T val)
{
	if (std::find(vec.begin(), vec.end(), val) != vec.end())
		return true;
	else
		return false;
}

struct item
{
	item(int _id, string _src, string _dest)
	{
		id = _id;
		src = _src;
		dest = _dest;
	}
	int id;
	string src;
	string dest;
};

bool DFS(vector<int>& selected, const vector<vector<string>>& tickets)
{
	if (selected.size() == N)
	{		
		for (auto i : selected)		
			sol.push_back(tickets[i][0]);
		
		sol.push_back(tickets[selected.back()][1]);
		//candidates.push_back(temp);

		return true;
	}

	vector<item> pool;

	for (int i = 0; i < N; ++i)
	{		
		if (selected.empty())
		{
			if( tickets[i][0]=="ICN")
				pool.push_back({ i, tickets[i][0], tickets[i][1] });			
		}
		else if (has(selected, i) == false)
		{
			int last = selected.back();
			if (tickets[last][1] == tickets[i][0])
			{
				pool.push_back({ i, tickets[i][0], tickets[i][1] });
			}
		}		
	}

	sort(pool.begin(), pool.end(), [](const item& i1, const item& i2)
									{
										if (i1.src != i2.src)
											return i1.src < i2.src;
										else
											return i1.dest < i2.dest;
									});

	for (const auto& item : pool)
	{
		selected.push_back(item.id);
		if (DFS(selected, tickets))
			return true;
		selected.pop_back();
	}

	return false;
}

vector<string> solution(vector<vector<string>> tickets) 
{
	N = tickets.size();
	vector<int> selected;

	DFS(selected, tickets);	
		
	return sol;
}



int main()
{
	vector<vector<string>> testData = { { "ICN", "SFO" } , { "ATL", "SFO" } , {"ICN", "ATL"}, {"SFO", "ATL"}, {"ATL", "ICN"} };

	solution(testData);
	
	
	for (const auto & airport : sol)
		cout << airport << ", ";

	cout << '\n';
	
	return 0;
}