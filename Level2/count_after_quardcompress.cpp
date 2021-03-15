// https://programmers.co.kr/learn/courses/30/lessons/68936?language=cpp

#include <string>
#include <vector>

using namespace std;

// 입력 받은 범위 내에서 압축이 불가능하면 4구역으로 분할해가며 압축 진행
// 위 과정을 recursive하게 반복
void Compress(int x, int y, int size, vector<int>& ret, vector<vector<int>>& arr) {
    bool zero = true;
    bool one = true;
    
    // 0, 1 모두 나오는 경우 one, zero 둘다 false가 되어 분할 진행
    // 압축가능한 경우 해당하는 변수만 true가 되어 ++후 재귀 탈출
    for (int i = y; i < y + size; i++) {
        for (int j = x; j < x + size; j++) {
            if (arr[i][j] == 0) one = false;
            else zero = false;
        }
        if (!zero && !one) break;
    }
    if (zero) {
        ret[0]++;
        return;
    }
    if (one) {
        ret[1]++;
        return;
    }
    Compress(x, y, (size / 2), ret, arr);
    Compress((x + size / 2), y, (size / 2), ret, arr);
    Compress(x, (y + size / 2), (size / 2), ret, arr);
    Compress((x + size / 2), (y + size / 2), (size / 2), ret, arr);
}

vector<int> solution(vector<vector<int>> arr) {
    vector<int> answer(2, 0);
    
    Compress(0, 0, arr.size(), answer, arr);
    
    return answer;
}