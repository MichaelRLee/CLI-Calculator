#include <iostream> // cout, cin
#include <string.h> // strcmp

using namespace std;

/* Forward declarations */
bool validate(string toCheck); // Declare the prototype so that it can be used in main

int main()
{
    bool reading = true; // Controls input loop
    char input[256]; // The user input

    while (reading) // Read until user quits
    {
        cout << "Please enter an expression: "; // Print the prompt for the user
        cin.getline(input, 256); // Get a line from the user

        if (!strcmp(input, "#")) // Check for the input which terminates the program (#)
        {
            reading = false; // End the input loop
        }

        /**
        * The user's input was not a message to quit, so we need to first validate and then parse the expression.
        **/
        else
        {
            /* Only proceed if the input is valid */

            if (validate(input)) // The expression is valid
            {
                cout << "Your expression is valid!" << endl; // Test code
            }

            else // The expression is invalid
            {
                cout << "Error: your expression is invalid!" << endl; // Test code
            }
        }
    }
}

/** \brief Checks if a string is an expression.=
 * \param toCheck - A string which contains the expression to validate.
 * \return True if the string represents a valid expression, false if it doesn't.
 */
bool validate(string toCheck)
{
    int i = 0; // Current position in the string

    while (i < toCheck.length()) // Loop through the whole string in a controlled manner
    {
        switch (toCheck[i]) // Perform different actions depending on the state of the machine and the current character
        {
        }
    }
}
