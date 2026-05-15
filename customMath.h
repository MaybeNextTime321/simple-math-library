#pragma once
#include <iostream>
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
		ParseError
	};

	int add(int firstNumber, int secondNumber, MathStatus& operationStatus)                            
	{       
		if(firstNumber > 0 && secondNumber > 0 && secondNumber > INT_MAX - firstNumber)
		{
			operationStatus = MathStatus::Overflow;
			return 0;
		}

                if(firstNumber > 0 && secondNumber < 0 && firstNumber < INT_MIN - secondNumber)
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
		long long result = firstNumber * secondNumber;
		if(result > INT_MAX)
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
                int result = 1;
		long long newResult = 1;
                for(int i = 0; i < secondNumber; ++i)
                {
			newResult = result *= firstNumber;
                	if(newResult > INT_MAX)
                	{
                		operationStatus = MathStatus::Overflow;
                		return 0;
                	}
                        result *= firstNumber;
                }

		return result;
        }

        int factorial(int firstNumber, MathStatus& operationStatus)
        {
                int result = 1;
                long long newResult = 1;
                for(int i = firstNumber; i > 0; --i)
                {
			newResult = result *= i;
                        if(newResult > INT_MAX)
                        {
                                operationStatus = MathStatus::Overflow;
                                return 0;
                        }
                        result *= i;
                }

                return result;
        }
}
