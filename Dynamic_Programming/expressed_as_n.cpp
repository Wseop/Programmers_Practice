// https://programmers.co.kr/learn/courses/30/lessons/42895?language=cpp

#include <string>
#include <vector>
#include <set>
#include <cmath>
#include <iostream>

using namespace std;

int solution(int N, int number) {
    int answer = 0;
    vector<set<int> > mem;   // i개의 N으로 만들 수 있는 수들의 집합
    set<int> temp_mem;
    
    // mem 초기화
    temp_mem.insert(0);
    mem.push_back(temp_mem);
    temp_mem.clear();
    temp_mem.insert(N);
    mem.push_back(temp_mem);
    temp_mem.clear();
    
    if (N == number) {
        return 1;
    }
    for (int i = 2; i <= 8; i++) {
        for (int j = 1; i - j >= j; j++) {
            set<int> set_a = mem[j];
            set<int> set_b = mem[i - j];
            
            for (auto iter_a = set_a.begin(); iter_a != set_a.end(); iter_a++) {
                for (auto iter_b = set_b.begin(); iter_b != set_b.end(); iter_b++) {
                    int result;
                    
                    // +
                    result = *iter_a + *iter_b;
                    if (result == number) {
                        return i;
                    } else {
                        temp_mem.insert(result);
                    }
                    // -
                    result = *iter_a - *iter_b;
                    if (result == number) {
                        return i;
                    } else {
                        temp_mem.insert(result);
                    }
                    result = *iter_b - *iter_a;
                    if (result == number) {
                        return i;
                    } else {
                        temp_mem.insert(result);
                    }
                    // *
                    result = (*iter_a) * (*iter_b);
                    if (result == number) {
                        return i;
                    } else {
                        temp_mem.insert(result);
                    }
                    // /
                    if (*iter_b != 0) {
                        result = *iter_a / *iter_b;
                        if (result == number) {
                            return i;
                        } else {
                            temp_mem.insert(result);
                        }
                    }
                    if (*iter_a != 0) {
                        result = *iter_b / *iter_a;
                        if (result == number) {
                            return i;
                        } else {
                            temp_mem.insert(result);
                        }
                    }
                    // NN
                    result = 0;
                    for (int k = 0; k < i; k++) {
                        result += N * pow(10, k);
                    }
                    if (result == number) {
                        return i;
                    } else {
                        temp_mem.insert(result);
                    }
                }
            }
        }
        mem.push_back(temp_mem);
        temp_mem.clear();
    }
    
    return -1;
}