#include <string>
#include <vector>
#include <map>
#include <set>
#include <iostream>

using namespace std;

int solution(vector<vector<string>> clothes) {
    int answer = 1;
    multimap<string, string> closet;
    vector<int> v;
    set<string> keys;
    
    //Move to closet
    for (int i = 0; i < clothes.size(); i++) {
        closet.insert(pair<string, string>(clothes[i][1], clothes[i][0]));
        keys.insert(clothes[i][1]);
    }
    for (set<string>::iterator i = keys.begin(); i != keys.end(); i++) {
        v.push_back(closet.count(*i));
        cout << closet.count(*i) << " ";
    }
    
    for (int i = 0; i < keys.size(); i++) {
        answer = answer * (v[i] + 1);
    }
    answer = answer - 1;
    
    return answer;
}