// https://programmers.co.kr/learn/courses/30/lessons/67257?language=cpp

// Comment...
// vector - erase : iterator가 가리키는 위치 삭제 후 다음 element를 가리킴
// vector - insert : iterator가 가리키는 위치의 앞에 삽입 후 삽입된 element를 가리킴

#include <string>
#include <vector>
#include <algorithm>

using namespace std;

long long DoCal(long long num1, long long num2, char op) {
    switch (op) {
        case '+':
            return num1 + num2;
        case '-':
            return num1 - num2;
        case '*':
            return num1 * num2;
    }
}

// iterator - erase, insert 활용
// next_permutation을 활용하여 가능한 모든 연산자 우선순위에 대해 탐색
long long solution(string expression) {
    long long answer = 0;
    vector<long long> results;
    string op = "+-*";
    vector<long long> operands_origin;
    vector<char> operators_origin;
    string operand = "";
    
    // next_permutation 사용을 위한 연산자 정렬
    sort(op.begin(), op.end());
    
    // expression parsing
    for (int i = 0; i < expression.size(); i++) {
        if (expression[i] >= '0' && expression[i] <= '9') {
            operand += expression[i];
        } else {
            operators_origin.push_back(expression[i]);
            operands_origin.push_back(stoi(operand));
            operand = "";
        }
    }
    operands_origin.push_back(stoi(operand));
    operand = "";
    
    do {
        vector<long long> operands = operands_origin;
        vector<char> operators = operators_origin;
        
        for (int i = 0; i < op.size(); i++) {
            auto iter_operand = operands.begin();
            auto iter_operator = operators.begin();
            
            while (iter_operator != operators.end()) {
                // 해당 연산자를 계산해야할 순서가 되면 iterator로 피연산자 2개를 구함
                // 계산 후 iterator가 가리키는 위치에 insert
                // 계산한 연산자는 제거
                if (*iter_operator == op[i]) {
                    long long num1 = *iter_operand;
                    iter_operand = operands.erase(iter_operand);
                    long long num2 = *iter_operand;
                    iter_operand = operands.erase(iter_operand);
                    iter_operand = operands.insert(iter_operand, DoCal(num1, num2, op[i]));
                    iter_operator = operators.erase(iter_operator);
                } else {
                    iter_operand++;
                    iter_operator++;
                }
            }
        }
        if (operands[0] < 0) operands[0] = -operands[0];
        results.push_back(operands[0]);
    } while (next_permutation(op.begin(), op.end()));
    sort(results.begin(), results.end());
    answer = results.back();
    
    return answer;
}