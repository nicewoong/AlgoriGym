//
//  다음 순열 구하기 문제
//  10972.cpp
//  AlgoriGym
//
//  Created by nicewoong on 2018. 2. 15..
//  Copyright © 2018년 nicewoong. All rights reserved.
//
//  See : https://www.acmicpc.net/problem/10972

#include <stdio.h>
#include <iostream>
#define MAX_N 10001


using namespace std;


int N[MAX_N] = {0};

bool next_order(int n) {
    // find [i-1] < [i] section
    int index;
    for(int i=n; i>=1; i--) {
        
        if(i == 1){
            return false;
        }
        
        if( N[i-1] < N[i] ) {
            index = i;
            break;
        }
    }// end of for
    
   
    int swap_index;
    // index-1 에 있는 놈의 값보다 크면서 젤 뒤에 있는 녀석 index 부터 n 까지 살펴보자.
    for(int i=index; i<=n; i++) {
        if(N[index-1] < N[i])
            swap_index = i;
    }
    // swap (index-1, swap_index)
    int temp = N[index-1];
    N[index-1] = N[swap_index];
    N[swap_index] = temp;
    
    // swap_index 부터 n 까지 역순으로 바꿔줘야해.
    int i = index;
    int j = n;
    while(i<j) {
        temp = N[i];
        N[i] = N[j];
        N[j] = temp;
        i++;
        j--;
    }
    
    return true;
    
}// end of function


int main() {
    int n;
    cin >> n;
    
    for( int i=1; i<=n; i++) {
        cin >> N[i] ;
    }
    
    bool ans  = next_order(n);
    
    if(ans == false)
        cout << -1 << "\n";
    else
        for (int i=1; i<=n; i++) {
            cout << N[i] << " " ;
        }
    
    return 0;
}
