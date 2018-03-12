//
//  암호 만들기 - 순열 이용해서 풀기
//  1759.cpp
//  AlgoriGym
//
//  Created by nicewoong on 2018. 3. 12..
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

vector<int> CHOICE;
vector<char> A_LIST;

// 모음 한 개 이상, 자음 두 개이상 맞는지.
int check_rule(char* list, int L) {
    int a_count=0; // 모음 카운트
    int b_count=0; // 자음 카운트
    
    for(int i=0; i<L; i++) {
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


void func(int L, int C) {
    // CHOICE 를 순열로 하면서 반복

    char list[MAX_C+1] ;
    
    do {
        
        // CHOICE  가 1인 인덱스에 따라 골라서 패스워드 만들자.
        int index = 0;
        for(int i=0; i<C; i++) {
            if(CHOICE[i]==1)
                list[index++] = A_LIST[i];
        }
        list[index] = '\0';
        
        if(check_rule(list, L)==1) // 패스워드 룰에 맞으면, 출력
            printf("%s\n", list);
        
        
    }while(prev_permutation(CHOICE.begin(), CHOICE.end() ));
}


int main () {
    int L; // L 개의 비번이 되어야 함.
    int C; // C 개의 알파벳이 주어짐
    
    cin >> L >> C;
    for(int i=1; i<=C; i++) {
        char temp;
        cin >> temp;
        A_LIST.push_back(temp);
        
        // 순열 돌릴 것
        if(i<=L)
            CHOICE.push_back(1);
        else
            CHOICE.push_back(0);
    }
    
    
    sort(A_LIST.begin(), A_LIST.end());
    func(L, C);
    
    
    return 0;
}
