// https://programmers.co.kr/learn/courses/30/lessons/42883?language=cpp

#include <string>
#include <vector>
#include <stack>

using namespace std;

string solution(string number, int k) {
    string answer = "";
    stack<char> stack_number;
    int len_number = number.size();

    stack_number.push(number[0]);
    for (int index = 1; index < len_number; index++) {
        // stack에 들어있는 값이 넣을 값보다 작으면 꺼내서 버림
        // 제거 가능 횟수 (k)가 남아 있을 경우 pop 가능
        while (!stack_number.empty() && stack_number.top() < number[index] && k > 0) {
            stack_number.pop();
            k--;
        }
        // pop 조건이 아니면 모두 stack에 넣음
        stack_number.push(number[index]);
    }
    // 남은 k만큼 버림
    while (k > 0) {
        stack_number.pop();
        k--;
    }
    // pop하여 앞에 이어붙임
    while (!stack_number.empty()) {
        answer.insert(0, 1, stack_number.top());
        stack_number.pop();
    }

    return answer;
}