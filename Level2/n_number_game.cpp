// https://programmers.co.kr/learn/courses/30/lessons/17687?language=cpp

#include <string>
#include <vector>

using namespace std;

string Convert(int num, int n) {
    char arr[16] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 
                    'A', 'B', 'C', 'D', 'E', 'F'};
    string ret = "";
    
    do {
        ret.insert(0, string(1, arr[num % n]));
        num /= n;
    } while (num != 0);
    
    return ret;
}

// number는 0부터 시작하며 변환할 때마다 1씩 증가
// 순번 i는 1부터 시작하며 매 loop마다 증가, m을 넘어서면 1부터 다시 시작
// number를 n진수로 변환하여 얻은 문자열을 탐색하며 순번(i)이 p와 같으면 answer에 추가
// 변환한 문자열이 매우 커서 answer의 크기가 t를 넘어서는 경우가 발생할 수 있으므로 최종적으로 t만큼만 잘라서 반환
string solution(int n, int t, int m, int p) {
    string answer = "";
    int number = 0;
    int i = 1;
    
    while (answer.size() < t) {
        string str = Convert(number++, n);
        for (int j = 0; j < str.size(); j++) {
            if (i == p) answer += str[j];
            i++;
            if (i > m) i = 1;
        }
    }
    answer = answer.substr(0, t);
    return answer;
}