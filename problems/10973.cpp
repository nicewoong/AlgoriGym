//
//  10973.cpp
//  AlgoriGym
//
//  Created by nicewoong on 2018. 2. 23..
//  Copyright © 2018년 nicewoong. All rights reserved.
//

#include <stdio.h>
#include <iostream>
#define MAX_N 10000

using namespace std;


int A[MAX_N] = {0};


void myswap(int index1, int index2) {
    int temp = A[index1];
    A[index1] = A[index2];
    A[index2] = temp;
}


bool func(int N) {
    
    int i;
    for( i=N-1; i>=0; i-- ) { // 뒤에서부터 보면서 a>b 인 구간을 찾는다.
        if(A[i] > A[i+1])
            break;
        if(i==0)
            return false;
    }
//
    // index 가 i 보다 오른쪽에 있는 녀석들 중 자기보다 작으면서 가장 큰 녀석을 찾는다.
    int j = i+1;
    int maxIndex = i+1;
    for(j=i+1; j<=N; j++ ) {
        if(A[i] > A[j] && A[maxIndex] < A[j])
            maxIndex = j;
    }
    
    myswap(i, maxIndex); // 바꿔치고,
    // i 인덱스 뒤쪽에 있는 녀석들을 a>b>c>d 이렇게 되도록 sort 한다.
    int k=N;
    int l=i+1;
    while(l < k) {
        myswap(l,k);
        l++;
        k--;
    }
    
    return true;
    
}

int main() {
    int N;
    cin >> N;
    
    for(int i=1; i<=N; i++) {
        cin>> A[i];
        
    }
    
    if(func(N))
        for(int i=1; i<=N; i++) {
            cout << A[i] << " ";
            
        }
    
    else
        cout << -1 << "\n";
    return 0;
}
