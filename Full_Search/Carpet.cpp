#include <string>
#include <vector>

using namespace std;

vector<int> solution(int brown, int yellow) {
    vector<int> answer;
    int x, y;   //예상되는 가로, 세로 길이를 위한 변수
    
    //brown 값을 기준으로 가능한 가로, 세로의 길이를 모두 탐색
    for (x = (brown / 2) - 1; x >= 0; x--) {
        int predict_y = 0;
        
        y = ((brown - (x * 2)) / 2) + 2;
        
        //예측한 가로, 세로길이로 yellow를 만들 수 있는지 확인
        predict_y = (x - 2) * (y - 2);
        if (predict_y == yellow) {
            break;
        }
    }
    answer = {x, y};
    return answer;
}