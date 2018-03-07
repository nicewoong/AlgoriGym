//
//  DSLR
//  9019.cpp
//  AlgoriGym
//
//  Created by nicewoong on 2018. 3. 7..
//  Copyright © 2018년 nicewoong. All rights reserved.
//
//  https://www.acmicpc.net/problem/9019


#include <cstdio>
#include <iostream>
#include <queue>
#define MAX_N 10000


using namespace std;

int visited[MAX_N] = {0};
int before[MAX_N] = {0};
char operation[MAX_N] = {0};

// 초기화
void init_array() {
    for(int i=0 ;i<MAX_N; i++) {
        visited[i] = 0;
        before[i] = 0;
        operation[i] = '\0';
    }
}

// D 연산 후 결과 리턴
int op_D(int A) {
    // n 을 두 배로
    int result = A*2 % MAX_N;
    return result;
}

// S 연산 후 결과 리턴
int op_S(int A) {
    if(A==0)
        return 9999;
    else
        return A-1;
}

// L 연산 후 결과 리턴 [d1 d2 d3 d4] -> [d2 d3 d4 d5]
int op_L(int A) {
    int d1;
    int d2;
    int d3;
    int d4;
    int result = 0;
    d1 = A/1000;
    A = A%1000;
    d2 = A/100;
    A = A%100;
    d3 = A/10;
    A = A%10;
    d4 = A;
    
    result = d2*1000 + d3*100 + d4*10 + d1;
    
    return result;
}

// R 연산 후 결과 리턴
int op_R(int A) {
    int d1;
    int d2;
    int d3;
    int d4;
    int result = 0;
    d1 = A/1000;
    A = A%1000;
    d2 = A/100;
    A = A%100;
    d3 = A/10;
    A = A%10;
    d4 = A;
    
    result = d4*1000 + d1*100 + d2*10 + d3;
    
    return result;
}


// A에서 B 까지 이동 경로 출력
void print_path(int A, int B) {
    if(B == A){
        return;
    }
    
    print_path(A, before[B]);
    printf("%c", operation[B]);
}

// bfs 로 연산 하나씩 파고 들어가면서 최소값 찾기.
int func(int A, int B) {
    init_array(); //  reset;
    
    //Q에 먼저 시작점을 집어넣고 진행.
    queue<int> q;
    q.push(A);
    visited[A] = 1;
    before[A] = A; // 자기 자신으로부터 시작
    operation[A] = 'A'; // 'A' (문자) 이면 중지할 수 있도록 시작 표시 다른 숫자에는 D,S,L,R 중 하나가 들어감.
    
    while(!q.empty()) { // q가 안 빌 때 까지 반복.
        int cur = q.front();
        q.pop();

        //D 의 경우 q에 집어넣고, 방문표시 하고, 어느 경로로 부터 왔는지
        int next = op_D(cur);
        if(visited[next] == 0){ // 방 문 안 했으면 진행
            q.push(next);
            visited[next] = visited[cur] + 1;
            before[next] = cur;
            operation[next] = 'D'; // cur->next 로 D 연산 통해서 갔음.
            if(next == B)
                break;
        }
        
        //S 의 경우 q에 집어넣고, 방문표시 하고, 어느 경로로 부터 왔는지
        next = op_S(cur);
        if(visited[next] == 0){ // 방 문 안 했으면 진행
            q.push(next);
            visited[next] = visited[cur] + 1;
            before[next] = cur;
            operation[next] = 'S'; // cur->next 로 S 연산 통해서 갔음.
            if(next == B)
                break;
        }
        
        //L 의 경우 q에 집어넣고, 방문표시 하고, 어느 경로로 부터 왔는지
        next = op_L(cur);
        if(visited[next] == 0){ // 방 문 안 했으면 진행
            q.push(next);
            visited[next] = visited[cur] + 1;
            before[next] = cur;
            operation[next] = 'L'; // cur->next 로 L 연산 통해서 갔음.
            if(next == B)
                break;
        }
        
        //R 의 경우 q에 집어넣고, 방문표시 하고, 어느 경로로 부터 왔는지
        next = op_R(cur);
        if(visited[next] == 0){ // 방 문 안 했으면 진행
            q.push(next);
            visited[next] = visited[cur] + 1;
            before[next] = cur;
            operation[next] = 'R'; // cur->next 로 R 연산 통해서 갔음.
            if(next == B)
                break;
        }
        
    } // end of while
    
    
    // B까지 이동 경로 출력
    print_path(A, B);
    cout << endl;
    
    return visited[B] - 1; // 이동 최소 횟수
}





int main() {
    
    int iteration;
    cin >> iteration;
    
    int A;
    int B;
    
    for(int i=1; i<= iteration ; i++ ) {
        cin >> A >> B;
        func(A, B);
    }
    
    
    
    return 0;
}







