#pragma once
using namespace std;

class Category
{
    public:
        int categoryID;
        string categoryName;
        int userID;

        Category(int id, string name, int uid) : categoryID(id), categoryName(name), userID(uid) {}
};

void addCategory(int id, string name, int userID)
{
    categories.push_back(Category(id, name, userID));
}

void displayCategories() 
{
    for (const auto& category : categories) {
        cout << "CategoryID: " << category.categoryID << ", Name: " << category.categoryName << ", UserID: " << category.userID << endl;
    }
}
