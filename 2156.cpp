//
//  포도주 시식 문제
//  main.cpp
//  AlgoriGym
//
//  Created by nicewoong on 2018. 2. 13..
//  Copyright © 2018년 nicewoong. All rights reserved.
//
//  See  : https://www.acmicpc.net/problem/2156
//

#include <iostream>
#include <stdio.h>
#define MAX_N 10000
#define MAX_WINE 1000
using namespace std;


long long d[MAX_N + 1][2] = {0};
int wine[MAX_N + 1] = {0};


long long func(int N) {
    d[1][1] = wine[1];
    d[1][0] = 0;
    d[2][1] = wine[1] + wine[2];
    d[2][0] = wine[1];
    
    for(int n = 3 ; n <= N; n++) {
        if( d[n-1][0] > d[n-1][1])
            d[n][0] = d[n-1][0];
        else
            d[n][0] = d[n-1][1];
        
        long long max = d[n-2][0] + wine[n];
        if(d[n-2][0] + wine[n-1] + wine[n] > max)
            max = d[n-2][0] + wine[n-1] + wine[n];
        if(d[n-2][1] + wine[n] > max)
            max = d[n-2][1] + wine[n];
        
        d[n][1] = max;
    } // end of for
    
    // return max sum
    if( d[N][0] > d[N][1])
        return d[N][0];
    else
        return d[N][1];
}// end of function


int main(int argc, const char * argv[]) {
    int N = 0;
    scanf("%d", &N);  // number of wine
    
    for(int i = 1; i <= N ; i++) {
        scanf("%d", &wine[i]);
    }
    
    cout << func(N) << "\n";
    
    
}
