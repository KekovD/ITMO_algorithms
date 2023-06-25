#include <iostream>
#include <regex>
#include <vector>

bool check(const std::string_view& str, int i) {
    std::regex regular;
    switch (i) {
        case 0:
        case 1:
        case 2:
            regular = std::regex("[A-Z][a-z]*");
            break;
        case 3:
            regular = std::regex("[0-9]{2}");
            break;
        case 4:
            regular = std::regex(R"(^\+7\(\d{3}\)-\d{3}-\d{2}-\d{2}$|^\+7\d{10}$|^\+7\(\d{3}\)\d{3}-\d{4}$)");
            break;
        case 5:
            regular = std::regex("g\\.[A-Z]{3},");
            break;
        case 6:
            regular = std::regex("ul\\.[A-Z][a-z]*,");
            break;
        case 7:
            regular = std::regex("d\\.[0-9]+");
            break;
    }
    return regex_match(str.begin(), str.end(), regular);
}
int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);

    int n;
    std::cin >> n;
    std::cin.ignore();

    for (int g = 0; g < n; g++) {
        char c;
        std::cin >> c;
        std::string input;
        getline(std::cin, input);
        input = c + input;

        std::vector<std::string> vec(8, "brake");
        std::string temp;
        int t = 0;

        for (char ch : input) {
            if (!isspace(ch)) {
                temp += ch;
            } else {
                vec[t++] = temp;
                temp.clear();
            }
        }
        vec[t] = temp;

        bool flag = true;
        for (const std::string& S : vec) {
            if (S == "brake") {
                flag = false;
                break;
            }
        }

        if (!flag) {
            std::cout << "NO" << '\n';
            continue;
        }

        for (int i = 0; i < 8; i++) {
            std::string str = vec[i];
            if (i < 3 || i == 3 || i == 5 || i == 6 || i == 7) {
                if (!check(str, i)) {
                    flag = false;
                    break;
                }
            } else if (i == 4) {
                if (str[0] == '+' && str[1] != '7') {
                    flag = false;
                    break;
                } else if (str[0] == '+') {
                    str.erase(remove(str.begin(), str.end(), '('), str.end());
                    str.erase(remove(str.begin(), str.end(), ')'), str.end());
                    str.erase(remove(str.begin(), str.end(), '-'), str.end());
                    if (!check(str, i)) {
                        flag = false;
                        break;
                    }
                }
            }
        }

        std::cout << (flag ? "YES" : "NO") << '\n';
    }

    return 0;
}
