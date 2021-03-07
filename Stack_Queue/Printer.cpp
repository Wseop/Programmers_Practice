// https://programmers.co.kr/learn/courses/30/lessons/42587?language=cpp

#include <string>
#include <vector>
#include <queue>
#include <algorithm>
#include <iostream>

using namespace std;

int solution(vector<int> priorities, int location) {
    int answer = 0;
    queue<int> q;
    
    //Queue로 이동
    for (int i = 0; i < priorities.size(); i++) {
        q.push(priorities[i]);
    }
    sort(priorities.begin(), priorities.end());    
    
    while (!q.empty()) {
        if (q.front() == priorities.back()) {
            answer++;
            if (location == 0) {
                break;
            } else {
                location--;
                q.pop();
                priorities.pop_back();
            }
        } else {
            q.push(q.front());
            q.pop();
            if (location == 0) {
                location = q.size() - 1;
            } else {
                location--;                
            }
        }
    }
    return answer;
}