#ifndef BANK_H
#define BANK_H

#include <iostream>
#include <string>
#include <vector>
using namespace std;

struct Customer {
    string name;
    int serviceTime;
};

class Bank {
public:
    Bank();
    void simulate();
    void addCustomCustomer(const string& name, int serviceTime);

private:
    struct ServiceWindow {
        bool available;
        Customer customer;
    };

    struct ServiceDepartment {
        vector<ServiceWindow> windows;
        int totalTime;
        int customerCount;
    };

    ServiceDepartment departments[4];

    void processCustomers();
    void printStatistics() const;
};

#endif


#pragma once
