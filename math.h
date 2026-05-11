#pragma once
#include "../utility.h"
#include <iostream>
#include <cmath>

namespace math
{
	void add(utility::Task & task)                            {                                                                 task.result = task.firstNumber + task.secondNumber;                                                         }                                                                                                                   void substract(utility::Task & task)                      {                                                                 task.result = task.firstNumber - task.secondNumber;                                                         }                                                                                                                   void multiply(utility::Task & task)                       {                                                                 task.result = task.firstNumber * task.secondNumber;                                                         }                                                                                                                   void divide(utility::Task & task)                         {                                                                 task.result = task.firstNumber / task.secondNumber;
	}

	        void power(utility::Task & task)
        {
                task.result = 1;
                for(int i = 0; i < task.secondNumber; ++i)
                {
                        task.result *= task.firstNumber;
                }
        }

        void moduo(utility::Task & task)
        {
                task.result = task.firstNumber % task.secondNumber;
        }

        void factorial(utility::Task & task)
        {
                double result = 1;

                for(double i = task.firstNumber; i > 0; --i)
                {
                        result *= i--;
                }

                task.result = result;
        }
}
