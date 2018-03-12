//
//  동전 2
//  2294.cpp
//  AlgoriGym
//
//  Created by nicewoong on 2018. 3. 12..
//  Copyright © 2018년 nicewoong. All rights reserved.
//  https://www.acmicpc.net/problem/2294
//

#include <cstdio>
#include <iostream>
#define MAX_N 100
#define MAX_K 10000

using namespace std;

int COIN[MAX_N + 1] = {0};
int d[MAX_K + 1] = {0}; // 최소 동전 갯수를 저장할 것임


int func(int N, int K) {
    
    for(int coin_index = 1; coin_index <= N; coin_index ++) {
        int cur_coin = COIN[coin_index]; // 현재 코인 얼마짜리
        if(cur_coin > K)
            continue;
        
        d[cur_coin] = 1;
        for(int k=cur_coin; k<=K; k++) {
            // 더 작으면 교체
            if(d[k-cur_coin]==0)
                continue;
            
            if(d[k] == 0 || d[k] > d[k-cur_coin] + 1)
                d[k] = d[k-cur_coin] + 1;
        }
    }
    
    int result = d[K];
    if(result == 0)
        return -1;
    
    return result;
}

int main() {
    int N, K;
    cin >> N >> K;
    
    for(int i=1; i<=N; i++) {
        cin >> COIN[i] ;
    }
    
    cout << func(N, K) << endl;
    
    
    return 0;
}
