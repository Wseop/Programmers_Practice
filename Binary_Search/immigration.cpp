// https://programmers.co.kr/learn/courses/30/lessons/43238?language=cpp

#include <string>
#include <vector>

using namespace std;

long long solution(int n, vector<int> times) {
    long long answer = 0;
    long long fastest_checker = 1000000000;
    
    // find the fastest checker
    for (int i = 0; i < times.size(); i++) {
        if (fastest_checker > times[i]) {
            fastest_checker = times[i];
        }
    }
    
    long long start = fastest_checker;      // at least one checker should work.
    long long end = fastest_checker * n;    // worst case is work only one person who is the fastest
    long long mid = (start + end) / 2;

    while (start <= end) {
        long long checked_person = 0;
        
        for (int i = 0; i < times.size(); i++) {
            checked_person += (mid / times[i]);
        }
        /*
        if (checked_person == n) {  // case 1. --> more faster case can be exist even if (checked_person == n)
            answer = mid;
            break;
        } else if (checked_person > n) { // case 2. 
            answer = mid;
            end = mid - 1;
        } else {    // case 3. checked_person < n
            start = mid + 1;
        }
        */
        if (checked_person >= n) {  // do same operate for case 1, 2
            answer = mid;
            end = mid - 1;
        } else {    // checked_person < n
            start = mid + 1;
        }
        mid = (start + end) / 2;
    }
    
    return answer;
}