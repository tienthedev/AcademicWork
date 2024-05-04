#include <iostream>
#include <vector>
#include <string>
#include <algorithm> // Include the algorithm header for std::sort

int main(int argc, char* argv[]) {
    std::vector<std::string> caps;
    std::vector<std::string> no_caps; // Use a vector on the stack, not the heap

    char previous_case = 0;
    std::cout << "Capitalized:" << std::endl;

    for (int i = 1; i < argc; i++) {
        std::string arg(argv[i]);

        if (!arg.empty()) {
            char first_char = arg[0];

            if (isupper(first_char)) {
                if (previous_case != 'C') {
                    previous_case = 'C';
                }
                caps.push_back(arg);
            } else {
                if (previous_case != 'L') {
                    previous_case = 'L';
                }
                no_caps.push_back(arg);
            }
        }
    }

    // Sort the vectors
    std::sort(caps.begin(), caps.end());
    std::sort(no_caps.begin(), no_caps.end());

    // Print the elements of caps
    for (const std::string& word : caps) {
        std::cout << word << std::endl;
    }

    std::cout << "\nLower Case:" << std::endl;
    // Print the elements of no_caps
    for (const std::string& word : no_caps) {
        std::cout << word << std::endl;
    }

    return 0;
}
