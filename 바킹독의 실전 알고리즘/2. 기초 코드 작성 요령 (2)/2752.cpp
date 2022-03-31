//백준 2752 : 세수 정렬
#include <bits/stdc++.h>
using namespace std;
int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int x, y, z;
	int max;
	cin >> x >> y >> z;
	if (x > y) {
		if (y > z)
			cout << z << ' ' << y << ' ' << x;
		else {
			if (x > z)	cout << y << ' ' << z << ' ' << x;
			else cout << y << ' ' << x << ' ' << z;
		}
			
	}
	else {
		if (x > z)
			cout << z << ' ' << x << ' ' << y;
		else {
			if (y>z) cout << x << ' ' << z << ' ' << y;
			else cout << x << ' ' << y << ' ' << z;
		}
	}
}

//정답 코드로 풀어보기
//백준 2752 : 세수 정렬
#include <bits/stdc++.h>
using namespace std;
int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int x, y, z;
	cin >> x >> y >> z;
	int a = min({ x,y,z });
	int b = max({ x,y,z });
	int c = x + y + z - a - b;
	cout << a << ' ' << c << ' ' << b;
}

//별해 코드로 풀어보기
//백준 2752 : 세수 정렬
#include <bits/stdc++.h>
using namespace std;
int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int arr[4] = {};
	for (int i=0; i<3; i++)
		cin >> arr[i];
	sort(arr, arr + 3);
	for (int i = 0; i < 3; i++)
		cout << arr[i] << ' ';
}
