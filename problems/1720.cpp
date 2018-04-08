//
//  타일 코드
//  1720.cpp
//  AlgoriGym
//
//  Created by nicewoong on 2018. 4. 8..
//  Copyright © 2018년 nicewoong. All rights reserved.
//  https://www.acmicpc.net/problem/1720
//

#include <cstdio>
#include <iostream>
#define MAX_N 30

using namespace std;
long long A[MAX_N + 1]; // 모든 경우의 수 저장
long long S[MAX_N + 1]; // 대칭인 것 갯수를 저장


long long func(int N) {
    
    S[0] = 1;
    S[1] = 1;
    S[2] = 3;
    S[3] = 1;
    
    A[0] = 1;
    A[1] = 1;
    
    for(int n=2; n<=N; n++) {
        A[n] = A[n-1] + 2*A[n-2];
        
    }
   
    for(int n=4; n<=N; n++) {
        S[n] = S[n-2] + 2*S[n-4];
    }
    
    if(N<=2) {
        return A[N];
    }

    
    return (A[N] - S[N])/2 + S[N];
    
}

int main() {
    int N;
    cin >> N;
    

    cout << func(N) << endl;
    
    
    return 0;
}
