#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

void solve() {
  // Read the message to be encoded
  string mgs;
  cin >> mgs;

  // Calculate the number of bits needed for parity bits
  ll k = int(mgs.size());
  ll r = 0;
  while (1 << r < k + r + 1) r++;

  // Calculate the total number of bits in the code word
  ll n = k + r;

  // Initialize the code word with all zeros
  string codeWord;
  codeWord.assign(n, '0');

  int a = 0;

  // Fill the data bits in the code word
  for (int i = n - 1, j = 0; i >= 0; i--, j++) {
    // Skip the positions that are powers of 2 (parity bits)
    if (!(i + 1 and (!(i + 1 & i)))) {
      codeWord[j] = mgs[a++];
    }
  }

  // Calculate the values of parity bits
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

  // Update the code word with the values of parity bits
  x = 0;
  for (int i = 0; i < r; i++) {
    codeWord[(1 << i) - 1] = res_of_Ps[x] + '0';
    x++;
  }
  reverse(codeWord.begin(), codeWord.end());

  // Print the encoded code word
  cout << "Encoded codeWord is: " << codeWord;
  cout << "\n";
  cout << "*******************\n";

  // Read the received code word
  string recivedCodeWord;
  cin >> recivedCodeWord;
  vector<long long> res_of_Ps_InResivedCodeWord(r);
  x = 1;
  reverse(recivedCodeWord.begin(), recivedCodeWord.end());

  // Calculate the values of parity bits in the received code word
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

  // Compare the calculated parity bits with the received parity bits to detect errors
  int error = 0;
  for (ll i = 0; i < r; i++) {
    if (res_of_Ps[i] != res_of_Ps_InResivedCodeWord[i]) {
      error += i + 1;
    }
  }

  // If no error is detected and the received code word matches the original code word
  if (error == 0 && recivedCodeWord == codeWord) {
    cout << "No error";
    cout << "\n";
    cout << "Code word: " << recivedCodeWord;
    cout << "\n";
  } else {
    // If no error is detected but the received code word does not match the original code word
    if (error == 0) {
      // Find the position of the bit that is different
      for (ll i = 0; i < n; i++) {
        if (codeWord[i] != recivedCodeWord[i]) {
          error = n - i;
          break;
        }
      }
    }

    cout << "Error in bit number " << error;
    cout << "\n";

    // Flip the bit at the detected error position to correct the error
    if (recivedCodeWord[n - error] == '0') {
      recivedCodeWord[n - error] = '1';
    } else {
      recivedCodeWord[n - error] = '0';
    }

    cout << "Correct code word: " << codeWord;
    cout << "\n";
  }
}

int main() {
  solve();
}
