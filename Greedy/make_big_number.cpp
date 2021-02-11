#include <string>
#include <vector>
#include <stack>

using namespace std;

string solution(string number, int k) {
    string answer = "";
    stack<char> stack_number;
    int index = 1;
    int len_number = number.size();

    stack_number.push(number[0]);
    for (; index < len_number; index++) {
        while (!stack_number.empty() && stack_number.top() < number[index] && k > 0) {
            stack_number.pop();
            k--;
        }
        stack_number.push(number[index]);
    }
    while (k > 0) {
        stack_number.pop();
        k--;
    }
    while (!stack_number.empty()) {
        answer.insert(0, 1, stack_number.top());
        stack_number.pop();
    }

    return answer;
}