// https://programmers.co.kr/learn/courses/30/lessons/77884?language=cpp

#include <string>
#include <vector>

using namespace std;

int GetNumberOfAliquot(int number) {
    int count = 2;

    if (number == 1) return 1;

    for (int i = 2; i < number; i++) {
        if (number % i == 0) count++;
    }

    return count;
}

int solution(int left, int right) {
    int answer = 0;

    for (int i = left; i <= right; i++) {
        if (GetNumberOfAliquot(i) & 1) answer -= i;
        else answer += i;
    }

    return answer;
}