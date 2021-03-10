// https://programmers.co.kr/learn/courses/30/lessons/68935?language=cpp

#include <string>
#include <vector>

using namespace std;

int solution(int n) {
    int answer = 0;
    vector<int> ternary;
    
    // 3진법으로 변환
    while (n != 0) {
        ternary.push_back(n % 3);
        n /= 3;
    }
    
    int digit = 1;
    // 실제로 뒤집지 않고 reverse iterator로 뒤에서부터 접근
    for (auto r_iter = ternary.rbegin(); r_iter != ternary.rend(); r_iter++) {
        answer += ((*r_iter) * digit);
        digit *= 3;
    }
    return answer;
}