#include <string>
#include <vector>
#include <iostream>

using namespace std;

int solution(int n, vector<int> lost, vector<int> reserve) {
    int answer = n - lost.size();
    int array_reserve[32] = {0, };
    int array_lost[32] = {0, };

    for (auto iter = lost.begin(); iter != lost.end(); iter++) {
        array_lost[*iter]++;
    }
    for (auto iter = reserve.begin(); iter != reserve.end(); iter++) {
        array_reserve[*iter]++;
    }
    for (int i = 1; i <= 30; i++) {
        if (array_lost[i] == 1 && array_reserve[i] == 1) {
            array_lost[i]--;
            array_reserve[i]--;
            answer++;
        }
    }
    for (int i = 1; i <= 30; i++) {
        if (array_lost[i] == 1) {
            if (array_reserve[i - 1] == 1) {
                array_reserve[i - 1]--;
                answer++;
            } else if (array_reserve[i + 1] == 1) {
                array_reserve[i + 1]--;
                answer++;
            }
        }
    }
    
    return answer;
}