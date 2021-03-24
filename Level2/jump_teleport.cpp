// https://programmers.co.kr/learn/courses/30/lessons/12980?language=cpp

#include <iostream>

using namespace std;

// 홀수이면 +1
// n이 0이 아닐때까지 반복하여 n/2
int solution(int n)
{
    int ans = 0;
    
    while (n != 0) {
        if (n & 1) ans++;
        n /= 2;
    }

    return ans;
}