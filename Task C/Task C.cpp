#include <iostream>
#include <algorithm>  // For reverse function
#include <algorithm>  // For transform
#include <cctype>     // For toupper

using namespace std;

// Helper function to convert a string to uppercase
string toUpperCase(string str)
{
    transform(str.begin(), str.end(), str.begin(), ::toupper);
    return str;
}

// Defines the function to reverse subsequence 'y' in string 'x' if prefixed by 'prefix' and suffixed by 'suffix'
void DNAreverse(string x, string y, string prefix, string suffix)
{
    int yLength = y.length();  // Stores the length of the subsequence 'y'
    string originalX = x;  // Stores the original string 'x' for resetting later
    int Index = 0;  // Initializes the index to start searching for subsequence 'y'
    int sentenceNum = 1;  // Initializes the sentence number for output labeling

    // Loop through 'x' to find all occurrences of 'y'
    while ((Index = x.find(y, Index)) != string::npos)
    {
        // Ensures the prefix is within valid range
        if (Index >= prefix.length())
        {
            string pref = x.substr(Index - prefix.length(), prefix.length());
            if (pref == prefix)
            {
                cout << "Prefix found" << endl;
            }
            else
            {
                cout << "Prefix not found" << endl;
                Index += yLength;
                continue;
            }
        }

        // Ensures the suffix is within valid range
        if (Index + y.length() + suffix.length() <= x.length())
        {
            string suf = x.substr(Index + y.length(), suffix.length());
            if (suf == suffix)
            {
                cout << "Suffix found" << endl;
            }
            else
            {
                cout << "Suffix not found" << endl;
                Index += yLength;
                continue;
            }
        }

        // If both prefix and suffix match, reverses the subsequence 'y' within 'x'
        if (Index >= prefix.length() && (Index + y.length() + suffix.length() <= x.length()))
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
    cout << "Enter DNA sequence (main string):" << endl;
    cin >> s;
    cout << "Enter subsequence to reverse:" << endl;
    cin >> Y;
    cout << "Enter Prefix: " << endl;
    cin >> l;
    cout << "Enter Suffix: " << endl;
    cin >> r;

    // Convert all inputs to uppercase
    s = toUpperCase(s);
    Y = toUpperCase(Y);
    l = toUpperCase(l);
    r = toUpperCase(r);

    // Input validation: Check if any input is empty
    if (s.empty() || Y.empty() || l.empty() || r.empty())
    {
        cout << "Input cannot be empty. Please provide valid DNA strings." << endl;
        return 1;
    }

    int firstIndex = s.find(Y);  // Finds the first occurrence of 'Y' in 's'

    // Checks if 'Y' is found in 's'
    if (firstIndex == string::npos)
    {
        // Output a message when subsequence is not found
        cout << "Subsequence not found in the DNA sequence." << endl;
    }
    else
    {
        // Calls DNAreverse if 'Y' is found in 's'
        DNAreverse(s, Y, l, r);
    }
}