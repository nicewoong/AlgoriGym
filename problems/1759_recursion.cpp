//
//  암호 만들기 - Recursion 이용해서 풀기
//  1759.cpp
//  AlgoriGym
//
//  Created by nicewoong on 2018. 3. 13.
//  Copyright © 2018년 nicewoong. All rights reserved.
//
//  https://www.acmicpc.net/problem/1759

#include <cstdio>
#include <iostream>
#include <vector> // for vector
#include <algorithm> // for sort
#include <cstring>

#define MAX_C 15

using namespace std;

vector<char> list;


// 모음 한 개 이상, 자음 두 개이상 맞는지.
int check_rule(string list) {
    int a_count=0; // 모음 카운트
    int b_count=0; // 자음 카운트
    
    for(int i=0; i<list.size(); i++) {
        char ch = list[i];
        if(ch == 'a' || ch == 'i' || ch == 'e'|| ch == 'o'|| ch == 'u')
            a_count++;
        else
            b_count++;
    }
    
    if(a_count<1) // 모음이 한 개도 없으면 false
        return 0;
    if(b_count<2) // 자음이 두 개 미만 되면 false
        return 0;
    
    return 1;
    
}


void func(string cur_str, int start_index, int L, int C, int origin_L) {
    
    
    if(cur_str.size() == origin_L) {
        if(check_rule(cur_str) == 1)
            cout << cur_str <<endl;
        return;
    }
    
    if(start_index >= C)
        return;
    
    for(int i = start_index; i<= C-L; i++) {
        string next_str = cur_str + list[i];
        int next_index = i+1;
        func(next_str, next_index, L - 1, C, origin_L);
    }
    

}


int main () {
    int L; // L 개의 비번이 되어야 함.
    int C; // C 개의 알파벳이 주어짐
    
    cin >> L >> C;
    for(int i=1; i<=C; i++) {
        char temp;
        cin >> temp;
        list.push_back(temp);
    }
    sort(list.begin(), list.end());
    
    func("", 0, L, C, L);
    return 0;
}

