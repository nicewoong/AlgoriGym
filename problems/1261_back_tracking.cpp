//
//  알고스팟
//  1261.cpp
//  AlgoriGym
//
//  Created by nicewoong on 2018. 4. 3..
//  Copyright © 2018년 nicewoong. All rights reserved.
//  https://www.acmicpc.net/problem/1261
//

#include <cstdio>
#include <iostream>
#define MAX_N 100

using namespace std;
char A[MAX_N + 1][MAX_N + 1] = {0};
bool visited[MAX_N + 1][MAX_N + 1] = {false};
int min_broken = MAX_N*MAX_N;
int x_dist[4] = {0, 0, -1, 1};  // 현재위치에서 위 아래 좌 우 순서로 x값을 어떻게 더해야하는지
int y_dist[4] = {-1, 1, 0, 0};  // 현재위치에서 위 아래 좌 우 순서로 y값을 어떻게 더해야하는지


void func(int N, int M, int cur_row, int cur_col, int broken_count) {

    
    if(broken_count > min_broken) // 이미 크기가 더 켜졌다면 Stop 더 볼 것도 없다.
        return;
    
    if(cur_row == N && cur_col==M) { // 종착점에 도착했다면 Stop
        if(min_broken > broken_count) // 더 작으면
            min_broken = broken_count; // update min
        return ;
    }
    
    // 위 아래 좌 우 하나씩 가능한지 확인해보고 들어가지
    for(int i=0 ; i<4; i++) {
        int next_row = cur_row + y_dist[i];
        int next_col = cur_col + x_dist[i];
        
        // 범위에 벗어나지 않으면 진입해보자.
        if((next_row > 0 && next_row <= N) && (next_col > 0 && next_col <= M) ) {
            
            if(visited[next_row][next_col] == false) { // 아직 방문하지 않았으면 방문해보자.
                
                visited[next_row][next_col] = true; // 방문표시하구
                if(A[next_row][next_col] == '1') // 벽이라면 벽을 부수눈 횟수 하나 증가!
                    broken_count ++;
                
                func(N, M, next_row, next_col, broken_count); // recursive 진입!
                
                // 다시 빠져나와서 방문 표시 빼고
                visited[next_row][next_col] = false;
                if(A[next_row][next_col] == '1') // 벽이라면 벽을 부수눈 횟수 하나 증가한 거 원상복귀!
                    broken_count --;
            }
            
            
        }// end of outer if
        
        
        
        
    }// end of for
    
}// end of func()



int main() {
    
    int N;  // row
    int M;  // col
    cin >> M >> N;
    for(int i=1; i<=N ; i++) {
        for(int j=1; j<=M; j++) {
            scanf(" %c", &A[i][j]);
        }
    }
    
    visited[1][1] = true; // 방문표시하구
    func(N, M, 1, 1, 0);
    
    if(min_broken > N)
        cout << 0 << endl;
    else
        cout << min_broken << endl;
    
    
    
    return 0;
}
