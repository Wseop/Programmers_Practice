// https://programmers.co.kr/learn/courses/30/lessons/42839?language=cpp

#include <string>
#include <vector>
#include <cmath>
#include <algorithm>
#include <set>

using namespace std;

// 인자로 받은 n이 소수이면 true, 아니면 false 반환
bool isPrime(int n) {
    // 1이하는 소수가 아님
    if (n <= 1) {
        return false;
    }
    
    // 해당 수의 제곱근까지만 체크해도 소수여부 판별 가능
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
    
    // string으로 주어진 숫자를 int로 변환하여 저장
    for (int i = 0; i < numbers.size(); i++) {
        v_numbers.push_back(numbers[i] - '0');
    }

    // next_permutation으로 가능한 모든 조합에 대해 탐색
    do {
        for (int i = 1; i <= numbers.size(); i++) {
            int temp = 0;
            
            // 현재 조합에서 만들 수 있는 1자리 ~ i자리의 수를 primes에 삽입
            // primes는 set, 중복 없음
            for (int j = 0; j < i; j++) {
                temp = (temp * 10) + v_numbers[j];
                primes.insert(temp);
            }
        }
    } while (next_permutation(v_numbers.begin(), v_numbers.end()));
    
    // primes set을 탐색하며 소수판별
    for (auto iter = primes.begin(); iter != primes.end(); iter++) {
        if (isPrime(*iter)) {
            answer++;
        }
    }
    
    return answer;
}