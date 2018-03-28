//
//  구간 나누기
//  2228.cpp
//  AlgoriGym
//
//  Created by nicewoong on 2018. 3. 28..
//  Copyright © 2018년 nicewoong. All rights reserved.
//  https://www.acmicpc.net/problem/2228
//

#include <cstdio>
#include <iostream>
#define MAX_N 100
#define MIN -3276800
using namespace std;
int A[MAX_N + 1] = {0};
int d[MAX_N + 1][MAX_N/2] = {0}; //d[n][m] = 1~n 까지 m에 나누어 담은 최대 총합.
int visited[MAX_N + 1][MAX_N/2] = {0};

int func(int cur_N, int cur_M) {

    if(cur_M==0)
        return 0;
    
    if(cur_N<1)
        return MIN;
    
    if(visited[cur_N][cur_M] != 0) // 이미 방문함.
        return d[cur_N][cur_M];
    
    visited[cur_N][cur_M] = 1;
    
    // 현재 N번째 요소가 포함안 될 때
    d[cur_N][cur_M] = func(cur_N-1, cur_M);
    
    // 현재 N 번째 요소까지 구간에 포함 될 때
    for(int k=1; k<=cur_N; k++) {
        int sum =0;
        for(int i=k; i<=cur_N ; i++) {
            sum += A[i];
        }
        
        int result = func(k-2, cur_M-1) + sum;
        if( d[cur_N][cur_M] < result) // 더 크다면, update
            d[cur_N][cur_M] = result;
    }// end of for
    
    return d[cur_N][cur_M];
}


int main () {
    
    int N;  // 총 배열 값 갯수
    int M;  // 구간 갯수
    cin >> N >> M;
    for(int i=1; i<=N; i++ ){
        cin >> A[i];
    }
    int res = func(N, M);
    cout << res << endl;
    
    return 0;
}
