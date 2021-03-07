// https://programmers.co.kr/learn/courses/30/lessons/43236?language=cpp

#include <string>
#include <vector>
#include <algorithm>

using namespace std;

// Target value is some value between start ~ end.
// but, the maximum of them, so use max() when determining the answer value (line 33.)
int solution(int distance, vector<int> rocks, int n) {
    int answer = 0;
    
    sort(rocks.begin(), rocks.end());
    
    int start = 0;
    int end = distance;
    int mid = (start + end) / 2;    
    
    while (start <= end) {
        int prev = 0;
        int count_remove = 0;
        
        // If the distance between the currently searched rock and the previous rock is less than mid, 
        // remove it so that mid can be satisfied.
        // Else, do not erase, so prev value becomes the current rock position.
        for (int i = 0; i < rocks.size(); i++) {
            if (rocks[i] - prev < mid) {
                count_remove++;
            } else {
                prev = rocks[i];
            }
        }
        // If erase more than the target, the mid is too large,
        // thus reducing end value.
        if (count_remove > n) {
            end = mid - 1;
            mid = (start + end) / 2;
        } else {
            answer = max(answer, mid);
            start = mid + 1;
            mid = (start + end) / 2;
        }
    }
    
    return answer;
}