#pragma once

using namespace std;

class Transaction
{
public:
    int transactionID;
    string date;
    double amount;
    string type; // "Income" or "Expense"
    int userID;
    int categoryID;

    Transaction(int id, string d, double a, string t, int uid, int cid) :
        transactionID(id), date(d), amount(a), type(t), userID(uid), categoryID(cid) {}
};

void addTransaction(int id, string date, double amount, string type, int userID, int categoryID)
{
    transactions.push_back(Transaction(id, date, amount, type, userID, categoryID));
}

void displayTransactions() 
{
    for (const auto& transaction : transactions) {
        cout << "TransactionID: " << transaction.transactionID << ", Date: " << transaction.date
            << ", Amount: " << transaction.amount << ", Type: " << transaction.type
            << ", UserID: " << transaction.userID << ", CategoryID: " << transaction.categoryID << endl;
    }
}

