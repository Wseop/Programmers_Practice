// https://programmers.co.kr/learn/courses/30/lessons/12899?language=cpp#

#include <string>
#include <vector>
#include <iostream>

using namespace std;

// 1, 2, 4를 순서대로 사용하는 방식 1 -> 2 -> 4 -> 11 -> 12 -> 14 -> ...
// 3의 배수가 아닌 경우는 3으로 나눈 나머지 (0인 경우는 4)
// 3의 배수인 경우는 결과에 4를 붙이고 3으로 나눈 몫의 -1에 대해 위 방식 적용
string solution(int n) {
    string answer = "";
    string answer_reverse = "";
    
    while (n != 0) {
        if (n % 3 == 0) {
            answer_reverse += '4';
            n = (n / 3) - 1;
        } else {
            answer_reverse += n % 3 == 0 ? '4' : ((n % 3) + '0');
            n /= 3;
        }
    }
    for (auto r_iter = answer_reverse.rbegin(); r_iter != answer_reverse.rend(); r_iter++)
        answer += *r_iter;
    
    return answer;
}