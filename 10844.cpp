
//  쉬운 계단 수 문제
//  10844.cpp
//  algorithm_discipline
//
//  Created by nicewoong on 2018. 1. 25..
//  Copyright © 2018년 nicewoong. All rights reserved.
//
//  See: https://www.acmicpc.net/problem/10844

#include <stdio.h>
#define MAX 101
long long d[MAX][10] = {0};

long long func(int n) {
    
    d[1][0] = 0;
    for(int k = 1; k <= 9 ; k++) {
        d[1][k] = 1;
    }
    
    for(int i = 2; i <= n ; i++) {
        for(int k = 0; k<=9 ; k++) {
            
            if(k==0) {
                d[i][k] = d[i-1][k+1] % 1000000000;
            }else if(k==9) {
                d[i][k] = d[i-1][k-1] % 1000000000;
            }else {
                d[i][k] = d[i-1][k+1] + d[i-1][k-1] % 1000000000;
            }
        }
    }
    long long sum= 0;
    for(int k = 0; k<=9 ; k++) {
        sum += d[n][k];
    }
    

    return sum % 1000000000;
}

int main() {
    int n;
    scanf("%d", &n);
    printf("%lld\n", func(n));
    
    return 0;
}
