//
//  타일 채우기
//  2133.cpp
//  AlgoriGym
//
//  Created by nicewoong on 2018. 2. 22..
//  Copyright © 2018년 nicewoong. All rights reserved.
//  See: https://www.acmicpc.net/problem/2133
//

#include <stdio.h>
#include <iostream>
#define MAX_N 30


using namespace std;


long long d[MAX_N + 1] = {0};


long long func(int N) {
    d[0] = 1;
    d[2] = 3;

    // N 이 홀 수 이면 0
    for(int n=4; n<=N; n++) {
        if(n%2==1)
            d[n] = 0;
        else {
            d[n] = d[n-2]*3;
            for(int k=4; k<=n; k=k+2)
            {
                d[n] += d[n-k]*2;
            }


        }
    }

    return d[N];
}

int main() {

    int N;
    cin >> N;
    cout<< func(N) << "\n";
    
    return 0;
}


