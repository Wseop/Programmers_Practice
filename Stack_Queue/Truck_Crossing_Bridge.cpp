#include <string>
#include <vector>
#include <queue>

using namespace std;

int solution(int bridge_length, int weight, vector<int> truck_weights) {
    int answer = 0;
    queue<int> bridge;
    int i = 0;
    int passing = 0;
    
    do {
        answer++;
        if (bridge.size() == bridge_length) {
            if (bridge.front() != 0) {
                passing--;
                weight += bridge.front();
            }
            bridge.pop();
        }
        if ((i < truck_weights.size()) && (weight >= truck_weights[i])) {
            bridge.push(truck_weights[i]);
            weight -= truck_weights[i];
            i++;
            passing++;
        } else {
            bridge.push(0);
        }
    } while (passing > 0);
    return answer;
}