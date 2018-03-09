//
//  동전 1
//  2293.cpp
//  AlgoriGym
//
//  Created by nicewoong on 2018. 3. 9..
//  Copyright © 2018년 nicewoong. All rights reserved.
//  https://www.acmicpc.net/problem/2293
//

#include <cstdio>
#include <iostream>
#define MAX_K 10000
#define MAX_N 100

using namespace std;

int COIN[MAX_N + 1] = {0}; // 코인 종류 기록
int d[MAX_K + 1]  = {0}; // 1 ~ MAX_K 까지. 경의 수 기록해 나가자.

void printout(int K) {
    
    for(int i=1; i<=K; i++) {
        cout << d[i] << " ";
    }
    cout << endl;
    
}

//// 중복이 가능한 문제일때 1+1+2 != 2+1+1
//int func(int N, int K) {
//
//    for(int k=1; k<=K; k++) { // 경우의 수를 1 부터 채워 나갈 거야.
//
//        for(int coin_index=1; coin_index<=N ; coin_index++) { // 현재 수 이하의 숫자에 해당하는 코인종류가 있는지.
//
//            if(COIN[coin_index] <= k) { //  현재 수 이하.
//                int index = k - COIN[coin_index];
//                d[k] += d[index];
//
//                if( k == COIN[coin_index])
//                    d[k] +=1 ;
////                printout(K);
//            }
//
//        }
//    }// end of for
//
//    return d[K];
//
//}


// 중복이 불가능! 1+1+2 = 2+1+1
int func_not_dup(int N, int K) {
    
    for(int coin_index=1; coin_index<=N; coin_index++) {
        if(COIN[coin_index] > K)
            continue;
        d[COIN[coin_index]] += 1;
        
        for(int k = COIN[coin_index]+1; k<=K; k++) {
            d[k] += d[ k - COIN[coin_index] ];
        }
//        printout(K);
    }
    return d[K];
}


int main() {
    int N; // 동전 종류 수
    int K;
    
    cin >> N >> K;
    
    for(int i=1; i<=N; i++) { // 동전 종류 수 만큼 반복
        cin >> COIN[i];
    }
    
    cout << func_not_dup(N, K) << endl;
    
    return 0;

}


