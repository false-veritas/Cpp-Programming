
/*******************************
*   BankReport.h               *
*                              *
*                              *
* Created by: Vitalie Cucuta   *
* Date: 07/31/2020             *
********************************/


#ifndef BANKREPORT_H
#define BANKREPORT_H

//create class for bank
class BankReport {
public:
    BankReport(); //default constructor
    virtual ~BankReport(); //destructor
    void userInput();   //function to get user input
    void displayScreenBlank();   //function to show blank display screen
    void displayScreen();   //function to show screen with user input
    bool checkValidity();   //function to make sure input valid
    void clrScreen();   //function to clear screen
    void runReportNoMonthly();   //function to run report without monthly
    void runReportMonthlyDeposit(); //function to run with monthly deposit
private:
    //all private variables used
    double m_initialAmntInvested;
    double m_monthlyDepositMade;
    double m_annualAcctInterest;
    int m_numYears;

};


#endif // BANKREPORT_H

