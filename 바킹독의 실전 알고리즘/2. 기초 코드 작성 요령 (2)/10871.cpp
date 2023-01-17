//백준 10871 : X보다 작은 수
#include <bits/stdc++.h>
using namespace std;
int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, x, a[10005];
    cin >> n >> x;
    for(int i=0; i<n; i++){
        cin >> a[i];
        if(a[i] < x)
            cout << a[i] << ' ';
    }
}
