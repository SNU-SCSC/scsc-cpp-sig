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
    std::string line;
    while (std::getline(istream, line)) {
        words.push_back(line);
    }
    for (string& word : words) {
        std::transform(word.begin(), word.end(), word.begin(), ::tolower);
    }
    return words;
}

// return the frequency of characters in words
int main() {
    std::vector<string> words = loadWords();
    // TODO: fill this space
}