#include <bits/stdc++.h>
using namespace std;

int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    int arr[201] = {0, };
    cin >> n;
    for(int i=0; i<n; i++){
        int t;
        cin >> t;
        arr[t+100]++;
    }
    int p = 0;
    cin >> p;
    p = p+100;
    cout << arr[p];
// }