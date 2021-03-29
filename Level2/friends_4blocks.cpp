// https://programmers.co.kr/learn/courses/30/lessons/17679

// 반복문 중첩으로도 시간내에 해결가능한 문제, 천천히 정리하면서 해결하자...

#include <string>
#include <vector>
#include <set>

using namespace std;

// 2x2가 같은 캐릭터인지 확인하여 결과 반환
bool IsSquare(int x, int y, vector<string>& board) {
    if (board[y][x] != '#') {
        char c = board[y][x];
        if (c == board[y+1][x] && c == board[y][x+1] && c == board[y+1][x+1]) {
            return true;
        } else {
            return false;
        }
    } else {
        return false;
    }
}

// 1. 모든 칸을 돌면서 2x2가 같은 모양이면 <set>에 4point를 저장 -> <set>으로 중복 point가 발생하지 않도록 함
// 2. <set>에 저장된 point를 빈 칸(#)으로 변경 -> 1단계에서 미리 바꿀 경우 다음 loop에서 접근하는 point는 변경이 불가함
// 3. 빈 칸 내리기 진행
// 4. 1~3 반복
int solution(int m, int n, vector<string> board) {
    int answer = 0;
    
    while (true) {
    set<pair<int, int>> erase_points;
        
        // 2x2인지 체크 및 지워야할 포인트를 set에 기억
        for (int y = 0; y < m-1; y++) {
            for (int x = 0; x < n-1; x++) {
                if (IsSquare(x, y, board)) {
                    erase_points.insert({y, x});
                    erase_points.insert({y, x+1});
                    erase_points.insert({y+1, x});
                    erase_points.insert({y+1, x+1});
                }
            }
        }
        // 지워야할 포인트를 '#'으로 변경
        if (erase_points.size() == 0) break;
        else answer += erase_points.size();
        for (auto iter = erase_points.begin(); iter != erase_points.end(); iter++) {
            board[iter->first][iter->second] = '#';
        }
        // 빈 칸 내리기
        for (int x = 0; x < n; x++) {
            for (int y = m-1; y > 0; y--) {
                if (board[y][x] == '#') {
                    for (int i = y-1; i >= 0; i--) {
                        if (board[i][x] != '#') {
                            board[y][x] = board[i][x];
                            board[i][x] = '#';
                            break;
                        }
                    }
                }
            }
        }
    }
    
    return answer;
}