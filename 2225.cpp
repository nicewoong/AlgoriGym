//
//  합분해
//  2225.cpp
//  AlgoriGym
//
//  Created by nicewoong on 2018. 2. 22..
//  Copyright © 2018년 nicewoong. All rights reserved.
//  See : https://www.acmicpc.net/problem/2225
//

#include <stdio.h>
#include <iostream>
#define MAX_N 200
#define MAX_K 200
#define MOD 1000000000

using namespace std;


long long d[MAX_N+1][MAX_N + 1] = {0};

// 0부터 N까지의 정수 K개를 더해서 그 합이 N이 되는 경우의수.
// 0부터인 것을 주의하라.
long long func(int N, int K) {
    
    d[0][0] = 1;
    
    
    for(int n=0; n<=N; n++) {
        for(int k=1; k<=K; k++) {
            for(int j=0; j<=n; j++) {
                d[n][k] += d[n-j][k-1];
                d[n][k] %= MOD;
            }
            
        }
        
    }
    
    return d[N][K] % MOD;
}


int main() {
    
    int N, K;
    cin >> N >> K;
    cout << func(N,K) << "\n";
    
    return 0;
}
