//  수들의 합2
//  2003.cpp
//  AlgoriGym
//
//  Created by nicewoong on 2018. 3. 28..
//  Copyright © 2018년 nicewoong. All rights reserved.
//

#include <cstdio>
#include <iostream>
#define MAX_N 10000
#define MAX_M 300000000
#define MAX_VALUE 30000 // 자연수

using namespace std;
int cnt = 0; // 합이 M 이 되는 경우의 수
int A[MAX_N + 1] = {0};

void func(int N, int M){

    int sum = A[1];
    int left = 1;
    int right = 1 ;
    
    while(left<=N && right<=N) {
    
        if(sum < M) {
            right ++;
            sum += A[right];
        }else if (sum==M) { // 찾았다!@ cnt 경우의 수 하나 증가.
            cnt++;
            
            if(left < right) {
                sum -= A[left];
                left ++;
            }else { // left == right 일 경우
                left ++;
                right ++;
                sum = A[left]; // 새로시작
            }
            
        }else if(sum > M) {
            sum -= A[left];
            left ++;
            
        }
            
        
    }
    
}// end of func()



int main( ) {
    

    int N; // 원소 갯수
    int M; // 합이 M이 될 경우의 수 구할 것.
    cin>> N >> M;
    for(int i=1; i<=N; i++) {
        cin >> A[i];
    }
    func(N,M);
    cout << cnt << endl;
    
    return 0;
}
