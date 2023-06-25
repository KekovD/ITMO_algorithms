#include <iostream>
#include <vector>
#include <algorithm>

struct Student {
    int isu;
    int points;

    Student (int isu, int points) : isu (isu), points (points) {}
};

class GroupHash {
private:
    std::vector<std::vector<Student>> table;
    std::vector<int> avgPoints;

public:
    GroupHash (int numGroups) : table (numGroups), avgPoints (numGroups) {}

    int hash (int group) {
        return group % table.size ();
    }

    int findAveragePoints (int group) {
        int index = hash (group);
        return avgPoints[index];
    }

    void removeStudent (int group, int isu) {
        int index = hash (group);
        auto& students = table[index];

        auto it = std::find_if (students.begin (), students.end (),
                                [isu] (const Student& student) {
                                    return student.isu == isu;
                                });

        if (it != students.end ()) {
            students.erase (it);
            recalculateAveragePoints (index);
        }
    }

    void addStudent (int group, int isu, int points) {
        int index = hash (group);
        table[index].emplace_back (isu, points);
        recalculateAveragePoints (index);
    }

    int findStudentWithMaxPoints (int group) {
        int index = hash (group);
        const auto& students = table[index];

        if (students.empty ())
            return -1;

        auto it = std::max_element (students.begin (), students.end (),
                                    [] (const Student& s1, const Student& s2) {
                                        return s1.points < s2.points;
                                    });

        return it->points;
    }

private:
    void recalculateAveragePoints (int index) {
        const auto& students = table[index];
        double sumPoints = 0;

        for (const auto& student : students) {
            sumPoints += student.points;
        }

        avgPoints[index] = sumPoints / students.size ();
    }
};

int main () {
    std::ios::sync_with_stdio (false);
    std::cin.tie (nullptr);
    std::cout.tie (nullptr);
    
    int numGroups, numQueries;
    std::cin >> numGroups >> numQueries;

    GroupHash groupHash (numGroups);

    for (int i = 0; i < numQueries; ++i) {
        char queryType;
        int group, isu, points;
        std::cin >> queryType >> group;

        switch (queryType) {
            case '+':
                std::cin >> isu >> points;
                groupHash.addStudent (group, isu, points);
                break;

            case '-':
                std::cin >> isu;
                groupHash.removeStudent (group, isu);
                break;

            case 'a':
                std::cout << groupHash.findAveragePoints (group) << '\n';
                break;

            case 'm':
                std::cout << groupHash.findStudentWithMaxPoints (group) << '\n';
                break;
        }
    }

    return 0;
}
