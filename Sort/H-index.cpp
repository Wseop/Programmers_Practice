#include <string>
#include <vector>
#include <functional>

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