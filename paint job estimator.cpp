// paint job estimator.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
/*
File Name: Paint job Estimator 
Programmer: Olivia Ruiz
Date: 4/22/25
Requirements: Write a program that determines the value of a paint job due to the price of 
the paint per gallon and the number of rooms with their sqaure feet. 
*/
#include <iostream>
#include <iomanip>
using namespace std;


const double COVERAGE_PER_GALLON = 110.0;
const double HOURS_PER_GALLON = 8.0;
const double LABOR_RATE = 25.0;


int getNumberOfRooms();
double getPaintPrice();
double getRoomSquareFeet(int roomNumber);
double calculateTotalSquareFeet(int rooms);
int calculateGallons(double totalSquareFeet);
double calculateLaborHours(int gallons);
double calculatePaintCost(int gallons, double paintPrice);
double calculateLaborCost(double hours);
void displayResults(int gallons, double laborHours, double paintCost, double laborCost, double totalCost);

int main() {
    int rooms = getNumberOfRooms();
    double paintPrice = getPaintPrice();

    double totalSquareFeet = 0.0;
    for (int i = 1; i <= rooms; ++i) {
        totalSquareFeet += getRoomSquareFeet(i);
    }

    int gallons = calculateGallons(totalSquareFeet);
    double laborHours = calculateLaborHours(gallons);
    double paintCost = calculatePaintCost(gallons, paintPrice);
    double laborCost = calculateLaborCost(laborHours);
    double totalCost = paintCost + laborCost;

    displayResults(gallons, laborHours, paintCost, laborCost, totalCost);

    return 0;
}


int getNumberOfRooms() {
    int rooms;
    do {
        cout << "Enter the number of rooms to be painted (at least 1): ";
        cin >> rooms;
    } while (rooms < 1);
    return rooms;
}

double getPaintPrice() {
    double price;
    do {
        cout << "Enter the price of paint per gallon (minimum $10): ";
        cin >> price;
    } while (price < 10);
    return price;
}

double getRoomSquareFeet(int roomNumber) {
    double squareFeet;
    do {
        cout << "Enter the square feet of wall space for room " << roomNumber << ": ";
        cin >> squareFeet;
    } while (squareFeet < 0);
    return squareFeet;
}

int calculateGallons(double totalSquareFeet) {
    return static_cast<int>(ceil(totalSquareFeet / COVERAGE_PER_GALLON));
}

double calculateLaborHours(int gallons) {
    return gallons * HOURS_PER_GALLON;
}

double calculatePaintCost(int gallons, double paintPrice) {
    return gallons * paintPrice;
}

double calculateLaborCost(double hours) {
    return hours * LABOR_RATE;
}

void displayResults(int gallons, double laborHours, double paintCost, double laborCost, double totalCost) {
    cout << fixed << setprecision(2);
    cout << "\nPaint Job Estimate:\n";
    cout << "--------------------------\n";
    cout << "Gallons of paint required: " << gallons << endl;
    cout << "Hours of labor required:   " << laborHours << endl;
    cout << "Cost of the paint:         $" << paintCost << endl;
    cout << "Labor charges:             $" << laborCost << endl;
    cout << "Total cost of the paint job: $" << totalCost << endl;
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
