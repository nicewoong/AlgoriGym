//
//  가장 긴 증가하는 부분 수열
//  11053.cpp
//  AlgoriGym
//
//  Created by nicewoong on 2018. 2. 13..
//  Copyright © 2018년 nicewoong. All rights reserved.
//
//  See:  https://www.acmicpc.net/problem/11053

#include <stdio.h>
#include <iostream>
#define MAX_N 1000


using namespace std;


int A[MAX_N + 1] = {0};
int d[MAX_N + 1] = {0};

int func(int N){
    for(int i=1; i<=N; i++) {
        d[i] = 1;
    }

    for(int i=1; i<=N; i++) {
        for(int j=1; j<i; j++) {
            if( (A[j] < A[i]) && (d[j]+1 > d[i]) )
                d[i] = d[j]+1 ;
        }

    }

    int max = 0;
    for(int i=1; i<=N; i++) {
        if(max < d[i])
            max = d[i];
    }

    return max;

}


int main() {
    int N;
    cin >>  N;

    for(int i=1; i<=N; i++) {
        cin >> A[i];
    }

    cout << func(N) << "\n";

    return 0;
}

