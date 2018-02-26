//
//  암호코드
//  2011.cpp
//  AlgoriGym
//
//  Created by nicewoong on 2018. 2. 25..
//  Copyright © 2018년 nicewoong. All rights reserved.
//  See : https://www.acmicpc.net/problem/2011
//

#include <stdio.h>
#include <iostream>
#define MAX_N 5000
#define MOD 1000000

using namespace std;


int main() {
    
    int d[MAX_N+1] = {0}; // 젠장... +1 안 해줘서 틀린 거였어.................

    char numbers[MAX_N+2] = {'\0'}; // 마지막에 null 문자('\0') 가 들어가야 하니깐 +2 해줬음!!!
    
    scanf("%s", &numbers[1]);
    
    
    d[0]=1;
    d[1]=1;
    
    int n=1;
    if(numbers[1] == '0' ){ // 0 만 입력됐을 때
        printf("%d\n", 0);
        return 0;
    }
        
    if(numbers[2] == '\0'){ // 한 자릿수만 입력됐을 때는 한 가지 경우 밖에 없다.
        printf("%d\n", d[1]);
        return 0;
    }
    
    
    for(n=2; numbers[n] != '\0'; n++) { // read array Numbers[]
        // 끝 두자리 숫자가 'AB' 라고 가정.
        int A = numbers[n-1]-'0'; // n-1번째 숫자 ~~~~(AB)
        int B = numbers[n]-'0'; // n번째
        
        
        // n번째 숫자 한 자리 숫자라고 봤을 때. 1~9 일때만.
        if(B>=1 && B<=9) {
            d[n] += d[n-1]*1;
            d[n]%=MOD;
        }
        
        
        // n-1번째 숫자까지 두 자리 숫자라고 봤을 때
        if((A==1 && B>=0 && B<=9) || (A==2 && B>=0 && B<=6)  ) {
            d[n] += d[n-2]*1;
            d[n]%=MOD;
        }
        
    }
    
    
    printf("%d\n", d[n-1]);
    
    return 0;
}
