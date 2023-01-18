#include <bits/stdc++.h>
using namespace std;

bool desc(float a, float b){
    return a > b;
}

int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    float arr[10] = {0, };  //0~8 배열
    int n;  //다솜이 방 번호
    cin >> n;   
    
    while(n > 0){
        int tmp = n%10;
        if(tmp == 6 || tmp == 9)
            arr[6] += 0.5;
        else
            arr[tmp]++;
        n /= 10;
    }

    sort(arr, arr+10, desc);       //내림차순
    int max = arr[0]+0.5;       //반올림
    cout << max;
    
    
}