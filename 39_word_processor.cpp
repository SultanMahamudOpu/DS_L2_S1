/*
Create a word processor using C/C++. It should be a menu driven program.
a) Text must be read from the file and after processing written into file
b) Number of line, characters, words, etc
c) Find a pattern from the text
d) Insert, delete, append a string
e) Replace a string

*/
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <vector>
#include <algorithm>

using namespace std;

// Function to count lines, characters, and words in a string
void countStats(const string &text, int &numLines, int &numChars, int &numWords)
{
    numLines = 0;
    numChars = 0;
    numWords = 0;

    stringstream ss(text);
    string line;

    while (getline(ss, line))
    {
        numLines++;
        numChars += line.length();

        stringstream wordStream(line);
        string word;

        while (wordStream >> word)
        {
            numWords++;
        }
    }
}

// Function to find and replace a pattern in a string
void findAndReplace(string &text, const string &pattern, const string &replacement)
{
    size_t pos = text.find(pattern);
    while (pos != string::npos)
    {
        text.replace(pos, pattern.length(), replacement);
        pos = text.find(pattern, pos + replacement.length());
    }
}

int main()
{
    string fileName;
    cout << "Enter the file name: ";
    cin >> fileName;

    ifstream inputFile(fileName);
    if (!inputFile)
    {
        cerr << "Error opening the file." << endl;
        return 1;
    }

    string text;
    string line;
    while (getline(inputFile, line))
    {
        text += line + "\n";
    }
    inputFile.close();

    int choice;
    do
    {
        cout << "\nWord Processor Menu:" << endl;
        cout << "1. Display Text" << endl;
        cout << "2. Count Lines, Characters, and Words" << endl;
        cout << "3. Find and Replace" << endl;
        cout << "4. Insert Text" << endl;
        cout << "5. Delete Text" << endl;
        cout << "6. Append Text" << endl;
        cout << "7. Save and Exit" << endl;
        cout << "Enter your choice (1-7): ";
        cin >> choice;

        switch (choice)
        {
        case 1:
        {
            cout << "Text Content:" << endl;
            cout << text << endl;
            break;
        }
        case 2:
        {
            int numLines, numChars, numWords;
            countStats(text, numLines, numChars, numWords);
            cout << "Number of Lines: " << numLines << endl;
            cout << "Number of Characters: " << numChars << endl;
            cout << "Number of Words: " << numWords << endl;
            break;
        }

        case 3:
        {
            string findPattern, replacePattern;
            cout << "Enter the pattern to find: ";
            cin.ignore();
            getline(cin, findPattern);
            cout << "Enter the replacement pattern: ";
            getline(cin, replacePattern);
            findAndReplace(text, findPattern, replacePattern);
            cout << "Text after replacement:" << endl;
            cout << text << endl;
            break;
        }

        case 4:
        {
            string insertText;
            int insertPos;
            cout << "Enter the text to insert: ";
            cin.ignore();
            getline(cin, insertText);
            cout << "Enter the position to insert (0-" << text.length() << "): ";
            cin >> insertPos;
            if (insertPos >= 0 && insertPos <= text.length())
            {
                text.insert(insertPos, insertText);
                cout << "Text after insertion:" << endl;
                cout << text << endl;
            }
            else
            {
                cout << "Invalid insertion position." << endl;
            }
            break;
        }

        case 5:
        {
            int deletePos, deleteLength;
            cout << "Enter the starting position to delete (0-" << text.length() - 1 << "): ";
            cin >> deletePos;
            cout << "Enter the number of characters to delete: ";
            cin >> deleteLength;
            if (deletePos >= 0 && deletePos < text.length() && deleteLength > 0)
            {
                text.erase(deletePos, deleteLength);
                cout << "Text after deletion:" << endl;
                cout << text << endl;
            }
            else
            {
                cout << "Invalid deletion position or length." << endl;
            }
            break;
        }

        case 6:
        {
            string appendText;
            cout << "Enter the text to append: ";
            cin.ignore();
            getline(cin, appendText);
            text += appendText;
            cout << "Text after appending:" << endl;
            cout << text << endl;
            break;
        }
        case 7:
        {
            ofstream outputFile(fileName);
            if (!outputFile)
            {
                cerr << "Error saving to the file." << endl;
                return 1;
            }
            outputFile << text;
            outputFile.close();
            cout << "Changes saved. Exiting." << endl;
            break;
        }

        default:
        {
            cout << "Invalid choice. Try again." << endl;
            break;
        }
        }
    } while (choice != 7);

    return 0;
}
