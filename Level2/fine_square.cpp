// https://programmers.co.kr/learn/courses/30/lessons/62048?language=cpp

using namespace std;

int GCD(int a, int b) {
    int temp, n;
    if (a < b) {
        temp = a;
        a = b;
        b = temp;
    }
    while (b != 0) {
        n = a % b;
        a = b;
        b = n;
    }
    return a;
}

// 특정 크기의 Block이 반복되는 모양
// 따라서, 최대공약수를 통해 영향을 받는 최소 Block에 대해 규칙을 찾음
// (w / 최대공약수) + (h / 최대공약수) - 1 : 반복되는 최소 단위의 Block에서 영향을 받는 사각형의 갯수
// 최대공약수만큼 반복되므로 위 식에 최대공약수를 곱함 -> (w + h - gcd)
long long solution(int w,int h) {
    long long answer = 1;
    int gcd = GCD(w, h);
    
    answer = ((long long)w * (long long)h) - (w + h - gcd);
    
    return answer;
}