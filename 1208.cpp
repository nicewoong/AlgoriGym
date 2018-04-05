//
//  부분집합의 합2
//  1208.cpp
//  AlgoriGym
//
//  Created by nicewoong on 2018. 4. 4..
//  Copyright © 2018년 nicewoong. All rights reserved.
//  https://www.acmicpc.net/problem/1208
//  ans = https://gist.github.com/Baekjoon/9a29c36ef0fcc80cbaf5
//
#include <cstdio>
#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>

#define MAX_N 40
#define MAX_SUM_OF_SUBSET_LIST_SIZE pow(2,MAX_N/2);
using namespace std;


int A[MAX_N + 1] = {0} ; // 집합 원소들. 음수가 저장될 수 있음.
vector<int> first_sum_of_subset_list;
vector<int> second_sum_of_subset_list;

void make_sum_of_subset_list(int N) {
    int middle = N/2;
    vector<int> first_elements; // 1~middle 까지의 원소 담고 있을 것. 인덱스는 0부터 시작!
    vector<int> second_elements; // middle+1 ~ N 까지의 원소 담고 있을 것. 인덱스 0부터 시작!
    
    // first_elements 에 데이터 넣기
    for(int i=1; i<= middle; i++ ) {
        first_elements.push_back(A[i]);
    }
    
    // second elemets에 데이터 넣기
    for(int i=middle+1; i<= N ; i++ ) {
        second_elements.push_back(A[i]);
    }
    
    
    int first_size = first_elements.size();
    int subset_size = pow(2, first_size);
    
    // 부분집합의 합을 first_sum_of_subset_list 에 저장
    for(int i=0; i< subset_size ; i++ ) {
        
        // i = 1~middle 까지가 비트로 부분집합의 원소를 포함할지(1) 안 포함할지(0)를 담고 있다.
        // 그럼 i의 비트 표현에서, 각 자리의 비트가 1이면 해당 부분집합의 합에 더해주면 된다.
        first_sum_of_subset_list.push_back(0);
        for(int k=0; k< first_size ; k++) { // 1의 자리부터, k번 shift 해서 i 의 k번째 자리가 1인지 0인지 판단할 기준이다.
            if( i & (1<<k)) { // 둘 다 1이어야 1, 1이면 i 가 1이라는 뜻
                first_sum_of_subset_list[i] += first_elements[first_size-k-1];
            }
        }
        
    }// end of first for
    
   
    int second_size = second_elements.size();
    subset_size = pow(2, second_size);
    
    // 부분집합의 합을 first_sum_of_subset_list 에 저장
    for(int i=0; i< subset_size ; i++ ) {
        
        // i = 1~middle 까지가 비트로 부분집합의 원소를 포함할지(1) 안 포함할지(0)를 담고 있다.
        // 그럼 i의 비트 표현에서, 각 자리의 비트가 1이면 해당 부분집합의 합에 더해주면 된다.
        second_sum_of_subset_list.push_back(0);
        for(int k=0; k< second_size ; k++) { // 1의 자리부터, k번 shift 해서 i 의 k번째 자리가 1인지 0인지 판단할 기준이다.
            if( i & (1<<k)) { // 둘 다 1이어야 1, 1이면 i 가 1이라는 뜻
                second_sum_of_subset_list[i] += second_elements[second_size-k-1];
            }
        }
        
    }// end of first for
    
    
}

long long func(int N, int S) {
    int first_index = 0;
    int second_index = second_sum_of_subset_list.size() -1 ;
    
    sort(first_sum_of_subset_list.begin(), first_sum_of_subset_list.end());
    sort(second_sum_of_subset_list.begin(), second_sum_of_subset_list.end());
    
    long long count = 0;
    int sum = first_sum_of_subset_list[first_index] + second_sum_of_subset_list[second_index];
    
    while(first_index < first_sum_of_subset_list.size() && second_index >=0) {
        
        if(sum < S) {
            first_index ++;
        }else if (sum > S) {
            second_index--;
        }else { // sum == S
            long long same_count_first = 1;
            long long same_count_second = 1;
            while(first_index < first_sum_of_subset_list.size()-1 ) {
                if(first_sum_of_subset_list[first_index] == first_sum_of_subset_list[first_index + 1]) {
                    first_index++;
                    same_count_first++;
                }else {
                    break;
                }
                
            }
            
            while(second_index >=1) {
                if(second_sum_of_subset_list[second_index] == second_sum_of_subset_list[second_index - 1]) {
                    second_index--;
                    same_count_second++;
                }else {
                    break;
                }
            }
            
            count += same_count_first*same_count_second;
            first_index++;
            second_index--;
        }
        
        sum = first_sum_of_subset_list[first_index] + second_sum_of_subset_list[second_index];
        
        
    }
    // 찾는 수가 0일 경우
    if (S == 0) // 공집합인 경우는 제외해야함
        count -= 1;
    
    return count;
    
    
} // end of func()


int main() {
    
    
    int N;  // 주어질 정수의 갯수
    int S;  // 더해서 합이 되어야 하는 수 , 음수가 될 수 있음.
    
    cin >> N >> S;
    for(int i=1; i<=N ;i++ ) {
        cin >> A[i];
    }
    
    make_sum_of_subset_list(N);
    cout << func(N, S) << endl;
    
    return 0;
}




