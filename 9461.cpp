//
//  파도반 수열
//  9461.cpp
//  AlgoriGym
//
//  Created by nicewoong on 2018. 2. 22..
//  Copyright © 2018년 nicewoong. All rights reserved.
//  See: https://www.acmicpc.net/problem/9461
//

#include <stdio.h>
#include <iostream>
#define MAX_N 100
using namespace std;

long long d[MAX_N + 1] = {0};

long long func(int N) {
    d[1] = 1;
    d[2] = 1;
    d[3] = 1;
    d[4] = 2;
    d[5] = 2;
    for(int n=6; n<=N; n++) {
        d[n] = d[n-1] + d[n-5];
    }
    
    return d[N];
}

int main() {
    
    int count;
    cin >> count;
    int N;
    for(int i=1; i<=count; i++) {
        
        cin >> N;
        cout << func(N) << "\n";
    }
}






