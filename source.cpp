#include <math.h>
#include <cstdlib>
#include <time.h>
#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
using namespace std;

// У всіх завданнях забороняється змінювати сигнатуру функції!
// Забороняється використовувати глобальні змінні!

// Функція знаходження num-го числа Фібоначчі за допомогою двох рекурсивних 
// викликів (спосіб а) у методичних рекомендаціях). Функцію слід застосовувати 
// у межах Завдання 1 (функція Task1).
long long FibonacciTask1(int num) {
  if (num <= 1) {
        return num;
    }
    else {
        return FibonacciTask1(num - 1) + FibonacciTask1(num - 2);
    }
}

// Функція знаходження num-го числа Фібоначчі за допомогою одного рекурсивного 
// виклику (спосіб б) у методичних рекомендаціях). Функцію слід застосовувати 
// у межах Завдання 2 (функція Task2).
long long FibonacciTask2(int k, int num, long long prev1, long long prev2) {
    if (num < 0) {
        return -1; // Помилка: некоректне значення num
    }
    if (num == 0) {
        return prev1;
    }
    if (k > 40) {
        return -2; // Помилка: значення num перевищує максимальне допустиме
    }
    return FibonacciTask2(k + 1, num - 1, prev2, prev1 + prev2);
}




// Завдання 1
// 
// Функція приймає у якості аргумента кількість елементів (чисел) послідовності
// Фібоначчі, які потрібно вивести (не більше 40). Обчислення проводяться за 
// допомогою функції FibonacciTask1.
// 
// У випадку коректного значення кількості елементів, функція має повертати 
// рядок, який міститиме вивід відповідної кількості елементів послідовності 
// Фібоначчі, які розділені одним пробілом, а після останнього елемента пробілу 
// бути не повинно. Наприклад:
// Task1(5) - "1 1 2 3 5" (без лапок)
// 
// У випадку некоректного значення кількості елементів (наприклад, уведене 
// від'ємне значення), функція має повертати вивід
// "Error" (без лапок).
//
// У випадку значення кількості елементів, яке перевищує максимальне допустиме, 
// функція має повертати вивід
// "Invalid input data" (без лапок).
string Task1(int num) {
    stringstream functionOutput;
    if (num < 1) {
        return "Error";
    }
    if (num > 40) {
        return "Invalid input data";
    }
    if (num == 1) {
        return "1";
    }
    functionOutput << Task1(num - 1) << " " << FibonacciTask1(num);
    return functionOutput.str();
}
 
// Завдання 2
// 
// Функція приймає у якості аргумента кількість елементів (чисел) послідовності
// Фібоначчі, які потрібно вивести (не більше 40). Обчислення проводяться за 
// допомогою функції FibonacciTask2.
// 
// У випадку коректного значення кількості елементів, функція має повертати 
// рядок, який міститиме вивід відповідної кількості елементів послідовності 
// Фібоначчі, які розділені одним пробілом, а після останнього елемента пробілу 
// бути не повинно. Наприклад:
// Task2(5) - "1 1 2 3 5" (без лапок)
// 
// У випадку некоректного значення кількості елементів (наприклад, уведене 
// від'ємне значення), функція має повертати вивід
// "Error" (без лапок).
//
// У випадку значення кількості елементів, яке перевищує максимальне допустиме, 
// функція має повертати вивід
// "Invalid input data" (без лапок).
string Task2(int num) {
    stringstream functionOutput;
    if (num < 1) {
        return "Error";
    }

    if (num > 40) {
        return "Invalid input data";
    }
    if (num == 1) {
        return "1";
    }

    long long prev1 = 0, prev2 = 1;

    for (int i = 1; i <= num; ++i) {
        long long fib = FibonacciTask2(0, i, prev1, prev2);
        functionOutput << fib;
        if (i < num) {
            functionOutput << " ";
        }
    }
    return functionOutput.str();
}



