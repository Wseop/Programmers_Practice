// https://programmers.co.kr/learn/courses/30/lessons/12904?language=cpp

#include <iostream>
#include <string>

using namespace std;

// substr을 사용할 경우 효율성 테스트 실패함 (주석처리된 코드) -> index값을 조절하여 substr을 구하지 않고 해결
// substr이 가장 길 경우부터 탐색하여 정답을 찾았을 경우 바로 return하여 탐색 시간을 최소화
// 맨 앞과 맨 뒤 index의 값을 비교하여 n/2만큼만 탐색
// substr의 길이에 따른 맨 앞/뒤 index는 line 23~24 참고
int solution(string s)
{
    int answer = 0;
    
    // answer를 substr의 길이로 사용, 최대 길이부터 하나씩 줄여나감
    for (answer = s.size(); answer > 1; answer--) {
        for (int i = 0; i <= (s.size() - answer); i++) {
            /*
            string sub_str = s.substr(i, answer);
            int left = 0;
            int right = sub_str.size() - 1;
            */
            int left = i;
            int right = (answer - 1) + i;
            bool succ = true;
            
            while (left < right) {
                /*
                if (sub_str[left] != sub_str[right]) {
                    succ = false;
                    break;
                }
                */
                if (s[left] != s[right]) {
                    succ = false;
                    break;
                }
                left++;
                right--;
            }
            if (succ) return answer;
        }
    }

    return answer;
}