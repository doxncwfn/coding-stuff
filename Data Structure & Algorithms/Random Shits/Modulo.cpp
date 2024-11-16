#include <iostream>
#include <string>

long long mod(const std::string& largeInt, long long mod)
{
    long long result = 0;

    for (char digit : largeInt)
        result = (result * 10 + (digit - '0')) % mod;

    return result;
}

int main()
{
    std::string largeInt;
    std::cout << "Enter the large integer: ";
    std::cin >> largeInt;

    long long divisor;
    std::cout << "Enter the divisor: ";
    std::cin >> divisor;

    if (divisor <= 0)
    {
        std::cerr << "Divisor must be a positive integer." << std::endl;
        return 1;
    }

    long long result = stringModulo(largeInt, divisor);

    std::cout << "The modulo is: " << result << std::endl;

    return 0;
}
