//
//  차이를 최대로
//  10819.cpp
//  AlgoriGym
//
//  Created by nicewoong on 2018. 2. 28..
//  Copyright © 2018년 nicewoong. All rights reserved.
//  https://www.acmicpc.net/problem/10819
//

#include <cstdio>
#include <iostream>
#include <cmath>
#include <algorithm>
#include <vector>

using namespace std;

vector<int> number_list;


int get_current_result(int N) {
    
    int result = 0;
    for(int i=1; i<= N-1; i++) {
        result += abs(number_list[i-1] -number_list[i]);
    }
    return result;
}


int get_max(int N) {
    sort(number_list.begin(), number_list.end());
   
    // 순열을 변경해가면서 결과 확인해서 최대값 뽑아내서 반환
    int max_result = get_current_result(N);
    for( ; ; ) {
        
        // 다음 순열로 변경
        if(next_permutation(number_list.begin(), number_list.end()) ) {
            int current_result = get_current_result(N);
            if(max_result < current_result) // 더 크면 갱신
                max_result = current_result;
        }else
            break;
    }
    
    return max_result;
}


int main() {

    int N;
    cin >> N;
    for( int i=0; i<N; i++) { // N번 반복
        int temp;
        cin >> temp;
        number_list.push_back(temp);
    }
    
    cout << get_max(N) << endl;
    
    return 0;
}
