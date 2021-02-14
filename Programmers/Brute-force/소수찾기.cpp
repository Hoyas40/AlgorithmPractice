#include <string>
#include <vector>
#include <iostream>
#include <cmath>
#include <set>
#include <algorithm>

using namespace std;
bool primes[10000000] = {true};

set<int> sol;
void calculatePrimes(int max)
{
    
    primes[0] = false;
    primes[1] = false;

    int iSqrt = static_cast<int>(ceil(sqrt(max)));

    for( int i = 2; i < iSqrt; ++i)
    {
        int tmp = i+i;
        while( tmp <= max)
        {
            primes[tmp] = false;
            tmp += i;
        }
    }
}

int isPrime(vector<int>& selected, const string & numbers)
{
    if(selected.empty())
        return 0;

    string tmp;
    for( const auto& i : selected)
        tmp += numbers[i];
    
    int iValue = stoi(tmp);
    if( primes[iValue])
    {
        sol.insert(iValue);
        return 1;
    }
    
    return 0;
}

int isZero(vector<int>& selected, const string & numbers)
{
    if( selected.size() > 0 )
    {
        if( numbers[selected[0]] == '0' )
        {
            return true;
        }
    }
    return false;
}

int recursive(vector<int>& selected, const string & numbers)
{   
    // for(int i : selected)
    //     cout << i;
    // cout << endl;

    if( !selected.empty() && selected.back() == numbers.size())
        return 0;

    if( isZero(selected, numbers))
    {
        //cout << "isZero" << endl;
        return 0;
    }
    
    int ret = isPrime(selected, numbers);
    // if(ret == 1)
    // {
    //     for(int i : selected)
    //         cout << i;
    //     cout << " : ";
    //     for(int i : selected)
    //         cout << numbers[i];
    //     cout << " : Prime" << endl;
    // }
    int start = selected.empty() ? 0 : selected.back() + 1;

    for( int i = 0; i <= numbers.size(); ++i)
    {
        auto it = find(selected.begin(), selected.end(), i);
        if( it == selected.end() )
        {
            selected.push_back(i);
            ret += recursive(selected, numbers);
            selected.pop_back();
        }
    }

    return ret;
}

int solution(string numbers) 
{
    fill_n(primes, 10000000, true);
    int decimals = static_cast<int>(pow(10, numbers.size()));

    calculatePrimes(decimals);

    vector<int> selected;
    int answer = recursive(selected, numbers);

    return sol.size();
}

int main()
{
    string q("011");
    
    cout << solution(q) << endl;
    return 0;
}





// better solution

#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
#include <set>
#define MAX 9999999999
using namespace std;

bool isPrime(int number)
{
    if (number == 1)
        return false;
    if (number == 2)
        return true;
    if (number % 2 == 0)
        return false;

    bool isPrime = true;
    for (int i = 2; i <= sqrt(number); i++)
    {
        if (number% i == 0)
            return false;
    }

    return isPrime;
}

bool compare(char a, char b)
{
    return a > b;
}

int solution(string numbers) {
    int answer = 0;

    string temp;
    temp = numbers;

    sort(temp.begin(), temp.end(),compare);

    vector<bool> prime(std::stoi(temp)+1);

    //cout << stoi(temp) << endl;
    prime[0] = false;
    for (long long i = 1; i < prime.size(); i++)
    {
        prime[i] = isPrime(i);
    }
    //cout << "chk1" << endl;
    //int num = std::stoi(numbers);

    string s, sub;

    s = numbers;

    sort(s.begin(), s.end());
    set<int> primes;
    int l = s.size();
    do {
        for (int i = 1; i <= l; i++)
        {
            sub = s.substr(0, i);
        //  cout << "chk2" <<  " " << sub<<  endl;
            if (prime[std::stoi(sub)])
            {
                primes.insert(std::stoi(sub));
            }
        }
    } while (next_permutation(s.begin(), s.end()));

    //cout << primes.size();
    answer = primes.size();
    return answer;
}