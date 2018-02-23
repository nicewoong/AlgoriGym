//
//  집합 문제
//  11723.cpp
//  AlgoriGym
//
//  Created by nicewoong on 2018. 2. 15..
//  Copyright © 2018년 nicewoong. All rights reserved.
//
//  See : https://www.acmicpc.net/problem/11723


#include <stdio.h>
#include <string.h>
#include <iostream>


using namespace std;


long long S = 0;  // 공집합, 뒷 20 bit 를 사용할 것이다.

void add(int x) {
    //     S에 x를 추가한다. (1 ≤ x ≤ 20) S에 x가 이미 있는 경우에는 연산을 무시한다.
    S = S | (1 << (x-1));
}

void remove(int x) {
    // S에서 x를 제거한다. (1 ≤ x ≤ 20) S에 x가 없는 경우에는 연산을 무시한다.
    S = S & (~ (1 << (x-1)) );
}

int check(int x) {
    if( (S >> (x-1)) & (1) ) {
        return 1;
    } else {
        return 0;
    }
        
}

void toggle(int x) {
    //     S에 x가 있으면 x를 제거하고, 없으면 x를 추가한다. (1 ≤ x ≤ 20)
    if( check(x) ) // x 번째 값이 무엇인지
        remove(x);//1 일 경우 -> 0 으로 제거
    else
        add(x);
}

void all() {
    for( int i = 0; i<20; i++) {
        S = S | (1 << i );
    }
   
}

void empty() {
    S = 0;
}

int main() {
    int M; // 수행해야하는 연산의 수
    cin >> M;
    
    int operand = 0;
    char operation[10];
    for (int i = 0; i< M ; i++ ) {
        
        scanf("%s", operation);
        if (strcmp("all", operation) == 0) {
            // don't read operand
            all();
            continue;
        }
        
        if (strcmp("empty", operation) == 0) {
            empty();
            continue;
        }
        
        scanf("%d", &operand); // read operand
        
        if (strcmp("add", operation) == 0) {
            add(operand);
        }else if (strcmp("remove", operation) == 0) {
            remove(operand);
        }else if (strcmp("check", operation) == 0) {
            cout<< check(operand) << "\n" ;
        }else if (strcmp("toggle", operation) == 0) {
            toggle(operand);
        }
        
    }// end of for
    
    return 0;
}
