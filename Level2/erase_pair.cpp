// https://programmers.co.kr/learn/courses/30/lessons/12973?language=cpp

#include <iostream>
#include <string>
#include <stack>

using namespace std;

// Stack 활용
// Stack이 비어있거나 top이 다른 문자이면 push
// top이 같은 문자이면 pop
// loop 종료 후 Stack이 비어있으면 모두 제거 가능한 문자열
int solution(string s)
{
    int answer = 0;
    stack<char> st;
    
    for (int i = 0; i < s.size(); i++) {
        if (st.empty() || st.top() != s[i]) {
            st.push(s[i]);
        } else {
            st.pop();
        }
    }
    if (st.empty()) {
        answer = 1;
    } else {
        answer = 0;
    }

    return answer;
}