// https://programmers.co.kr/learn/courses/30/lessons/12915?language=cpp

#include <string>
#include <vector>
#include <algorithm>

using namespace std;

// a와 b가 다르면 a와 b로 비교
// a와 b가 같으면 문자열로 비교
bool cmp(pair<char, string> a, pair<char, string> b) {
    if (a.first == b.first) return a.second < b.second;
    else return a.first < b.first;
}

// n번째 단어와 주어진 문자열을 pair로 하는 vector 사용
// 위 vector를 cmp로 정렬
vector<string> solution(vector<string> strings, int n) {
    vector<string> answer;
    vector<pair<char, string>> nword_str;
    
    for (int i = 0; i < strings.size(); i++) {
        nword_str.push_back({strings[i][n], strings[i]});
    }
    sort(nword_str.begin(), nword_str.end(), cmp);
    for (int i = 0; i < nword_str.size(); i++) {
        answer.push_back(nword_str[i].second);
    }
    
    return answer;
}