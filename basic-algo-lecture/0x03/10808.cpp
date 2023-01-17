#include <bits/stdc++.h>
using namespace std;

int main(void){
    ios::sync_with_stdio(0);
	cin.tie(0);
    
    string s = "";
    int alp[50];
    fill(alp, alp+50, 0);
    cin >> s;

    for(int a : s){
        alp[a-97]++;
    }
    for(int i=0; i<26; i++)
        cout << alp[i] << ' ';
}

//아스키코드 a=97
//string s에 저장 후, int a에 각 알파벳을 차례로 받아와 alp 배열에 저장