#include <iostream>
#include <string>
#include <cstring>
using namespace std;

const int MAXNUM = 10;
const int MAXLEN = 100;

int splitline(string, char, char[][MAXLEN]);

int splitline(string txt, char delimiter, char target[][MAXLEN]) {
    // Initialize variables
    int cnt = 0;
    int wordIndex = 0;

    // Iterate through each character in the string
    for (int i = 0; i < txt.length(); ++i) {
        // If the character is the delimiter, push the current word into the target array
        if (txt[i] == delimiter) {
            txt.copy(target[cnt], i - wordIndex, wordIndex);
            target[cnt][i - wordIndex] = '\0'; // Null-terminate the string
            wordIndex = i + 1;
            cnt++;
        }
    }
    
    // Push the last word into the target array
    txt.copy(target[cnt], txt.length() - wordIndex, wordIndex);
    target[cnt][txt.length() - wordIndex] = '\0'; // Null-terminate the string
    cnt++;

    // Return the number of split words
    return cnt;
}