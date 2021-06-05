#include <string>
#include <vector>
#include <set>

using namespace std;

bool WallCheck(vector<vector<pair<int, int>>>& wall, int x, int y, int obj) {
    if (obj == 0) {
        // 기둥 체크
        if ((y == 0) || 
            (wall[y - 1][x].first) || 
            (wall[y][x].second) || 
            (x - 1 >= 0 && wall[y][x - 1].second)) {
                return true;
        }
    } else {
        // 보 체크
        if ((y - 1 >= 0 && wall[y - 1][x].first) || 
            (y - 1 >= 0 && x + 1 <= wall.size() && wall[y - 1][x + 1].first) || 
            (x - 1 >= 0 && x + 1 <= wall.size() && wall[y][x - 1].second && wall[y][x + 1].second)) {
                return true;
        }
    }
    return false;
}

// 삭제 가능여부를 검사하는 것이 매우 까다로웠으나 크기가 작기 때문에 전체 탐색을 해도 무방함!!
// 설치 시에는 배치가 가능할 경우만 설치
// 삭제 시에는 우선 삭제 후 history를 기반으로 전체 탐색 후 삭제가 불가능한 경우이면 다시 설치
vector<vector<int>> solution(int n, vector<vector<int>> build_frame) {
    vector<vector<int>> answer;
    vector<vector<pair<int, int>>> wall;    // <기둥, 보>, 1이면 설치됨
    set<pair<int, int>> history;

    for (int i = 0; i <= n; i++) {
        vector<pair<int, int>> tmp(n + 1, {0, 0});
        wall.push_back(tmp);
    }
    for (int i = 0; i < build_frame.size(); i++) {
        int x = build_frame[i][0];
        int y = build_frame[i][1];
        int obj = build_frame[i][2];
        int op = build_frame[i][3];

        if (op == 1) {
            // 설치
            if (obj == 0) {
                // 기둥 설치
                wall[y][x].first = 1;
                if (WallCheck(wall, x, y, obj)) history.insert({x, y});
                else wall[y][x].first = 0;
            } else {
                // 보 설치
                wall[y][x].second = 1;
                if (WallCheck(wall, x, y, obj)) history.insert({x, y});
                else wall[y][x].second = 0;
            }
        } else {
            // 삭제
            if (obj == 0) {
                // 기둥 삭제
                wall[y][x].first = 0;
                for (auto itr = history.begin(); itr != history.end(); itr++) {
                    if (wall[itr->second][itr->first].first && !WallCheck(wall, itr->first, itr->second, 0)) {
                        wall[y][x].first = 1;
                        break;
                    }
                    if (wall[itr->second][itr->first].second && !WallCheck(wall, itr->first, itr->second, 1)) {
                        wall[y][x].first = 1;
                        break;
                    }
                }
            } else {
                // 보 삭제
                wall[y][x].second = 0;
                for (auto itr = history.begin(); itr != history.end(); itr++) {
                    if (wall[itr->second][itr->first].first && !WallCheck(wall, itr->first, itr->second, 0)) {
                        wall[y][x].second = 1;
                        break;
                    }
                    if (wall[itr->second][itr->first].second && !WallCheck(wall, itr->first, itr->second, 1)) {
                        wall[y][x].second = 1;
                        break;
                    }
                }
            }
        }
    }
    // 정렬 순서에 맞게 탐색 진행
    for (int x = 0; x <= n; x++) {
        for (int y = 0; y <= n; y++) {
            if (wall[y][x].first) {
                vector<int> tmp;
                tmp.push_back(x);
                tmp.push_back(y);
                tmp.push_back(0);
                answer.push_back(tmp);
            }
            if (wall[y][x].second) {
                vector<int> tmp;
                tmp.push_back(x);
                tmp.push_back(y);
                tmp.push_back(1);
                answer.push_back(tmp);
            }
        }
    }

    return answer;
}