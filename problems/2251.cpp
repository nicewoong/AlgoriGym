//
//  물통
//  2251.cpp
//  AlgoriGym
//
//  Created by nicewoong on 2018. 3. 8..
//  Copyright © 2018년 nicewoong. All rights reserved.
//  https://www.acmicpc.net/problem/2251
//

#include <cstdio>
#include <iostream>
#include <string>
#include <cstring>
#include <algorithm>
#include <vector>
#include <queue>
#include <map>

#define MAX_L 200

using namespace std;
vector<int> result_c_list; // A가 0일 때 C의 결과를 하나씩 저장할 거야.

int max_list[3] = {0};

// visited 로 넣을 때만 연결한 숫자로 변경해서 넣어주자.
int make_one_number(int A, int B, int C) {
    // 모두 세자리로 만들어줘야해.
    int one_number = A*1000000 + B*1000 + C;
    return one_number;
}

void make_three_number_list(int one_number, int* A, int* B, int* C) {
    (*A) = one_number/1000000;
    one_number -= (*A)*1000000;
    (*B) = one_number/1000;
    one_number -= (*B)*1000;
    (*C) = one_number;
}

int pour(int *cur_list_origin,int index_from, int index_to) {
    int cur_list[3];
    for(int i=0; i<=2; i++) {
        cur_list[i] = cur_list_origin[i] ;
    }
    int gap_to = max_list[index_to] - cur_list[index_to];
    int gap_from = cur_list[index_from];
    if(gap_from  <= gap_to) {
        cur_list[index_to] += cur_list[index_from];
        cur_list[index_from] = 0;
    }else {
        cur_list[index_from] -= gap_to;
        cur_list[index_to] = max_list[index_to];
    }
    return make_one_number(cur_list[0], cur_list[1], cur_list[2]);
}

void printlist(int * list) {
    for(int i=0 ; i < 3; i++) {
        cout << list[i] << " ";
    }
    cout <<endl;
}



void func() {
    queue<int> q;
    map<int, int> visited;
    vector<int> result_list;
    // 시작 점 큐에 넣고, visited 하고
    int start = make_one_number(0, 0, max_list[2]); // 이렇게 시작해. A 는 비어있고, 나머진 꽉차있어.
    q.push(start);
    visited[start] = 1;
    result_list.push_back(start%1000);
    
    
    while(!q.empty()) {
        int cur_one_number = q.front();
        q.pop();
        
        int cur_list[3];
        make_three_number_list(cur_one_number, &cur_list[0], &cur_list[1], &cur_list[2]);
        
        // A->B
        int next = pour(cur_list, 0, 1);
        if( visited[next] == 0) { // 아직 방문 안 했으면
            q.push(next);
            visited[next] = visited[cur_one_number] + 1;
            if(next/1000000 == 0) // A가 0 일 때
                result_list.push_back(next%1000); // C의 값 저장.
        }
        // A->C
        next = pour(cur_list, 0, 2);
        if( visited[next] == 0) { // 아직 방문 안 했으면
            q.push(next);
            visited[next] = visited[cur_one_number] + 1;
            if(next/1000000 == 0) // A가 0 일 때
                result_list.push_back(next%1000); // C의 값 저장.
        }
        // B->A
        next = pour(cur_list, 1, 0);
        if( visited[next] == 0) { // 아직 방문 안 했으면
            q.push(next);
            visited[next] = visited[cur_one_number] + 1;
            if(next/1000000 == 0) // A가 0 일 때
                result_list.push_back(next%1000); // C의 값 저장.
        }
        // B->C
        next = pour(cur_list, 1, 2);
        if( visited[next] == 0) { // 아직 방문 안 했으면
            q.push(next);
            visited[next] = visited[cur_one_number] + 1;
            if(next/1000000 == 0) // A가 0 일 때
                result_list.push_back(next%1000); // C의 값 저장.
        }
        // C->A
        next = pour(cur_list, 2, 0);
        if( visited[next] == 0) { // 아직 방문 안 했으면
            q.push(next);
            visited[next] = visited[cur_one_number] + 1;
            if(next/1000000 == 0) // A가 0 일 때
                result_list.push_back(next%1000); // C의 값 저장.
        }
        // C->B
        next = pour(cur_list, 2, 1);
        if( visited[next] == 0) { // 아직 방문 안 했으면
            q.push(next);
            visited[next] = visited[cur_one_number] + 1;
            if(next/1000000 == 0) // A가 0 일 때
                result_list.push_back(next%1000); // C의 값 저장.
        }
        
    } // end of queue while
    
    sort(result_list.begin(), result_list.end());
    for(int i=0; i<result_list.size(); i++) {
        cout << result_list[i] << " ";
    }
    cout << endl;
    
    
    
    
}


int main() {
    

    cin >> max_list[0] >> max_list[1] >> max_list[2]; // 용량을 입력받아.

    func();
    
//    int result = make_one_number(8, 1, 10);
//    cout << result;
    return 0;
}




