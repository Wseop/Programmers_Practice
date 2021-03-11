// https://programmers.co.kr/learn/courses/30/lessons/60057?language=cpp

#include <string>
#include <vector>
#include <iostream>

using namespace std;

// Need to edit!!!
int solution(string s) {
    int answer = s.size();
    
    for (int cut_size = 1; cut_size <= s.size(); cut_size++) {
        string new_str = "";
        string cut_string = s.substr(0, cut_size);
        int count = 0;
        
        for (int index = 0; index < s.size();) {
            string sub_s;
            
            if (s.size() - index < cut_size) {
                new_str += cut_string;
                new_str += s.substr(index, s.size() - index);
                break;
            }
            sub_s = s.substr(index, cut_size);
            if (sub_s == cut_string) {
                count++;
                index += cut_size;
                if (index == s.size()) 
                    new_str += (count == 1) ? cut_string : (to_string(count) + cut_string);
            } else {
                new_str += (count == 1) ? cut_string : (to_string(count) + cut_string);
                count = 0;
                cut_string = sub_s;
            }
        }
        //cout << new_str << endl;
        answer = (new_str.size() < answer) ? new_str.size() : answer;
    }
    
    return answer;
}