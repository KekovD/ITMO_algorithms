#include <iostream>
#include <string>

int countUniqueSubstrings (const std::string_view& password) {
    int count = 0;
    int n = password.length ();

    for (int len = 1; len <= n; ++len) {
        for (int i = 0; i <= n - len; ++i) {
            std::string_view substring = password.substr (i, len);
            bool found = false;
            for (int j = 0; j < i; ++j) {
                if (password.substr (j, len) == substring) {
                    found = true;
                    break;
                }
            }
            if (!found) {
                count++;
            }
        }
    }

    return count;
}

int main () {
    std::ios_base::sync_with_stdio (false);
    std::cin.tie (nullptr);
    std::cout.tie (nullptr);
    
    std::string password;
    std::cin >> password;

    int uniqueSubstrings = countUniqueSubstrings (password);
    std::cout << uniqueSubstrings << '\n';

    return 0;
}
