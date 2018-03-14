//
//  N-Queen
//  9663_back_tracking.cpp
//  AlgoriGym
//
//  Created by nicewoong on 2018. 3. 13..
//  Copyright © 2018년 nicewoong. All rights reserved.
//  https://www.acmicpc.net/problem/9663
//

#include <cstdio>
#include <iostream>
#include <cmath>
#define MAX_N 15

using namespace std;

int how_many = 0;
int A[MAX_N][MAX_N] = {0};
int check_right_agonal[MAX_N + MAX_N + 1] = {0};
int check_left_agonal[MAX_N + MAX_N + 1] = {0};
int check_veritcal[MAX_N + 1] = {0};


void print_agonal(int mat[][MAX_N], int N) {
    for(int i=0; i<N;i++) {
        for(int j=0;j<N;j++) {
            cout << mat[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
}


// 하나라도 포함되면 0 반환 , 마지막까지 아무것도 없으면 1 반환
int is_possible(int N, int cur_row, int cur_col) {

    if(check_right_agonal[cur_row + cur_col] ==1)
        return 0;
    if(check_left_agonal[cur_col - cur_row + N] == 1)
        return 0;
    if(check_veritcal[cur_col] == 1)
        return 0;
    
    return 1;
}


void func(int cur_row, int N, int q_count) {

    if(q_count == N) {
        how_many += 1;
        return;
    }
    
    if(cur_row >= N)
        return;
    
    // 현재 row 에서 col을 하나씩 하나씩 둘 경우를 따져보며 파고들어가자.
    for(int cur_col = 0; cur_col < N; cur_col++ ) {
        // 가능한지 확인하고 가능하다면
        if(is_possible(N, cur_row, cur_col) == 1) {
            // 현재 자리에 Queen 을 놓아보자. 그리고 퀸 표시 해주고
            A[cur_row][cur_col] = 1;
            check_right_agonal[cur_row + cur_col] = 1;
            check_left_agonal[cur_col - cur_row + N] = 1;
            check_veritcal[cur_col] = 1;
            
            // 파고 들어보자.
            func(cur_row + 1, N, q_count + 1);
            
            // 원상복귀해보자. 퀸 표시 해제
            A[cur_row][cur_col] = 0;
            check_right_agonal[cur_row + cur_col] = 0;
            check_left_agonal[cur_col - cur_row + N] = 0;
            check_veritcal[cur_col] = 0;
        }
    }// end of for

} // end of func()



int main() {

    int N;
    cin >> N;
    
    func(0, N, 0);
    cout << how_many << endl;
    
    return 0;
}





