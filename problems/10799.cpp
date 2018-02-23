//
//  cutting_brackets.cpp
//  algorithm_discipline
//
//  Created by nicewoong on 2018. 1. 8..
//  Copyright © 2018년 nicewoong. All rights reserved.
//
//  BACKJUN problem number : 10799
//  See : https://www.acmicpc.net/problem/10799
//  input format : "()(((()())(())()))(())"
//  output format : 17

#include <iostream>

using namespace std;


// Global var
char last_brk = NULL;
int sliceable_count = 0;
int sum_of_slice = 0;


void prob() {
    string brackets;
    cin>>brackets;  // input barkets sitrngs
    
    for(int i = 0; i < brackets.size(); i++) {
        char current_brk = brackets[i];
        
        if (last_brk == '(') {
            
            if(current_brk == ')') {
                sliceable_count -= 1;
                // () 괄호 닫힘이 생겼으니깐 지금까지의 것 한 번 토막내야지. 레이저 쏴야지!
                sum_of_slice += sliceable_count;
                
            } else { //current_brk == '('
                sliceable_count += 1;
            }
            
        }else if (last_brk == ')') {
            
            if(current_brk == ')') {
                sliceable_count -= 1;
                // 예전에 형성된 짝대기의 ) 괄호 닫힘이 생겼으니깐 이 끝난 작대기 하나를 추가해줘야지.
                sum_of_slice += 1;
                
            } else { //current_brk == '('
                sliceable_count += 1;
            }
            
        } else {  // last_brk == NULL
            last_brk = current_brk;
            if(current_brk == '(')
                sliceable_count += 1;
            else
                sliceable_count -= 1;
        }
        
        // update last brk
        last_brk = current_brk;
        
    }
    
    cout << sum_of_slice <<"\n";
    
}


int main() {
    prob();
}


