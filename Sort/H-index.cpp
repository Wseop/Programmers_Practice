// https://programmers.co.kr/learn/courses/30/lessons/42747?language=cpp

#include <string>
#include <vector>
#include <functional>
#include <algorithm>

using namespace std;

int solution(vector<int> citations) {
    int answer = citations.size();
    
    sort(citations.begin(), citations.end());
    for (int i = 0 ; i < citations.size(); i++) {
        if (answer <= citations[i]) { 
            break; 
        }
        answer--;
    }
    return answer;
}