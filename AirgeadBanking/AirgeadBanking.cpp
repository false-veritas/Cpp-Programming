/*******************************
*   AirgeadBanking.cpp         *
*                              *
*                              *
* Created by: Vitalie Cucuta   *
* Date: 07/31/2020             *
********************************/

#include <iostream>
#include "BankReport.h"
using namespace std;

int main() {
    //declare object 
    BankReport Report = BankReport();

    //declare variable
    char userChoice = 'Y';

    //while user choice is yes, keep running program
    while (userChoice == 'Y' || userChoice == 'y') {
        Report.displayScreenBlank();
        Report.clrScreen();

        Report.userInput();
        //if negative number used end program
        if (Report.checkValidity() == false) {
            cout << "\n\nINVALID ENTRY! Input cannot be a negative number.\nPlease restart the program.\n\n";
            return 0;
        }
        Report.clrScreen();

        Report.displayScreen();
        Report.clrScreen();

        Report.runReportNoMonthly();
        Report.runReportMonthlyDeposit();
        system("pause");
        Report.clrScreen();

        //ask if user wants to continue
        cout << "Would you like to run another report? Y/N \n";
        cin >> userChoice;
        Report.clrScreen();
    }

    //goodbye statement when program ends
    cout << "Thank you for using Airgead Banking!\n\nGoodbye!\n\n";

        
 
    return 0;
}
