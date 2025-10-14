#pragma once

#include <iostream>
#include <string>
#include <limits> // ����� �� std::numeric_limits / Needed for std::numeric_limits

using namespace std;

namespace InputLib {

        // ���� ����� ��� ���� �� ������ �� ��� ������� (������� ��������)
        // Function to read an integer with input validation (defensive programming)
    int ReadNumberInt(string Massage = " ") {
        int number;
        (Massage != " ") ? cout << Massage << endl : cout << "Please enter a number: " << endl;
        cin >> number;

        // ������ �� ������� ������� �� ���� �����
        // Validate input and fix in case of failure
        while (cin.fail()) {
            cin.clear(); // ����� ���� ����� �� cin / Clear the error state
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // ����� ����� ������� ��� ����� ����� / Ignore invalid input till end of line
            cout << "Invalid input! Please enter a valid number: ";
            cin >> number;
        }
        cin.ignore(numeric_limits<streamsize>::max(), '\n'); // ����� buffer
        return number;
    }
    int ReadNumberFloat(string Massage = " ") {
        int number;
        (Massage != " ") ? cout << Massage << endl : cout << "Please enter a number: " << endl;
        cin >> number;

        // ������ �� ������� ������� �� ���� �����
        // Validate input and fix in case of failure
        while (cin.fail()) {
            cin.clear(); // ����� ���� ����� �� cin / Clear the error state
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // ����� ����� ������� ��� ����� ����� / Ignore invalid input till end of line
            cout << "Invalid input! Please enter a valid number: ";
            cin >> number;
        }
        cin.ignore(numeric_limits<streamsize>::max(), '\n'); // ����� buffer

        return number;
    }

        // ���� ����� ��� ���� (��� �� ����) �� ����� �����
        // Function to read a positive integer (zero or more) with a custom message
    int ReadPositiveInt(const string& message = " ") {
        int number = 0 ;
        (message != " ") ? cout << message << endl : cout << "Please enter a positive number: " << endl;

        do {
            
            number = ReadNumberInt(message);  // ����� ������� ���� ReadNumber / Reuse ReadNumber function
            if (number < 0)
                cout << "Number must be positive. Try again." << endl;
        } while (number < 0);
        cin.ignore(numeric_limits<streamsize>::max(), '\n'); // ����� buffer

        return number;
    }

       // ���� ����� ��� ���� ��� ���� [From, To] �� ����� �������
       // Function to read a number within a specific range [From, To] with prompt message
    int ReadNumberInRange(int From, int To) {
        int number;
        do {
            cout << "Enter a number between " << From << " To " << To << ": ";
            number = ReadNumberInt("");  // ����� ������� ���� ReadNumber / Reuse ReadNumber function
            if (number < From || number > To)
                cout << "Number out of range. Try again." << endl;
        } while (number < From || number > To);

        return number;
    }

       // ���� ����� �� (String) �� �������� �� ����� �����
       // Function to read a string from the user with a custom prompt
    string ReadString(string Latter = "Please Enter Your String ?") {
        string S1;
        cout << Latter << endl;  // ��� ������� �������� / Display the prompt message
        getline(cin, S1);        // ����� ����� ���� ��� �� ��� �������� / Read the entire line including spaces
        return S1;               // ����� ���� ������ / Return the entered string
        }

      // ���� ����� ��� ���� (Char) �� �������� �� ����� �����
      // Function to read a single character from the user with a custom prompt
    char ReadChar(string Massage = "Please Enter your a Character") {
        char Ch1;
        cout << Massage << endl;
        cin >> Ch1;
        cin.ignore(numeric_limits<streamsize>::max(), '\n'); // ����� �� ������ ������ / Clear any extra input in buffer
        return Ch1;
    }

} // ����� ����� ���� InputLib / End of InputLib namespace
