//  모든 순열
//  10974.cpp
//  AlgoriGym
//
//  Created by nicewoong on 2018. 2. 23..
//  Copyright © 2018년 nicewoong. All rights reserved.
//  See : https://www.acmicpc.net/problem/10974


#include <stdio.h>
#include <iostream>
#include <vector>
#include <algorithm>

#define MAX_N 8

using namespace std;


int A[MAX_N] = {0};


void func(int N) {
    
}


int main() {
    int N;
    cin >>  N;
    
    vector<int> numbers(N);
    
    for(int i=0; i<N; i++) {
        numbers[i] = i+1;
    }
    
    
    
    
    // 첫 permutation  출력
    for(int i=0; i< N ; i++) {
        cout << numbers[i] << " ";
    }
    cout<<"\n";
    
    
    
    // next permutation 을 반복적으로 출력
    while(next_permutation(numbers.begin(), numbers.end() )){
          // 현재 순열 출력
        for(int i=0; i < numbers.size(); i++) {
              cout<< numbers.at(i) << " ";
        }
        cout<<"\n";
    }

    return 0;
  }

          
