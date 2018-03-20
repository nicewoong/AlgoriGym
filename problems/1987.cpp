//
//  알파벳 문제
//  1987.cpp
//  AlgoriGym
//
//  Created by nicewoong on 2018. 3. 20..
//  Copyright © 2018년 nicewoong. All rights reserved.
//  https://www.acmicpc.net/problem/1987
//

#include <cstdio>
#include <iostream>
#include <map>
#define MAX 20 // 포함


using namespace std;


map<char, int> visited;
int max_count = 0;
char A[MAX + 1][MAX + 1] = {'\0'}; // index 1 ~ MAX 접근 가능

bool is_possible(int next_row, int next_col, int R, int C) {
    //(테두리 안 벗어나는지 체크 )R, C 의 범위를 안 벗어나는지, 0을 안 넘어 가는지.
    if(next_row <= 0 || next_row > R || next_col <= 0 || next_col > C)
        return false;
    
    // 이미 방문한 알파벳인지 체크 -
    char next_A = A[next_row][next_col];
    if( visited[next_A] != 0) // 방문했다면 노!.
        return false;
    
    // 위 조건 모두 충족 안 하면 next 로 진입해도 괜찮다.
    return true;
}


void func(int cur_row, int cur_col, int R, int C, int count) {
    
    int next_row = cur_row;
    int next_col = cur_col;
    
    // 진입 할 수 있으니깐 현재 함수가 실행 됐겠지.
    if(max_count < count) // 현재까지 count 최대값이면 갱신
        max_count = count;
    
    // 상(cur_row-1), 하(cur_row+1), 좌(cur_col-1), 우(cur_col+1) 로 이동 가능한지 체크 한 후 들어가기
    
    // 상(cur_row-1)
    next_row = cur_row - 1;
    next_col = cur_col ;
    if(is_possible(next_row, next_col, R, C) == true) {
        // visited 표시하고
        visited[A[next_row][next_col]] = 1; // 해당 알파벳 지난 걸로.
        // Recursion 들어가고
        func(next_row, next_col, R, C, count+1);
        // 다시 나와서 visited 원상복귀
        visited[A[next_row][next_col]] = 0; // 해당 알파벳 다시 안 지난 걸로
    }
    
    // 하(cur_row+1)
    next_row = cur_row + 1;
    next_col = cur_col ;
    if(is_possible(next_row, next_col, R, C) == true) {
        // visited 표시하고
        visited[A[next_row][next_col]] = 1; // 해당 알파벳 지난 걸로.
        // Recursion 들어가고
        func(next_row, next_col, R, C, count+1);
        // 다시 나와서 visited 원상복귀
        visited[A[next_row][next_col]] = 0; // 해당 알파벳 다시 안 지난 걸로
    }

    // 좌(cur_rol - 1)
    next_row = cur_row;
    next_col = cur_col - 1 ;
    if(is_possible(next_row, next_col, R, C) == true) {
        // visited 표시하고
        visited[A[next_row][next_col]] = 1; // 해당 알파벳 지난 걸로.
        // Recursion 들어가고
        func(next_row, next_col, R, C, count+1);
        // 다시 나와서 visited 원상복귀
        visited[A[next_row][next_col]] = 0; // 해당 알파벳 다시 안 지난 걸로
    }

    
    // 우(cur_col + 1)
    next_row = cur_row ;
    next_col = cur_col + 1 ;
    if(is_possible(next_row, next_col, R, C) == true) {
        // visited 표시하고
        visited[A[next_row][next_col]] = 1; // 해당 알파벳 지난 걸로.
        // Recursion 들어가고
        func(next_row, next_col, R, C, count+1);
        // 다시 나와서 visited 원상복귀
        visited[A[next_row][next_col]] = 0; // 해당 알파벳 다시 안 지난 걸로
    }
        
    
    
}

int main() {

    int R; // Row 수
    int C; // Col 수
    
    scanf("%d %d\n", &R, &C);
    for(int i=1; i<=R; i++) {
        for(int j=1; j<=C; j++ ){
//            cin >> A[i][j];
            scanf(" %c", &A[i][j]);
        }
    }
//    
//    for(int i=1; i<=R; i++) {
//        for(int j=1; j<=C; j++ ){
//            cout << A[i][j];
//        }
//        printf("\n");
//    }
    
    
    visited[A[1][1]] = 1; // 처음 시작하는 알파벳 지난 걸로.
    max_count  = 1;
    func(1, 1, R, C, 1);
    
    cout << max_count << endl;;
    
    return 0;
}
