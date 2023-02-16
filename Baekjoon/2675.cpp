#include <bits/stdc++.h>
using namespace std;

int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;
    while(t--){
        int r;
        string s;
        cin >> r >> s;
        for(auto c : s){
            for(int i=0; i<r; i++){
                cout << c;
            }
        }
        cout << "\n";
    }

}