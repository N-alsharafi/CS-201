#include <iostream>
#include <string>
using namespace std;

//declaration of the functions to be used

bool getCompanyData(string& companyName, string& location, double& grossIncome, double& expenses, int& noOfShareholders);
double calculateVAT(double grossIncome, string location);
double calculateCorporateTax(double profit);
double calculateProfit(double grossIncome, double expenses, string location);
double calculateNetProfit(double grossIncome, double expenses, string location);
double calculateDividend(double netProfit, int noOfShareholders);
void outputCompanyResults(string companyName, double grossIncome, double expenses, int noOfShareholders, string location);


int main()
    {
        //declaring main variables

        string companyName1, companyName2, location1, location2;
        double grossIncome1, grossIncome2, expenses1, expenses2, netProfit1, netProfit2;
        int noOfShareholders1, noOfShareholders2;

        //getting company data

        cout << "This accounting program calculates the state taxes and dividends for the company shareholders.\n";

        bool company1 = getCompanyData(companyName1, location1, grossIncome1, expenses1, noOfShareholders1);
        if (!company1) {
            return 0;
        }
        bool company2 = getCompanyData(companyName2, location2, grossIncome2, expenses2, noOfShareholders2);
        if (!company2) {
            return 0;
        }

        //printing financial report
        outputCompanyResults(companyName1, grossIncome1, expenses1, noOfShareholders1, location1);
        outputCompanyResults(companyName2, grossIncome2, expenses2, noOfShareholders2, location2);

        //doing the final comparison
        netProfit1 = calculateNetProfit(grossIncome1, expenses1, location1);
        netProfit2 = calculateNetProfit(grossIncome2, expenses2, location2);

        cout << endl;

        if (netProfit1 == netProfit2) {
            cout << "Both " << companyName1 << " and " << companyName2
                << " have an equivalent financial performance in terms of net profit.";
        
        }
        else if (netProfit1 > netProfit2) {
            cout << companyName1 << " has a superior financial performance in terms of net profit compared to "
                << companyName2 << ".";
        }
        else {
            cout << companyName2 << " has a superior financial performance in terms of net profit compared to "
                << companyName1 << ".";
        }

        
        return 0;
    }


//Implementation of the functions

bool getCompanyData(string& companyName, string& location, double& grossIncome, 
    double& expenses, int& noOfShareholders) {
    /*
    This function asks the user for input and checks the input ensuring
    sensible arguments
    */
    cout << "Please enter the name of the company: ";
    cin >> companyName;
    cout << "Is the company local or foreign? ";
    cin >> location;
    if (location != "local" && location != "foreign") {
        cout << "Invalid location.";
        return false;
    }
    cout << "Please enter the gross income of "<<companyName<<": ";
    cin >> grossIncome;
    if (grossIncome <= 0) {
        cout << "Invalid input for gross income.";
        return false;
    }
    cout << "Please enter expenses of "<<companyName<<": ";
    cin >> expenses;
    if (expenses < 0) {
        cout << "Invalid input for expenses.";
        return false;
    }
    cout << "Please enter the number of shareholders: ";
    cin >> noOfShareholders;
    if (noOfShareholders < 1) {
        cout << "Invalid input for the number of shareholders.";
        return false;
    }

    return true;
}

double calculateVAT(double grossIncome, string location) {
    /*
    This function takes grossIncome and location of a company to determine the 
    percentage of VAT that company has to pay, then calculates the dollar amount
    given the company's gross income and returns a dollar amount value that the 
    company has to pay considering it's grossIncome
    */
    bool local = true;
    double vatpercent, vatamount;

    if (location == "foreign") {
        local = false;
    }

    if (local) {
        vatpercent = 0.15;
    }
    else {
        vatpercent = 0.18;
    }

    vatamount = grossIncome * vatpercent;

    return vatamount;
}

double calculateCorporateTax(double profit) {
    /*
    This function takes a company's profit, decides how much corporate tax it has to
    pay based on that profit, and returns the dollar amount value the company has to pay
    given how much profit it made
    Also, the return value is absolute value just in case
    */
    double corporateTaxPercent, corporateTaxAmount;

    if (profit <= 0) {
        corporateTaxPercent = 0;
        return corporateTaxAmount = 0;
    }
    else if (profit <= 10000) {
        corporateTaxPercent = 0.10;
    }
    else if (profit <= 25000) {
        corporateTaxPercent = 0.15;
    }
    else if (profit <= 50000) {
        corporateTaxPercent = 0.20;
    }
    else {
        corporateTaxPercent = 0.25;
    }

    corporateTaxAmount = profit * corporateTaxPercent;

    return corporateTaxAmount;
}

double calculateProfit(double grossIncome, double expenses, string location) {
    /*
    This functions calculates a company's base profit which is income - expenses(including VAT)
    returns a dollar amount
    */
    double profit;

    profit = grossIncome - expenses - calculateVAT(grossIncome, location);

    return profit;
}

double calculateNetProfit(double grossIncome, double expenses, string location) {
    /*
    This function calculates a company's net profit,
    income - expenses(including VAT) - corporate tax and returns the dollar amount net profit
    */
    double netProfit, profit;
    profit = calculateProfit(grossIncome, expenses, location);

    netProfit = profit - calculateCorporateTax(profit); 

    return netProfit;
}

double calculateDividend(double netProfit, int noOfShareholders) {
    /*
    This function calculates the share of money each shareholder gets out of
    the net profit of the company, half the netprofit goes to capital increase
    the other half is distributed equally among shareholders then, 15% is taken off
    that share as shareholder dividend tax
    */
    double sharePerHolder=0;

    if (netProfit > 0) {
        netProfit = 0.5 * netProfit;
        sharePerHolder = netProfit * (1.0 - 0.15);
        sharePerHolder = sharePerHolder / noOfShareholders;
        
    }
    

    return sharePerHolder;
}

void outputCompanyResults(string companyName, double grossIncome,
    double expenses, int noOfShareholders, string location) {
    /*
    This function prints a company's financial report
    */
    double profit = calculateProfit(grossIncome, expenses, location);
    double netProfit = calculateNetProfit(grossIncome, expenses, location);


    cout << "\n*********** " << companyName << " Financial Report **********";
    cout << endl << endl;

    if (netProfit == 0) {
        cout << "Net Profit: " << netProfit << " TL. (Break Even)\n";
    }
    else if (netProfit < 0) {
        cout << "Net Loss: " << netProfit << " TL.\n";
    }
    else {
        cout << "Net Profit: " << netProfit << " TL.\n";
    }

    cout << "VAT: " << calculateVAT(grossIncome, location) << " TL.\n";
    cout << "Corporate Tax: " << calculateCorporateTax(profit) << " TL.\n";
    cout << endl;
    cout << "Capital Increase: " << netProfit / 2.0 << " TL.\n";
    cout << noOfShareholders << " shareholders will have a share of: " <<
        calculateDividend(netProfit, noOfShareholders) << " TL.\n";

}