#include <iostream>

struct fridge {
    int milk;
    int meat;
    int cheese;
    int cake;
};

int operation(int a) {
    int x = 0, num, res = a;

    do {
        std::cout << "1. Put\n";
        std::cout << "2. Take\n";
        std::cout << "3. Other product\n";
        std::cout << "Choice operation:";
        std::cin >> x;
    } while (x < 1 || x > 3);

    if (x == 1) {
        std::cout << "How much to put in: ";
        do {
            std::cin >> num;
        } while (num < 0);
        res = a + num;
        a = res;
        return a;
    }

    if (x == 2 && a == 0){
        std::cout << "\nEmpty!\n";
        return a;
    } else if (x == 2 && a != 0){
        std::cout << "How much to take out:";
        std::cin >> num;
        if (num <= a) {
            res = a - num;
            a = res;
            return a;
        } else {
            std::cout << "\nToo much\n";
            return a;
        }
    }

    if (x == 3) return a;
};

int main() {
    char choice = 0;
    struct fridge fr, fr_2;

    fr.milk = 0;
    fr.meat = 0;
    fr.cake = 0;
    fr.cheese = 0;

    fr_2.milk = 0;
    fr_2.meat = 0;
    fr_2.cake = 0;
    fr_2.cheese = 0;

    std::cout << "Fridge 2:\n";
    std::cout << "1. Milk: " << fr_2.milk << " L.\n";
    std::cout << "2. Meat: " <<  fr_2.meat << " kg\n";
    std::cout << "3. Cheese: " << fr_2.cheese << " piece\n";
    std::cout << "4. Cake: " << fr_2.cake << " piece\n\n";

    fr_2.meat = fr_2.meat + 5;
    std::cout << "Put meat: " << fr_2.meat << " kg\n";
    fr_2.meat = fr_2.meat - 3;
    std::cout << "Take meat: " << fr_2.meat << " kg\n\n";

    for(;;){
        do {
            std::cout << "Fridge:\n";
            std::cout << "1. Milk: " << fr.milk << " L.\n";
            std::cout << "2. Meat: " <<  fr.meat << " kg\n";
            std::cout << "3. Cheese: " << fr.cheese << " piece\n";
            std::cout << "4. Cake: " << fr.cake << " piece\n";
            std::cout << "Choice (print q to close): ";
            std::cin >> choice;
            std::cout << "\n";
        } while (choice < '1' || choice > '4' && choice != 'q');

        if (choice == 'q') break;

        switch (choice) {
            case '1':
                fr.milk=operation(fr.milk);
                break;
            case '2':
                fr.meat=operation(fr.meat);
                break;
            case '3':
                fr.cheese=operation(fr.cheese);
                break;
            case '4':
                fr.cake=operation(fr.cake);
                break;
        }
        std::cout << "\n";
    }

    return 0;
}
