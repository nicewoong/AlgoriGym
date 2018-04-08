//
//  1학년
//  5557.cpp
//  AlgoriGym
//
//  Created by nicewoong on 2018. 4. 8..
//  Copyright © 2018년 nicewoong. All rights reserved.
//  https://www.acmicpc.net/problem/5557
//

#include <cstdio>
#include <iostream>
#define MAX_RESULT 20 // 0~20
#define MAX_N 100 // 3~100

using namespace std;


long long d[MAX_RESULT + 1][MAX_N + 1] = {0};
int A[MAX_N + 1]  = {0};

void print_mat(int N) {
    for(int m=0; m<=MAX_RESULT; m++) {
        for(int n=1; n<=N; n++) {
            printf("%3lld", d[m][n]) ;
        }
        cout << endl;
    }
}

long long func(int N) {
    int start_num = A[1];
    
    d[start_num][1] = 1;
    

    for(int n=1; n<=N-2; n++) { // 마지막 숫자는 덧셈 뺄셈에 사용되지 않고 = 다음에 오는 결과의 숫자이므로 반복문의 범위를 제한한다!!
        int result_of_plus = 0 ;
        int result_of_minus = 0;
        
        for(int m=0; m<=MAX_RESULT; m++) {
            if(d[m][n] > 0) { // 해당 숫자가 가능하다면, 해당 숫자에서 +,- 해서 그 다음 숫자에 경우의 수 바톤 더해서 넘겨주자
                // '+'
                result_of_plus = m + A[n+1];
                // 범위에 벗어나지 않으면 다음 n+1단게의 해당 숫자에 경우의 수 += 해준다.
                if(result_of_plus >= 0 && result_of_plus <= MAX_RESULT) {
                    d[result_of_plus][n+1] += d[m][n];
                }
                
                // '-'
                result_of_minus = m - A[n+1];
                // 범위에 벗어나지 않으면 다음 n+1단게의 해당 숫자에 경우의 수 += 해준다.
                if(result_of_minus >= 0 && result_of_minus <= MAX_RESULT) {
                    d[result_of_minus][n+1] += d[m][n];
                }
            }
            
        }// end of inner for
    }// end of outer for
    
    int final_index = A[N];
    
//    print_mat(N);
    
    return d[final_index][N-1];
    
}// end of func()


int main() {
    int N;
    cin >> N;
    for(int i=1; i<=N; i++) {
        cin >> A[i];
    }
    
    cout << func(N) << endl;
    
    return 0;
}
