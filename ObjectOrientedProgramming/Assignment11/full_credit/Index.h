// Index.h
#ifndef INDEX_H
#define INDEX_H

#include "Location.h"
#include <map>
#include <set>
#include <string>
#include <iostream>
#include <algorithm> // Add this line
#include <cctype>    // Add this line
class Index {
public:
    using Word = std::string;
    using Locations = std::set<Location>;

    void add_word(const std::string& filename, int line, const Word& word);

    friend std::ostream& operator<<(std::ostream& os, const Index& index);

private:
    std::map<Word, Locations> _index;

    void cleanup_word(std::string& word);
};

#endif // INDEX_H
