// https://programmers.co.kr/learn/courses/30/lessons/60059?language=cpp

#include <string>
#include <vector>

using namespace std;

// 1. 구멍 비교 (lock / key)
//      1-1. 0 / 0 -> fail
//      1-2. 1 / 1 -> fail
//      1-3. 0 / 1 -> match!
//      1-4. 1 / 0 -> 상관없음
// XOR 연산을 이용하면 fail case를 바로 걸러낼 수 있음

// 2. key를 아래 4가지 방향으로 옮겨가며 비교
//      2-1. 북서방향 -> lock은 항상 0, 0에서 시작 / key의 x, y 좌표의 시작 위치 변경
//      2-2. 북동방향 -> lock의 y좌표와 key의 x좌표는 항상 0에서 시작 / lock의 x좌표와 key의 y좌표의 시작 위치 변경
//      2-3. 남서방향 -> lock의 x좌표와 key의 y좌표는 항상 0에서 시작 / lock의 y좌표와 key의 x좌표의 시작 위치 변경
//      2-4. 남동방향 -> lock의 x, y 좌표의 시작 위치 변경 / key는 항상 0, 0에서 시작
vector<vector<int>> RotateKey(vector<vector<int>>& key) {
    vector<vector<int>> ret;
    
    for (int i = 0; i < key.size(); i++) {
        vector<int> tmp;
        for (int j = key[i].size() - 1; j >= 0; j--) {
            tmp.push_back(key[j][i]);
        }
        ret.push_back(tmp);
    }
    return ret;
}

bool solution(vector<vector<int>> key, vector<vector<int>> lock) {
    bool answer = false;
    int M = key.size();
    int N = lock.size();
    int hole_count = 0;
    
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (lock[i][j] == 0) hole_count++;
        }
    }
    
    for (int i = 0; i < 4; i++) {
        for (int ds = 0; ds < N; ds++) {
            for (int de = 0; de < N; de++) {
                int match_count = 0;
                bool success = true;
                for (int lock_y = ds, key_y = 0; lock_y < N && key_y < M; lock_y++, key_y++) {
                    for (int lock_x = de, key_x = 0; lock_x < N && key_x < M; lock_x++, key_x++) {
                        if ((lock[lock_y][lock_x] ^ key[key_y][key_x]) == 0) {
                            success = false;
                            break;
                        } else if (key[key_y][key_x] == 1) {
                            match_count++;
                        }
                    }
                    if (!success) break;
                }
                if (success && (match_count == hole_count)) return true;
            }
        }
        key = RotateKey(key);
    }
    for (int i = 0; i < 4; i++) {
        for (int dn = 0; dn < M; dn++) {
            for (int dw = 0; dw < M; dw++) {
                int match_count = 0;
                bool success = true;
                for (int lock_y = 0, key_y = dn; key_y < M; key_y++, lock_y++) {
                    for (int lock_x = 0, key_x = dw; key_x < M; key_x++, lock_x++) {
                        if ((lock[lock_y][lock_x] ^ key[key_y][key_x]) == 0) {
                            success = false;
                            break;
                        } else if (key[key_y][key_x] == 1) {
                            match_count++;
                        }
                    }
                    if (!success) break;
                }
                if (success && (match_count == hole_count)) return true;
            }
        }
        key = RotateKey(key);
    }
    for (int i = 0; i < 4; i++) {
        for (int ds = 0; ds < N; ds++) {
            for (int dw = 0; dw < M; dw++) {
                int match_count = 0;
                bool success = true;
                for (int lock_y = ds, key_y = 0; lock_y < N && key_y < M; lock_y++, key_y++) {
                    for (int lock_x = 0, key_x = dw; lock_x < N && key_x < M; lock_x++, key_x++) {
                        if ((lock[lock_y][lock_x] ^ key[key_y][key_x]) == 0) {
                            success = false;
                            break;
                        } else if (key[key_y][key_x] == 1) {
                            match_count++;
                        }
                    }
                    if (!success) break;
                }
                if (success && (match_count == hole_count)) return true;
            }
        }
        key = RotateKey(key);
    }
    for (int i = 0; i < 4; i++) {
        for (int dn = 0; dn < N; dn++) {
            for (int de = 0; de < N; de++) {
                int match_count = 0;
                bool success = true;
                for (int lock_y = 0, key_y = dn; lock_y < N && key_y < M; lock_y++, key_y++) {
                    for (int lock_x = de, key_x = 0; lock_x < N && key_x < M; lock_x++, key_x++) {
                        if ((lock[lock_y][lock_x] ^ key[key_y][key_x]) == 0) {
                            success = false;
                            break;
                        } else if (key[key_y][key_x] == 1) {
                            match_count++;
                        }
                    }
                    if (!success) break;
                }
                if (success && (match_count == hole_count)) return true;
            }
        }
        key = RotateKey(key);
    }
    
    return answer;
}