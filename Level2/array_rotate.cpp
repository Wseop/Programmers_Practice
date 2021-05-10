// https://programmers.co.kr/learn/courses/30/lessons/77485?language=cpp

#include <string>
#include <vector>
#include <algorithm>

using namespace std;

void Swap(int& a, int& b) {
    int temp = a;
    a = b;
    b = temp;
}

vector<int> solution(int rows, int columns, vector<vector<int>> queries) {
    vector<int> answer;
    vector<vector<int>> array(rows + 1, vector<int>(columns + 1, 0));
    
    int num = 1;
    for (int i = 1; i <= rows; i++) {
        for (int j = 1; j <= columns; j++) {
            array[i][j] = num++;
        }
    }
    
    for (vector<int> query : queries) {
        int y1 = query[0];
        int x1 = query[1];
        int y2 = query[2];
        int x2 = query[3];
        int temp = array[y1][x1];
        int min_num = temp;

        for (int i = x1; i < x2; i++) {
            Swap(temp, array[y1][i + 1]);
            min_num = min(min_num, temp);
        }
        for (int i = y1; i < y2; i++) {
            Swap(temp, array[i + 1][x2]);
            min_num = min(min_num, temp);
        }
        for (int i = x2; i > x1; i--) {
            Swap(temp, array[y2][i - 1]);
            min_num = min(min_num, temp);
        }
        for (int i = y2; i > y1; i--) {
            Swap(temp, array[i - 1][x1]);
            min_num = min(min_num, temp);
        }
        answer.push_back(min_num);
    }
    
    return answer;
}