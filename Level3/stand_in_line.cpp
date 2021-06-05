// https://programmers.co.kr/learn/courses/30/lessons/12936?language=cpp

#include <string>
#include <vector>

using namespace std;

long long fact(int n) {
    if (n == 1) return 1;
    return n * fact(n - 1);
}

// 각 자리마다 숫자가 바뀌는 순간 : fact(n) / n번째 -> slice로 칭함
// 경계에 있는 경우 계산을 편하게 하기 위해 k -= 1후 진행
// i번째에 k를 slice로 나눈 몫이 해당 자리에 와야할 숫자의 index
// k %= slice 후 반복
vector<int> solution(int n, long long k) {
    vector<int> answer;
    vector<int> numbers;

    for (int i = 1; i <= n; i++) {
        numbers.push_back(i);
    }
    k--;
    for (int i = n; i >= 1; i--) {
        long long slice = fact(i) / i;
        int index = k / slice;
        answer.push_back(numbers[index]);
        k %= slice;
        numbers.erase(numbers.begin() + index);
    }

    return answer;
}