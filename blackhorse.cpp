#include <iostream>
#include <vector>
#include <string>
#include <googlesearch.h> 

int main(int argc, char* argv[]) {
    // Set the license key (must be unique to you)
    // google::setLicense("$YOUR_API_KEY");

    std::string domain;
    // Get the domain from the user
    if (argc < 2) {
        std::cerr << "Usage: dnscour <domain.tld>\n";
        return 1;
    } else {
        domain = argv[1];
    }

    // Create the query
    std::string keyword = "inurl:";
    std::string query = keyword + domain;

    // Start the query
    std::vector<std::string> potentials;

    for (int i = 0; i < 100; i += 10) {
        // Perform the query five times, taking 10 results each time
        // and putting them into our potentials list
        // google::doGoogleSearch(query, i, 10); // Google arama işlevselliği burada kullanılır.

        // Example: Dummy data insertion
        for (int j = 0; j < 10; ++j) {
            potentials.push_back("https://example.com/page" + std::to_string(i + j));
        }
    }

    // Initialize a second list to hold unique, cleaned entries
    std::vector<std::string> refined;

    // Do the cleaning work and populate the new list
    for (const auto& i : potentials) {
        std::string temp = i;
        temp.erase(0, 7); // Remove "http://"
        temp.erase(0, 8); // Remove "https://"
        size_t pos = temp.find('/');
        if (pos != std::string::npos) {
            temp = temp.substr(0, pos);
        }
        bool found = false;
        for (const auto& entry : refined) {
            if (entry == temp) {
                found = true;
                break;
            }
        }
        if (!found) {
            refined.push_back(temp);
        }
    }

    // Print the contents of the refined list
    for (const auto& i : refined) {
        std::cout << i << std::endl;
    }

    return 0;
}
