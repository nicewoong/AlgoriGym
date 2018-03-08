//
//  퍼즐
//  1525.cpp
//  AlgoriGym
//
//  Created by nicewoong on 2018. 3. 8..
//  Copyright © 2018년 nicewoong. All rights reserved.
//  https://www.acmicpc.net/problem/1525
//
//  2차원 배열을 1차원 배열로 보자.
//  1차원 배열을 하나의 문자열 또는 숫자로 보고 상태를 저장할 수 있다.
//  최대 경우의 수가 매우 많고 빈틈이 많으므로, Map 을 이용해서 방문 표시 한다.
//  숫자로 상태 저장하며푸는 것이 오버헤드가 더 적다!
//  https://gist.github.com/Baekjoon/6fa3fdc760b4ffc95d75

#include <cstdio>
#include <queue>
#include <iostream>
#include <algorithm>
#include <cstring>
#include <map>
#include <string>

#define MAX_LEN 10


using namespace std;



char A[MAX_LEN] = {0}; //초기 값 저장, 2차원 배열을 1차원 배열에 저장. 0부터 ~ 8까지 사용. 9에는 널문자 넣어야함.


// 위의 녀석과 바꾸는 경우의 결과 상태 반환.
string swap_up(string cur_string, int index_of_zero) {
    string next(cur_string);
    
    int index_of_swap ;

    index_of_swap = index_of_zero - 3;
    if(index_of_swap < 0)
        return next;

    next[index_of_zero] = next[index_of_swap];
    next[index_of_swap] = '0';
    return next;
    
}

// 아래의 녀석과 바꾸는 경우의 결과 상태 반환.
string swap_down(string cur_string, int index_of_zero) {
    string next(cur_string);
    int index_of_swap ;
    
    index_of_swap = index_of_zero + 3;
    if(index_of_swap > 8) // 바꾸는 것이 불가능하면 그대로 리턴.
        return next;
    
    next[index_of_zero] = next[index_of_swap];
    next[index_of_swap] = '0';
    return next;
    
}

// 오른쪽의 녀석과 바꾸는 경우의 결과 상태 반환.
string swap_right(string cur_string, int index_of_zero) {
    string next(cur_string);
    int index_of_swap ;
    
    index_of_swap = index_of_zero + 1;
    if(index_of_swap % 3 ==0) // 바꾸는 것이 불가능하면 그대로 리턴.
        return next;
    
    next[index_of_zero] = next[index_of_swap];
    next[index_of_swap] = '0';
    return next;
    
}

// 왼쪽의 녀석과 바꾸는 경우의 결과 상태 반환.
string swap_left(string cur_string, int index_of_zero) {
    string next(cur_string);
    int index_of_swap ;
    
    index_of_swap = index_of_zero - 1;
    if(index_of_zero % 3 == 0) // 바꾸는 것이 불가능하면 그대로 리턴.
        return next;
    
    next[index_of_zero] = next[index_of_swap];
    next[index_of_swap] = '0';
    return next;
    
}


int func() {
    string target("123456780"); // 최종적으로 찾아야할 것.
    string start(A);
    //시작점 큐에 넣고, visited 표시하고,
    queue<string> q;
    map<string, int> visited;
    
    q.push(start);
    visited[start] = 1;
    
    while(!q.empty()) {
        
        string cur_string =  q.front();
        q.pop();
        
        // 0위치를 찾고,
        int index_of_zero = 0;
        // 0이 있는 자리의 인덱스를 찾아야해.
        for(int i=0; i<10; i++) {
            if(cur_string[i] == '0')
                index_of_zero = i;
        }
        
        // 위 상태, 방문확인, 큐에 저장, visited 저장
        string next = swap_up(cur_string, index_of_zero);
        if(!visited[next]) {
            q.push(next);
            visited[next] = visited[cur_string] + 1;
            if(next.compare(target)==0)
                break;
        }
        // 아래
        string next_down = swap_down(cur_string, index_of_zero);
        if(!visited[next_down]) {
            q.push(next_down);
            visited[next_down] = visited[cur_string] + 1;
            if(next_down.compare(target)==0)
                break;
        }
        // 왼
        string next_left = swap_left(cur_string, index_of_zero);
        if(!visited[next_left]) {
            q.push(next_left);
            visited[next_left] = visited[cur_string] + 1;
            if(next_left.compare(target)==0)
                break;
        }
        
        // 오
        string next_right = swap_right(cur_string, index_of_zero);
        if(!visited[next_right]) {
            q.push(next_right);
            visited[next_right] = visited[cur_string] + 1;
            if(next_right.compare(target)==0)
                break;
        }
        
        
    }// end of while
    
    
    int result = visited[target];
    
    return result-1;


}

string get_next(string current) {
    string next(current);
    return next;
}


void test() {
    map<string, int> m;
    string current("123456780");
    m[current] = 1;
    string next = get_next("123456780");
    int result = m[next];
    
    if(!result) {
        cout << "없대" << endl;
    }else {
        cout << "있대." << endl;
    }
        
}

int main() {

    // 3*3 배열이 주어짐.
    for(int i=0; i<=8 ; i++) {
        cin >> A[i];
    }
    A[9] = '\0';

    cout << func() << endl;

//    string start(A);
//    cout << swap_right(A, 6) << endl;
////    test();
    
    return 0;
}





