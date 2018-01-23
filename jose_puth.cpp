//
//  jose_puth.cpp
//  algorithm_discipline
//
//  Created by nicewoong on 2018. 1. 22..
//  Copyright © 2018년 nicewoong. All rights reserved.
//
//  BACKJUN problem number : 1158
//  See : https://www.acmicpc.net/problem/1158

#include <iostream>
#include <queue>

using namespace std;


int main(){
    queue<int> circle;
    queue<int> result;
    int count = 0;
    
    int M; // M번째마다 제거
    int N; // 총 인원 1~N
    scanf("%d %d",&N, &M );
    
    for ( int i = 1; i <= N; i++) {
        circle.push(i); // 1~ N 까지 삽입
    }
    
    int temp;
    // back 에 있는 거 하나씩 pop 해서 front 에 push 해주자. N 번재마다 push 를 생략
    
    while(1){
        if(circle.size() == 0) // 이제 원소 다 삭제 했으면 끝~!
            break;
        count += 1;
        
        temp  = circle.front(); // 다음 숫자 담고,
        circle.pop(); // 큐에서 삭제
        
        if(count % M == 0) // 이번 차례에 제거하자.
            result.push(temp);
        else
            circle.push(temp); // 큐에 다시 넣어
        
    }
    
    
    // 결과 출력
    printf("<");
    while(1) {
        temp  = result.front();
        result.pop();
        printf("%d", temp);
        if(!result.size()){
            printf(">\n");
            break;
        }else{
            printf(", ");
        }
    }
    
    
    
}
