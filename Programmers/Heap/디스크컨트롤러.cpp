#include <string>
#include <vector>
#include <iostream>
#include <queue>
#include <functional>
using namespace std;

struct item
{
	item(int _start, int _duration)
		: start(_start), duration(_duration)
	{
	}

	int start;
	int duration;
};

int solution(vector<vector<int>> jobs) 
{
	sort(jobs.begin(), jobs.end());

	int answer = 0;
	int currTime = 0;

	auto comp1 = [](const item& item1, const item& item2)
	{
		if (item1.start != item2.start)
			return item1.start > item2.start;
		else
			return item2.duration > item2.duration;
	};
	std::priority_queue< item, std::vector<item>, decltype(comp1)> q1(comp1);

	auto comp2 = [](const item& item1, const item& item2)
	{
		int s1 = item1.start, d1 = item1.duration;
		int s2 = item2.start, d2 = item2.duration;

		return (2 * d1 + d2 - s1 - s2 > 2 * d2 + d1 - s2 - s1);

	};
	std::priority_queue< item, std::vector<item>, decltype(comp2)> q2(comp2);

	for (const auto& job : jobs)
		q1.push(item(job[0], job[1]));

	while (!q1.empty() || !q2.empty())
	{
		while(!q1.empty() && q1.top().start <= currTime)
		{
			q2.push(q1.top());
			q1.pop();
		}

		if (q2.empty())
		{
			item temp = q1.top();
			q1.pop();
			answer += temp.duration;
			currTime = temp.start + temp.duration;
		}
		else
		{
			item temp = q2.top();
			q2.pop();
			answer += (currTime - temp.start + temp.duration);
			currTime += temp.duration;
		}
	}
	return answer / (int)jobs.size();
}

int main()
{
	vector<vector<int>> data = { {0, 3},{0, 9},{2, 6} };
	vector<vector<int>> data2 = { {0, 5},{1, 2},{5, 5} };
	vector<vector<int>> data3 = { {24, 10}, { 18, 39 }, { 34, 20 }, { 37, 5 }, { 47, 22 }, { 20, 47 }, { 15, 34 }, { 15, 2 }, { 35, 43 }, { 26, 1 }};
	vector<vector<int>> data4 = { {24, 10}, {28, 39}, {43, 20}, {37, 5}, {47, 22}, {20, 47}, {15, 34}, {15, 2}, {35, 43}, {26, 1} };
	cout << solution(data4) << endl;
}


#include <string>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

bool compare(vector<int> a, vector<int> b) {
	return a[1] < b[1];
}

int solution(vector<vector<int>> jobs) {
	int answer = 0;
	int start = 0; // 현재까지 작업이 진행된 시간
	int time = 0; // 각각의 작업이 진행되는데 걸린 시간들의 합
	int size = jobs.size();

	sort(jobs.begin(), jobs.end(), compare); // 소요시간으로 우선 배열

	while (!jobs.empty()) {
		for (int i = 0; i<jobs.size(); i++) {
			if (jobs[i][0] <= start) {
				start += jobs[i][1];
				time += start - jobs[i][0];
				jobs.erase(jobs.begin() + i);
				break;
			}

			if (i == jobs.size() - 1) start++;
		}
	}

	answer = time / size;
	return answer;
}