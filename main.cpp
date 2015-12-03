#include <iostream> // cout, cin
#include <string.h> // strcmp

using namespace std;

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

        else // Parse the input
        {
            // DEBUGGING
            cout << "Your input was: \"" << input << "\"" << endl;
        }
    }
}
