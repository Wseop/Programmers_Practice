#include <string>
#include <vector>

using namespace std;

vector<int> solution(int brown, int yellow) {
    vector<int> answer;
    int x, y;
    
    for (x = (brown / 2) - 1; x >= 0; x--) {
        int predict_y = 0;
        
        y = ((brown - (x * 2)) / 2) + 2;
        predict_y = (x - 2) * (y - 2);
        if (predict_y == yellow) {
            break;
        }
    }
    answer = {x, y};
    return answer;
}