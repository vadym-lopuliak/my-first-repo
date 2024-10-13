#include <math.h>
#include <cstdlib>
#include <time.h>
#include <iostream>
#include <fstream>
#include <sstream>
using namespace std;

// У всіх завданнях забороняється змінювати сигнатуру функції!

// Завдання 1
// 
// Функція приймає у якості аргументів кількість рядків rows та кількість 
// стовпців cols двовимірного масиву.
// 
// У випадку коректного значення розмірів масиву, функція має повертати рядок,
// який міститиме вивід елементів масиву по рядках: між елементами рядка не 
// повинні знаходитись розділові знаки, а після останнього рядка теж повинен 
// бути присутній перехід на новий рядок. Наприклад:
// Task1(5,6) - "111111\n122221\n125521\n122221\n111111\n" (без лапок)
// 
// У випадку некоректного значення розмірів масиву, функція має повертати вивід
// "Error" (без лапок).
string Task1 (int rows, int cols) {
 if (rows <= 0 || cols <= 0) {
     return "Error";
 }
 int **array = new int*[rows];
 for (int i = 0; i < rows; i++) {
     array[i] = new int[cols];
 }
 for (int i = 0; i < rows; i++) {
     for (int j = 0; j < cols; j++) {
         if (i == 0 || i == rows - 1 || j == 0 || j == cols - 1) {
             array[i][j] = 1;
         } else if (i == 1 || i == rows - 2 || j == 1 || j == cols - 2) {
             array[i][j] = 2;
         } else {
             array[i][j] = 5;
         }
     }
 }

 // Об'єкт stringstream для збереження результату
 stringstream functionOutput;

 for (int i = 0; i < rows; i++) {
     for (int j = 0; j < cols; j++) {
         functionOutput << array[i][j];
     }
     functionOutput << '\n'; 
 }
 // Конвертування об'єкту stringstream у рядок
 for (int i = 0; i < rows; i++) {
     delete[] array[i];
 }
 delete[] array;
 return functionOutput.str();
}
 


// Завдання 2
// 
// Функція приймає у якості аргумента рядок адреси (назви) файлу з набором 
// цілих чисел у діапазоні від 0 до 999 (включно), які розділені пробілами - 
// textFile та кількість рядків rows і кількість стовпців cols двовимірного 
// масиву.
// 
// У випадку коректного значення розмірів масиву та коректного відкривання і 
// зчитування файлу, функція має повертати рядок, який міститиме вивід 
// елементів масиву та максимумів по рядках і стовпцях у вигляді таблиці згідно 
// завдання. Слід урахувати наступне:
// * для кожного числа слід зарезервувати три позиції на виведення, якщо 
//   позиції не зайняті, то їх слід заповнити пробілами, вирівнявши таким чином 
//   число за правим краєм;
// * між числами (зарезервованими позиціями під них) повинен знаходитись один 
//   пробіл;
// * між знаком | зліва та справа мають знаходитись по два пробіли, які 
//   відмежовують цей знак від найближчих чисел;
// * після останнього числа у рядку (у т.ч. останнього) повинен 
//   знаходитись пробіл та символ переходу на новий рядок.
//
// Наприклад:
// Task2("testfiles/array1.txt", 3, 5) - " 34  54  12   3  45  |   54 \n212 234 533 332   2  |  533 \n243  33  57 546 765  |  765 \n---------------------+-----\n243 234 533 546 765  |  765 \n" (без лапок)
// 
// У випадку відсутності файлу або неможливості відкрити його для роботи 
// функція має повертати вивід: 
// "No such file or file is corrupted" (без лапок). 
//
// У випадку відсутності у файлі необхідної кількості чисел для заповнення 
// двовимірного масиву визначених розмірів функція має повертати вивід: 
// "Insufficient data" (без лапок).
//
// У випадку некоректного значення розмірів масиву, функція має повертати вивід:
// "Error" (без лапок).
// 
// УВАГА! Під час виконання цього завдання дозволяється виносити частини 
// функціоналу у окремі функції, які будуть викликані у процесі роботи функції 
// Task2. Такі функції слід розмістити у поточному файлі source.cpp
//string Task2 (string textFile, int rows, int cols) {
    // Об'єктом stringstream можна користуватись як і об'єктом iostream
    // Наприклад, коректним є запис
string Task2(string textFile, int rows, int cols) {
    int** arr = nullptr;
    int* rowMax = nullptr;
    int* colMax = nullptr;

    ifstream inputFile(textFile);
    if (!inputFile) {
        return "No such file or file is corrupted";
    }
    if(rows <= 0 || cols <= 0){
        return "Error";
    }

    arr = new int*[rows];
    for (int i = 0; i < rows; i++) {
        arr[i] = new int[cols];
    }

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if (!(inputFile >> arr[i][j])) {
                for (int i = 0; i < rows; i++) {
        delete[] arr[i];
    }
    delete[] arr;

                return "Insufficient data";
            }
        }
    }

    inputFile.close();
    rowMax = new int[rows];
    colMax = new int[cols];

    for (int i = 0; i < rows; i++) {
        rowMax[i] = arr[i][0];
        for (int j = 1; j < cols; j++) {
            if (arr[i][j] > rowMax[i]) {
                rowMax[i] = arr[i][j];
            }
        }
    }

    for (int j = 0; j < cols; j++) {
        colMax[j] = arr[0][j];
        for (int i = 1; i < rows; i++) {
            if (arr[i][j] > colMax[j]) {
                colMax[j] = arr[i][j];
            }
        }
    }

    int overallMax = arr[0][0];
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if (arr[i][j] > overallMax) {
                overallMax = arr[i][j];
            }
        }
    }
    stringstream functionOutput;
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if (arr[i][j] < 10) functionOutput  << "  "; 
            if(arr[i][j] >=10 && arr[i][j] < 100) functionOutput  << " "; 
            functionOutput  << arr[i][j] << " ";
        }
        functionOutput  << " | ";
            if (rowMax[i] < 10) functionOutput  << "  "; 
            if(rowMax[i] >=10 && rowMax[i] < 100) functionOutput  << " "; 
            
            functionOutput  << " " << rowMax[i] << " "; 
        functionOutput  << endl;
    }
    for ( int i = 0; i < cols; i++){
        functionOutput  << "----"; 
    }
    functionOutput  << "-+-----"<< endl;
    for (int j = 0; j < cols; j++) {
        if (colMax[j] < 10) functionOutput  << "  "; 
            if(colMax[j] >=10 && colMax[j] < 100) functionOutput  << " "; 
        functionOutput  << colMax[j] << " ";
    }

    if (overallMax < 10) functionOutput  <<  " |  " << "  "; 
    if (overallMax >= 100) functionOutput  <<  " |  ";
            if(overallMax >=10 && overallMax < 100) functionOutput  <<  " |  " << " "; 
    functionOutput  << overallMax << " " << endl; 
    for (int i = 0; i < rows; i++) {
        delete[] arr[i];
    }
    delete[] arr;
    delete[] rowMax;
    delete[] colMax;

    return functionOutput.str();
}
