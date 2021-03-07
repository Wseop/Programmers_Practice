// https://programmers.co.kr/learn/courses/30/lessons/42577?language=cpp

#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <stdlib.h>

using namespace std;

bool solution(vector<string> phone_book) {
    bool answer = true;
    multimap<int, string> pb_table;
    
    sort(phone_book.begin(), phone_book.end());
    //Fill pb_table
    for (vector<string>::iterator i = phone_book.begin(); i != phone_book.end(); i++) {
        pb_table.insert(pair<int, string>(i->size(), *i));
    }
    
    for (vector<string>::iterator target = phone_book.begin(); target != phone_book.end(); target++) {
        for (int len = target->size(); len < 20; len++) {
            multimap<int, string>::iterator pb_list = pb_table.find(len + 1);
            
            while (pb_list != pb_table.end()) {
                string prefix = pb_list->second.substr(0, target->size());
                
                if (prefix.compare(*target) == 0) {
                    return false;
                } else if (prefix.compare(*target) == 1) {
                    pb_list++;
                } else {
                    break;
                }
            }
            
        }        
    }
    return answer;
}