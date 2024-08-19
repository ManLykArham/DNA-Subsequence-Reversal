#include <iostream>
using namespace std;

// Defines the function to reverse subsequence 'y' in string 'x' if prefixed by 'prefix' and suffixed by 'sufix'
void DNAreverse(string x, string y, string prefix, string sufix)
{
    int yLength = y.length();  // Stores the length of the subsequence 'y'
    string originalX = x;  // Stores the original string 'x' for resetting later
    int Index = 0;  // Initializes the index to start searching for subsequence 'y'
    int sentenceNum = 1;  // Initializes the sentence number for output labeling

    // Loop through 'x' to find all occurrences of 'y'
    while ((Index = x.find(y, Index)) != string::npos)
    {
        // Extracts the prefix of the current occurrence of 'y' in 'x'
        string pref = x.substr(Index - prefix.length(), prefix.length());
        if (pref == prefix)  // Checks if the prefix matches the desired prefix
        {
            cout << "Prefix found" << endl;
        }
        else
            cout << "Prefix not found" << endl;

        // Extracts the suffix of the current occurrence of 'y' in 'x'
        string suf = x.substr(Index + y.length(), sufix.length());
        if (suf == sufix)  // Checks if the suffix matches the desired suffix
        {
            cout << "Sufix found" << endl;
        }
        else
            cout << "Sufix not found" << endl;

        // If both prefix and suffix match, reverses the subsequence 'y' within 'x'
        if (pref == prefix && suf == sufix)
        {
            reverse(x.begin() + Index, x.begin() + (Index + yLength));  // Reverses the segment within 'x'
            cout << "Sentence " << sentenceNum << ":" << endl;  // Outputs the sentence number
            cout << x << endl;  // Displays the modified string 'x'
            x = originalX;  // Resets 'x' to its original state for the next occurrence
            sentenceNum++;  // Increments the sentence number
        }
        Index += yLength;  // Moves the index forward by the length of 'y' to continue searching
    }
}

int main()
{
    // Variables to store user input
    string s;
    string Y;
    string l;
    string r;

    // Prompts user for the main string, subsequence, prefix, and suffix
    cout << "String S:" << endl;
    cin >> s;
    cout << "String Y:" << endl;
    cin >> Y;
    cout << "Prefix: " << endl;
    cin >> l;
    cout << "Sufix: " << endl;
    cin >> r;

    int firstIndex = -1;  // Initializes index for finding the first occurrence of 'Y' in 's'
    firstIndex = s.find(Y);  // Finds the first occurrence of 'Y' in 's'

    // Checks if 'Y' is found in 's'
    if (firstIndex == string::npos)  // If 'Y' is not found
    {
        cout << "String y not found" << endl;
    }
    else
    {
        // Calls DNAreverse if 'Y' is found in 's'
        DNAreverse(s, Y, l, r);
    }
}
