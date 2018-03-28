//  부분합
//  1806.cpp
//  AlgoriGym
//
//  Created by nicewoong on 2018. 3. 28..
//  Copyright © 2018년 nicewoong. All rights reserved.
//  https://www.acmicpc.net/problem/1806
//

#include <cstdio>
#include <iostream>
#define MAX_N 100000


using namespace std;
int A[MAX_N + 1]  = {0}; // 10,000이하의 자연수가 저장될 것.

int func(int N, int S) {
    int left = 1;
    int right = 1;
    int sum = A[1];
    int min_dist = 2*N;
    
    while(left<=N && right <= N) {
        if(min_dist <= right-left+1) { // 최소 길이 보다 더 크다면, 계산해 볼 것도 없어. 다음으로 넘어가자.
            if(left == right) {
                left++;
                right ++;
                sum = A[left]; // SUM 은 다시 시작.
            }else {
                sum -= A[left];
                left++;
            }
            
        }else {
            if(sum < S) { // 더 작으니 더 더해주러 진행해야함. 오른쪽 끝이.
                right++;
                sum += A[right];
            }else if(sum >= S) { // S 보다 크거나 같으면 길이를 한 번 봅시다.
                if(min_dist > right-left+1) // 더 작으면 갱신해주구요.
                    min_dist = right-left+1;
                // 자 이제 left 를 옮겨줍시다.
                if(left == right) {
                    left++;
                    right ++;
                    sum = A[left]; // SUM 은 다시 시작.
                }else {
                    sum -= A[left];
                    left++;
                }
            }
                
        }
        
        
            
            
    }// end of while
    
    if(min_dist == 2*N) { // min dist 에 변화가 없었다면 발견하지 못 한것.
        return 0;
    }else {
        return min_dist;
    }

} // end of func


int main() {
   
    int N; //  10 ≤ N < 100,000
    int S; //  0 < S ≤ 100,000,000 - > 합이 S 이상.
    cin >> N >> S;
    for(int i=1; i <= N; i++ ) {
        cin >> A[i];
    }
    
    cout << func(N,S) << endl;
    
    
    
    return 0;
}
