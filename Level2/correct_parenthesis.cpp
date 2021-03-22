// https://programmers.co.kr/learn/courses/30/lessons/12909?language=cpp

#include <string>
#include <stack>

using namespace std;

// stack 활용
// ( 이면 stack에 push
// ) 이면 pop, 만약 stack이 빈 상태이면 올바르지 않은 괄호
// loop 종료 후 stack이 빈 상태이면 올바른 괄호
bool solution(string s)
{
    bool answer = true;
    stack<char> st;
    
    for (int i = 0; i < s.size(); i++) {
        if (s[i] == '(') {
            st.push('(');
        } else if (st.empty()) {
            return false;
        } else {
            st.pop();
        }
    }
    if (st.empty()) answer = true;
    else answer = false;
    
    return answer;
}