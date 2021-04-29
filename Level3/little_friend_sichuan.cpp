// https://programmers.co.kr/learn/courses/30/lessons/1836?language=cpp

#include <string>
#include <vector>
#include <map>

using namespace std;

// 구현 문제
// 알파벳 순으로 탐색해야 하므로 multimap으로 타일별로 2개씩 좌표를 기억
// 두 타일의 x좌표가 같을 경우, y좌표가 같을 경우, xy 모두 다를 경우 각각 탐색 방법을 달리하여 구현
// 한 좌표라도 같으면 직선상에 경로 확인
// 두 좌표가 모두 다르면 아래 4가지 case로 구분하여 탐색
// | T . | T * | . T | * T |
// | * T | . T | T * | T . |
string solution(int m, int n, vector<string> board) {
    string answer = "";
    multimap<char, pair<int, int>> tile_info;

    // tile_info 초기화
    for (int i = 0; i < board.size(); i++) {
        for (int j = 0; j < board[i].size(); j++) {
            char c = board[i][j];
            if (c != '.' && c != '*') {
                tile_info.insert({c, {j, i}});
            }
        }
    }
    while (!tile_info.empty()) {
        char tile = '#';

        for (auto tile_itr = tile_info.begin(); tile_itr != tile_info.end(); ) {
            int x1 = tile_itr->second.first;
            int y1 = tile_itr->second.second;
            tile_itr++;
            int x2 = tile_itr->second.first;
            int y2 = tile_itr->second.second;
            tile_itr++;
            bool erase = true;

            if (x1 == x2) {
                for (int i = y1 + 1; i < y2; i++) {
                    if (board[i][x1] != '.') {
                        erase = false;
                        break;
                    }
                }
            } else if (y1 == y2) {
                for (int i = x1 + 1; i < x2; i++) {
                    if (board[y1][i] != '.') {
                        erase = false;
                        break;
                    }
                }
            } else {
                if (x1 < x2) {
                    for (int x = x1 + 1; x <= x2; x++) {
                        if (board[y1][x] != '.') {
                            erase = false;
                            break;
                        }
                        for (int y = y1 + 1; y < y2; y++) {
                            if (board[y][x2] != '.') {
                                erase = false;
                                break;
                            }
                        }
                    }
                    if (!erase) {
                        erase = true;
                        for (int y = y1 + 1; y <= y2; y++) {
                            if (board[y][x1] != '.') {
                                erase = false;
                                break;
                            }
                            for (int x = x1 + 1; x < x2; x++) {
                                if (board[y2][x] != '.') {
                                    erase = false;
                                    break;
                                }
                            }
                        }
                    }
                } else {
                    for (int x = x1 - 1; x >= x2; x--) {
                        if (board[y1][x] != '.') {
                            erase = false;
                            break;
                        }
                        for (int y = y1 + 1; y < y2; y++) {
                            if (board[y][x2] != '.') {
                                erase = false;
                                break;
                            }
                        }
                    }
                    if (!erase) {
                        erase = true;
                        for (int y = y1 + 1; y <= y2; y++) {
                            if (board[y][x1] != '.') {
                                erase = false;
                                break;
                            }
                            for (int x = x1 - 1; x > x2; x--) {
                                if (board[y2][x] != '.') {
                                    erase = false;
                                    break;
                                }
                            }
                        }
                    }
                }
            }
            if (erase) {
                tile_info.erase(board[y1][x1]);
                tile = board[y1][x1];
                board[y1][x1] = '.';
                board[y2][x2] = '.';
                break;
            }
        }
        if (tile == '#') {
            answer = "IMPOSSIBLE";
            break;
        } else {
            answer += tile;
        }
    }

    return answer;
}