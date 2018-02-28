//
//  외판원 순회 2
//  10971.cpp
//  AlgoriGym
//
//  Created by nicewoong on 2018. 2. 28..
//  Copyright © 2018년 nicewoong. All rights reserved.
//  https://www.acmicpc.net/problem/10971
//

#include <cstdio>
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


#define MAX_COST 1000000

int W[11][11]={0};

vector<int> list;


int TSP(int N) {
    
    // next_permutation 해가면서 다 해보고 최소값 찾기
    int min = MAX_COST*20;
    
    do{
        
        
        int distance = 0;
        for(int k=0; k <= N-1; k++) {
            // k->k+1 번까지 가는 길 더해가자
            int start = list[k];
            int end = list[(k+1)%N];
//            cout << start << "->" << end << ":" <<W[start][end] <<endl;
            if(W[start][end]==0) {
                distance = 0;
                break;
            }
            distance += W[start][end];
        }
        
        
        // 다 더 한 길이 최소 값인지
        if(distance > 0 && min > distance)
            min = distance;
        
    
            
    }while(next_permutation(list.begin(), list.end() ));

    return min;

    
}// end of TSP()

int main() {
    
    int N;
    cin>> N ;
    for(int i = 1; i<= N; i++) {
        for(int j = 1; j<= N; j++)
            cin >> W[i][j];
    }
    
    for(int i=0; i<N; i++)
        list.push_back(i+1);
        
    cout << TSP(N) << endl;
    
    
    
    return 0;
    
}
