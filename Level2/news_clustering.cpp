// https://programmers.co.kr/learn/courses/30/lessons/17677?language=cpp

#include <string>
#include <set>
#include <algorithm>

using namespace std;

char ConvertLower(char c) {
    int diff = 'a' - 'A';
    
    if (c >= 'A' && c <= 'Z') return c + diff;
    else return c;
}

bool IsChar(char c) {
    if (c >= 'a' && c <= 'z') return true;
    else return false;
}

// multiset의 count()를 활용하여 해결
// multiset 집합에서 count()로 특정 element의 갯수를 각각 구함
// 둘 중 min이 교집합, max가 합집합의 갯수
int solution(string str1, string str2) {
    int answer = 0;
    double count1 = 0, count2 = 0;
    set<string> keys;               // 가능한 element들의 집합
    multiset<string> elements1;     // str1을 parsing하여 나온 element들의 집합
    multiset<string> elements2;     // str2를 parsing하여 나온 element들의 집합

    // parsing str1   
    for (int i = 0; i < str1.size() - 1; i++) {
        char a = ConvertLower(str1[i]);
        char b = ConvertLower(str1[i+1]);
        if (IsChar(a) && IsChar(b)) {
            string key = "";
            key += a;
            key += b;
            keys.insert(key);
            elements1.insert(key);
        }
    }
    // parsing str2
    for (int i = 0; i < str2.size() - 1; i++) {
        char a = ConvertLower(str2[i]);
        char b = ConvertLower(str2[i+1]);
        if (IsChar(a) && IsChar(b)) {
            string key = "";
            key += a;
            key += b;
            keys.insert(key);
            elements2.insert(key);
        }
    }
    for (auto iter = keys.begin(); iter != keys.end(); iter++) {
        count1 += min(elements1.count(*iter), elements2.count(*iter));
        count2 += max(elements1.count(*iter), elements2.count(*iter));
    }
    if (count1 == 0 && count2 == 0) answer = 65536;
    else answer = (count1 / count2) * 65536;
    
    return answer;
}