//
//  스도쿠
//  2580.cpp
//  AlgoriGym
//
//  Created by nicewoong on 2018. 3. 16..
//  Copyright © 2018년 nicewoong. All rights reserved.
//  https://www.acmicpc.net/problem/2580
//

#include <cstdio>
#include <iostream>

#define SIZE 9

using namespace std;


int A[SIZE][SIZE] = {0}; // 0~8 인덱스 사용

bool is_possible(int row, int col, int N) {

    for(int i=0; i<SIZE; i++) { // O(SIZE)
        // 현재 row와 같은 줄 쭉 보고 N 이미 있으면 안됨.
        if(A[row][i] == N)
            return false;
        // 현재 col와 같은 줄 쭉 보고 N 이미 있으면 안됨.
        if(A[i][col] == N)
            return false;
        
    }
    
    int start_row = row-(row%3);
    int start_col = col-(col%3);
    
    // 현재 작은 mat 검사
    for(int i=start_row; i<start_row + 3; i++) { // 세 번만 반복
        for(int j=start_col; j<start_col+3 ; j++){
            if(A[i][j] == N)
                return false;
        }
        
    }
    
    
    return true;

}

void print_out() {
    for(int i=0 ; i<SIZE; i++) {
        for(int j=0 ; j<SIZE; j++){
            cout << A[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
}

void func(int cur_row, int cur_col) {
    
    // 어떻게 다 채워진 것만 체크해서 출력하지??
    if(cur_row >= SIZE) {
        print_out();
        return;
    }
    
    
    int next_col = (cur_col + 1) % SIZE; // 게속 반복
    int next_row = cur_row;
    if(next_col==0)
        next_row += 1; // 한 번 쭉 내려가면 끝남
    
    if(A[cur_row][cur_col] == 0) { // 빈칸이면

        for(int k=1 ; k<=SIZE; k++) { // 1~9 까지의 숫자 하나씩 대입해보면서 되는지 안되는지.
            if(is_possible(cur_row, cur_col, k) == true) {
                // 대입하고,
                A[cur_row][cur_col] = k;
                // recursion 진입하고,
                
                func(next_row, next_col);
                // 되돌아와서 복구하고
                A[cur_row][cur_col] = 0;
            }
        }// end of for

    }else { // 빈칸이 아니면 그냥 다음으로 넘어가
        func(next_row, next_col);
    }
                

}

int main() {
    
    for(int i=0 ; i<SIZE; i++) {
        for(int j=0 ; j<SIZE; j++){
            cin >> A[i][j];
        }
    }
    
    
    func(0,0);
    
    
    return 0;
}



