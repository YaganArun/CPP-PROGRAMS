#include <iostream>
using namespace std;

void natural_numbers(int number)
{
    if (number == 1)
    {
        cout << number << " ";
        return;
    }

    else
    {
        natural_numbers(number - 1);
        cout << number << " ";
        return;
    }
}

int sum_of_digits(int number)
{
    if (number / 10 <= 0)
        return number % 10;
    else
        return (number % 10 + sum_of_digits(number / 10));
}

int main()
{
    //N natural numbers
    cout << "N natural numbers :=> ";
    natural_numbers(10);
    cout << "\n";

    //Sum of digits
    cout << "Sum of digits :=> " << sum_of_digits(11) << "\n";
}
