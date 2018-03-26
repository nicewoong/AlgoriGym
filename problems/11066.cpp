//
//  파일 합치기
//  11066.cpp
//  AlgoriGym
//
//  Created by nicewoong on 2018. 3. 26..
//  Copyright © 2018년 nicewoong. All rights reserved.
//  https://www.acmicpc.net/problem/11066
//

#include <cstdio>
#include <iostream>
#define MAX_K 500 // 3<= K <= 500(포함)

using namespace std;

int A[MAX_K + 1] = {0};
int d[MAX_K + 1][MAX_K + 1] = {0}; // i~j 까지 총 비용을 저장.
int s[MAX_K + 1][MAX_K + 1] = {0}; // i~j 까지 총 사이즈를 저장

// d[i][j] = d[i][k] + d[k+1][j] + s[i][k] + s[k+1][j];

void init(int K) {
    for(int i=1; i<=K; i++) {
        d[i][i] = 0;
        s[i][i] = A[i];
    }
}


void func(int K) {
    
    for(int dist=1; dist<=K-1; dist++) { // 1개씩, 두 개씩, 세개씩 밀고나가면서 값을 채워나갈거
        
        for(int i=1; i+dist<=K; i++) {
            int j= i+dist;
            
            // 최소값 넣을 거니까, 비교를 위해서 첫 값(k=i+1)을 미리 넣어주자.
            int k=i;
            d[i][j] = d[i][k] + d[k+1][j] + s[i][k] + s[k+1][j];
            s[i][j] = s[i][k] + s[k+1][j];
            for(k=i+1; k<=j-1; k++) {
                if(d[i][j] > d[i][k] + d[k+1][j] + s[i][k] + s[k+1][j]){ // 만약 더 작으면 갱신
                    d[i][j] = d[i][k] + d[k+1][j] + s[i][k] + s[k+1][j];
                    s[i][j] = s[i][k] + s[k+1][j];
                }
            }// inner for
        }
    }// end of outer 
    
    cout << d[1][K] << endl;
    
    
}


int main () {
    
    int T; // 프로그램 7번 반복 수행
    int K; // 합쳐야할 챕터 갯수
    cin >> T;
    for(int t=0; t<T; t++) { // 프로그램 반복수행
        cin >> K;
        
        // read data (size of each chatper)
        for(int i=1; i<=K; i++) {
            cin >> A[i];
        }
        init(K);
        func(K);
    }
    
    return 0;
}
