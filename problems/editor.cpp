//
//  editor.cpp
//  algorithm_discipline
//
//  Created by nicewoong on 2018. 1. 11..
//  Copyright © 2018년 nicewoong. All rights reserved.
//
//  BACKJUN problem number : 1406
//  See : https://www.acmicpc.net/problem/1406
//
// input :
//    abcd
//    3
//    P x
//    L
//    P y
//
// output : "abcdyx"
//

#include <iostream>
#include <stack>
//#define MAX_SIZE 600,000  // 최대 600,000글자까지 입력할 수 있다.

using namespace std;


// Global var
string input_text; // 길이는 100,000을 넘지 않는다.
int N; // (1≤N≤500,000)
stack<char> left_line;
stack<char> right_line;

void prob() {
    cin >> input_text;
    for(int i = 0; i<input_text.size(); i++) {
        left_line.push(input_text[i]);  // time :O(n)
    }
    
    cin >> N;
    // read N of command
    char command;
    for (int i = 0; i < N ; i++) {
        cin >> command;  // read command
        
        char ch;
        if (command == 'L') {  // move left
            if(left_line.empty())
                continue;
            ch = left_line.top();
            left_line.pop();
            right_line.push(ch);
        
        } else if (command == 'D') {  // move right
            if(right_line.empty())
                continue;
            ch = right_line.top();
            right_line.pop();
            left_line.push(ch);
            
        } else if (command == 'B') {  // delete left
            if(left_line.empty())
                continue;
            ch = left_line.top();
            left_line.pop();
            
        } else if (command == 'P') {  // add left a character
            cin >> ch;
            left_line.push(ch);
        }
    }
    
    char ch;
    while(!left_line.empty()) {
        ch = left_line.top();
        left_line.pop();
        right_line.push(ch);
        
    }
    
    while(!right_line.empty()) {
        cout << right_line.top();
        right_line.pop();
    }
    cout<<"\n";
}


int main() {
    prob();
}


