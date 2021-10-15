#include <string>
#include <vector>
#include <iostream>
#include <cmath>
#include <algorithm>

using namespace std;

// 어떤 조합을 만들어낼땐, 백트래킹으로 all_search

vector<vector<int>> set;

void recursion(int iter, int n, vector<int> arr, vector<int> visited, string nums){
    
    if ( iter == n){
        set.push_back(arr);
    }
    else{
        
        for(int i = 0 ; i < visited.size(); ++i){
            
            if(visited[i] == 0){
                visited[i] = 1;
                
                arr[iter] = int(nums[i]-'0');
                recursion(iter+1, n, arr, visited, nums);
                
                visited[i] = 0;
            }            
        }
    }
}

bool isPrime(string _number)
{
    
    int number = stoi(_number);
    
    if (number == 0)
        return false;
    else if (number == 1)
        return false;
    else if (number == 2)
        return true;
    else if (number % 2 == 0)
        return false;

    bool isPrime = true;
    for (int i = 2; i <= sqrt(number); i++)
    {
        if (number% i == 0)
            return false;
    }

    return isPrime;
}

int solution(string numbers) {
    int answer = 0;
    
    vector<int> arr;
    vector<int> visited;


    for(int i = 1 ; i <= numbers.length(); ++i){
        arr.resize(i,0);
        visited.resize(numbers.size(), 0);
        recursion(0, i, arr, visited, numbers);
    }
    

    vector<string> primes;
    for(int i = 0 ; i < set.size() ; ++i){
        string num="";
        for(int j = 0 ; j < set[i].size(); ++j)
            num += to_string(set[i][j]);
        
        for(int j =0 ; j < num.length(); ++j){
            if (num[j] =='0'){
                num.erase(j,1);
            }
            else
                break;
            
       }
        
        
        if(!num.empty() && isPrime(num))
            primes.push_back(num);
    }

    primes.erase(unique(primes.begin(), primes.end()), primes.end());
    answer =primes.size();
    
    
    return answer;
}