//
//  행렬 곱셈 순서
//  11049.cpp
//  AlgoriGym
//
//  Created by nicewoong on 2018. 3. 26..
//  Copyright © 2018년 nicewoong. All rights reserved.
//  https://www.acmicpc.net/problem/11049
//

#include <cstdio>
#include <iostream>
#define MAX_N 500  //행렬 최대 갯수

int A[MAX_N + 1][2] = {0} ; // 행렬의 row 크기 [0], col의 크기 [1]  가 저장됨.
int S[MAX_N + 1][MAX_N + 1][2] = {0}; // i~j 하고 난 다음의 최소일 때 row 크기 [0], col의 크기 [1] 가 저장됨.
int d[MAX_N + 1][MAX_N + 1] = {0}; // i~j 하고 난 최소 값 저장.

using namespace std;

void init_mat(int N){
    for(int i=1; i<=N; i++) {
        S[i][i][0] = A[i][0];
        S[i][i][1] = A[i][1];
        d[i][i] = 0;
    }
}

void func(int N) {
    
    for(int dist=1; dist<= N-1; dist++) { // 두개 짜리부터 밀고나가보자. 밀고 나가면서 최소값 채우는 거야. 두개씩, 세개씩 네개씩 쭈우욱
        
        for(int i=1; i+dist <= N; i++) {
            int j= i+dist;
            
            // 비교해서 최소값을 넣기 위해, 초기값으로 세팅해놓자.
            int mid = i;
            d[i][j] = d[i][mid] + d[mid+1][j] + (S[i][mid][0] * S[mid+1][j][0] * S[mid+1][j][1]);
            S[i][j][0] = S[i][mid][0];
            S[i][j][1] = S[mid+1][j][1];
            
            // 비교해가면서 더 작은 값이 나오면 고고씽!
            for(mid = i+1; mid + 1 <= j ; mid++) {
                if(d[i][j] > d[i][mid] + d[mid+1][j] + (S[i][mid][0] * S[mid+1][j][0] * S[mid+1][j][1])){ // 더 작으면 갱신
                    d[i][j] = d[i][mid] + d[mid+1][j] + (S[i][mid][0] * S[mid+1][j][0] * S[mid+1][j][1]);
                    S[i][j][0] = S[i][mid][0];
                    S[i][j][1] = S[mid+1][j][1];
                }
            }
            
        }// end of inner for
        
    }// end of outer dist for
    
    // 최종 결과 출력
    cout << d[1][N] << endl;
    
}// end of func()


int main() {
    
    int N;
    cin >> N;
    
    for(int i=1; i<=N; i++) {
        cin >> A[i][0] >> A[i][1];  // row x col
    }
    
    init_mat(N);
    func(N);
    
    
    return 0;
}
