#include <string>
#include <vector>
#include <functional>

using namespace std;

vector<int> solution(vector<int> array, vector<vector<int>> commands) {
    vector<int> answer;
    vector<int>::iterator pos_s;
    vector<int>::iterator pos_e;
    int target;
    
    for (int i = 0; i < commands.size(); i++) {
        pos_s = array.begin() + commands[i][0] - 1;
        pos_e = array.begin() + commands[i][1];
        target = commands[i][2] - 1;
        
        vector<int> sub_array (pos_s, pos_e);
        sort(sub_array.begin(), sub_array.end());
        answer.push_back(sub_array[target]);
    }
    
    return answer;
}