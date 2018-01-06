#ifndef WORDENTRY_H
#define WORDENTRY_H

#include <string>
#include <vector>
#include <iostream>

using namespace std;

class WordEntry {

    string word;
    int numAppearances;
    int totalScore;
    public:
        WordEntry(string,int);
        void addNewAppearance(int);
        string getWord();
        double getAverage();
};
#endif
