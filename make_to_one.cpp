//  1로 만들기 문제 
//  make_to_one.cpp
//  algorithm_discipline
//
//  Created by nicewoong on 2018. 1. 23..
//  Copyright © 2018년 nicewoong. All rights reserved.
//
//  BACKJUN problem number : 1463, 1로 만들기
//  See : https://www.acmicpc.net/problem/1463

#include <stdio.h>
#include <iostream>
#define MAX 1000000

using namespace std;

int d[MAX] = {0}; // 배열 전체를 0으로 초기화

// make to one in recursive way
int recursive_make_to_one(int num){
    if(num == 1) {
        return 0;
    }
    
    // 이거 안하면 답은 나오는데 시간 초과됨. d[num] 의 값이 채워진다면 바로 끝내야함! !!
    if(d[num]>0)
        return d[num];
    
    // -1 해보기
    int temp = recursive_make_to_one(num-1);
    d[num] = temp + 1;
    
    if(num % 3 == 0) { // 3으로 나누어 떨어지면
        int temp = recursive_make_to_one(num/3);
        if(temp < d[num])
            d[num] = temp + 1;
    }
    
    if(num % 2 == 0) { // 2로 나누어 떨어지면
        int temp = recursive_make_to_one(num/2);
        if(temp < d[num])
            d[num] = temp + 1;
    }
    
    
    
    return d[num];
    
}


// make to one in iterative way
// 둘 다 해보니 반복문이 훨씬 메모리도 적고, 시간도 단축됨!!!! bottom-up 방식을 지향하자.
int iterate_make_to_one(int num) {
    int temp;
    
    d[1] = 0;
    d[2] = 1;
    d[3] = 1;
    
    for(int i = 4 ; i <= num ; i++) {
        d[i] = d[i-1] + 1;
        
        if(i%3==0) {
            temp = d[i/3] + 1;
            if(d[i] > temp )
                d[i] = temp;
        }
        
        if(i%2 == 0) {
            temp = d[i/2] + 1;
            if(d[i] > temp)
                d[i] = temp;
        }
        
    }
    
    return d[num];
    
    
}

int main() {
    int num;
    scanf("%d", &num);
    int res = iterate_make_to_one(num);
    printf("%d \n", res);
    
    return 0;
}
