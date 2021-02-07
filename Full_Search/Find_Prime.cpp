#include <string>
#include <vector>
#include <cmath>
#include <algorithm>
#include <set>

using namespace std;

bool isPrime(int n) {
    if (n <= 1) {
        return false;
    }
    
    for (int i = 2; i <= sqrt(n); i++) {
        if (n % i == 0) {
            return false;
        }
    }
    return true;
}

int solution(string numbers) {
    int answer = 0;
    vector<int> v_numbers;
    set<int> primes;
    
    sort(numbers.begin(), numbers.end());
    
    for (int i = 0; i < numbers.size(); i++) {
        v_numbers.push_back(numbers[i] - '0');
    }
    do {
        for (int i = 1; i <= numbers.size(); i++) {
            int temp = 0;
            
            for (int j = 0; j < i; j++) {
                temp = (temp * 10) + v_numbers[j];
                primes.insert(temp);
            }
        }
    } while (next_permutation(v_numbers.begin(), v_numbers.end()));
    
    for (auto iter = primes.begin(); iter != primes.end(); iter++) {
        if (isPrime(*iter)) {
            answer++;
        }
    }
    
    return answer;
}