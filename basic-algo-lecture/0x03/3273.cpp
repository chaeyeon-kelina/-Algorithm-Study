#include <bits/stdc++.h>
using namespace std;

int arr[1000001] = {};      //입력받은 배열을 인덱스로 사용할 배열
bool occur[2000001];

int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, x, ans = 0;
    
    cin >> n;

    for(int i=0; i<n; i++){
        cin >> arr[i];
    }

    cin >> x;

    for(int i=0; i<n; i++){
        // x-a[i]가 존재하는지 확인
        if(x-arr[i] > 0 && occur[x-arr[i]]) ans++;
        occur[arr[i]] = true;
    }
    cout << ans;
}