// https://programmers.co.kr/learn/courses/30/lessons/43163?language=cpp

#include <string>
#include <vector>
#include <queue>
#include <iostream>

using namespace std;

// 다른 단어의 수를 반환
int diff(string a, string b) {
    int diff = 0;
    
    for (int i = 0; i < a.size(); i++) {
        if (a[i] != b[i]) diff++;
    }
    return diff;
}

int solution(string begin, string target, vector<string> words) {
    int answer = 0;
    int i;
    queue<string> q;
    
    // 예외 처리, words에 target이 없으면 0 반환 후 종료
    for (i = 0; i < words.size(); i++) {
        if (words[i] == target) break;
    }
    if (i == words.size()) return 0;
    q.push(begin);
    
	// BFS
	// 변환할 수 있는 단어들을 queue에 넣음
	// 변환 횟수를 기억하기 위해 queue에 있는 모든 단어를 next_words로 옮긴 후 작업
    while (true) {
        vector<string> next_words;
        while (!q.empty()) {
            next_words.push_back(q.front());
            q.pop();
        }
        answer++;
        
        // for (int temp = 0; temp < next_words.size(); temp++) {
        //     cout << next_words[temp] << " ";
        // }
        // cout << " answer : " << answer << endl;
        
        for (auto current = next_words.begin(); current != next_words.end(); current++) {
            auto next = words.begin();
            
            if (*current == target) return answer - 1;
            
            while (next != words.end()) {
                if (diff(*current, *next) == 1) {
                    q.push(*next);
                    words.erase(next);
                } else next++;
            }
        }
    }
    
    return 0;
}