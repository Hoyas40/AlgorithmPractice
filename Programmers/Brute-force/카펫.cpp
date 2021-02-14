#include <string>
#include <vector>
#include <cmath>
using namespace std;

vector<int> solution(int brown, int yellow) 
{
    int iSqrt = static_cast<int>(sqrt(yellow));
    vector<int> answer;
    
    for(int i = yellow; i >= iSqrt; --i)
    {
        if(yellow % i == 0)
        {
            int w = i;
            int h = yellow / i;
            
            int predicted = (w+2)*2 + h*2;
            if(predicted == brown)
            {
                answer.push_back(w+2);
                answer.push_back(h+2);
                return answer;
            }
        }
    }    
    
    return answer;
}

//better solution

vector<int> solution2(int brown, int red) 
{
    // wh = b + r
    // (w-2)(b-2)=r
    // 위 두 방정식을 정리하면, w = b/2 + 2 - h 가 나온다.
    int len = brown / 2 + 2;

    int w = len - 3;
    int h = 3;

    while(w >= h){
        if(w * h == (brown + red)) break;

        w--;
        h++;
    }

    return vector<int>{w, h};
}

int main()
{
    return 0;
}