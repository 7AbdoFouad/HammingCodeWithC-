/*
The Hamming code algorithm was developed by "Richard Hamming", an American mathematician and computer scientist.
It involves adding redundant parity bits to a data word to enable error detection and correction.
This algorithm has been widely used in computer systems and communication protocols since its development in the "1950s".
*/

#include <bits/stdc++.h>
#include <windows.h>

using namespace std;

typedef long long ll;

void encoding(string &message) {
  // Calculate the number of bits needed for parity bits
  ll k = int(message.size());

  ll r = 0;
  while (pow(2, r) < k + r + 1) r++;

  // Calculate the total number of bits in the code word
  ll n = k + r;

  // Initialize the code word with all zeros
  string codeWord(n, '0');

  int a = 0;
  // Fill the message bits in the codeWord
  for (int i = n - 1, j = 0; i >= 0; i--, j++) {
    // Skip the positions that are powers of 2 (parity bits)
    if (i + 1 & i) {
      codeWord[j] = message[a++];
    }
  }

  // Calculate the values of parity bits
  vector<long long> parity_bits(r);
  int x = 1;
  reverse(codeWord.begin(), codeWord.end());
  // p1 p2 0 p4 1 0 1
  // 3
  for (int i = 0; i < r; i++) {
    int parity_pos = pow(2, i) - 1;
    bool check = true;

    // get each parity bits
    for (int k = parity_pos; k < n; k += x) {
      if (check) {
        // calc the colection of bits
        for (int t = k; t < k + x && t < n; t++) {  // '45'
          parity_bits[i] = parity_bits[i] ^ (codeWord[t] - '0');
        }
      }
      check = !check;
    }

    x *= 2;
  }

  // Update the code word with the values of parity bits

  for (int i = 0, b = 0; i < r; i++, b++) {
    codeWord[pow(2, i) - 1] = parity_bits[b] + '0';
  }
  reverse(codeWord.begin(), codeWord.end());

  cout << "Encoded codeWord is: " << codeWord << "\n";
}

void decoding(string &receivedCodeWord) {
  ll n = int(receivedCodeWord.size());
  ll r = 0;
  while (1 << r < n + 1) r++;
  ll k = n - r;

  vector<long long> res_of_Ps_InResivedCodeWord(r);
  int error = 0;
  int x = 1;
  reverse(receivedCodeWord.begin(), receivedCodeWord.end());
  // Calculate the values of parity bits in the received code word
  for (int i = 0; i < r; i++) {
    // res_of_Ps_InResivedCodeWord[i] = 0;
    int parity_pos = pow(2, i) - 1;
    bool check = 1;
    for (int k = parity_pos; k < n; k += x) {
      if (check) {
        for (int t = k; t < k + x && t < n; t++) {
          if (k == parity_pos && k == t) continue;
          res_of_Ps_InResivedCodeWord[i] ^= (receivedCodeWord[t] - '0');
        }
      }
      check = !check;
    }

    x *= 2;
  }

  for (int i = 0; i < r; i++) {
    int a = pow(2, i);
    if (res_of_Ps_InResivedCodeWord[i] != (receivedCodeWord[a - 1] - '0')) {
      error += a;
    }
  }

  reverse(receivedCodeWord.begin(), receivedCodeWord.end());

  // If no error is detected and the received code word matches the original code word
  if (!error) {
    cout << "No error\n";
  } else {
    cout << "Error in bit number " << error << "\n";

    // Flip the bit at the detected error position to correct the error
    if (receivedCodeWord[n - error] == '0')
      receivedCodeWord[n - error] = '1';
    else
      receivedCodeWord[n - error] = '0';

    cout << "Corrected code word: " << receivedCodeWord << "\n";
  }

  // Print the message bits in the code word
  cout << "Message bits: ";
  for (int i = n - 1, j = 0; i >= 0; i--, j++) {
    if (i + 1 & i) {
      cout << receivedCodeWord[j];
    }
  }
}

int main() {
  cout << "\n \e[35m   __________  ____ \e[0m  \e[35m   _____ ________________  ____________\e[0m \n";
  cout << "   \e[35m/_  __/ __ \\/ __ \\ \e[0m \e[35m  / ___// ____/ ____/ __ \\/ ____/_  __/\e[0m \n";
  cout << "   \e[35m / / / / / / /_/ / \e[0m   \e[35m\\__ \\/ __/ / /   / /_/ / __/   / /   \e[0m \n";
  cout << "  \e[35m / / / /_/ / ____/ \e[0m   \e[35m___/ / /___/ /___/ __ _/ /___  / /    \e[0m \n";
  cout << " \e[35m /_/  \\____/_/   \e[0m    \e[35m /____/_____/\\____/_/ |_/_____/ /_/     \e[0m \n\n";

  Sleep(1200);
  cout << "\e[36m";

  cout << " -------------------------------------\n";
  cout << "|  Welcome to the Hamming code tool   |\n";
  cout << " -------------------------------------\n";

  while (1) {
    cout << "\nPlease choose an option:\n";
    cout << "--------------------------\n";
    cout << "1. Encode a message\n";
    cout << "2. Decode a received code word\n";
    cout << "3. To exit\n";
    cout << "--------------------------\n";
    cout << "Your choice: ";

    int choice;
    cin >> choice;

    switch (choice) {
      case 1: {
        cout << "Enter the message to encode: ";
        string message;
        cin >> message;
        encoding(message);
        Sleep(500);
        break;
      }
      case 2: {
        cout << "Enter the received code word: ";
        string receivedCodeWord;
        cin >> receivedCodeWord;
        decoding(receivedCodeWord);
        Sleep(500);
        break;
      }
      case 3:
        return cout << "\nthanks for using our tool. Goodbye!\n", 0;
      default: {
        cout << "Invalid choice. Please try again.\n";
        continue;
      }
    }
    char flag;
    cout << "\nDo you want to continue using the tool? (y/n): ", cin >> flag;
    if (tolower(flag) == 'n') return cout << "\nthanks for using our tool. Goodbye!\n", 0;
    Sleep(500);
  }
}