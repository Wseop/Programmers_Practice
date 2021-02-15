#include <string>
#include <vector>
#include <functional>

using namespace std;

const int cycle_a = 5;
const int cycle_b = 8;
const int cycle_c = 10;

vector<int> solution(vector<int> answers) {
    vector<int> answer;
    int score[3] ={0, 0, 0};
    int person_a[cycle_a] = {1, 2, 3, 4, 5};
    int person_b[cycle_b] = {2, 1, 2, 3, 2, 4, 2, 5};
    int person_c[cycle_c] = {3, 3, 1, 1, 2, 2, 4, 4, 5, 5};
    int winner_score = 0;
    
    // 모든 문제의 답을 탐색하며 정답인 사람의 score 값을 ++
    for (int i = 0; i < answers.size(); i++) {
        int answer = answers[i];
        
        if (answer == person_a[i % cycle_a]) score[0]++;
        if (answer == person_b[i % cycle_b]) score[1]++;
        if (answer == person_c[i % cycle_c]) score[2]++;
    }
    // 1위의 점수를 찾는 과정
    if (score[0] >= score[1] && score[0] >= score[2]) winner_score = score[0];
    else if (score[1] >= score[0] && score[1] >= score[2]) winner_score = score[1];
    else winner_score = score[2];
    
    for (int i = 0; i < 3; i++) {
        if (score[i] == winner_score) {
            answer.push_back(i + 1);
        }
    }
    
    return answer;
}