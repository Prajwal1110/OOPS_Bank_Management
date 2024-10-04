#include <iostream>
#include <fstream>
#include <string>

using namespace std;

class Login
{
public:
    int accNo;
    string password;

    // Default Constructor
    Login()
    {
        accNo = 0;
        password = "";
    }

    // Parameterized Constructor:
    Login(int accNo, string password)
    {
        this->accNo = accNo;
        this->password = password;
    }

    bool login()
    {
        int accNoInFile;
        string passwordInFile;

        ifstream in("login.txt"); // Open file for reading

        while (in >> accNoInFile >> passwordInFile)
        { // Read account number and password from file
            if (accNo == accNoInFile && password == passwordInFile)
            {
                return true; // Return true if account number and password match
            }
        }

        return false; // Return false if no match found
    }

    void createAccount(int accNo)
    {
        ofstream out("login.txt", ios::app); // Open file for writing in append mode
        if (!out)
        { // Check if file was successfully opened
            cerr << "Unable to open file for writing" << endl;
            return; // Exit the function if the file could not be opened
        }

        cout << "Create a new Password: ";
        cin >> password;

        out << accNo << " " << password << endl; // Write account number and password to file
        out.close();                             // Close the file

        cout << "Account created successfully with Account Number: " << accNo << endl;
    }
};



class Application
{
    // Static pointer to hold the single instance of the Application class
    static Application *application;

    // Private constructor to prevent direct instantiation from outside the class
    Application() {}



public:
    // Static method to provide global access to the single instance of Application
    static Application *getInstance()
    {
        // If the application instance hasn't been created yet, create it
        if (!application)
            application = new Application;
        // Return the single instance of the Application class
        return application;
    }

    // Method to handle user login based on account number and password
    bool login(int accNo)
    {
        string passwrd;
        cout << "Enter Password: ";
        cin >> passwrd;  // Prompt the user to enter the password

        // Create a Login object with the provided account number and password
        Login login(accNo, passwrd);

        // Call the login function of the Login class to verify credentials
        return login.login();
    }

    // Method to create a new account
    void createAccount(int accNo)
    {
        Login login;  // Create a Login object

        // Call the createAccount function of the Login class to create a new account
        login.createAccount(accNo);
    }
};