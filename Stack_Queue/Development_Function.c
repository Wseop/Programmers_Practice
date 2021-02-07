#include <string>
#include <vector>
#include <queue>
#include <iostream>

using namespace std;

vector<int> solution(vector<int> progresses, vector<int> speeds) {
    vector<int> answer;
    queue<int> complete;
    
    //남은 일수를 complete에 push
    for (int i = 0; i < progresses.size(); i++) {
        int remain = 100 - progresses[i];
        int day = remain / speeds[i];
        if (remain % speeds[i] != 0) {
            day += 1;
        }
        
        complete.push(day);
    }
    while (!complete.empty()) {
        int release_first = complete.front();
        int release_count = 0;
        
        while (true) {
            if (complete.front() <= release_first) {
                release_count++;
                complete.pop();
                if (complete.empty()) {
                    break;
                }
            } else {
                break;
            }
        }
        answer.push_back(release_count);
    }
    return answer;
}