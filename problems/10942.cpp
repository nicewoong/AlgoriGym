//
//  팰린드롬
//  10942.cpp
//  AlgoriGym
//
//  Created by nicewoong on 2018. 3. 6..
//  Copyright © 2018년 nicewoong. All rights reserved.
//  https://www.acmicpc.net/problem/10942
//
//  시간초과 나옴... 똑같이 햇는데.... 왜....?
//  그리고 도저히 recursive 는 어찌해야하는지 마무리를 못 짓겠음.

#include <cstdio>
#include <iostream>
#include <cmath>

#define MAX_N 2003 // 자연수 최대 갯수
#define MAX_M 1000003 // 질문 최대 갯수
#define MAX_NUM 100000 // 하나의 자연수 최대값

using namespace std;

int A[MAX_N + 1] = {0};
int d[MAX_N + 1][MAX_N + 1] = {0};


// 먼저 전체 계산 한 번 해놓고 d 채워넣어 놓으면 됨.
void func_iter(int N) {

    for(int i=1; i<=N ;i++) {
        // 1개 짜리
        d[i][i] = 1;

        // 2개 짜리
        if(A[i]==A[i+1]) // 같으면 yes
            d[i][i+1] = 1;
        else
            d[i][i+1] = 0; // 서로 다르면 no
    }

    // 3개 짜리 이상 // dist 는 j-i [i][~][~][j]
    for(int dist=2; dist <= N-1 ; dist++) {
        
        for(int i=1; i+dist <= N; i++) {
            
            if(A[i] != A[i+dist]) {// 일단 끝이 같아야해. 끝이 다르면 바로 no
                
                d[i][i+dist] = 0;
                
            }else { // 양 끝이 같으면 그 내부를 이제 확인해보면 된다.
                
                if(d[i+1][i+dist-1] == 1)
                    d[i][i+dist] = 1;
                else
                    d[i][i+dist] = 0;

            }
            
        }
    }

}

//int func_recursive(int I, int J) {
//
//
//
//    if(I==J) { // 한 개짜리
//        d[I][J] = 1;
//        return 1;
//    }
//    if(abs(I-J) == 1) { // 두 개짜리
//        if(A[I]==A[J]){
//            d[I][J] = 1;
//            return 1;
//        }else{
//            d[I][J] = 0;
//            return 0;
//        }
//    }
//
//    //3. 다이나믹으로...
//    if(A[I]!=A[J]){ //A[I]!=A[J] 끝이 서로 다르면 이미 아닌 것.
//        d[I][J] = 0;
//    }else {
//        if( I+1 <= J-1) {
//            d[I][J] = func_recursive(I+1, J-1);
//        }
//    }
//
//
//    return d[I][J];
//}


int main() {
    
    int N;
    int M;
    cin >> N;
    for(int i=1; i<=N; i++) {
        cin >> A[i];
    }
    
    func_iter(N);
    
    cin >> M;
    for(int i=1; i<=M; i++) {
        int I, J;
        cin >> I >>  J;
        cout << d[I][J] << endl;
    }
    
    
}
