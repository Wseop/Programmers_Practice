// https://programmers.co.kr/learn/courses/30/lessons/42626?language=cpp

#include <string>
#include <vector>
#include <queue>
#include <functional>
#include <iostream>

using namespace std;

int solution(vector<int> scoville, int K) {
    int answer = 0;
    priority_queue<int, vector<int>, greater<int> > pq;
    
    for (int i = 0; i < scoville.size(); i++) {
        pq.push(scoville[i]);
    }
    while (pq.size() > 1) {
        int min, sub_min;
        
        min = pq.top();
        pq.pop();
        sub_min = pq.top();
        pq.pop();
        
        if (min >= K) {
            return answer;
        } else if (sub_min == 0) {
            return -1;
        } else {
            pq.push(min + (sub_min * 2));
            answer++;
        }
    }
    if (pq.top() >= K) {
        return answer;
    } else {
        return -1;
    }
}