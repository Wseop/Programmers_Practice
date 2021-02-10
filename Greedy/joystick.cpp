#include <string>
#include <vector>

using namespace std;

int solution(string name) {
    int answer = 0;
    int remains = 0;
    int len = name.size();
    int cursor = 0;
    int cursor_left = 0;
    int cursor_right = 0;

    for (auto iter = name.begin(); iter != name.end(); iter++) {
        if (*iter != 'A') {
            remains++;
        }
    }
    while (remains != 0) {
        if (name[cursor] != 'A') {
            if (('A' + 'Z') / 2 >= name[cursor]) {
                answer += name[cursor] - 'A';
            }
            else {
                answer += 'Z' - name[cursor] + 1;
            }
            remains--;
            name[cursor] = 'A';
        }
        if (remains == 0) {
            break;
        }
        for (int i = 1; i < len; i++) {
            cursor_left = cursor - i;
            if (cursor_left < 0) {
                cursor_left += len;
            }
            cursor_right = cursor + i;
            if (cursor_right >= len) {
                cursor_right = len - 1;
            }

            if (name[cursor_right] != 'A') {
                cursor = cursor_right;
                answer += i;
                break;
            }
            else if (name[cursor_left] != 'A') {
                cursor = cursor_left;
                answer += i;
                break;
            }
        }
    }

    return answer;
}