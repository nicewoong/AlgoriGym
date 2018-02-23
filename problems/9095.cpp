//  1, 2, 3 더하기 문제
//  9095.cpp
//  algorithm_discipline
//
//  Created by nicewoong on 2018. 1. 24..
//  Copyright © 2018년 nicewoong. All rights reserved.
//
//  See : https://www.acmicpc.net/problem/9095

#include <stdio.h>
#define MAX 1000

int d[MAX] = {0};

int func(int n) {
    d[1] = 1;
    d[2] = 2;
    d[3] = 4;
    for(int i = 4 ; i<=n ; i+=1) {
        d[i] = d[i-1] + d[i-2] + d[i-3];
    }
    return d[n];
    
}

int main() {
    int count = 0;
    int num = 0;
    scanf("%d", &count);
    for(int i = 0 ; i<count ; i +=1 ) {
        scanf("%d", &num);
        printf("%d\n", func(num));
    }
    
    return 0;
}
