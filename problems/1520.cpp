//
//  내리막길
//  1520.cpp
//  AlgoriGym
//
//  Created by nicewoong on 2018. 3. 25..
//  Copyright © 2018년 nicewoong. All rights reserved.
//  https://www.acmicpc.net/problem/1520
//

#include <iostream>
#include <cstdio>
#define MAX_N 500 // 500 이하 (포함)
#define MAX_HIGHT 10000

using namespace std;

int A[MAX_N + 1][MAX_N + 1] = {0};
int d[MAX_N + 1][MAX_N + 1] = {0};
int visited[MAX_N + 1][MAX_N + 1] = {0};

int dx[4] = {0, 0, -1, 1}; // 왼쪽 오른쪽 확인
int dy[4] = {1, -1, 0, 0}; // 위쪽 아래쪽 확인

//void print_mat(int M, int N) {
//    for(int i=1; i<=M; i++) {
//        for(int j=1; j<=N; j++) {
//            cout<< d[i][j] << " ";
//        }
//        cout << endl;
//    }
//    cout << endl;
//}

int func(int i, int j, int M, int N) {

    if(i==1 && j==1) // 첫 스타트 자리이면 1 반환.
        return 1;

    if(visited[i][j] != 0)// 이미 방문해서 구한 값이 있으면, 한 번 더 하면 중복되므로 계산된 값만 반환하면 된다.
        return d[i][j];

    // 위 아래, 좌 우 확인하고 그곳에서 현재로 올 수 있으면 경우의 수 더해주기.
    for(int offset=0; offset<4; offset++) {
        int before_i = i+dx[offset];
        int before_j = j+dy[offset];

        // 범위 밖을 벗어나지 않는 경우만 보겠다.
        if(before_i <= M && before_i>=1 && before_j<= N && before_j>=1) {
            // 해당 높이가 현재보다 더 높아아 올 수 있다.
            // 그리고 해당 자리에 방문이 가능해야한다. d가 0보다 커야 현재로 올 수 있다.
            if(A[before_i][before_j] >  A[i][j]){
                d[i][j] += func(before_i, before_j, M, N);
            }

        }

    }// end of 상하좌우

    visited[i][j] =1;
    return d[i][j];

}



int main() {
    int M; // 세로크기
    int N; // 가로크기
    
    cin >> M >> N;
    
    for(int i=1; i<=M; i++) {
        
        for(int j=1; j<=N; j++) {
            cin >> A[i][j];
        }
    }
        
        cout << func(M, N, M, N) << endl;
        return 0;
}




