//
//  계단 오르기 문제
//  2579.cpp
//  AlgoriGym
//
//  Created by nicewoong on 2018. 2. 20..
//  Copyright © 2018년 nicewoong. All rights reserved.
//
//  See : https://www.acmicpc.net/problem/2579
//


#include <stdio.h>
#include <iostream>
#define MAX_N 300
#define MAX_SCORE 10000


using namespace std;

//  이렇게 풀면 왜 안되는지 모르겠다. n 번째에서 계단을 밟을 때, 안 밟을 때 두 경우로 나눴는데...
//  반례) 6
// 3 3 2 2 4 1
//  이 경우 10이 최대인데, 아래 코드는 13이 나온다. 어떻게 된 것이냐...
//long long d[MAX_N + 1][2] = {0}; // 0 - not touch, 1 - touch
//int A[MAX_N + 1] = {0}; // score of each stair
//
//long long func(int n) {
//    d[0][0] = 0;
//    d[0][1] = 0;
//
//    d[1][0] = 0;
//    d[1][1] = A[1];
//
//    d[2][0] = A[1];
//    d[2][1] = A[1] + A[2];
//
//    for(int i=3; i<=n ; i++) {
//        // when touch.
//        d[i][1] = d[i-2][1] + A[i];
//        if(d[i][1] < d[i-2][0] + A[i-1] + A[i] ) // if larger then current
//            d[i][1] = d[i-2][0] + A[i-1] + A[i] ;  // update with larger value
//
//        // when  not touch
//        d[i][0] = d[i-2][1] + A[i-1] ;
//        if(d[i][0] < d[i-2][0] + A[i-1] ) // if larger then current
//            d[i][0] = d[i-2][0] + A[i-1];  // update with larger value'
//
//
//    }
//
//    return d[n][1];
//
//}
//

long long d[MAX_N + 1][3] = {0};
int A[MAX_N + 1] = {0};

long long func2(int N ) {
    
    d[1][1] = A[1];
    d[1][2] = A[1];
    d[2][1] = A[2];
    d[2][2] = A[1] + A[2];
    
    for(int n=3; n<=N; n++) {
        // 1개 연속인 경우
        d[n][1] = d[n-2][1] + A[n];
        if( d[n][1] < d[n-2][2] + A[n])
            d[n][1] = d[n-2][2] + A[n];
        
        //2개 연속인 경우
        d[n][2] = d[n-1][1] + A[n];
    }
    
    if(d[N][1] > d[N][2])
        return d[N][1];
    else
        return d[N][2];
}


int main() {
    int n;
    cin >> n;
    for(int i=1; i<=n ; i++) {
        cin >> A[i];
    }
    
    printf("%lld\n", func2(n));

    return 0;
}
