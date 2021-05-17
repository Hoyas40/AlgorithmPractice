#include <string>
#include <vector>
#include <iostream>
#include <queue>
#include <memory>
#include <functional>
#include <stdlib.h>
using namespace std;


struct item
{
public:
	item(int val)
		:value(val)
	{
	}
	int value{ -1 };
	bool deleted{ false };
};


vector<int> solution(vector<string> operations)
{
	vector<int> answer;

	auto comp1 = [](const shared_ptr<item>& item1, const shared_ptr<item>& item2)
	{
		return item1->value < item2->value;
	};

	auto comp2 = [](const shared_ptr<item>& item1, const shared_ptr<item>& item2)
	{
		return !(item1->value < item2->value);
	};

	// 내림순 정렬
	std::priority_queue< shared_ptr<item>, std::vector<shared_ptr<item>>, decltype(comp1)> q1(comp1);

	// 오름순 정렬
	std::priority_queue< shared_ptr<item>, std::vector<shared_ptr<item>>, decltype(comp2)> q2(comp2);

	int countValidElement = 0;
	for (const auto & op : operations)
	{
		if (op[0] == 'I')
		{
			countValidElement++;

			string subStr = op.substr(2);
			int val = atoi(subStr.c_str());

			shared_ptr<item> t(new item(val));
			q1.push(t);
			q2.push(t);
		}
		else if (op[2] == '-') // 최솟값 삭제
		{
			if (countValidElement == 0)
				continue;

			countValidElement--;

			while (q2.top()->deleted)
			{
				q2.pop();
			}

			q2.top()->deleted = true;
			q2.pop();
		}
		else
		{
			if (countValidElement == 0)
				continue;

			countValidElement--;

			while (q1.top()->deleted)
			{
				q1.pop();
			}

			q1.top()->deleted = true;
			q1.pop();
		}
	}

	if (countValidElement == 0)
		answer = { 0, 0 };
	else
	{
		while (q1.top()->deleted)
			q1.pop();
		answer.push_back(q1.top()->value);

		while (q2.top()->deleted)
			q2.pop();
		answer.push_back(q2.top()->value);


	}

	return answer;
}





int main()
{
	

	vector<string> in{ "I 7", "I 5", "I -5", "D -1" };

	auto res = solution(in);

	return 0;
}