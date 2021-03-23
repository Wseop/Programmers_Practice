// https://programmers.co.kr/learn/courses/30/lessons/70129?language=cpp

#include <string>
#include <vector>
#include <algorithm>

using namespace std;

// 10진수를 2진수로 변환 후 string type으로 반환
string Dec2Bin(int num) {
    string ret = "";
    
    while (num != 0) {
        if (num % 2 == 0) {
            ret += '0';
        } else {
            ret += '1';
        }
        num /= 2;
    }
    reverse(ret.begin(), ret.end());
    return ret;
}

// 1. 변환 횟수 counting
// 2. 0 제거 및 제거 횟수 counting
// 3. 0 제거한 결과의 길이를 2진수로 변환
// 4. 결과가 1이면 변환 횟수와 0제거 횟수 return
vector<int> solution(string s) {
    vector<int> answer;
    int count_zero = 0;
    int count_convert = 0;
    
    while (s != "1") {
        string zero_erased = "";
        int len;
        
        count_convert++;
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == '1') {
                zero_erased += '1';
            } else {
                count_zero++;
            }
        }
        len = zero_erased.size();
        s = Dec2Bin(len);
    }
    answer.push_back(count_convert);
    answer.push_back(count_zero);
    return answer;
}