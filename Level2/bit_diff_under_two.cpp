// https://programmers.co.kr/learn/courses/30/lessons/77885?language=cpp

// 비트가 2개 이하로 다른 가장 작은 다음 수를 구하는 문제
// 짝수일 경우 +1
// 홀수일 경우 연속된 1의 갯수를 n이라 할 때, 2^(n-1)을 더한 값이 됨
// overflow에 주의! temp를 int로 선언할 경우 while문을 탈출하지 못할 수 있음

#include <string>
#include <vector>

using namespace std;

long long GetNextNum(long long num) {
    int count = 0;
    long long temp = num;

    if ((num & 1) == 0) return (num + 1);
    while (temp & 1) {
        count++;
        temp = temp >> 1;
    }
    return num + (1LL << (count - 1));
}

vector<long long> solution(vector<long long> numbers) {
    vector<long long> answer;

    for (long long number : numbers) {
        answer.push_back(GetNextNum(number));
    }

    return answer;
}