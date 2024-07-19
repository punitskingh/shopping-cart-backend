#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Product
{
    int id;
    int price;
    string name;

public:
    Product(int id, int price, string name) : id(id), price(price), name(name) {}

    string list() const
    {
        return to_string(id) + ". " + name;
    }

    string showPrice() const
    {
        return "Price of " + name + " is " + to_string(price);
    }

    int getId() const
    {
        return id;
    }

    string getName() const
    {
        return name;
    }

    int getPrice() const
    {
        return price;
    }
};

class Supermarket
{
    vector<Product> products;
    vector<pair<Product, int>> cart;
    double totalIncome;

public:
    Supermarket() : totalIncome(0)
    {
        // Initialize product list
        products = {
            {1, 200, "Apple"},
            {2, 200, "Mango"},
            {3, 200, "Milk"},
            {4, 200, "Orange"},
            {5, 200, "Papaya"},
            {6, 200, "Pineapple"},
            {7, 200, "Jackfruit"},
            {8, 200, "Samosa"},
            {9, 200, "Poha"},
            {10, 200, "Pav"},
            {11, 200, "Rasgulla"},
            {12, 200, "Gulab"},
            {13, 200, "Rasmalai"},
            {14, 200, "Jalebi"},
            {15, 200, "Honey"},
            {16, 6200, "Peanut"},
            {17, 200, "Bread"},
            {18, 200, "Aloo"},
            {19, 200, "Brinjal"},
            {20, 200, "Bhindi"}};
    }

    void menu()
    {
        int c;
        string email, password;
        while (true)
        {
            cout << "_______________________________________" << endl;
            cout << "          Select an Option:            " << endl;
            cout << "          1. Administrator.            " << endl;
            cout << "          2. Buyer.                    " << endl;
            cout << "          3. Exit.                     " << endl;
            cin >> c;
            if (c == 3)
            {
                return;
            }
            else if (c == 1)
            {
                admin();
            }
            else if (c == 2)
            {
                cout << "_____________________________________" << endl;
                cout << " Enter your Email-id:   " << endl;
                cin >> email;
                cout << " Enter your Password:   " << endl;
                cin >> password;
                cout << " Welcome to our shop!" << endl;
                buyer();
            }
            else
            {
                cout << "Please try again." << endl;
            }
        }
    }

    void admin()
    {
        string password;
        int id, c;
        cout << "Enter Your Employee-Id:" << endl;
        cin >> id;
        cout << "Enter Password:" << endl;
        cin >> password;
        // Validate password here
        if (password != "adminpassword")
        {
            cout << "Invalid password!" << endl;
            return;
        }
        while (true)
        {
            cout << "Welcome To Office! Select an option:" << endl;
            cout << "1. Edit items list." << endl;
            cout << "2. Today's income." << endl;
            cout << "3. Total Employee Present." << endl;
            cout << "4. Total Employee Absent." << endl;
            cout << "5. Exit." << endl;
            cin >> c;
            if (c == 5)
                return;
            if (c == 1)
            {
                editItems();
            }
            else if (c == 2)
            {
                cout << "Total Income: Rs" << totalIncome << endl;
            }
            else if (c == 3 || c == 4)
            {
                cout << "All employees are present!" << endl;
            }
        }
    }

    void buyer()
    {
        int c;
        while (true)
        {
            cout << "1. View items" << endl;
            cout << "2. Add item to cart" << endl;
            cout << "3. View cart" << endl;
            cout << "4. Checkout" << endl;
            cout << "5. Exit" << endl;
            cin >> c;
            if (c == 5)
                return;
            if (c == 1)
            {
                productList();
            }
            else if (c == 2)
            {
                addItemToCart();
            }
            else if (c == 3)
            {
                viewCart();
            }
            else if (c == 4)
            {
                checkout();
            }
        }
    }

    void editItems()
    {
        int id, price, c;
        string name;
        cout << "1. Add new item" << endl;
        cout << "2. Edit existing item" << endl;
        cout << "3. Remove item" << endl;
        cin >> c;
        if (c == 1)
        {
            cout << "Enter item ID, name, price: ";
            cin >> id >> name >> price;
            products.push_back(Product(id, price, name));
        }
        else if (c == 2)
        {
            cout << "Enter item ID: ";
            cin >> id;
            for (auto &product : products)
            {
                if (product.getId() == id)
                {
                    cout << "Enter new name and price: ";
                    cin >> name >> price;
                    product = Product(id, price, name);
                    break;
                }
            }
        }
        else if (c == 3)
        {
            cout << "Enter item ID: ";
            cin >> id;
            products.erase(remove_if(products.begin(), products.end(), [&](Product &p)
                                     { return p.getId() == id; }),
                           products.end());
        }
    }

    void productList()
    {
        cout << "Product List:" << endl;
        for (const auto &product : products)
        {
            cout << product.list() << " - " << product.showPrice() << endl;
        }
    }

    void addItemToCart()
    {
        int id, quantity;
        cout << "Enter item ID and quantity: ";
        cin >> id >> quantity;
        for (const auto &product : products)
        {
            if (product.getId() == id)
            {
                cart.push_back(make_pair(product, quantity));
                break;
            }
        }
    }

    void viewCart()
    {
        cout << "Cart:" << endl;
        int i = 1;
        for (const auto &item : cart)
        {
            cout << to_string(i) + ". " + item.first.list() << " - " << item.first.showPrice() << " x " << item.second << endl;
            ++i;
        }
    }

    void checkout()
    {
        double total = 0;
        cout << "Receipt:" << endl;
        for (const auto &item : cart)
        {
            total += item.first.getPrice() * item.second;
            cout << item.first.list() << " - " << item.first.showPrice() << " x " << item.second << endl;
        }
        cout << "Total Amount: Rs" << total << endl;
        totalIncome += total;
        cart.clear();
        thankCustomer();
    }

    void thankCustomer()
    {
        cout << "Thank you for shopping with us!" << endl;
    }
};
