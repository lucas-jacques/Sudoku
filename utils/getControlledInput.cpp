#include <iostream>
#include <limits>

/**
 * This function is used to get an input from the user and will keep asking the user for an input until the input is valid.
 * The condition parameter is a function that takes the input as a parameter and returns a boolean.
 *
 * @param condition A function that takes the input as a parameter and returns a boolean.
 * @return The input from the user.
 *
 */
template <typename T>
T getControlledInput(bool condition(T option))
{
    T input;
    while (!(std::cin >> input) || !condition(input))
    {
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cout << "Invalid option. Please try again." << std::endl;
    }
    return input;
}