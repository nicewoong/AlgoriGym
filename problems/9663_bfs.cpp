//
//  N-Queen
//  9663.cpp
//  AlgoriGym
//
//  Created by nicewoong on 2018. 3. 13..
//  Copyright © 2018년 nicewoong. All rights reserved.
//  https://www.acmicpc.net/problem/9663
//
//  BFS 를 이용한 완전탐색. 답은 나오지만, 메모리초과. 시간도 너무 오래 걸리구. 

#include <cstdio>
#include <iostream>
#include <vector>
#include <queue>
#include <map>
#include <string>
#include <cstring>

#define MAX_N 15

using namespace std;

// 퀸 놓은 자리는 1, 못 넣는 자리 2, 아직 아무것도 안 놓은자리 0

//// queue 와 map 에 Matrix 상태를 저장하기 위해서 string 형으로 만들어 반환
//string mat_to_string(int **matrix, int N) {
//
//}

void printString(string cur_str, int N) {
    int index=0;
    for(int i=0; i<N; i++) {
        for(int j=0; j<N; j++) {
            cout << cur_str[index++] << " ";
        }
        cout << endl;
    }
}

// 현재 index 에 퀸 놓으면 1표시, 놓을 수 없는 곳을 2 표시. O(N^2)
string give_new_queen(string cur_string, int N, int queen_index) {
    
    int cur_matrix[MAX_N][MAX_N];
    int queen_row = queen_index / N;
    int queen_col = queen_index % N;
    
    // 먼저 string을 매트릭스로 바꿔서 풀자.
    int str_index = 0;
    for(int i=0; i<N; i++) {
        for(int j=0; j<N; j++) {
            char cur_ch = cur_string[str_index++];
            cur_matrix[i][j] = atoi(&cur_ch);
        }
    }
    
    
    // 블락 = 2 표시
    for(int i=0; i<N; i++) {
        for(int j=0; j<N; j++) {
            // 같은 row 는
            if(i == queen_row)
                cur_matrix[i][j] = 2;
                
            // 같은 col 는
            if(j == queen_col)
                cur_matrix[i][j] = 2;
        }
    }
    
    
    for (int dist=1; dist <= N; dist++){
        // 우대각 블락
        if(queen_row-dist >= 0 && queen_col+dist<N) // 위로
            cur_matrix[queen_row-dist][queen_col+dist] = 2;
        if(queen_row+dist < N && queen_col-dist >= 0) // 아래로
            cur_matrix[queen_row + dist][queen_col - dist] = 2;
        
        // 좌대각 블락
        if(queen_row + dist < N && queen_col + dist < N)
            cur_matrix[queen_row + dist][queen_col + dist] = 2;
        if(queen_row - dist >= 0 && queen_col -dist >=0 )
            cur_matrix[queen_row -dist][queen_col -dist] = 2;
    }
    
    
    // 퀸 1 표시
    cur_matrix[queen_row][queen_col] = 1;


    // 다시 string 으로 바꿔서 반환.
    string new_string = "";
    for(int i=0; i<N; i++) {
        for(int j=0; j<N; j++) {
            new_string += to_string(cur_matrix[i][j]);
        }
    }
    return new_string;
    
}

// N 개의 퀸이 되었다면 1 아직 아니라면 0 O(N^2)
int is_N_Queen(string queen_str, int N) {
    int count = 0;
    for(int i=0; i< N*N ; i++) {
        if(queen_str[i] == '1') // 퀸인거 갯수 세아려
            count +=1;
    }
    if(count == N)
        return 1; // N-Queen 이야.
    else
        return 0; // 아니야
}


// N-Queen 가능한 갯수 반환
int func(int N) {
    // N*N개의 배열 칸이 필요. 인덱스 0부터 N*N-1 까지 쓴다.
    
    int count = 0; // 더이상 퀸을 놓을 수 없다면 count 증가시킴
    queue<string> q;
    map<string, int> visited;
    
    // start 는 첫 자리만 1이고 나머지 0으로 채워짐 0~
    // start 를 q 에 넣고, 방문표시하고!
    string start = "";
    for(int i=0; i<N*N; i++) {
        start += "0";
    }
    
    q.push(start); // 시작점을 큐에 넣고,
    visited[start] = 1; // 시작점 방문표시하고.


    // q 빌 때 까지 q에서 하나씩 빼면서 반복
    while( !q.empty() ) {
        const string cur_string = q.front();
        q.pop();
        
        // 쭈욱 찾아보면서 0인 부분은 queen 놓을 수 있음.
        for(int i=0; i<N*N; i++) {
            if(cur_string[i] == '0') { // 퀸 놓을 수 있는 자리.
                string new_queen_string = give_new_queen(cur_string, N, i);
                
                // 방문확인 // 방문 안 했으면 큐에 넣고, 방문표시하고, 더이상 못 가면 count도 올려주고
                if(visited[new_queen_string] == 0) {
                    q.push(new_queen_string);
                    visited[new_queen_string] = visited[cur_string] + 1;

                    if(is_N_Queen(new_queen_string, N) == 1) { // N개의 Queen 이라면 경우의 수 하나 증가!
                        count += 1; // 경우의수 하나 증가해주자.
                    }
                }
                
            }
                
        } // end of for
    }// end of while

    
    return count;
}



int main() {
    
    int N;
    cin >> N;
    if(N==1)
        cout << 1 << endl;
    else
        cout << func(N) << endl;
    
//    string str  = "0000000000000000";
//    cout << give_new_queen(str, 4, 1) << endl;
    return 0;
}
