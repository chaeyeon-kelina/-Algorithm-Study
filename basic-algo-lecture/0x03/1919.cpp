#include <bits/stdc++.h>
using namespace std;

int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);

    string s1, s2;
    cin >> s1 >> s2;

    int arr[30] = {0, };
    for(int i : s1){
        arr[i-97]++;
    }
    for(int i:s2)
        arr[i-97]--;
    
    int sum = 0;

    for(int i=0; i<28; i++){
        if(arr[i] < 0)
            arr[i] *= -1;
        sum += arr[i];
    }
    cout << sum;
}