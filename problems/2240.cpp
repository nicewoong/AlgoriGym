//
//  자두나무
//  2240.cpp
//  AlgoriGym
//
//  Created by nicewoong on 2018. 4. 3..
//  Copyright © 2018년 nicewoong. All rights reserved.
//  https://www.acmicpc.net/problem/2240
//

#include <cstdio>
#include <iostream>
#define MAX_T 1000
#define MAX_W 30
using namespace std;

int A[MAX_T + 1][3] = {0};
int d[MAX_T + 1][MAX_W + 1] = {0};

int get_bigger(int a, int b) {
    if(a>b) {
        return a;
    }else {
        return b;
    }
    
}

int func(int T, int W) {
    // 처음 시작은 1번 나무 아래에 있음.
    d[0][0] = 0;
    
    d[1][0] = A[1][1]; // 1초 때 안 움직이면 나무1에 있으니, 나무1에 1초 때 떨어지는 자두 먹음
    d[1][1] = A[1][2]; // 1초 때 움직이면 나무2에 있으니, 나무2에 1초 때 떨어지는 자두 먹음
    
    
    for(int t=2; t<=T; t++ ) {
        for(int w=0; w<=W && w<=t; w++ ){
            if(w==0) {
                //한 번도 움직이지 않은 경우
                d[t][w] = d[t-1][0] + A[t][1];
            }else {
                if(w%2==0) { // 짝수번 움직였을 때 : 나무1에 위치
                    d[t][w] = get_bigger(d[t-1][w] + A[t][1], d[t-1][w-1] + A[t][1]) ;
                    
                }else { // 홀수번 움직였을 때 : 나무2에 위치
                    d[t][w] = get_bigger(d[t-1][w] + A[t][2], d[t-1][w-1] + A[t][2]) ;
                }
            }
            
            
                
        }
    }
    
    int max = 0;
    for(int w=0; w<=W && w<=T; w++ ){
        if(max < d[T][w])
            max = d[T][w];
    }
    
    return max;
}


int main() {
    int T;  // 자두 떨어지는 횟수
    int W;  // 이동가능한 횟수
    cin >> T >> W;
    
    for(int i=1; i<=T; i++) {
        int cur_tree;
        cin >> cur_tree;
        A[i][cur_tree] = 1;
    }
    
    cout << func(T, W) << endl;
    
    
    
    return 0;
}
