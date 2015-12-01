/** Main program **/

/* Includes */
#include <iostream> // cout

/* Namespaces */
using namespace std; // Use the standard namespace

int main()
{
    bool running = true; // Controls the main input loop
    char uinput[256]; // The user input

    while (running) // Loop until the user quits
    {
        cout << "Please enter an expression: "; // Print the prompt
        cin.getline(uinput, 256); // Get the expression from the user
        cout << "You entered: \"" << uinput << "\"" << endl; // DEBUGGING
    }
}
