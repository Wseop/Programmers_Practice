// https://programmers.co.kr/learn/courses/30/lessons/60057?language=cpp

#include <string>
#include <vector>
#include <iostream>

using namespace std;

int solution(string s) {
    int answer = s.size();

    // 압축 가능한 문자열의 길이가 전체 문자열 크기의 절반을 넘어서면 압축 불가
    // 따라서, cut_size = 1 ~ (문자열 길이 / 2)
    for (int cut_size = 1; cut_size <= s.size() / 2; cut_size++) {
        string new_str = "";
        string cut_string = s.substr(0, cut_size);      // 압축할 문자열
        int count = 0;                                  // 압축 가능한 문자열 갯수
        int index = 0;                                  // substr을 추출할 시작 위치
        
        while (true) {
            string sub_s;
            
            // case 1. index가 size를 넘어서는 경우는 문자열의 길이에 딱 맞게 종료된 경우 -> count + 압축할 문자열을 붙인 후 종료
            // case 2. size를 초과하여 cut_size크기의 substr을 생성할 수 없는 경우 -> 남은 문자열까지 추가로 붙인 후 종료
            if (index > s.size()) {
                new_str += (count == 1) ? cut_string : to_string(count) + cut_string;
                break;
            } else if (index + cut_size > s.size()) {
                new_str += (count == 1) ? cut_string : to_string(count) + cut_string;
                new_str += s.substr(index, s.size() - index);
                break;
            }
            
            sub_s = s.substr(index, cut_size);
            if (sub_s == cut_string) {    
                count++;
                index += cut_size;
            } else {                       
                new_str += (count == 1) ? cut_string : to_string(count) + cut_string;
                count = 0;
                cut_string = sub_s;
            }
        }
        answer = (answer > new_str.size()) ? new_str.size() : answer;
    }
    
    return answer;
}