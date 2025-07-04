#include <iostream> // For std::cout
#include <iomanip>  // For std::fixed, std::setprecision, std::showpoint

int main() {
    double pi = 3.1415926535;
    double price = 19.99;
    double calculation = 123.45;
    double smallValue = 0.000000123;
    double largeValue = 1234567.89;

    std::cout << "Original pi: " << pi << std::endl;

    // --- Printing with a fixed number of decimal places ---

    // 1. Use std::fixed: This tells cout to print floating-point numbers in fixed-point notation
    //    (i.e., not scientific notation, and with a fixed number of digits after the decimal point).
    // 2. Use std::setprecision(n): This sets the number of digits to be displayed *after* the decimal point
    //    when std::fixed is active. If std::fixed is not active, setprecision controls the *total* number of significant digits.
    // 3. Use std::showpoint (optional): This ensures that the decimal point and trailing zeros are
    //    always shown, even if the fractional part is zero (e.g., 5.00 instead of 5).

    std::cout << "\n--- Fixed Decimal Places ---" << std::endl;

    std::cout << std::fixed << std::setprecision(2); // Set to 2 decimal places
    std::cout << "Pi (2 decimal): " << pi << std::endl;
    std::cout << "Price (2 decimal): " << price << std::endl;
    std::cout << "Calculation (2 decimal): " << calculation << std::endl;
    std::cout << "Small Value (2 decimal): " << smallValue << std::endl; // Will show 0.00
    std::cout << "Large Value (2 decimal): " << largeValue << std::endl; // Will show 1234567.89

    std::cout << std::fixed << std::setprecision(4); // Set to 4 decimal places
    std::cout << "Pi (4 decimal): " << pi << std::endl;
    std::cout << "Price (4 decimal): " << price << std::endl;

    std::cout << std::fixed << std::setprecision(8); // Set to 8 decimal places
    std::cout << "Pi (8 decimal): " << pi << std::endl;
    std::cout << "Small Value (8 decimal): " << smallValue << std::endl;

    // --- Resetting or using default behavior ---
    // You can use std::defaultfloat to revert to the default floating-point output
    // (which uses scientific notation for very large/small numbers and controls total significant digits).
    std::cout << std::defaultfloat; // Reverts to default behavior
    std::cout << "\n--- Default Floating Point ---" << std::endl;
    std::cout << "Pi (default): " << pi << std::endl;
    std::cout << "Small Value (default): " << smallValue << std::endl;
    std::cout << "Large Value (default): " << largeValue << std::endl;

    // --- Using setprecision for total significant digits (without std::fixed) ---
    // If you don't use std::fixed, std::setprecision controls the *total* number of significant digits.
    // It will switch to scientific notation if the number is too large or too small to fit in that precision.
    std::cout << "\n--- Total Significant Digits (no fixed) ---" << std::endl;
    std::cout << std::setprecision(4); // 4 total significant digits
    std::cout << "Pi (4 total significant): " << pi << std::endl; // 3.142
    std::cout << "Large Value (4 total significant): " << largeValue << std::endl; // 1.235e+06 (scientific notation)
    std::cout << std::setprecision(8); // 8 total significant digits
    std::cout << "Large Value (8 total significant): " << largeValue << std::endl; // 1234567.9

    return 0;
}