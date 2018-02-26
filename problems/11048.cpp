//
//  이동하기 
//  11048.cpp
//  AlgoriGym
//
//  Created by nicewoong on 2018. 2. 26..
//  Copyright © 2018년 nicewoong. All rights reserved.
//  See : https://www.acmicpc.net/problem/11048
//
#include <stdio.h>
#include <iostream>
#define MAX_N 3000


using namespace std;

long d[MAX_N+1][MAX_N+1] = {0}; // 각 방까지의 최대값 저장해나감.
int A[MAX_N+1][MAX_N+1] = {0}; // 각 방의 사탕 개수


long func(int N, int M) {
    
    for(int n=1; n<=N; n++) {
        
        for(int m=1; m<=M; m++) {
            // 1. 위에서 아래로 왔을 경우
            d[n][m] = d[n-1][m] + A[n][m];
            
            
            // 2. 왼쪽에서 오른쪽으로 왓을 경우
            if(d[n][m] < d[n][m-1] + A[n][m]) // 더 크면 업데이트
                d[n][m] = d[n][m-1] + A[n][m];
            
            
            // 3. 대각선위에서 현재로 왔을 경우
            if(d[n][m] < d[n-1][m-1] + A[n][m]) // 더 크면 업데이트
                d[n][m] = d[n-1][m-1] + A[n][m];
        }
    }// end of for
    
    return d[N][M];
    
}// end of func


int main() {
    
    int N, M;
    scanf("%d %d", &N, &M);
    for(int i=1; i<=N; i++) {
        for(int j=1; j<=M; j++ ){
            cin >> A[i][j];
        }
    }
    
    cout << func(N,M) << endl;
    
    return 0;
}
