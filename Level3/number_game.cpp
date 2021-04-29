// https://programmers.co.kr/learn/courses/30/lessons/12987?language=cpp

#include <string>
#include <vector>
#include <algorithm>

using namespace std;

// Greedy???
// 정렬 후 A < B인 B값의 갯수를 반환
// 처음에 B만 정렬해서 해결하려고 했으나 이 경우 for 중첩이 불가피해짐
// B는 아무때나 아무숫자를 낼 수 있으므로 A까지 정렬해도 상관이 없음!
int solution(vector<int> A, vector<int> B) {
    int answer = 0;
    int index_a = 0, index_b = 0;

    sort(A.begin(), A.end());
    sort(B.begin(), B.end());

    while (index_b < B.size()) {
        if (A[index_a] < B[index_b]) {
            answer++;
            index_a++;
        }
        index_b++;
    }

    return answer;
}