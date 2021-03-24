// https://programmers.co.kr/learn/courses/30/lessons/12985?language=cpp

#include <iostream>

using namespace std;

// 이길 시 다음 라운드의 순번은 (현재 순번 + 1) / 2
int solution(int n, int a, int b)
{
    int answer = 1;

    while (true) {
        a = (a + 1) / 2;
        b = (b + 1) / 2;
        if (a == b) break;
        else answer++;
    }

    return answer;
}