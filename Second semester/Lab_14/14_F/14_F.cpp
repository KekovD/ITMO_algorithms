#include <iostream>
#include <vector>

bool equal (std::vector<int>& vec, int k) {
    for (int i = 0; i < k; i++) {
        if (k - 1 - i < 0 || k + 1 > vec.size()) {
            continue;
        }
        if (vec[k - 1 - i] != vec[k + i]) {
            return false;
        }
    }
    return true;
}

int main () {
    std::ios::sync_with_stdio (false);
    std::cin.tie (nullptr);
    std::cout.tie (nullptr);

    int n, m;
    std::cin >> n >> m;

    std::vector<int> cards;
    for (int i = 0; i < n; i++) {
        std::cin >> m;
        cards.push_back(m);
    }

    std::vector<int> pos;
    for (int i = 0; i < n; i++) {
        if (equal (cards, i)) {
            pos.push_back (n - i);
        }
    }

    std::reverse (pos.begin (), pos.end ());

    for (auto i : pos) {
        std::cout << i << ' ';
    }
    
    return 0;
}
