// https://programmers.co.kr/learn/courses/30/lessons/42883?language=cpp

#include <string>
#include <vector>
#include <iostream>

using namespace std;

string solution(string number, int k) {
    string answer = "";

    for (int i = 0; i < k; i++) {
        string next_number_a = number.substr(1);
        string next_number_b;
        int len_number = number.size();

        for (int pos = 1; pos < len_number; pos++) {
            if (next_number_a[0] == 9) {
                break;
            }
            next_number_b = number;
            next_number_b = next_number_b.erase(pos, 1);

            if (next_number_b.compare(next_number_a) >= 1) {
                next_number_a = next_number_b;
            }
        }
        number = next_number_a;
    }
    answer = number;

    return answer;
}