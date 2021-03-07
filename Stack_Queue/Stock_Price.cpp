// https://programmers.co.kr/learn/courses/30/lessons/42584?language=cpp

#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> prices) {
    vector<int> answer;
    
    for (int i = 0; i < prices.size() - 1; i++) {
        int increase = 0;
        
        for (int j = i + 1; j < prices.size(); j++) {
            if (prices[i] <= prices[j]) {
                increase++;
            } else {
                increase++;
                break;
            }
        }
        answer.push_back(increase);
    }
    answer.push_back(0);
    return answer;
}