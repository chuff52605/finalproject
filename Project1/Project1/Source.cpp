#include <iostream>
#include <string>

using namespace std;

int main() {
    string mode; // temporarily stores whether or not encryption or decryption will be used
    int key;    // stores the value of the shift 
    string input_text;


    // 1.
   // determines if the file is encrypted or decrypted //
    // determines the shift value //

    cout << "Mode (encrypt or decrypt): ";
    if (!(cin >> mode)) return 1;

    cout << "Shift value (e.g., 3): ";
    if (!(cin >> key)) return 1;

    // 2.
    // prompts user to input a word to cipher
    cout << "Enter the text to cipher (press Enter when done):" << endl;

    // This is a redundant path to follow in case there is an error on the user end 
     cin.ignore(); 
    getline(cin, input_text); // Reads the user's text

    // cipher logic
    int direction = (mode == "encrypt") ? 1 : -1; // determines the shift 
    int shift_amount = key % 26; // limits the shift to be between 0 and 25
    string result = "";

    // checks each character
    for (int i = 0; i < input_text.length(); ++i) {
        char ch = input_text[i];

        // checks the character to make sure that is a letter
        if ((ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z')) {

           // checks the capitalization of said character
            char base = (ch >= 'a' && ch <= 'z') ? 'a' : 'A';

            int old_pos = ch - base; // Position 0-25
            int new_pos = (old_pos + (shift_amount * direction) + 26) % 26;

            // this adds the fixed character back to the result string
            result += (new_pos + base);

        }
        else {
            // anything other than letters are not changed
            result += ch;
        }
    }

    // result
    cout << "------------------------------------" << endl;
    cout << "Processed Text: " << result << endl;

    return 0;
}