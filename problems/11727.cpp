//  2×n 타일링 2 문제
//  11727.cpp
//  algorithm_discipline
//
//  Created by nicewoong on 2018. 1. 24..
//  Copyright © 2018년 nicewoong. All rights reserved.
//
//  See : https://www.acmicpc.net/problem/11727

#include <stdio.h>
#include <iostream>
#define MAX 1000
using namespace std;
    

int d[MAX] = {0};

int iterative_func(int n){
    d[0] = 1;
    d[1] = 1;
    d[2] = 3;
    for(int i = 3 ; i <= n ; i += 1) {
        d[i] = d[i-1] + (2 * d[i-2]);
        d[i] = d[i] % 10007;
    }
    
    return d[n] % 10007;
}

int main() {
    int n;
    scanf("%d", &n);
    int ans = iterative_func(n);
    printf("%d\n", ans);
}
