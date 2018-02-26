//
//  점프
//  1890.cpp
//  AlgoriGym
//
//  Created by nicewoong on 2018. 2. 26..
//  Copyright © 2018년 nicewoong. All rights reserved.
//  See : https://www.acmicpc.net/problem/1890
// 

#include <stdio.h>
#include <iostream>
#define MAX_N 100

using namespace std;

long long d[MAX_N + 1][MAX_N + 1]  ={0};
int A[MAX_N + 1][MAX_N + 1]  ={0};


long long func(int N) {
    
    d[1][1] = 1;
    
    for(int i=1; i<=N; i++) {
        for(int j=1; j<=N; j++) {
            int dist = A[i][j];
            
             // 요기까지 왔는데 여기서 부터 갈 수 있는 곳은0이야. 그럼 지가 지한테 또 경우의 수 두 번 더해주게 됨. 그래서 스킵해야함.
            if(dist == 0)
                continue;
            
            if(d[i][j]==0)// 현재 위치가 도달할 수 없는 곳이면 스킵. 이 코드는 있으면 좋고, 없어도 되고.
                continue;
            
            // 헤당 디스턴스만큼 이동할 수 있는 자리에 경우의 수 더해주면 돼 현
            // 만약 오른쪽으로 범위가 안 넘어가면! 을 확인해야해.
            // 그러면 현재까지 올 수 있는 경우의수를 해당 자리에 더해주는 거지
            if(j+dist <= N)
                d[i][j+dist] += d[i][j];
            if(i+dist <= N)
                d[i+dist][j] += d[i][j];
        }
    }// end of for
    
    return d[N][N];
    
}


int main() {
    
    
    int N;
    
    cin >> N;
    for(int i=1; i<=N; i++) {
        for(int j=1; j<=N; j++) {
            cin >> A[i][j];
        }
    }
    
    cout << func(N) << endl;
    return 0;
}
