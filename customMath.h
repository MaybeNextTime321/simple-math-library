#pragma once
#include <cmath>
#include <climits>

namespace math
{

        enum class MathStatus

        {
                Ok,
                DivideByZero,
                Overflow,
                FactorialFromNegative,
                ParseError,
                Help
        };

        int add(int firstNumber, int secondNumber, MathStatus& operationStatus)
        {
                if(firstNumber > 0 && secondNumber > 0 && secondNumber > INT_MAX - firstNumber)
                {
                        operationStatus = MathStatus::Overflow;
                        return 0;
                }

                if(firstNumber < 0 && secondNumber < 0 && firstNumber < INT_MIN - secondNumber)
                {
                        operationStatus = MathStatus::Overflow;
                        return 0;
                }

                return firstNumber + secondNumber;
        }

        int substract(int firstNumber, int secondNumber, MathStatus& operationStatus)
        {
                if(firstNumber > 0 && secondNumber < 0 &&  firstNumber > INT_MAX + secondNumber)
                {
                        operationStatus = MathStatus::Overflow;
                        return 0;
                }

                if(firstNumber < 0 && secondNumber > 0 && firstNumber < INT_MIN + secondNumber)
                {
                        operationStatus = MathStatus::Overflow;
                        return 0;
                }

                return firstNumber - secondNumber;
        }

        int multiply(int firstNumber, int secondNumber, MathStatus& operationStatus)
        {
                long long result = static_cast<long long>(firstNumber) * secondNumber;
                if(result > INT_MAX || result < INT_MIN)
                {
                operationStatus = MathStatus::Overflow;
                return 0;
                }
                return firstNumber * secondNumber;
        }

        int divide(int firstNumber, int secondNumber, MathStatus& operationStatus)
        {
                if(secondNumber == 0)
                {
                 operationStatus = MathStatus::DivideByZero;
                 return 0;
                }

                if(firstNumber == INT_MIN && secondNumber == -1)
                {
                        operationStatus = MathStatus::Overflow;
                        return 0;
                }


                return firstNumber / secondNumber;
        }

        int power(int firstNumber, int secondNumber, MathStatus& operationStatus)
        {
                long long result = 1;
                for(int i = 0; i < secondNumber; ++i)
                {
                        result *= firstNumber;
                        if(result > INT_MAX || result < INT_MIN)
                        {
                                operationStatus = MathStatus::Overflow;
                                return 0;
                        }
                }

                return static_cast<int>(result);
        }

        int factorial(int firstNumber, MathStatus& operationStatus)
        {
                if (firstNumber < 0)
                {
                        operationStatus = MathStatus::FactorialFromNegative;
                        return 0;
                }

                if (operationStatus != MathStatus::Ok)
                {
                        return 0;
                }

                if(firstNumber == 1 || firstNumber == 0)
                {
                        return 1;
                }

                long long result = static_cast<long long>(firstNumber) * factorial(firstNumber - 1, operationStatus);


                if(result > INT_MAX || result < INT_MIN)
                {
                        operationStatus = MathStatus::Overflow;
                        return 0;
                }

                return static_cast<int>(result);
        }
}
