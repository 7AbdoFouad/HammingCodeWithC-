# Hamming Code: Error Detection and Correction Technique

Hamming code is a linear error-correcting code that can detect and correct single-bit errors in data transmission. It achieves this by adding redundant bits to the original data word, which allows for error detection and correction.

## Introduction

The Hamming distance between two binary strings is the number of bit positions in which the two bits are different. The Hamming distance of two codewords is defined as the number of positions in which the two codewords differ.

## Encoding Algorithm

The encoding algorithm for Hamming code is as follows:

1. Convert the data word to binary form.
2. Determine the number of redundant bits required using the formula `2^r >= m + r + 1`, where `m` is the number of bits in the data word and `r` is the number of redundant bits.
3. Allocate the redundant bits in the codeword at positions that are powers of two (e.g., 1, 2, 4, 8, etc.).
4. Fill in the remaining positions with the binary digits of the data word.
5. Calculate the value of each redundant bit using the formula: `P(i) = b1 XOR b2 XOR b3 XOR ... XOR bk`, 
where `bi` represents the bits whose indices contain a 1 in the binary representation of `i`.
7. Place the values of the redundant bits in their corresponding positions in the codeword.

## Decoding Algorithm

The decoding algorithm for Hamming code is as follows:

1. Receive the transmitted codeword.
2. Calculate the values of the redundant bits of the received codeword using the same formula as step 5 of the encoding algorithm.
3. If no errors are detected (all redundant bits are 0), the transmitted codeword is the decoded message.
4. If an error is detected, determine the bit position at which the error occurred by comparing the values of the redundant bits of the received codeword with those of the transmitted codeword.
5. Correct the error by flipping the bit in the received codeword at the determined bit position.
6. The corrected codeword is the decoded message.

By using the Hamming Code, it is possible to detect and correct single-bit errors in data transmission, enhancing the reliability and accuracy of digital communication systems.
