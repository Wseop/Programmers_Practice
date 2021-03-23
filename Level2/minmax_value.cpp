// https://programmers.co.kr/learn/courses/30/lessons/12939?language=cpp

#include <string>
#include <vector>
#include <algorithm>

using namespace std;

// stoi 및 to_string 함수 활용
// 공백 아닐 경우 새로운 문자열에 이어붙이면서 문자열 형태의 정수 parsing
// 공백을 만나면 parsing한 문자열을 배열에 push
// 배열을 정렬하여 min, max를 구함
string solution(string s) {
    string answer = "";
    string parsing = "";
    vector<int> numbers;
    
    for (int i = 0; i < s.size(); i++) {
        if (s[i] == ' ') {
            numbers.push_back(stoi(parsing));
            parsing = "";
        } else {
            parsing += s[i];
        }
    }
    numbers.push_back(stoi(parsing));
    sort(numbers.begin(), numbers.end());
    answer += to_string(numbers[0]);
    answer += ' ';
    answer += to_string(numbers[numbers.size() - 1]);
    
    return answer;
}