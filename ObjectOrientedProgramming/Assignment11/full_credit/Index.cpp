// Index.cpp
#include "Index.h"

void Index::add_word(const std::string& filename, int line, const Word& word) {
    cleanup_word(const_cast<std::string&>(word));

    // Check if the word is already in the index, if not, add it
    if (_index.find(word) == _index.end()) {
        _index[word] = Locations();
    }

    // Add the location to the set for this word
    _index[word].insert(Location(filename, line));
}

std::ostream& operator<<(std::ostream& os, const Index& index) {
    for (const auto& entry : index._index) {
        os << entry.first << ": ";
        for (const auto& location : entry.second) {
            os << location << ", ";
        }
        os << '\n';
    }
    return os;
}

void Index::cleanup_word(std::string& word) {
    // Remove punctuation
    word.erase(std::remove_if(word.begin(), word.end(), [](unsigned char c) { return !std::isalnum(c); }), word.end());

    // Convert to lowercase
    std::transform(word.begin(), word.end(), word.begin(), [](unsigned char c) { return std::tolower(c); });
}