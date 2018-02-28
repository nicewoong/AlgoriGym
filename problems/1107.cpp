//
//  리모컨
//  1107.cpp
//  AlgoriGym
//
//  Created by nicewoong on 2018. 2. 27..
//  Copyright © 2018년 nicewoong. All rights reserved.
//  https://www.acmicpc.net/problem/1107
//

#include <stdio.h>
#include <iostream>
#include <cstring>
#include <cmath>

#define MAX_N 500000 // 최대 6자리수
using namespace std;

int button_broken[10] = {0}; // (0~9번 버튼) 1이면 broken

// 100 번인 현재로부터 N 번 채널로 +- 를 이용해서만 갈 수 있는 경우 min 값
int get_step_min(int N) {
    return abs(100-N);
}


// 해당 채널로 이동 가능한지(1) 불가능한지(0)
int is_possible_channel(int channel) {
    int possible = 1; // default true;
    
    // 현재 채널을 누를 수 있는 지 보면서 하나이 버튼이라도 broken 이면  안됨.
    // 채널 각 버튼 하나씩 가능한지 살펴보고 하나라도 불가능하면  false 하고 반복문 종료
    if(channel == 0)
        if( button_broken[0] == 1)
            possible= 0; // false
    
    while(channel>0) {
        int btn = channel % 10;
        if( button_broken[btn] == 1) {//broken
            possible = 0 ; // false
            break;
        }
        channel /= 10;
    }// end of while
    
    return possible;
    
}// end of function()

    
// N 번 채널로 점프한 다음 +, - 로 움직일 수 있는 것의 최소 값
// N 은 최대 50만. 가능한 것을 다 해보고 최소 값 찾아라.
int get_jump_min(int N) {
    
    int min_distance = MAX_N; // 앞으로 min 을 찾을 것임
    int min_channel = 0;
    for(int channel = 0; channel<= MAX_N*2 ; channel++) {
        
        // 불가능한 채널이면 패스
        if(is_possible_channel(channel) == 0) // false
            continue;
        else {
            // 가능하다면 구해보고 min 값 갱신
            if(min_distance > abs(channel-N) ){
                min_channel = channel;
                min_distance = abs(channel-N);
            }
        }
        
    }// end of for

    
    // min_distance인 채널까지 가고, + - 갯수 리턴해주자.
    int count = 0;
    if (min_channel == 0)
        count ++;
    
    while(min_channel>0) {
        count ++;
        min_channel /= 10;
    }// end of while

    count += min_distance;
    return count;
    
}



int main() {
    int N;
    int broken_num;
    cin >> N ;
    cin >> broken_num;
    
    for(int i=1; i<=broken_num; i++) {
        int broken_btn;
        cin >> broken_btn;
        button_broken[broken_btn] = 1; // broken 이라고 표시
    }
    

    int count_step = get_step_min(N);
    int count_jump = get_jump_min(N);
    
    if(count_step < count_jump ) // 더 작은 것 출력
        cout << count_step << endl;
    else
        cout<< count_jump << endl;
    
    
    
    return 0;
}





