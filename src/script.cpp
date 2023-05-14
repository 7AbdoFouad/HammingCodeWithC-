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
  ll k = int(message.size()); // message "Data-Word" = 11010 => k = 5

  ll r = 0; // len of parity_bits
  while (pow(2, r) < k + r + 1) r++; // r = 4  if  k =5

  // Calculate the total number of bits in the code word
  ll n = k + r; // len of Codeword  n = 9  if r = 4 , k = 5

  // Initialize the code word with all zeros
  string codeWord(n, '0'); // if n = 9 ,, codeWord = "000000000"

  int a = 0;
  // Fill the message bits in the codeWord

  for (int i = n - 1, j = 0; i >= 0; i--, j++) {
    // Skip the positions that are powers of 2 (parity bits)
    if (i + 1 & i) {
      codeWord[j] = message[a++];
    }
  }
  // after fill => codeWord = "101010000"

  // Calculate the values of parity bits [p1,p2,p4,p8,...]
  // parity bits ==> 1?101?0?? => PowerS of 2 [2^0 , 2^1 ,....]
  vector<long long> parity_bits(r);
  int x = 1; // x => range that we take and skip [1 , 2 , 4 , 8]
  // reverse codeWord to deal with from left to right 
  reverse(codeWord.begin(), codeWord.end()); // after reverse => codeWord = "000010101"
  //After Reverse ==> parity bits that need to found ??0?101?1 ,,
  //Note : every ?"parity bit" in codeword we make it = 0 so when "we take it"  same as
  //" we don't take it" (0^0 =0),,(0^1=1) "not effect"
  
  for (int i = 0; i < r; i++) {
    int parity_Idx = pow(2, i) - 1; // catch start '?'
    bool check = true; // flag => to Take once  and skip once 

    // get each parity bits
    for (int k = parity_Idx; k < n; k += x) {
      if (check) {
        
        for (int t = k; t < k + x && t < n; t++) {  
          parity_bits[i] = parity_bits[i] ^ (codeWord[t] - '0');
        }
      }
      check = !check;  //flip check
    }

    x *= 2;
  }

  // Update the code word with the values of parity bits

  for (int i = 0, b = 0; i < r; i++, b++) {
    codeWord[pow(2, i) - 1] = parity_bits[b] + '0';
  }
  reverse(codeWord.begin(), codeWord.end()); // after finish reverse to get the right codeWord

  cout << "Encoded codeWord is: " << codeWord << "\n";
}

void decoding(string &receivedCodeWord) {
  
  ll n = int(receivedCodeWord.size()); // receivedCodeWord "101010011" ,, n = 9
  ll r = 0;
  while (1 << r < n + 1) r++; // r => len of parity_bits
  ll k = n - r; // k => len of Message

  vector<long long> parity_bits_InResivedCodeWord(r); // hold parity_bits of receivedCodeWord

  int x = 1; // x => range that we take and skip [1 , 2 , 4 , 8]
  reverse(receivedCodeWord.begin(), receivedCodeWord.end()); 
  // reverse receivedCodeWord to deal with from left to right  
  // receivedCodeWord after reverse = "110010101"
  
  // Calculate the values of parity bits in the received code word
  for (int i = 0; i < r; i++) {
    // parity_bits_InResivedCodeWord[i] = 0;
    int parity_Idx = (1 << i) - 1; // // catch start '?' [2^0 , 2^1 and so on]
    bool check = 1; // flag to take once  And skip once
    for (int k = parity_Idx; k < n; k += x) {
      
      if (check) {
        for (int t = k; t < k + x && t < n; t++) {
          if (k == parity_Idx && k == t) continue; // skip power OF 2
          parity_bits_InResivedCodeWord[i] ^= (receivedCodeWord[t] - '0');
        }
      }
      check = !check; //flip check
    }

    x *= 2;
  }
  
  int error = 0; // pos of error bit
  for (int i = 0; i < r; i++) {
    int a = (1 << i); //   parity_position ,,, a-1 ==> parity_Idx
    if (parity_bits_InResivedCodeWord[i] != (receivedCodeWord[a - 1] - '0')) {
      error += a; // sum of all parity_position that not equal in [parity_bits_InResivedCodeWord , receivedCodeWord]
    }
  }

  reverse(receivedCodeWord.begin(), receivedCodeWord.end());

  // If no error is detected and the received code word matches the original code word
  if (!error)
    cout << "No error"
         << "\n"
         << "Code word: " << receivedCodeWord << "\n";
  else {
    cout << "Error in bit number " << error << "\n";

    // Flip the bit at the detected error position to correct the error
    if (receivedCodeWord[n - error] == '0') // why n-error ? beca we deal From right To Left
      receivedCodeWord[n - error] = '1';
    else
      receivedCodeWord[n - error] = '0';

    cout << "Correct code word: " << receivedCodeWord;
    cout << "\n";
  }
  cout<<"The dataWord = ";
  for (int i = n - 1, j = 0; i >= 0; i--, j++) {
    // Skip the positions that are powers of 2 (parity bits)
    if (i + 1 & i) {
      cout<<receivedCodeWord[j];
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
