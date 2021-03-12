// https://programmers.co.kr/learn/courses/30/lessons/68645?language=cpp

#include <string>
#include <vector>

using namespace std;

int triangle[1000][1000];
int dx[3] = {0, 1, -1};
int dy[3] = {1, 0, -1};

// 주어진 n만큼 아래, 오른쪽, 좌상단 방향으로 이동하며 숫자를 채우는 규칙
vector<int> solution(int n) {
    vector<int> answer;
    int num = 1;
    int x = 0, y = -1;
    
    // i는 채워나갈 방향 및 반복 횟수
    for (int i = 0; i < n; i++) {
        while (true) {
            // 방향 설정
            x += dx[i % 3];
            y += dy[i % 3];
            // 이미 채워진 값이거나 index를 벗어나면 채우기 Stop
            if (triangle[y][x] != 0 || y >= n || x >= n) {
                x -= dx[i % 3];
                y -= dy[i % 3];
                break;
            }
            triangle[y][x] = num++;
        }        
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j <= i; j++) {
            answer.push_back(triangle[i][j]);
        }
    }
    
    return answer;
}