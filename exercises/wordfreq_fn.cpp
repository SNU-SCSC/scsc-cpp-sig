#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <iterator>
#include <map>
#include <algorithm>

using std::string;
using std::cout; using std::endl;

std::vector<string> loadWords() {
    std::ifstream istream("fruits.txt");
    std::vector<std::string> words;
    std::copy(std::istream_iterator<std::string>(istream),
              std::istream_iterator<std::string>(),
              std::back_inserter(words));
    for (string& word : words) {
        std::transform(word.begin(), word.end(), word.begin(), ::tolower);
    }
    return words;
}

// return the frequency of characters in words
int main() {
    std::vector<string> words = loadWords();

    std::vector<std::vector<string>> wordsByLength(20);
    std::map<char, int> charCountMap;

    for (const string& word : words) {
        int len = word.length();
        wordsByLength[len].push_back(word);
    }

    words.length()


    // print words by length
    cout << "Words by length: " << endl;
    int wordLen = 0;
    for (const auto& sameLengthWords : wordsByLength) {
        int count = sameLengthWords.size();
        if (count == 0) continue;
        string wordsStr = count == 1 ? "word" : "words";
        cout << wordLen << " (" << count << " " << wordsStr << "): ";
        for (const auto& word : sameLengthWords) {
            cout << word << " ";
        }
        cout << endl;
        wordLen++;
    }

    // print character frequency of the word list
    cout << "Character frequency: " << endl;
    for (const auto& entry : charCountMap) {
        char c = entry.first;
        int count = entry.second;
        cout << c << ": " << static_cast<float>(count) / totalCharCount << "%" << endl;
    }
}



