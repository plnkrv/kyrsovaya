#include <iostream>
#include <string>
#include <fstream>
#include "course.h"

using namespace std;

string text;

//лишние пробелы
void probely(string txt)
{
    for (int i = 0; i < txt.size(); i++)
    {
        if (txt[i] == ' ' && txt[i + 1] == ' ')
            while (txt[i + 1] == ' ')
                txt.erase((i + 1), 1);
    }
    text = txt;
}

//лишние знаки
void znaki(string txt) {
    for (int i = 0; i <= txt.size(); i++) {
        if ((txt[i] == '.' || txt[i] == ',' || txt[i] == ';' || txt[i] == ':' || txt[i] == '!' || txt[i] == '?') && (txt[i + 1] == '.' || txt[i + 1] == ',' || txt[i + 1] == ';' || txt[i + 1] == ':' || txt[i + 1] == '!' || txt[i + 1] == '?'))
            if (txt[i] == '.' && txt[i + 1] == '.' && txt[i + 2] == '.' && txt[i + 3] == ' ')
                i += 3;
            else {
                while (txt[i + 1] == '.' || txt[i + 1] == ',' || txt[i + 1] == ';' || txt[i + 1] == ':' || txt[i + 1] == '!' || txt[i + 1] == '?')
                    txt.erase((i + 1), 1);
            }
    }
    text = txt;
}

//регистр
void registr(string txt) {
    for (int i = 0; i < txt.size(); i++) {
        if (txt[i] == ' ')
            i += 2;
        txt[i] = tolower(txt[i]);
    }
    text = txt;
}
//3 задание
void printWordsWithSameLetters(string txt)
{
    string word;
    for (int i = 0; i <= txt.size(); i++)
    {
        if (txt[i] == ' ' || i == txt.size())
        {
            bool sameLetters = false;
            for (int j = 0; j < word.size() - 1; j++)
            {
                for (int k = j + 1; k < word.size(); k++)
                {
                    if (word[j] == word[k])
                    {
                        sameLetters = true;
                        break;
                    }
                }
                if (sameLetters)
                    break;
            }
            if (sameLetters)
                cout << word << endl;
            word = "";
        }
        else
        {
            word += txt[i];
        }
    }
}

void course4()
{
    setlocale(0, "");
    cout << "введите текст " << endl;

    //1 задание
    {

        cin.ignore();
        getline(cin, text);

        cout << "1) исходная строка: " << text << "\n";

        //2 задание
        {
            probely(text);
            znaki(text);
            registr(text);

            cout << "2) отредактированная строка: " << text << "\n";

            //3 задание
            {
                cout << "3) слова с одинаковыми буквами: " << endl;
                printWordsWithSameLetters(text);


            }

        }

    }
    //4 задание
    {
        string new_text;
        int start = 0;
        for (int i = 0; i <= text.size(); i++) {
            if (text[i] == ' ' || i == text.size()) {
                string word = text.substr(start, i - start);
                word[0] = toupper(word[0]); // заменяем первую букву на прописную
                new_text += word + " ";
                start = i + 1;
            }
        }
        cout << "4) последовательность со словами, где первая буква прописная: " << new_text << endl;
    }
}

