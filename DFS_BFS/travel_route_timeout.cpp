#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

bool cmp(vector<string> a, vector<string> b) {
    return a[1] < b[1];
}

vector<string> solution(vector<vector<string>> tickets) {
    vector<string> answer;
    string current = "ICN";
    
    sort(tickets.begin(), tickets.end(), cmp);
    answer.push_back(current);
    
    while (!tickets.empty()) {
        auto iter_ticket = tickets.begin();
        
        while (iter_ticket != tickets.end()) {
            string src = (*iter_ticket)[0];
            string dst = (*iter_ticket)[1];
            
            if (src == current) {
                answer.push_back(dst);
                current = dst;
                tickets.erase(iter_ticket);
                break;
            } else {
                iter_ticket++;
            }
        }
    }
    
    return answer;
}