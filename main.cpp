#include <iostream>
#include <iomanip>
#include <stdexcept>

#include "main.hpp"

using std::cout, std::cin, std::setw, std::fixed, std::setprecision, std::endl, std::string;

int main()
{
    bool quit = false;
    cout << "Financial Goal Calculator" << endl;
    while (!quit)
    {
        cout << "1. Calculate Years to Financial Goal\n2. Calculate Amount based on Years\n3. Quit" << endl;
        string answer = "";
        int answer_as_int = 0xDEADBEEF;
        cin >> answer;
        
        try
        {
            answer_as_int = std::stoi(answer);
        }
        catch (std::invalid_argument e)
        {
            cout << "Please enter an integer and stop making my life difficult." << endl;
            continue;
        }
        catch (std::out_of_range e)
        {
            cout << "I don't think there's that many menu options; please enter a sane integer." << endl;
            continue;
        }

        // if we get here then the input is an integer
        switch (answer_as_int)
        {
            case 1:
                years_to_financial_goal();
                break;
            case 2:
                amount_based_on_years();
                break;
            case 3:
                quit = true;
                break;
                
            default:
                cout << "Please enter a valid menu option." << endl;
                break;
        }
    }


    return 0;
}


// Hey I know I should probably be decoupling the calculation side of things and the output side of things, but I'm sort of lazy and this won't be graded anyways so yeah...
void years_to_financial_goal() {
    double investment_amt = 0;
    double interest_rate = 0;
    double money_goal = 0;

    cout << "Enter Investment amount: ";
    cin >> investment_amt;
    cout << "Enter Interest Rate AS A PERCENTAGE: ";
    cin >> interest_rate;
    cout << "Enter financial Goal: ";
    cin >> money_goal;

    double money = investment_amt;
    interest_rate /= 100; // to get the decimal version of the percentage.

    int year;
    for (year = 1; money < money_goal; year++)
    {
        money += money * interest_rate;

        cout <<  "Year" << setw(4) << year << ". " << fixed << setprecision(2) << money << endl;

    }

    cout << "That will take " << year << "years" << endl;
    return;
}

void amount_based_on_years()
{
    double investment_amt = 0;
    double interest_rate = 0;
    int years_of_incubation; // sorry, I like this better than mature. makes it sound like an alien or something :)

    cout << "Enter Investment amount: ";
    cin >> investment_amt;
    cout << "Enter Interest Rate: ";
    cin >> interest_rate;
    cout << "Enter Years to maturity: ";
    cin >> years_of_incubation;

    interest_rate /= 100; // to get the decimal version of the percentage.
    double money = investment_amt;

    int year;
    for (year = 0; year < years_of_incubation; year++)
    {
        money += money * interest_rate;
    }

    cout << "You will have " << fixed << setprecision(2) << money << " in " << year << " years" << endl;

    return;
}