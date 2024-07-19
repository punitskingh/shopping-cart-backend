#include <iostream>
#include <bits/stdc++.h>
#include "file.h"
using namespace std;

vector<Product> v = {
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

signed main()
{
    Supermarket s;
    s.menu();
    return 0;
}