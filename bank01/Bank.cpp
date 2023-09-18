#include "Bank.h"
#include <cstdlib>
#include <ctime>

Bank::Bank() {
    for (int i = 0; i < 4; ++i) {
        departments[i].totalTime = 0;
        departments[i].customerCount = 0;
        for (int j = 0; j < 5; ++j) {
            ServiceWindow window;
            window.available = true;
            departments[i].windows.push_back(window);
        }
    }
}

void Bank::simulate() {
    srand(static_cast<unsigned>(time(nullptr)));

    for (int time = 0; time < 480; ++time) {  // 8 hours simulation
        processCustomers();
    }

    printStatistics();
}

void Bank::processCustomers() {
    int time = 0;
    for (int i = 0; i < 4; ++i) {
        for (int j = 0; j < departments[i].windows.size(); ++j) {
            if (departments[i].windows[j].available) {
                if (rand() % 4 == 0) {
                    Customer customer;
                    customer.name = "Customer" + to_string(departments[i].customerCount + 1);
                    customer.serviceTime = rand() % 10 + 1;
                    departments[i].windows[j].customer = customer;
                    departments[i].windows[j].available = false;
                    departments[i].customerCount++;
                }
            }
            else {
                departments[i].windows[j].customer.serviceTime--;
                if (departments[i].windows[j].customer.serviceTime == 0) {
                    departments[i].totalTime += (480 - time);
                    departments[i].windows[j].available = true;
                }
            }
        }
    }
}

void Bank::addCustomCustomer(const std::string& name, int serviceTime) {
    // Choose a random department (0 to 3) to add the custom customer
    int departmentIndex = rand() % 4;

    // Find an available window in the chosen department
    for (int i = 0; i < departments[departmentIndex].windows.size(); ++i) {
        if (departments[departmentIndex].windows[i].available) {
            Customer customer;
            customer.name = name;
            customer.serviceTime = serviceTime;
            departments[departmentIndex].windows[i].customer = customer;
            departments[departmentIndex].windows[i].available = false;
            departments[departmentIndex].customerCount++;
            break; // Stop after adding one customer
        }
    }
}

void Bank::printStatistics() const {
    for (int i = 0; i < 4; ++i) {
        cout << "部门 " << i + 1 << " 统计数据:" <<endl;
        cout << "当前已服务顾客总人数: " << departments[i].customerCount << endl;
        if (departments[i].customerCount > 0) {
            double averageTime = static_cast<double>(departments[i].totalTime) / departments[i].customerCount;
            cout << "当前部门个人顾客平均服务长: " << averageTime << " minutes" << endl;
        }
        else {
            cout << "该部门没有服务任何客户。" <<endl;
        }
        cout << endl;
    }
}
