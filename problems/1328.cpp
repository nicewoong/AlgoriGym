//  고층 빌딩
//  1328.cpp
//  AlgoriGym
//
//  Created by nicewoong on 2018. 4. 4..
//  Copyright © 2018년 nicewoong. All rights reserved.
//  https://www.acmicpc.net/problem/1328
//

#include <cstdio>
#include <iostream>
#define MOD 1000000007LL
#define MAX_N 100


using namespace std;
long long d[MAX_N + 1][MAX_N + 1][MAX_N + 1] = {0};


long long func(int N, int L, int R) {
    
    
//    for(int n=1; n<=N; n++) {
//        d[n][n][1] = 1;  // 계단식 한가지
//        d[n][1][n] = 1;  // 계단식 한가지
//    }
//
//    d[2][1][1] = 2;

    d[1][1][1] = 1LL;
    
    for(int n=2; n<=N; n++) {
        for(int l=1; l<=L; l++) {
            for(int r=1; r<=R ; r++) {
                d[n][l][r] += d[n-1][l][r]*(n-2) + d[n-1][l-1][r] + d[n-1][l][r-1];
                d[n][l][r] %= MOD;
                
            }// end of inner for
        }
    }// end of outer for
    
    
    return d[N][L][R] % MOD;
    
}// end of func()


int main() {

    int N;  // 건물 전체 갯수
    int L;  // left 에서 봤을 때 보이는 건물 수
    int R;  // right 에서 봤을 때 보이는 건물 수
    cin >> N >> L >> R ;
    cout << func(N, L, R) << endl;
    
}
