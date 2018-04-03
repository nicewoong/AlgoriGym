//
//  소수의 연속합
//  1644.cpp
//  AlgoriGym
//
//  Created by nicewoong on 2018. 4. 3..
//  Copyright © 2018년 nicewoong. All rights reserved.
//  https://www.acmicpc.net/problem/1644
//

#include <cstdio>
#include <iostream>
#include <cmath>

#define MAX_N 4000000  // 사 백만
using namespace std;

bool is_sosu[MAX_N + 1] ;  // 소수이면 true, 소수가 아니면 false

void make_sosu(int N) {
    int end = sqrt(N);
    for(int i=2; i<= N ; i++ ) { // i 의 곱셈에 해당하는 것에 대해 모두 소수가 아닌 것으로 처리
        is_sosu[i] = true;
    }// end of for
    
    for(int i=2; i<= end ; i++ ) { // i 의 곱셈에 해당하는 것에 대해 모두 소수가 아닌 것으로 처리
        for(int j=2; j*i<= MAX_N ; j++) {
            is_sosu[i*j] = false;
            
        }
    }// end of for
}// end of func

int next_sosu(int N, int cur_num) {
    for(int i=cur_num+1; i<=N; i++) {
        if(is_sosu[i]==true)  // 바로 다음 소수를 찾자마자 리턴
            return i;
    }
    return -1; // 그 다음 소수가 더이상 존재하지 않을 때
}

int func(int N) {
    int count = 0;
    int left = 2;
    int right = 2;
    int sum = left;
    
    while(left <= N && right<=N && left <= right) {

//        cout << "left = " << left << " right = " << right <<" sum =  " <<sum << endl;
        if(sum == N) {
            
            count ++;
            
            if(left == right) {
                left = next_sosu(N, left);
                right = next_sosu(N, right);
                sum = left;
            }else {
                sum -= left;
                left = next_sosu(N, left);
                right = next_sosu(N, right);
                sum += right;
            }

            if( left <0 || right <0)
                break;
        }else if(sum < N) {
            right = next_sosu(N, right);
            sum += right;
            if( left <0 || right <0)
                break;
            
        }else { // sum > N
            sum -= left;
            left = next_sosu(N, left);
            
            if( left <0 || right <0)
                break;
        }
 
    } // end of while
    return count;
}



int main() {

    int N;
    cin >> N;
    
    make_sosu(N);
    
//    for(int i=1; i<=N; i++) {
//        if(is_sosu[i]==true)  // 소수이면 출력
//            cout << i << " ";
//    }
//    cout << endl;
    
    cout << func(N) << endl;
    
    
    return 0;
}
