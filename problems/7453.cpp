//
//  합이 0인 네 정수
//  7453.cpp
//  AlgoriGym
//
//  Created by nicewoong on 2018. 4. 5..
//  Copyright © 2018년 nicewoong. All rights reserved.
//  https://www.acmicpc.net/problem/7453
//

#include <cstdio>
#include <iostream>
#include <vector>
#include <algorithm>

#define MAX_N 4000


using namespace std;


int A[MAX_N + 1];
int B[MAX_N + 1];
int C[MAX_N + 1];
int D[MAX_N + 1];

long long func(int N) {

    long long count = 0; // 합이 0이 되는 쌍의 갯수
    // 두 개 두 개 먼저 더해서 배열에 넣어놓자. N*N 개의 합을 담을 거임
    vector<int> first_sum_list;  // A와 B의 원소 합들을 저장  index 는 0~ size()-1 까지 접근가능! !!!
    vector<int> second_sum_list;  // C와 D의 원소 합들을 저장
    
    // O(N^2)
    for(int i=1; i<=N; i++) {
        for(int j=1; j<=N; j++) {
            first_sum_list.push_back(A[i] + B[j]);
            second_sum_list.push_back(C[i] + D[j]);
        }
    } // end of for
    
    // 두 리스트를 정렬하고 하나씩 비교해보아야 빠르게 할 수 있다.
    sort(first_sum_list.begin(), first_sum_list.end());
    sort(second_sum_list.begin(), second_sum_list.end());
    
    // 이제 A와 B 원소 합들과 C와 D의 원소 합들을 하나씩 더해보면서 0이 되면 count ++을 해주면되겠다.
    // 효율적으로 하기 위해서, 전혀 안 봐도 되는 경우는 스킵하는 기법을 사용하자.
    
    int first_index = 0; // 앞에서부터 시작 (작은 수부터)
    int second_index = second_sum_list.size() - 1 ; // 끝에서부터 시작 (큰 수부터)
    long long sum = first_sum_list[first_index] + second_sum_list[second_index];
    
    while(first_index <= first_sum_list.size() -1 && second_index >= 0) {
        
        if(sum == 0) {
            
            long long first_same_count = 1;
            long long second_same_count = 1;
            
            while(first_index + 1 <=  first_sum_list.size() - 1 ) {
                // 그 다음 숫자도 같은 경우 , 같은 숫자가 몇 번 나왔는지 센다.
                if(first_sum_list[first_index] == first_sum_list[first_index + 1]) {
                    first_same_count ++;
                    first_index ++;
                }else {
                    break;
                }
            }
            
            while(second_index-1 >= 0) {
                // 그 다음 숫자도 같은 경우 , 같은 숫자가 몇 번 나왔는지 센다.
                if(second_sum_list[second_index] == second_sum_list[second_index - 1]) {
                    second_same_count ++;
                    second_index --;
                }else {
                    break;
                }
            }
            
            count += first_same_count * second_same_count;
            
            // 0을 발견했으니, 서로 한 칸씩 이동함.
            first_index++;
            second_index--;
            
        }else if(sum < 0) {
            // 현재 0보다 더 작으니깐, 더 크게 만들어야지. 작은수부터 시작한 first index를 큰 수 가까이로 옮기자
            first_index++;
            
        }else { // sum > 0
            // 현재 더 크니깐 더 작게만들어야지. 큰수부터 시작한 second index를 작은 수 가까이로 옮겨야지
            second_index--;
        }
        
        sum = first_sum_list[first_index] + second_sum_list[second_index];
        
    }// end of while()
    
    
    return count;
    
}// end of func


int main() {
    
    int N;
    cin >> N;
    for(int i=1; i<=N; i++ ){
        cin >> A[i] >> B[i] >> C[i]>> D[i] ;
    }
    
    cout << func(N) << endl;
    
    return 0;
}
