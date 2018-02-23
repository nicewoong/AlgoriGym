//  이친수 문제
//  2193.cpp
//  algorithm_discipline
//
//  Created by nicewoong on 2018. 1. 25..
//  Copyright © 2018년 nicewoong. All rights reserved.
//
//  See : https://www.acmicpc.net/problem/2193


#include <stdio.h>

#define MAX_N 91
long long one[MAX_N] = {0}; //  끝이 1인 경우의 수
long long zero[MAX_N] = {0}; //  끝이 0인 경우의 수

//  90자리 이친수의 갯수는 2880067194370816120 개
//  따라서 int 로 표현할 수 있는 정수 범위를 넘어선다.
long long func(int num) {
    one[0] = 0;
    zero[0] = 0;
    
    one[1] = 1;
    zero[1] = 0;
    
    one[2] = 0;
    zero[2] = 1;
    
    one[3] = 1;
    zero[3] = 1;
    
    for(int i = 4; i <= num ; i++) {
        one[i] = zero[i-1];
        zero[i] = one[i-1] + zero[i-1];
    }
    return one[num] + zero[num];
}


int main() {
    int n;
    scanf("%d", &n);
    printf("%lld\n", func(n));  //  long long 을 출력할 때는 %lld 임을 주의!
    return 0;
}
