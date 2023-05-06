#include <bits/stdc++.h>
using namespace std;
typedef long long ll;


void solve() {
	// hamming code algorithm
	string mgs;
	cin >> mgs;  // 11010 dataWord
	ll k = int(mgs.size());
	ll r = 0;
	while (1 << r < k + r + 1) r++;
	ll n = k + r;
	string codeWord;  // codeWord
	codeWord.assign(n, '0');
	// put dataWord in codeWord

	int a = 0;

	for (int i = n - 1, j = 0; i >= 0; i--, j++) {
		if (!(i + 1 and (!(i + 1 & i)))) {
			codeWord[j] = mgs[a++];
		}
	}

	vector<long long> res_of_Ps(r);
	int x = 1;
	reverse(codeWord.begin(), codeWord.end());
	for (int i = 0; i < r; i++) {
		res_of_Ps[i] = 0;
		int cnt = (1 << i) - 1;
		bool check = true;
		for (int k = cnt; k < n; k += x) {
			if (check) {
				for (int t = k; t < k + x && t < n; t++) {
					res_of_Ps[i] = (res_of_Ps[i] ^ codeWord[t] - '0');
				}
			}
			check = !check;
		}
		x *= 2;
	}
	x = 0;
	for (int i = 0; i < r; i++) {
		codeWord[(1 << i) - 1] = res_of_Ps[x] + '0';
		x++;
	}
	reverse(codeWord.begin(), codeWord.end());
	cout << "Encoded codeWord is: " << codeWord;
	cout << "\n";
	cout << "*******************\n";

	string recivedCodeWord;
	cin >> recivedCodeWord;
	vector<long long> res_of_Ps_InResivedCodeWord(r);
	x = 1;
	reverse(recivedCodeWord.begin(), recivedCodeWord.end());

	for (int i = 0; i < r; i++) {
		res_of_Ps_InResivedCodeWord[i] = 0;
		int cnt = (1 << i) - 1;
		bool check = true;
		for (int k = cnt; k < n; k += x) {
			if (check) {
				for (int t = k; t < k + x && t < n; t++) {
					if (k == cnt && k == t) continue;
					res_of_Ps_InResivedCodeWord[i] = (res_of_Ps_InResivedCodeWord[i] ^ recivedCodeWord[t] - '0');
				}
			}
			check = !check;
		}
		x *= 2;
	}
	reverse(recivedCodeWord.begin(), recivedCodeWord.end());

	int error = 0;
	for (ll i = 0; i < r; i++) {
		if (res_of_Ps[i] != res_of_Ps_InResivedCodeWord[i]) {
			error += i + 1;
		}
	}
	if (error == 0 && recivedCodeWord == codeWord) {
		cout << "no error";
		cout << "\n";
		cout
				<< "codeWord = " << recivedCodeWord;
		cout << "\n";
	} else {
		if (error == 0) {
			for (ll i = 0; i < n; i++) {
				if (codeWord[i] != recivedCodeWord[i]) {
					error = n - (i);
					break;
				}
			}
		}

		cout << "there is error in bit number " << error;
		cout << "\n";
		if (recivedCodeWord[n - error] == '0') recivedCodeWord[n - error] = '1';
		else recivedCodeWord[n - error] = '0';
		cout << "the correct codeWord = " << codeWord;
		cout << "\n";
	}
}
int main() {
	solve();
}