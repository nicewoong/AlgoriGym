//
//  로또 (조합 문제는 순열 문제에다가 1이랑 0 대입해서 풀기 )
//  1963.cpp
//  AlgoriGym
//
//  Created by nicewoong on 2018. 3. 1..
//  Copyright © 2018년 nicewoong. All rights reserved.
//
//  https://www.acmicpc.net/problem/6603


#include <cstdio>
#include <iostream>
#include <vector>
#include <algorithm>
#define MAX_K 12

using namespace std;





// K개의 집합에서, 6개 선택하기.
void lotto(vector<int> list, int K) {
    
    // 선택할지 말지를 담고 있는 리스트 이것을 순열 순서대로 하면 됨.
    vector<int> choice(K); // 0 ~ K-1
    for(int i=0; i<K; i++) {
        if(i<6) //
            choice[i] = 1;
        else //
            choice[i] = 0;
    }
    

    // 조합 변경해가며 출력하기
    do{
        
//        for(int i=0; i<K; i++) { // k번 반복하기
//            cout << choice[i] << " ";
//        }
//        cout << endl;
       
        // 현재 조합 출력
        for(int i=0; i<K; i++) { // k번 반복하기
            if(choice[i]==1) // choice[] 가 1인 index만 list의 숫자 출력. 1인 녀석이 선택 받은 거임. 선택받은 녀석만 출력
                cout << list[i] << " ";
        }
        cout << endl;
        
    }while( prev_permutation( choice.begin(), choice.end() ) );
    
    
    
}

void lotto_interface(int K) {
    
    
    vector<int> list; // 새로운 벡터 생성
    
    for(int i=0; i<K; i++) { // k번 반복하기
        int temp;
        cin >> temp;
        list.push_back(temp); // 리스트 값 입력받아서 채우기 0 ~ K-1 에 K 개가 저장됨.
    }
    
    lotto(list, K);
    cout << endl;
    
}


int main() {
    int K;
    
    
    while(1) {
        cin >> K;
        if(K==0) // 0이 들어오면 끝내기
            break;
        
        lotto_interface(K);
    }
    
        
    return 0;
}




