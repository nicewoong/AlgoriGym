//  붕어빵 판매하기 문제
//
//  11052.cpp
//  algorithm_discipline
//
//  Created by nicewoong on 2018. 1. 24..
//  Copyright © 2018년 nicewoong. All rights reserved.
//
//  See : https://www.acmicpc.net/problem/11052

#include <stdio.h>
#define MAX_N 1001
#define MAX_SUM 10000001

int p[MAX_N] = {0};  //  j 개당 price
int d[MAX_N] = {0}; // 최대수익 .. MAx 다른 걸로 바꾸야함.

int func(int n) {
    d[0] = 0;

    for(int num = 1 ; num <= n ; num++){
        d[num] = p[1] + d[num-1];
        
        for(int i = 2; i<= num ; i++) {
            
            if(d[num] < p[i] + d[num-i])
                d[num] = p[i] + d[num-i];
            
        }// end of inner for
    
    }// end of for 

    return d[n];
}


int main() {
    int n;
    scanf("%d", &n);
    for(int i = 1 ; i <= n ; i++) {
        scanf("%d", &p[i]);
    }
    
    printf("%d\n", func(n));
    
    
    return 0;
}
