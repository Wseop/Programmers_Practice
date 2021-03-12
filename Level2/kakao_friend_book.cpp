// https://programmers.co.kr/learn/courses/30/lessons/1829?language=cpp

#include <vector>
#include <queue>

using namespace std;

// BFS를 활용
// 탐색한 위치는 0으로 변경
vector<int> solution(int m, int n, vector<vector<int>> picture) {
    int number_of_area = 0;
    int max_size_of_one_area = 0;
    queue<pair<int, int>> q;
    int dy[4] = {-1, 0, 1, 0};
    int dx[4] = {0, 1, 0, -1};
    
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (picture[i][j] != 0) {
                int size_of_one_area = 0;
                int element = picture[i][j];
                
                q.push({i, j});
                picture[i][j] = 0;
                while (!q.empty()) {
                    pair<int, int> pos = q.front();
                    q.pop();
                    size_of_one_area++;
                    for (int d = 0; d < 4; d++) {
                        int ny = pos.first + dy[d];
                        int nx = pos.second + dx[d];
                        if (ny >= 0 && ny < m && nx >= 0 && nx < n && picture[ny][nx] == element) {
                            picture[ny][nx] = 0;
                            q.push({ny, nx});
                        } 
                    }
                }
                max_size_of_one_area = (max_size_of_one_area > size_of_one_area) ? max_size_of_one_area : size_of_one_area;
                number_of_area++;
            }
        }
    }
    
    vector<int> answer(2);
    answer[0] = number_of_area;
    answer[1] = max_size_of_one_area;
    return answer;
}