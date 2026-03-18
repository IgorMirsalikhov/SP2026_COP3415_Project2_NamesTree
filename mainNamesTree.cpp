#include "NamesTree.hpp"

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <regex>
#include <stdexcept>

std::vector<std::string> split(const std::string& s);
void runQuery(const std::vector<std::string>& query, NamesTree& tree);
void runFromFile(const char* file_name, NamesTree& tree);

int main(int argc, char** argv) {
    if (argc != 2) {
        std::cerr << "Error: incorrect number of arguments\n";
        return 1;
    }
    
    NamesTree tree;
    try {
        runFromFile(argv[1], tree);
    }
    catch(std::logic_error& ex) {
        std::cout << ex.what() << std::endl;
    }

    return 0;
}


std::vector<std::string> split(const std::string& s) {
    std::vector<std::string> out;
    std::regex del(" ");
    // Create a regex_token_iterator to split the string
    std::sregex_token_iterator it(s.begin(), s.end(), del, -1);

    // End iterator for the 
    // regex_token_iterator
    std::sregex_token_iterator end;

    // Iterating through each token
    while (it != end) {
        out.push_back(*it);
        ++it;
    }

    return out;
}



void runFromFile(const char* file_name, NamesTree& tree) {
    std::ifstream in;

    // Open the file
    in.open(file_name);

    // Check if file exists
    if (in.fail()) {
        std::cerr << file_name << " could not be opened\n";
        throw std::logic_error("File could not be opened\n");
    }

    std::string line;
    std::vector<std::string> words;
    while (getline(in, line)) {
        words = split(line);
        runQuery(words, tree);
    }

    // Close the file
    in.close();
}
