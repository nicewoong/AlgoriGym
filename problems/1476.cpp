//
//  날짜 계산
//  1476.cpp
//  AlgoriGym
//
//  Created by nicewoong on 2018. 2. 27..
//  Copyright © 2018년 nicewoong. All rights reserved.
//  https://www.acmicpc.net/problem/1476
//

#include <stdio.h>
#include <iostream>
#define MAX_E 15
#define MAX_S 28
#define MAX_M 19


using namespace std;


int func(int E, int S, int M) {
    int e=0;
    int s=0;
    int m=0;
    int count=0;
    
    while(1) {
        
        count++;
        if(e >= MAX_E){
            e=1;
        }else {
            e++;
        }
        
        if(s >= MAX_S) {
            s=1;
        }else {
            s++;
        }
        
        if(m >= MAX_M) {
            m=1;
        }else {
            m++;
        }
        
        
        if( e==E && s==S && m==M)
            break;
        
    }
    
    return count;
}


int main() {
    int E,S,M;
    cin >> E >>S >>M;
    cout << func(E, S, M) <<endl;
    
    return 0;
}
