//
//  부분집합의 합
//  1182.cpp
//  AlgoriGym
//
//  Created by nicewoong on 2018. 3. 26..
//  Copyright © 2018년 nicewoong. All rights reserved.
//  https://www.acmicpc.net/problem/6603
//

#include <cstdio>
#include <iostream>
#include <vector>

#define MAX_N 20 //1<=N<=20 (포함)

using namespace std;

int A[MAX_N + 1] = {0};
int count_all=0; // 경우의 수
vector<int> list;

bool is_correct(int S) {
    int sum = 0;
    
    if(list.size()==0)
        return false;
    
    // 현재까지의 리스트 다 더해보고 S가 되면 true 반환
    for(int i=0; i<list.size(); i++ ) {
        sum+=list[i];
    }
    
    if(sum == S)
        return true;
    else
        return false;
    
}

void func(int K, int S, int cur_i) {
    
    if(is_correct(S)) {
        count_all += 1; // 경우의 수 하나 증가
    }
    
    if(cur_i==K) // 마지막 인덱스까지 다 봤으면 스톱!
        return;
    
    for(int i=cur_i+1; i<=K; i++) {
        list.push_back(A[i]); // 다음 것 넣어보고
        func(K, S, i); // 진입해서 진행해보고
        list.pop_back(); // 다시 원상복귀 해보고.
    }
    
}


int main() {

    int N; // 정수 갯수
    int S; // 합이 S가 되는 경우의 수 구할거임.
    cin >> N >> S;
    
    for(int i=1; i<=N; i++) {
        cin >> A[i];
    }
    
    func(N, S, 0);
    
    cout << count_all << endl;
    
    
    return 0;
}
