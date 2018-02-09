//
//  오르막 수 문제
//  11057.cpp
//  algorithm_discipline
//
//  Created by nicewoong on 2018. 2. 9..
//  Copyright © 2018년 nicewoong. All rights reserved.
//
//  See : https://www.acmicpc.net/problem/11057


#include <stdio.h>
#include <iostream>

#define MAX_N 1001
#define mod 10007
using namespace std;

long long d[MAX_N][10] = {0};

long long func(int N) {
    
    for(int k = 0; k <= 9 ; k++) {
        d[1][k] = 1;
    }
    
    for(int n = 2; n <= N; n = n+1) {
        for( int k=0; k<=9 ; k++) {
            for(int i=0; i<=k; i++) {
                d[n][k] += d[n-1][i];
                d[n][k] %= mod;
            }
        }
   }
    
    long long sum = 0;
    for(int k=0; k<=9; k++) {
        sum += d[N][k];
    }

    return sum % mod;
}

int main() {
    
    int n;
    scanf("%d", &n);
    printf("%lld\n", func(n));
    return 0 ;
}
