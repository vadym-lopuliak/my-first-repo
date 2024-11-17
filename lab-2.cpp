#include <math.h>
#include <cstdlib>
#include <time.h>
#include <iostream>
#include <fstream>
#include <sstream>
using namespace std;

// Забороняється змінювати сигнатуру функцій Task1, Task2 і Task3!
// Забороняється використовувати глобальні змінні!

// Функція знаходження суми ряду для заданої кількості членів. 
// Функцію слід застосовувати у межах Завдання 1 (функція Task1).
long double CalculationsTask1(int num) {
    if (num == 0) {
        return 0; 
    } else {
        return 1 / pow(num, 4) + CalculationsTask1(num - 1); //1 / pow(num, 4) додає поточний член ряду до суми.
    }
}


// Функція знаходження значення ланцюгового дробу для заданої кількості членів. 
// Функцію слід застосовувати у межах Завдання 2 (функція Task2).
long double CalculationsTask2(int num, int precision) {
    if (num == precision) {
        return (pow(num +2, 2) - 2); 
    } else {
        return (pow(num +2, 2) - 2)+ 1/(CalculationsTask2(num + 1, precision)); 
    }
}
//Результат — повертає значення ланцюгового дробу для заданої кількості членів.

// Функція знаходження суми ряду для заданої кількості членів (кількості у 
// кожній із сум). 
// Функцію слід застосовувати у межах Завдання 3 (функція Task3).
long double CalculationsTask3(int num) { //приймає кількість членів ряду num.
    long double  a,b; //для обчислення членів ряду для бази 2 і 3
    if (num == 0) {
        return 1/2. + 1/3.; 
    } 
    a = (1/(pow(2, num * 2 + 1)) * pow(-1, num)) * 1/(num* 2+ 1)//обчислює знак і базовий член ряду для основи 2.
    b = (1/(pow(3, num * 2 + 1)) * pow(-1, num)) * 1/(num* 2+ 1);
    return a + b + CalculationsTask3 (num- 1); 
    //Результат — повертає суму ряду для заданої кількості членів.
}


// Завдання 1
// 
// Функція приймає у якості аргумента кількість членів ряду, суму якого 
// необхідно обчислити. Обчислення проводяться за допомогою функції 
// CalculationsTask1.
// 
// У випадку коректного значення кількості членів, функція має повертати 
// значення числа π з точністю 11 знаків після десяткової крапки. Наприклад:
// Task1(1000) - "3.14159265335" (без лапок)
// 
// У випадку некоректного значення кількості членів (наприклад, уведене 
// від'ємне значення), функція має повертати вивід
// "Error" (без лапок).
string Task1(int precision) {
    stringstream functionOutput;
    if (precision <= 0) {
        return "Error"; 
    } else {
        long double result = pow(CalculationsTask1(precision)* 90, 0.25);//викликає рекурсивну функцію для обчислення суми ряду
        //pow(..., 0.25)-обчислює четвертий корінь для знаходження п
        
        functionOutput.precision(12);//встановлює точність до 12 символів
        functionOutput << result;// результат у рядковий потік
        
    }
     return functionOutput.str();
}

// Завдання 2
// 
// Функція приймає у якості аргумента кількість членів ланцюгового дробу, 
// значення якого необхідно обчислити. Обчислення проводяться за допомогою 
// функції CalculationsTask2.
// 
// У випадку коректного значення кількості членів, функція має повертати 
// значення ланцюгового дробу з точністю 14 знаків після десяткової крапки. 
// Наприклад:
// Task2(10) - "2.14141855829559" (без лапок)
// 
// У випадку некоректного значення кількості членів (наприклад, уведене 
// від'ємне значення), функція має повертати вивід
// "Error" (без лапок).
string Task2(int precision) {
    stringstream functionOutput;
    if (precision < 0) {
        return "Error"; 
    } else {
        long double result = CalculationsTask2(0, precision);// обчислює значення ланцюгового дробу для заданої кількості членів.
        
        functionOutput.precision(15);
        functionOutput << result;
        
    }
     return functionOutput.str();
}


// Завдання 3
// 
// Функція приймає у якості аргумента кількість членів ряду (кількість у кожній 
// із сум), суму якого необхідно обчислити. Обчислення проводяться за допомогою 
// функції CalculationsTask3.
// 
// У випадку коректного значення кількості членів, функція має повертати 
// значення числа π з точністю 14 знаків після десяткової крапки. Наприклад:
// Task3(100) - "3.14159265358979" (без лапок)
// 
// У випадку некоректного значення кількості членів (наприклад, уведене 
// від'ємне значення), функція має повертати вивід
// "Error" (без лапок).
string Task3(int precision) {
    stringstream functionOutput;
    if (precision < 0) {
        return "Error"; 
    } else {
        long double result = CalculationsTask3(precision)* 4;// множем результат для отримання п
        
        functionOutput.precision(15);
        functionOutput << result;// зберігання результату
        
    }
     return functionOutput.str();
}
