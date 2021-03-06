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
