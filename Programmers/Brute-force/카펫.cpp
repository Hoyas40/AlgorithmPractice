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



int main()
{
    return 0;
}