// Функція обчислення довжини найкоротшого шляху до виходу з лабіринту
// від заданих початкових координат. Рухатись можна вперед, назад, вправо та 
// вліво по карті масиву.
// Функцію слід застосовувати у межах Завдання 3 (функція Task3).
int CalculationsTask3(string map[], int row, int col) {
    if (row < 0 || col < 0 || map[row][col] == '1') {
        return -1;
    }
    if (map[row][col] == '9') {
        return 0;
    }
    map[row][col] = '1';
    int down = CalculationsTask3(map, row + 1, col);
    int right = CalculationsTask3(map, row, col + 2);
    int left = CalculationsTask3(map, row, col - 2);
    int up = CalculationsTask3(map, row - 1, col);

    int minPath = -1;

    if (right >= 0 && (minPath == -1 || right < minPath)) {
        minPath = right;
    }

    if (left >= 0 && (minPath == -1 || left < minPath)) {
        minPath = left;
    }

    if (down >= 0 && (minPath == -1 || down < minPath)) {
        minPath = down;
    }

    if (up >= 0 && (minPath == -1 || up < minPath)) {
        minPath = up;
    }

    map[row][col] = '0';
    if (minPath == -1) {
        return -1;
    }
    return minPath + 1;
}

// Завдання 3
// 
// Функція приймає у якості аргументів: 
// * рядок адреси (назви) файлу textFile, який містить карту лабіринту 
//   (інформація подана у вигляді двовимірного масиву 0, 1 та 9, розділених 
//   пробілами та переходами на новий рядок, при цьому на карті прийняті такі 
//   позначення:
//   0 - доступні для проходу комірки, 
//   1 - стіни,
//   9 - вихід (він завжди є і єдиний)); 
// * розміри карти масиву: rowsCount (кількість рядків) та 
//                         colsCount (кількість стовпців);
// * початкові координати: startRow (номер стартового рядка, нумерація від 0, 
//                                   як у масивах) та
//                         startCol (номер стартового стовпця, нумерація від 0, 
//                                   як у масивах).
// Обчислення довжини найкоротшого шляху від заданої початкової точки до виходу 
// проводяться за допомогою рекурсивної функції CalculationsTask3.
// 
// У випадку коректного відкривання і зчитування файлу та коректних значень 
// rowsCount, colsCount, startRow, startCol, функція повинна повертати 
// повертати рядок, який міститиме інформацію про довжину найкоротшого шляху 
// від заданих початкових координат до виходу (кількість кроків, які слід 
// здійснити, щоб від початкової точки дійти до виходу). Наприклад:
// Task3("testfiles/map1.txt", 8, 8, 1, 1) - "The shortest path consists of 11 steps" (без лапок)
// 
// У випадку некоректного значення розмірів карти масиву, функція має повертати 
// вивід
// "Wrong dimensions" (без лапок).
//
// У випадку відсутності файлу або неможливості відкрити його для роботи 
// функція має повертати вивід: 
// "No such file or file is corrupted" (без лапок). 
//
// У випадку початкових координат, які містяться поза межами лабіринту, функція 
// має повертати вивід
// "The starting point is outside the maze" (без лапок).
//
// У випадку початкових координат, які відповідають комірці лабіринту зі 
// стіною, функція має повертати вивід
// "The starting point is in the wall" (без лапок).
string Task3(string textFile, int rowsCount, int colsCount, int startRow, int startCol) {
    stringstream functionOutput;
    ifstream file(textFile);
    if (!file) {
        return "No such file or file is corrupted";
    }
    char character;
    int counter = 0;
    if (rowsCount <= 0 || colsCount <= 0) return "Wrong dimensions";
    while (file >> character)
    {
        counter++;
    }
    if (counter != (rowsCount * colsCount)) return "Wrong dimensions";
    file.close();

    file.open(textFile);
    string map[rowsCount];
    for (int i = 0; i < rowsCount; i++) {
        getline(file, map[i], '\n');
    }
    if (startRow < 0 || startRow >= rowsCount) {
        return "The starting point is outside the maze";
    }
    if (startCol < 0 || startCol >= colsCount) {
        return "The starting point is outside the maze";
    }
    if (map[startRow][startCol * 2] == '1') {
        return "The starting point is in the wall";
    }
    file.close();

    functionOutput << "The shortest path consists of " << CalculationsTask3(map, startRow, startCol * 2) << " steps";
    return functionOutput.str();
}
