/*
    e569.cpp
    00245 - Uncompress
    String handling
    Tricky dealing with last character in input line
    Solved using brute force
*/

#include <iostream>
#include <string>
#include <vector>

using namespace std;

void number_handler(int idx, vector<string> &list)
{
    string word = list[idx];
    cout << word;
    for (int i = idx; i >= 2; i--)
    {
        list[i] = list[i - 1];
    }
    list[1] = word;
}

void word_handler(string word, vector<string> &list)
{
    cout << word;
    list.push_back("tmp");
    for (int i = list.size() - 1; i >= 2; i--)
    {
        list[i] = list[i - 1];
    }
    list[1] = word;
}

int main()
{
    string line;
    vector<string> list(1, "");
    while (getline(cin, line))
    {
        line += "\n"; // Handle input a empty line
        int number = 0;
        string word = "";
        for (char c : line)
        {
            if (c >= '0' && c <= '9')
            {
                number *= 10;
                number += c - '0';
            }
            else if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'))
            {
                word += c;
            }
            else
            {
                if (number)
                {
                    number_handler(number, list);
                }
                else if (!word.empty())
                {
                    word_handler(word, list);
                }
                cout << c;
                number = 0;
                word = "";
            }
        }
    }

    return 0;
}