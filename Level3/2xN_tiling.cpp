// https://programmers.co.kr/learn/courses/30/lessons/12900?language=cpp

#include <string>
#include <vector>

using namespace std;

// 1과 2를 사용하여 n을 만들 수 있는 경우의 수를 찾는 문제
// n-1의 경우의 수 + n-2의 경우의 수 = n의 경우의 수
int solution(int n) {
    int answer = 0;
    int num1 = 1;
    int num2 = 2;
    
    if (n == 1) answer = num1;
    else if (n == 2) answer = num2;
    else {
        for (int i = 3; i <= n; i++) {
            int temp = (num1 + num2) % 1000000007;
            num1 = num2;
            num2 = temp;
        }
    }
    answer = num2;
    return answer;
}