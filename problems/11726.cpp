//  2×n 타일링 문제
//  11726.cpp
//  algorithm_discipline
//
//  Created by nicewoong on 2018. 1. 23..
//  Copyright © 2018년 nicewoong. All rights reserved.
//
//  See : https://www.acmicpc.net/problem/11726

#include <stdio.h>
#include <iostream>
#define MAX 1001

using namespace std;
int d[MAX] = {0};

int f(int n) {
    d[0] = 1;
    d[1] = 1;
    d[2] = 2;
    
    if(n<3)
        return d[n];
    
    for(int i = 3; i <= n; i += 1) {
        d[i] = (d[i-1] + d[i-2])%10007;
    }
    
    return d[n];
}


int main() {
    int input;
    scanf("%d", &input);
    printf("%d\n", f(input) );
    
}
