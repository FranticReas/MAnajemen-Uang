#pragma once

using namespace std;

class Budget
{
public:
    int budgetID;
    string budgetName;
    double amount;
    string period;
    int userID;
    int categoryID;

    Budget(int id, string name, double amt, string per, int uid, int cid) :
        budgetID(id), budgetName(name), amount(amt), period(per), userID(uid), categoryID(cid) {}
};

void addBudget(int id, string name, double amount, string period, int userID, int categoryID)
{
    budgets.push_back(Budget(id, name, amount, period, userID, categoryID));
}

void displayBudgets() 
{
    for (const auto& budget : budgets) {
        cout << "BudgetID: " << budget.budgetID << ", Name: " << budget.budgetName
            << ", Amount: " << budget.amount << ", Period: " << budget.period
            << ", UserID: " << budget.userID << ", CategoryID: " << budget.categoryID << endl;
    }
}

