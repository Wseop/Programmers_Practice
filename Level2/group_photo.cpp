// https://programmers.co.kr/learn/courses/30/lessons/1835?language=cpp

#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

// 조건으로 주어진 두 사람의 index를 구함
// 두 index로 두 사람 사이의 간격을 구함
// 조건과 간격을 모두 만족하는지 check 후 결과 반환
bool CheckCondition(string& pos, char p1, char p2, char range, int interval) {
    int index_p1, index_p2;
    int diff;
        
    for (int i = 0; i < pos.size(); i++) {
        if (pos[i] == p1) index_p1 = i;
        else if (pos[i] == p2) index_p2 = i;
    }
    
    diff = index_p2 - index_p1;
    if (diff < 0) diff = -diff;
    diff--;
    
    switch (range) {
        case '=':
            if (diff == interval) return true;
            else return false;
        case '<':
            if (diff < interval) return true;
            else return false;
        case '>':
            if (diff > interval) return true;
            else return false;
    }
}

// next_permutation으로 가능한 모든 조합에 대해 조건을 만족하는지 확인
int solution(int n, vector<string> data) {
    int answer = 0;
    string position = "ACFJMNRT";
    
    do {
        bool pass = true;
        
        for (int i = 0; i < n; i++) {
            if (!CheckCondition(position, data[i][0], data[i][2], data[i][3], data[i][4] - '0')) {
                pass = false;
                break;
            }
        }
        if (pass) answer++;
    } while (next_permutation(position.begin(), position.end()));
    
    return answer;
}