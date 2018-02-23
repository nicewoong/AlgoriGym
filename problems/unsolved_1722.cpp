//
//  순열의 순서
//  1722.cpp
//  AlgoriGym
//
//  Created by nicewoong on 2018. 2. 23..
//  Copyright © 2018년 nicewoong. All rights reserved.
//  See : https://www.acmicpc.net/problem/1722
//  solution : https://gist.github.com/Baekjoon/1b94fe874444c2287fe5


#include <stdio.h>
#include <iostream>
#include <algorithm>
#define MAX_N 20

using namespace std;

vector<int> number_lists();

int A2[MAX_N] = {0};
int flag_A2[MAX_N] = {0};


int d[MAX_N] = {0};


int getRemained_A2(int N){
    int sum = 0;
    for(int i=1; i<N; i++){
        if( flag_A2[i] == 0)
            sum++;
    }
    return sum;
}

void func1(int N, int K) {
    
}


void func2(int N) {
    int sum = 0;
    for(int i=1; i<= N-1; i++) {
        sum += d[N-i] * (A2[i]-1 - getRemained_A2(A2[i]));
        flag_A2[A2[i]] = 1;
    }
    cout << sum << endl;
}




int main() {
    int N; // 순열 숫자 갯수 1,2,3...N
    int prob_num; // 문제 번호
    
    cin >>  N;
    cin >> prob_num;
    
    // factorial 결과를 미리 만들어 놓자. 배열에 저장해놓으면 됨. 한 번만 참조하면 된다.
    d[0] = 1;
    d[1] = 1;
    for(int i=2; i<=N; i++) {
        d[i] = i*d[i-1];
    }
    
    if(prob_num==1) { // k 번째 순열 출력하기
        int K;
        cin >>  K;
        func1(N, K);
    }else { //  2일 때 N 개의 숫자 읽어서 몇 번째인지 순서를 출력
        for(int i=1; i<=N; i++)
            cin>>A2[i];
        func2(N);
    }
    
}
