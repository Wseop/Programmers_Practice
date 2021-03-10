// https://programmers.co.kr/learn/courses/30/lessons/64061?language=cpp

#include <string>
#include <vector>
#include <stack>

using namespace std;

// 뽑은 인형은 stack에 넣음
// 넣기 전에 top에 같은 인형이 있으면 꺼냄 -> 넣을 인형, 꺼낸 인형 총 2개의 인형이 사라지므로 +2
int solution(vector<vector<int>> board, vector<int> moves) {
    int answer = 0;
    stack<int> basket;
    
    for (int i = 0; i < moves.size(); i++) {
        int position = moves[i] - 1;
        
        for (int j = 0; j < board.size(); j++) {
            if (board[j][position] != 0) {
                if (!basket.empty() && basket.top() == board[j][position]) {
                    answer += 2;
                    basket.pop();
                } else {
                    basket.push(board[j][position]);
                }
                board[j][position] = 0;
                break;
            }
        }
    }
    
    return answer;
}