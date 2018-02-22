//  제곱수의 합
//  1699.cpp
//  AlgoriGym
//
//  Created by nicewoong on 2018. 2. 22..
//  Copyright © 2018년 nicewoong. All rights reserved.
//
//  See :  https://www.acmicpc.net/problem/1699
#include <stdio.h>
#include <iostream>
#define MAX_N 100000
using namespace std;


int d[MAX_N + 1] = {0};


int func(int N) {
   
    d[1] = 1;
    for(int n=2; n<=N; n++) {
        d[n] = n;
        for(int k=1; k*k<=n; k++){
            if(d[n] > d[n-k*k] + 1)  // if smaller then current
                d[n] = d[n-k*k] + 1; // update min
        }
        
    } // end of for
    
    return d[N];
} // end of func


int main () {
    int N;
    cin>> N;
    cout << func(N);
    
    return 0;
}
