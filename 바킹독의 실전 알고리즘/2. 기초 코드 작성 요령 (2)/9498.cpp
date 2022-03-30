//백준 9498 : 시험 성적 
#include <bits/stdc++.h>
using namespace std;
int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int x;
    cin >> x;
    if (x <= 100 && x > 89)  cout << "A";
    else if (x <= 89 && x > 79)  cout << "B";
    else if (x <= 79 && x > 69)  cout << "C";
    else if (x <= 69 && x > 59)  cout << "D";
    else cout << "F";
}