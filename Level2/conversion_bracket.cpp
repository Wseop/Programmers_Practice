// https://programmers.co.kr/learn/courses/30/lessons/60058?language=cpp

#include <string>
#include <vector>
#include <stack>

using namespace std;

// 올바른 괄호 문자열인지 확인하여 결과를 반환
// ( 이면 stack에 push
// ) 이면 pop을 하지만 stack이 빈 상태라면 false
// for loop을 빠져나온 경우 stack이 비어있다면 올바른 문자열
bool IsCorrect(string str) {
    stack<char> st;
    
    for (int index = 0; index < str.size(); index++) {
        if (str[index] == '(') {
            st.push('(');
        } else {
            if (st.empty()) return false;
            else st.pop();
        }
    }
    if (st.empty()) return true;
    else return false;
}

string Split(string str) {
    string u, v;
    int count_open = 0, count_close = 0;
    int index = 0;
    
    // 1. 입력이 빈 문자열인 경우, 빈 문자열을 반환
    if (str == "") return "";
    // 2. 두 균형잡힌 괄호 문자열로 분리
    while (index < str.size()) {
        if (count_open == count_close && count_open != 0) break;
        if (str[index] == '(') count_open++;
        else count_close++;
        index++;
    }
    u = str.substr(0, index);
    if (index == str.size()) v = "";
    else v = str.substr(index, str.size() - index);
    // 3. u가 올바른 괄호 문자열이면 v에 대해 재수행 (재귀)
    if (IsCorrect(u)) {
        return u += Split(v);
    } else {    // 4. u가 올바른 괄호 문자열이 아닌 경우
        string new_str = "(";
        new_str += Split(v);
        new_str += ")";
        u.erase(u.begin());
        u.erase(u.size() - 1, 1);
        for (int i = 0; i < u.size(); i++) {
            if (u[i] == '(') new_str += ")";
            else new_str += "(";
        }
        return new_str;
    }
}

string solution(string p) {
    string answer = "";
    
    answer = Split(p);
    
    return answer;
}