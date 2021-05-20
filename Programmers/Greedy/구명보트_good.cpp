#include <string>
#include <vector>
#include <algorithm>

using namespace std;

// ภฬป๓วิ!!!


int solution(vector<int> people, int limit) 
{
	sort(people.begin(), people.end());
	reverse(people.begin(), people.end());
	int N = (int)people.size();
	int res = 0;
	for (int i = 0, j = N - 1; i <= j; i++) 
	{
		if (people[i] + people[j] <= limit) 
			j--;

		res++;
	}
	return res;
}