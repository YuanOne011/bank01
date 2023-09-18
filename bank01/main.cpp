#include "Bank.h"

int main() {
    Bank bank;

    // Simulate for a fixed period (e.g., 480 minutes)
    for (int time = 0; time < 480; ++time) {
        // Process regular customers

        // Simulate custom customer entry
        if (time % 30 == 0) {  // Add a custom customer every 30 minutes
            std::string name;
            int serviceTime;
            std::cout << "Enter customer name: ";
            std::cin >> name;
            std::cout << "Enter service time (minutes): ";
            std::cin >> serviceTime;
            bank.addCustomCustomer(name, serviceTime);
        }
    }

    bank.simulate();

    return 0;
}
