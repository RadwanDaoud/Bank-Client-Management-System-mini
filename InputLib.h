#pragma once

#include <iostream>
#include <string>
#include <limits> // ÖÑæÑí áÜ std::numeric_limits / Needed for std::numeric_limits

using namespace std;

namespace InputLib {

        // ÏÇáÉ ŞÑÇÁÉ ÑŞã ÕÍíÍ ãÚ ÇáÊÍŞŞ ãä ÕÍÉ ÇáÅÏÎÇá (ÇáÈÑãÌÉ ÇáÏİÇÚíÉ)
        // Function to read an integer with input validation (defensive programming)
    int ReadNumberInt(string Massage = " ") {
        int number;
        (Massage != " ") ? cout << Massage << endl : cout << "Please enter a number: " << endl;
        cin >> number;

        // ÇáÊÍŞŞ ãä ÇáÅÏÎÇá æÅÕáÇÍå İí ÍÇáÉ ÇáÎØÃ
        // Validate input and fix in case of failure
        while (cin.fail()) {
            cin.clear(); // ÊÕÍíÍ ÍÇáÉ ÇáÎØÃ İí cin / Clear the error state
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // ÊÌÇåá ÇáÎØÃ ÈÇáßÇãá ÍÊì äåÇíÉ ÇáÓØÑ / Ignore invalid input till end of line
            cout << "Invalid input! Please enter a valid number: ";
            cin >> number;
        }
        cin.ignore(numeric_limits<streamsize>::max(), '\n'); // ÊäÙíİ buffer
        return number;
    }
    int ReadNumberFloat(string Massage = " ") {
        int number;
        (Massage != " ") ? cout << Massage << endl : cout << "Please enter a number: " << endl;
        cin >> number;

        // ÇáÊÍŞŞ ãä ÇáÅÏÎÇá æÅÕáÇÍå İí ÍÇáÉ ÇáÎØÃ
        // Validate input and fix in case of failure
        while (cin.fail()) {
            cin.clear(); // ÊÕÍíÍ ÍÇáÉ ÇáÎØÃ İí cin / Clear the error state
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // ÊÌÇåá ÇáÎØÃ ÈÇáßÇãá ÍÊì äåÇíÉ ÇáÓØÑ / Ignore invalid input till end of line
            cout << "Invalid input! Please enter a valid number: ";
            cin >> number;
        }
        cin.ignore(numeric_limits<streamsize>::max(), '\n'); // ÊäÙíİ buffer

        return number;
    }

        // ÏÇáÉ ŞÑÇÁÉ ÑŞã ãæÌÈ (ÕİÑ Ãæ ÃßÈÑ) ãÚ ÑÓÇáÉ ãÎÕÕÉ
        // Function to read a positive integer (zero or more) with a custom message
    int ReadPositiveInt(const string& message = " ") {
        int number = 0 ;
        (message != " ") ? cout << message << endl : cout << "Please enter a positive number: " << endl;

        do {
            
            number = ReadNumberInt(message);  // ÅÚÇÏÉ ÇÓÊÎÏÇã ÏÇáÉ ReadNumber / Reuse ReadNumber function
            if (number < 0)
                cout << "Number must be positive. Try again." << endl;
        } while (number < 0);
        cin.ignore(numeric_limits<streamsize>::max(), '\n'); // ÊäÙíİ buffer

        return number;
    }

       // ÏÇáÉ ŞÑÇÁÉ ÑŞã ÏÇÎá ãÏì ãÍÏÏ [From, To] ãÚ ÑÓÇáÉ ÊæÖíÍíÉ
       // Function to read a number within a specific range [From, To] with prompt message
    int ReadNumberInRange(int From, int To) {
        int number;
        do {
            cout << "Enter a number between " << From << " To " << To << ": ";
            number = ReadNumberInt("");  // ÅÚÇÏÉ ÇÓÊÎÏÇã ÏÇáÉ ReadNumber / Reuse ReadNumber function
            if (number < From || number > To)
                cout << "Number out of range. Try again." << endl;
        } while (number < From || number > To);

        return number;
    }

       // ÏÇáÉ ŞÑÇÁÉ äÕ (String) ãä ÇáãÓÊÎÏã ãÚ ÑÓÇáÉ ãÎÕÕÉ
       // Function to read a string from the user with a custom prompt
    string ReadString(string Latter = "Please Enter Your String ?") {
        string S1;
        cout << Latter << endl;  // ÚÑÖ ÇáÑÓÇáÉ ááãÓÊÎÏã / Display the prompt message
        getline(cin, S1);        // ŞÑÇÁÉ ÇáÓØÑ ßÇãá ÈãÇ İí Ğáß ÇáİÑÇÛÇÊ / Read the entire line including spaces
        return S1;               // ÅÚÇÏÉ ÇáäÕ ÇáãÏÎá / Return the entered string
        }

      // ÏÇáÉ ŞÑÇÁÉ ÍÑİ æÇÍÏ (Char) ãä ÇáãÓÊÎÏã ãÚ ÑÓÇáÉ ãÎÕÕÉ
      // Function to read a single character from the user with a custom prompt
    char ReadChar(string Massage = "Please Enter your a Character") {
        char Ch1;
        cout << Massage << endl;
        cin >> Ch1;
        cin.ignore(numeric_limits<streamsize>::max(), '\n'); // ÊäÙíİ Ãí ãÏÎáÇÊ ÅÖÇİíÉ / Clear any extra input in buffer
        return Ch1;
    }

} // äåÇíÉ Çáäíã ÓÈíÓ InputLib / End of InputLib namespace
