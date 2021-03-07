// https://programmers.co.kr/learn/courses/30/lessons/42839?language=cpp

#include <string>
#include <vector>
#include <cmath>
#include <algorithm>
#include <set>

using namespace std;

// ���ڷ� ���� n�� �Ҽ��̸� true, �ƴϸ� false ��ȯ
bool isPrime(int n) {
    // 1���ϴ� �Ҽ��� �ƴ�
    if (n <= 1) {
        return false;
    }
    
    // �ش� ���� �����ٱ����� üũ�ص� �Ҽ����� �Ǻ� ����
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
    
    // string���� �־��� ���ڸ� int�� ��ȯ�Ͽ� ����
    for (int i = 0; i < numbers.size(); i++) {
        v_numbers.push_back(numbers[i] - '0');
    }

    // next_permutation���� ������ ��� ���տ� ���� Ž��
    do {
        for (int i = 1; i <= numbers.size(); i++) {
            int temp = 0;
            
            // ���� ���տ��� ���� �� �ִ� 1�ڸ� ~ i�ڸ��� ���� primes�� ����
            // primes�� set, �ߺ� ����
            for (int j = 0; j < i; j++) {
                temp = (temp * 10) + v_numbers[j];
                primes.insert(temp);
            }
        }
    } while (next_permutation(v_numbers.begin(), v_numbers.end()));
    
    // primes set�� Ž���ϸ� �Ҽ��Ǻ�
    for (auto iter = primes.begin(); iter != primes.end(); iter++) {
        if (isPrime(*iter)) {
            answer++;
        }
    }
    
    return answer;
}