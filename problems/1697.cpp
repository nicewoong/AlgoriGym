//
//  숨바꼭질
//  1697.cpp
//  AlgoriGym
//
//  Created by nicewoong on 2018. 3. 1..
//  Copyright © 2018년 nicewoong. All rights reserved.
//  https://www.acmicpc.net/problem/1697
//

#include <iostream>
#include <cstdio>
#include <algorithm>
#include <queue>
#define MAX_N 100000 * 2 + 1
using namespace std;

int visited[MAX_N]  = {0}; // 1 ~  MAX_N


int get_min_time(int N, int K) {
    
    // N 부터 시작해서 가지를 하나씩 하나씩 큐에 넣어( 넣을 땐 방문 안 한 녀석들만 넣어).
    // (넣을 때 방문 표시 해야함.) -> 방문표시할 땐 이전 놈 + 1 저장하자.
    // 큐에서 하나 빼서 K에 도착햇는지 확인해.
    // 도착 안 햇으면 역시 가지들 하나씩 큐에 넣어. 도착이면 스탑하고 이전놈 +1 출력. 이거 반복.
    
    queue<int> q;
    q.push(N);
    visited[N] = 0;
    
    while(!q.empty()) {
        int cur_num = q.front(); // 큐에서 하나 뽑고
        q.pop(); // 데이터 뽑았으면 삭제!
        
        // -1 로 갈 경우
        if(cur_num - 1  >= 0 && visited[cur_num - 1] == 0 ) { // 아직 방문 안 했으면
            // 넣어주며 방문 표시
            q.push(cur_num-1);
            visited[cur_num-1] = visited[cur_num] + 1; // 방문표시
            if( cur_num-1 == K)
                break;
        
        }
        
        // +1 로 갈 경우
        if(cur_num + 1 < MAX_N && visited[cur_num + 1] == 0 ) { // 아직 방문 안 했으면
            q.push(cur_num+1);
            visited[cur_num + 1] = visited[cur_num] + 1;
            if( cur_num + 1 == K)
                break;
        }
        
        
        // * 2로 갈 경우
        if(cur_num * 2 < MAX_N && visited[cur_num * 2] == 0 ) { // 아직 방문 안 했으면
            q.push(cur_num * 2);
            visited[cur_num * 2] = visited[cur_num] + 1;
            if( cur_num * 2 == K)
                break;
        }
        
        
    } // end of while()
    
    
    return visited[K];
    
}


int main() {
    int N;
    int K;
    
    cin >> N >> K;
    if(N==K) {
        cout << 0 << endl;
        return 0;
    }
        
    cout << get_min_time(N, K) << endl;
    
    
    return 0;
}
