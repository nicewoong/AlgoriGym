//
//  가장 큰 증가 부분 수열
//  11055.cpp
//  AlgoriGym
//
//  Created by nicewoong on 2018. 2. 13..
//  Copyright © 2018년 nicewoong. All rights reserved.
//
//  See : https://www.acmicpc.net/problem/11055

#include <stdio.h>
#include <iostream>
#define MAX_N 1000


using namespace std;


int A[MAX_N + 1] = {0};
int d[MAX_N + 1] = {0};


int func(int N)  {
    for(int i=1; i<=N; i++) {
        d[i] = A[i];
    }
    
    for(int i=1; i<=N; i++) {
        for(int j=1; j<i; j++) {
            if( (A[j] < A[i] ) && (d[j] + A[i] > d[i] ) )
                d[i] = d[j] + A[i];
        }
    }
    int max =0;
    for(int i=1; i<=N; i++) {
        if(max < d[i])
            max = d[i];
    }
    
    return max;
}


int main() {
    int N;
    cin >> N;
    for(int i=1; i<=N; i++) {
        cin >> A[i];
    }
    
    cout << func(N) << "\n";
    
    
    return 0;
}

