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
        // stack�� ����ִ� ���� ���� ������ ������ ������ ����
        // ���� ���� Ƚ�� (k)�� ���� ���� ��� pop ����
        while (!stack_number.empty() && stack_number.top() < number[index] && k > 0) {
            stack_number.pop();
            k--;
        }
        // pop ������ �ƴϸ� ��� stack�� ����
        stack_number.push(number[index]);
    }
    // ���� k��ŭ ����
    while (k > 0) {
        stack_number.pop();
        k--;
    }
    // pop�Ͽ� �տ� �̾����
    while (!stack_number.empty()) {
        answer.insert(0, 1, stack_number.top());
        stack_number.pop();
    }

    return answer;
}