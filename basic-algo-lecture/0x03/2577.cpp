#include <bits/stdc++.h>
using namespace std;

int main(void){
    ios::sync_with_stdio(0);
	cin.tie(0);

    int a, b, c;
    int arr[10] = {0, };
    cin >> a >> b >> c;
    int mul = a*b*c;
    string str = to_string(mul);    //int -> str
    for(auto i : str)
        arr[i-'0']++;       //해당 숫자에 맞는 배열 칸에 +1
    for(int i=0; i<10; i++)
        cout << arr[i] << '\n';
}
