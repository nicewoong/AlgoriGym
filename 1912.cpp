//
//  연속합
//  1912.cpp
//  AlgoriGym
//
//  Created by nicewoong on 2018. 2. 14..
//  Copyright © 2018년 nicewoong. All rights reserved.
//
//  See : https://www.acmicpc.net/problem/1912

#include <stdio.h>



#define MAX_N 100000
using namespace std;

long d[MAX_N+1] = {0};
long A[MAX_N+1] = {0};

long func(int N) {
    long final_max = A[1];
    
    d[1] = A[1];
        
    
    for(int i=2; i<=N; i++) { // i 번째 수
        if(d[i-1] + A[i] < A[i])
            d[i] = A[i];
        else
            d[i] = d[i-1] + A[i];
        
        if(d[i] >  final_max)
            final_max = d[i];
    }
    
    return final_max;
    
}// end of func


int main() {
    int N = 0;
    scanf("%d\n", &N);

    for(int i=1; i<=N; i++) {
        scanf("%ld", &A[i]);
    }
    long ans = func(N);
    printf("%ld\n", ans);
    
    return 0;
}
