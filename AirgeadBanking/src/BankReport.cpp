/*******************************
*   BankReport.cpp             *
*                              *
*                              *
* Created by: Vitalie Cucuta   *
* Date: 07/31/2020             *
********************************/

#include <iostream>
#include "BankReport.h"
using namespace std;

//default constructor
BankReport::BankReport() {
    m_initialAmntInvested = 0;
    m_monthlyDepositMade = 0;
    m_annualAcctInterest = 0;
    m_numYears = 0;
}

//destructor
BankReport::~BankReport() {};

//clear screen function
void BankReport::clrScreen() {
    system("cls");
}

//display the screen without user input
void BankReport::displayScreenBlank() {
    cout << "***********************************\n";
    cout << "*********** Data Input ************\n";
    cout << "Initial Investement Amount: \n";
    cout << "Monthly Deposit: \n";
    cout << "Annual Interest: \n";
    cout << "Number of Years: \n";
    system("pause");
    
}

//get user input function
void BankReport::userInput() {
    cout << "***********************************\n";
    cout << "*********** Data Input ************\n";
    cout << "Enter Initial Investement Amount: \n";
    cin >> m_initialAmntInvested;
    cout << "Enter Monthly Deposit: \n";
    cin >> m_monthlyDepositMade;
    cout << "Enter Annual Interest: \n";
    cin >> m_annualAcctInterest;
    cout << "Enter Number of Years: \n";
    cin >> m_numYears;
    system("pause");
}

//make sure user input is valid 
bool BankReport::checkValidity() {
    if (m_initialAmntInvested < 0 || m_monthlyDepositMade < 0 || m_annualAcctInterest < 0 || m_numYears < 0) {
        return false;
    }
    else {
        return true;
    }
}

//display screen with user input
void BankReport::displayScreen() {
    cout << "***********************************\n";
    cout << "*********** Data Input ************\n";
    printf("Initial Investment Amount: $%.2f\n", m_initialAmntInvested);
    printf("Monthly Deposit: $%.2f\n",  m_monthlyDepositMade);
    cout << "Annual Interest: " << m_annualAcctInterest << "%" << endl;
    cout << "Number of Years: " << m_numYears << endl;
    system("pause");
}

//function to run report without additional monthly deposits
void BankReport::runReportNoMonthly() {
    //declare variables to be used within function
    int t_yearsRemaining = m_numYears;
    double t_openingAmnt = m_initialAmntInvested;
    double t_interestAmnt = (t_openingAmnt * (m_annualAcctInterest / 100));
    double t_endBalance = t_openingAmnt + t_interestAmnt;
    double t_balPrevYear = t_openingAmnt;
    double t_yearEndInterest;

    //print header for report
    cout << "\t  Balance and Interest Without Additional Monthly Deposit\n";
    cout << "===========================================================================\n";
    cout << "  Year\t\tYear End Balance\t\tYear End Earned Interest\n";
    cout << "---------------------------------------------------------------------------\n";
    
    //iterate through years and show calculated values
    for (int i = 0; i < t_yearsRemaining; i++) {
        t_yearEndInterest = (t_endBalance - t_balPrevYear);

        printf("%d \t\t\t $%.2f \t\t\t\t\t $%.2f \n", i + 1, t_endBalance, t_yearEndInterest);

        //set up variables for following year to be calculated
        t_balPrevYear = t_endBalance;
        t_openingAmnt = t_endBalance;
        t_interestAmnt = t_openingAmnt * (m_annualAcctInterest / 100);
        t_endBalance = t_openingAmnt + t_interestAmnt;

    }

    cout << endl << endl << endl;
}

//function to run report with additional monthly deposits
void BankReport::runReportMonthlyDeposit() {
    //declare variables to be used within function
    int t_yearsRemaining = m_numYears;
    double t_openingAmnt = m_initialAmntInvested;
    double t_depositedAmnt = m_monthlyDepositMade;
    double t_total = t_openingAmnt + (t_depositedAmnt * 12);
    double t_interestAmnt = (t_total * (m_annualAcctInterest / 100));
    double t_endBalance = t_total + t_interestAmnt;
    double t_balPrevYear = t_openingAmnt;
    double t_yearEndInterest;
    

    //print header for report
    cout << "\t  Balance and Interest With Additional Monthly Deposit\n";
    cout << "===========================================================================\n";
    cout << "  Year\t\tYear End Balance\t\tYear End Earned Interest\n";
    cout << "---------------------------------------------------------------------------\n";

    //iterate through years and show calculated values
    for (int i = 0; i < t_yearsRemaining; i++) {
        t_yearEndInterest = (t_endBalance - t_balPrevYear - (t_depositedAmnt * 12));

        printf("%d \t\t\t $%.2f \t\t\t\t $%.2f \n", i + 1, t_endBalance, t_yearEndInterest);

        //set up variables for following year to be calculated
        t_balPrevYear = t_endBalance;
        t_openingAmnt = t_endBalance;
        t_total = t_openingAmnt + (t_depositedAmnt * 12);
        t_interestAmnt = t_total * (m_annualAcctInterest / 100);
        t_endBalance = t_total + t_interestAmnt;

    }

    cout << endl << endl << endl;
}


