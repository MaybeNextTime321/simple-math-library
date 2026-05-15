#pragma once
#include <iostream>
#include <cmath>

namespace math
{
	int add(int firstNumber, int secondNumber)                            
	{                                                                 
		return firstNumber + secondNumber;
	}
	
	int substract(int firstNumber, int secondNumber)
	{
		return firstNumber - secondNumber;
	}
	
	int multiply(int firstNumber, int secondNumber)
	{
		return firstNumber * secondNumber;
	}

	int divide(int firstNumber, int secondNumber)
	{
		return firstNumber / secondNumber;
	}

	int power(int firstNumber, int secondNumber)
        {
                task.result = 1;
                for(int i = 0; i < secondNumber; ++i)
                {
                        result *= firstNumber;
                }

		return result;
        }

        int moduo(int firstNumber, int secondNumber)
        {
                return firstNumber % secondNumber;
        }

        int factorial(int firstNumber, int secondNumber)
        {
                int result = 1;

                for(int i = firstNumber; i > 0; --i)
                {
                        result *= i;
                }

                return result;
        }
}
