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
// Функція приймає у якості аргумента довжину масиву n
// У випадку коректного значення довжини масиву, функція має повертати рядок,
// який міститиме вивід елементів масиву у рядок з пробілами (після 
// останнього елемента теж повинен бути пробіл). Наприклад:
// Task1(5) - "1 2 3 2 1 " (без лапок)
// Task1(6) - "1 2 3 3 2 1 " (без лапок)
// 
// У випадку некоректного значення довжини масиву, функція має повертати вивід
// "Error" (без лапок).
string Task1 (int n) {
    // Об'єктом stringstream можна користуватись як і об'єктом iostream
    // Наприклад, коректним є запис
    // functionOutput << arr[i] << " ";
    stringstream functionOutput;
     if (n <= 0) {
        return "Error";
    }

    int* arr = new int[n];//виділяєм память для динамічного масиву розміром n

    for (int i = 0; i < round ((double) n/2) ; i++) {
        arr[i] = i + 1;
    }
    for (int i = round ((double) n/2); i < n; i++) {
        arr[i] = n - i;
        
    }
    for( int i = 0; i < n; i++){
        functionOutput << arr[i] << " "; 
    }
    return functionOutput.str();
}


// Завдання 2
// 
// Функція приймає у якості аргумента довжину масиву n
// У випадку коректного значення довжини масиву, функція має повертати рядок,
// який міститиме вивід елементів масиву у рядок з пробілами (після 
// останнього елемента теж повинен бути пробіл) до упорядкування та після 
// упорядкування. Наприклад:
// Task2(5) - "0.146 1.45 0.25 8.47 1.16 0.146 0.25 1.16 1.45 8.47 " (без лапок)
//             |->невпорядкована частина |->впорядкована частина
// 
// У випадку некоректного значення довжини масиву, функція має повертати вивід
// "Error" (без лапок).
// 
// УВАГА! Створюваний масив чисел повинен бути типу double
// 
// Для підвищення ступеня випадковості генерування псевдовипадкових чисел
// можна скористатись конструкцією: srand( (unsigned)time(0) );
string Task2 (int n) {
    // Об'єктом stringstream можна користуватись як і об'єктом iostream
    // Наприклад, коректним є запис
    // functionOutput << arr[i] << " ";
    if( n<= 0){
        return "Error"; 
    }
    stringstream functionOutput;
    double *num = new double[n];
    srand( (unsigned)time(0) ); //генератор випадкових чисел
    for(int i = 0; i < n; i++){
        num[i] = (cos(rand())+ 1)* 5; 
    }
    //вивід до сортування
     for(int i = 0; i< n; i++){
        functionOutput << num[i]<< ' '; 
    }
    //сортування методом бульбашки
      int i, j;
    for (i = 0; i < n - 1; i++)
        for (j = 0; j < n - i - 1; j++)
            if (num[j] > num[j + 1]){
                double temp = num[j];
                num[j]= num[j+ 1];
                num[j+1] = temp;   
            }
    //після сортування
    for(int i = 0; i< n; i++){
        functionOutput << num[i]<< ' '; 
    }
    delete[] num ;
    num = nullptr;  
    // Конвертування об'єкту stringstream у рядок для відповідності сигнатурі функції
    return functionOutput.str();
}



// Завдання 3
// 
// Функція має повертати рядок, який міститиме вивід мільйонного елемента 
// масиву послідовних простих чисел. Наприклад:
// Task3() - "15485863" (без лапок)
string Task3() {
    // Об'єктом stringstream можна користуватись як і об'єктом iostream
    // Наприклад, коректним є запис
    // functionOutput << arr[i] << " ";
    stringstream functionOutput;
    int *simple = new int[1000000];// створеня масиву простих чисел
    int count = 0;
    int num = 2;  
    //алгоритм пошуку простих чисел
    while (count < 1000000) {
        bool isSimple = true;
        for (int i = 0; i < count; i++) {
            if (num % simple[i] == 0) {
                isSimple = false; 
                break;
            }
            if (simple[i] * simple[i] > num){
                break;
            }
        }
        if (isSimple) {
            simple[count] = num;
            count++;
            }
        
        num++;
    }
    functionOutput<< simple[999999];//Виведення мільйонного простого числа
    //очищення
    delete[] simple;
    simple = nullptr;

    // Конвертування об'єкту stringstream у рядок для відповідності сигнатурі функції
    return functionOutput.str();
}



// Завдання 4
// 
// Функція приймає у якості аргумента рядок адреси (назви) файлу з текстом - 
// textFile та файлу з ключем - keyFile
// У випадку коректного відкривання та зчитування з обидвох файлів, функція 
// має повертати рядок, який міститиме вивід шифрованого тексту на екран 
// (з урахуванням заміни символів з ASCII-кодами < 32 на крапки ".") та вивід
// дешифрованого тексту, які відділяються одне від одного переходом на новий 
// рядок. Наприклад:
// Task4("testfiles/text2.txt", "testfiles/key2.txt") - 
// "?..K.....K.....K...E.....E....K...E....K...\nThe quick brown fox jumps over the lazy dog" (без лапок)
// 
// У випадку некоректного відкривання та (чи) зчитування з файлу тексту або 
// файлу ключа, функція має повертати вивід 
// "Error" (без лапок).
string Task4 (string textFile, string keyFile) {
    // Об'єктом stringstream можна користуватись як і об'єктом iostream
    // Наприклад, коректним є запис
    // functionOutput << arr[i] << " ";
    stringstream functionOutput;
    char *x = new char[1000];
    char *y = new char[1000];
    char *z = new char[1000];
    int k[32]; 

    ifstream file(textFile);
    ifstream key(keyFile);
    //перевірка файлів
    if(!file || !key){
        return "Error"; 
    }
    int longFile = 0;
    int longKey = 0;
    char countChar;
    //зчитування тексту та ключа
    while(file.get(countChar) ){
        x[longFile] = countChar;
        longFile++;  
    }
    while(key.get(countChar) ){
        k[longKey] = countChar;
        longKey++;
        if(longKey == 32){
            break;
        }  
        
    }
    //шифрування
    for(int i = 0; i < longFile; i++){
        y[i] = x[i]^k[i%longKey]; 
        if(y[i]< 32){
            functionOutput<< '.';
        }
        if(y[i] >= 32) {
            functionOutput << y[i]; 
        }
    }
    //розшифрумання 
    functionOutput << endl; 
    for(int i = 0; i < longFile; i++ ){
        z[i] = y[i]^k[i%longKey];
        functionOutput<< z[i];  
    }
    file.close();
    key.close();
//очищення пам'яті
    delete[] x; x = nullptr;
    delete[] y; y = nullptr;
    delete[] z; z = nullptr;

    // Конвертування об'єкту stringstream у рядок для відповідності сигнатурі функції
    return functionOutput.str();
}
