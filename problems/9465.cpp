//
//  스티커 문제
//  9465.cpp
//  algorithm_discipline
//
//  Created by nicewoong on 2018. 2. 12..
//  Copyright © 2018년 nicewoong. All rights reserved.
//
//  See : https://www.acmicpc.net/problem/9465

#include <stdio.h>
#include <iostream>
#define MAX_N 100000

using namespace std;

long long d[MAX_N + 1][3] = {0}; // 0 : 위 아래 아무것도 선택 안 함. 1: 위의 것 선택 , 2: 아래 것 선택
long long score[2][MAX_N + 1] = {0};


long long mymax(long long one, long long two, long long three) {
    long long max_value = one;
    if(max_value < two)
        max_value = two;
    
    if(max_value < three )
        max_value = three;
    
    return max_value;
    
}


long long func(int N) {
    
    d[1][0] = 0; // 아무 것도 선택 안 함
    d[1][1] = score[0][1]; // 위의 것 선택
    d[1][2] = score[1][1]; // 밑의 것 선택
    
    for(int i = 2 ; i<= N ; i++) {
        d[i][0] = mymax(d[i-1][0], d[i-1][1], d[i-1][2] );  // i 번째에 아무 것도 선택 안 하기
        d[i][1] = score[0][i] + mymax(d[i-1][0], d[i-1][2], 0 );  // i 번째에 위의 것 선택 하기
        d[i][2] = score[1][i] + mymax(d[i-1][0], d[i-1][1], 0 );  // i 번째에 아래 것 선택 하기
    }
    
    return mymax(d[N][0], d[N][1], d[N][2]);
}


int main( ) {
    int T;
    int N;
    cin >> T; // input T
    
    //repeat number of T
    for(int i = 1 ; i <= T ; i++) {
        // read N
        cin >> N;
        
        for(int j = 1; j<= N ; j++ ) {
            cin >> score[0][j];
        }
        
        for(int j = 1; j<= N ; j++ ) {
            cin >> score[1][j];
        }
        
        cout << func(N) << "\n" ;
        
    }
    
    
    return 0;
    
}
