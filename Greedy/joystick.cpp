#include <string>
#include <vector>

using namespace std;

int solution(string name) {
    int answer = 0;
    int remains = 0;    // 'A'로 만들기 위해 작업해야할 갯수
    int len = name.size();
    int cursor = 0;
    int cursor_left = 0;
    int cursor_right = 0;
    // 'A'가 아닌 경우 작업해야할 갯수에 추가
    for (auto iter = name.begin(); iter != name.end(); iter++) {
        if (*iter != 'A') {
            remains++;
        }
    }
    while (remains != 0) {
        // 'A'로 변경하는 작업 수행
        // 위, 아래 중 빠른 방향으로
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
        // 모두 변경이 되었으면 종료
        if (remains == 0) {
            break;
        }
        for (int i = 1; i < len; i++) {
            // 좌, 우 방향 커서의 위치 지정 (1씩 이동)
            cursor_left = cursor - i;
            if (cursor_left < 0) {
                cursor_left += len;
            }
            cursor_right = cursor + i;
            if (cursor_right >= len) {
                cursor_right = len - 1;
            }
            // 'A'가 아닌 값을 찾았으면 해당 위치로 커서 변경
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