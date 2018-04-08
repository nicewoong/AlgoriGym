//
//  기타리스트
//  1495.cpp
//  AlgoriGym
//
//  Created by nicewoong on 2018. 4. 8..
//  Copyright © 2018년 nicewoong. All rights reserved.
//  https://www.acmicpc.net/problem/1495
//

#include <cstdio>
#include <iostream>
#define MAX_N 100
#define MAX_M 1000

int V[MAX_N + 1] ; // 해당 인덱스에서 연산할 수 있는 볼륨 크기
int d[MAX_M + 1][MAX_N + 1] = {0};

using namespace std;

int func(int N, int S, int M) {
    
    
    // init first volume
    int cur_plus = S + V[1];
    int cur_minus = S - V[1];
    
    if(cur_plus <= M) {
        d[cur_plus][1] = 1;
    }
    
    if(cur_minus >= 0) {
        d[cur_minus][1] = 1;
    }
    
    
    for(int n=1; n<=N-1; n++) {
        for(int m=0; m<=M; m++) {
            // n번째에 m 번 볼륨이 가능했다면, (1이라면), n+1 에다가, V[n+1]값을 - , + 해서 가능한 볼륨(m)에 1 표시해놓기
            if(d[m][n] == 1) {
                int next_plus = m + V[n+1];  // 현재(n) 볼륨(m)에 V[n+1] 볼륨ㅈ 조절 값을 더한 값
                if(next_plus <= M) { // 더한 값이 가능한 범위에 있으면 그 다음 n+1번째에 해당 볼륨에 1표시
                    d[next_plus][n+1] = 1;
                }
                
                int next_minus = m - V[n+1];
                if(next_minus >= 0) {
                    d[next_minus][n+1] = 1;
                }
                
            }
        }// end of inner for
    }// end of outer for
    
    // N 번째에서 가능한 볼륨에 표시되어 있는 것들 중 가장 큰 값을 return 하면 된다. 아무것도 없으면 -1 리턴
    for(int m=M; m>=0; m--) {
        if(d[m][N]==1)
            return m;
    }
    
    return -1;
    
}// end of func()


int main() {
    int N; // 연주 곡 갯수 = 볼렴 조절 가능 V 리스트 갯수
    int S; // 시작 볼륨
    int M; // 최대 가능 볼륨
    
    cin >> N >> S >> M;
    for(int i=1; i<=N; i++) {
        cin >> V[i];
    }
    
    cout << func(N, S, M) << endl;
    
    return 0;
}
