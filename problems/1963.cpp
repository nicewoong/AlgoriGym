//
//  소수 경로
//  1963.cpp
//  AlgoriGym
//
//  Created by nicewoong on 2018. 3. 2..
//  Copyright © 2018년 nicewoong. All rights reserved.
//  https://www.acmicpc.net/problem/1963
//

#include <cstdio>
#include <iostream>
#include <cmath>
#include <algorithm>
#include <vector>
#include <queue>

using namespace std;


#define MAX_N 9999




int isPrime(int n) {
    
    for(int i=2; i<=n-1; i++ ) {
        if(n%i==0) // 나누어 떨어지면 false 소수가 아님.
            return 0;
    }
    return 1;
}


//네 자리 소수 -> 네 자리 소수 로 한 자리씩 바꾸는데 몇 번 걸리는지 반환
int func(int N_from, int N_to) {
    int visited[MAX_N + 1] = {0};
    queue<int> q;
    
    q.push(N_from); // q에 최초 하나 넣고 시작할 것.
    visited[N_from] = 1; // q 에 넣을 때 visited 표시해야함.  visited 가 현재까지 오는데 얼마나 걸렸는지 갖고 있겠다.
    
    while( ! q.empty() ) {
        int cur_num = q.front();
        q.pop();
        
        int converted_num = cur_num;
        // 첫 째 자리 바꿨을 경우 (1~9), 방문 안 했고, 소수 이면 큐에 집어넣자.
        for(int i=1; i<=9; i++) {
            // 첫 째 자리 숫자를 i 로 바꾸자.
            int post = cur_num % 1000; // 뒷 세자리 구하고.
            converted_num = i*1000 + post; // 앞 자리를 바꿔서 뒷 세자리 더해줘서 네 자리 됐음
            
            // 방문 했다면, continue;// 소수가 아니라면 continue;
            if( (visited[converted_num] != 0) || (isPrime(converted_num) == 0) )
                continue;
            
            // 이제 방문표시 해주고 큐에 넣으면 된다.
            visited[converted_num] = visited[cur_num] + 1; // 이동한 횟수에 1을 더해주자.
            q.push(converted_num);
            
        }
        
        // 둘 째 자리 바꿨을 경우 (0~9)
        for(int i=0; i<=9; i++) {
            // 천의 자리 숫자 구하고
            int prev = cur_num / 1000;
            int post = cur_num % 100; // 뒷 두자리 구하고.
            
            converted_num = prev*1000 + i*100 + post; // 두 째자리 바꿔서 네 자리 됐음
            
            
            // 방문 했다면, continue;// 소수가 아니라면 continue;
            if( (visited[converted_num] != 0) || (isPrime(converted_num) == 0) )
                continue;
            
            // 이제 방문표시 해주고 큐에 넣으면 된다.
            visited[converted_num] = visited[cur_num] + 1; // 이동한 횟수에 1을 더해주자.
            q.push(converted_num);
        }
        
        // 셋 째 자리 바꿨을 경우 (0~9)
        for(int i=0; i<=9; i++) {
            // 앞의 두 자리 숫자 구하고
            int prev = cur_num / 100;
            int post = cur_num % 10; // 뒷 한 자리 구하고.
            
            converted_num = prev*100 + i*10 + post; // 셋 째 자리 바꿔서 네 자리 됐음
            
            // 방문 했다면, continue;// 소수가 아니라면 continue;
            if( (visited[converted_num] != 0) || (isPrime(converted_num) == 0) )
                continue;
            
            // 이제 방문표시 해주고 큐에 넣으면 된다.
            visited[converted_num] = visited[cur_num] + 1; // 이동한 횟수에 1을 더해주자.
            q.push(converted_num);
            
        }
        
        // 넷 째 자리 바꿨을 경우 (0~9)
        for(int i=0; i<=9; i++) {
            // 앞의 세 자리 숫자 구하고
            int prev = cur_num / 10;
            converted_num = prev*10 + i; // 셋 째 자리 바꿔서 네 자리 됐음
            
            // 방문 했다면, continue;// 소수가 아니라면 continue;
            if( (visited[converted_num] != 0) || (isPrime(converted_num) == 0) )
                continue;
            
            // 이제 방문표시 해주고 큐에 넣으면 된다.
            visited[converted_num] = visited[cur_num] + 1; // 이동한 횟수에 1을 더해주자.
            q.push(converted_num);
            
        }
    }
    
    return visited[N_to] - 1;
}



int main() {
    
    
    
    // 게임 몇 번 할지
    int how_many ;
    cin >> how_many;
    
    for(int i=0; i<how_many ;i++) {
        // 네자리숫자 두 개를 입력 받는다.
        int N_from;
        int N_to;
        cin >> N_from >> N_to
        
        if(N_from==N_to) { // 동일한 수는 이동 0 번.
            cout << 0 << endl;
            continue;
        }
        
        int ans = func(N_from, N_to);
        if(ans==0) // 불가능할 경우 0
            cout << "Impossible" << endl;
        else
            cout << ans << endl;
    }
    
    
    return 0;
}




