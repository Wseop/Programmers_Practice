#include <string>
#include <vector>
#include <functional>

using namespace std;

bool compare(string a, string b) {
    return (a + b) > (b + a);
}

string solution(vector<int> numbers) {
    string answer = "";
    vector<string> sNumbers;
    
    for (int i = 0; i < numbers.size(); i++) {
        sNumbers.push_back(to_string(numbers[i]));
    }
    sort(sNumbers.begin(), sNumbers.end(), compare);
    for (int i = 0 ; i < sNumbers.size(); i++) {
        answer += sNumbers[i];
    }
    if (answer[0] == '0') answer = '0';
    return answer;
}