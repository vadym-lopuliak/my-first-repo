#include <math.h>
#include <cstdlib>
#include <time.h>
#include <iostream>
#include <fstream>
#include <sstream>
using namespace std;

// Завдання 1
string Task1 (int n) {
    stringstream functionOutput;
    if (n <= 0) {
        return "Error";
    }

    int *arr = new int[n];
    for (int i = 0; i < n / 2; ++i) {
        arr[i] = i + 1;
        arr[n - i - 1] = i + 1;
    }
    if (n % 2 != 0) {
        arr[n / 2] = n / 2 + 1;
    }

    for (int i = 0; i < n; ++i) {
        functionOutput << arr[i] << " ";
    }

    delete[] arr;
    return functionOutput.str();
}

// Завдання 2
string Task2 (int n) {
    stringstream functionOutput;
    if (n <= 0) {
        return "Error";
    }

    srand((unsigned)time(0));
    double *arr = new double[n];

    // Заповнення масиву випадковими числами
    for (int i = 0; i < n; ++i) {
        arr[i] = ((double)rand() / RAND_MAX) * 10.0;
        functionOutput << arr[i] << " ";
    }

    functionOutput << " "; // Пропуск для поділу масивів

    // Сортування масиву
    for (int i = 0; i < n - 1; ++i) {
        for (int j = i + 1; j < n; ++j) {
            if (arr[i] > arr[j]) {
                swap(arr[i], arr[j]);
            }
        }
    }

    // Виведення відсортованого масиву
    for (int i = 0; i < n; ++i) {
        functionOutput << arr[i] << " ";
    }

    delete[] arr;
    return functionOutput.str();
}

// Допоміжна функція для перевірки простоти числа
bool isPrime(int num, int* primes, int count) {
    for (int i = 0; primes[i] * primes[i] <= num && i < count; ++i) {
        if (num % primes[i] == 0) {
            return false;
        }
    }
    return true;
}

// Завдання 3
string Task3 () {
    stringstream functionOutput;
    const int targetPrimeCount = 1000000;
    int *primes = new int[targetPrimeCount];
    primes[0] = 2;
    int count = 1;
    int num = 3;

    while (count < targetPrimeCount) {
        if (isPrime(num, primes, count)) {
            primes[count] = num;
            count++;
        }
        num += 2;
    }

    functionOutput << primes[targetPrimeCount - 1]; // Мільйонне просте число
    delete[] primes;
    return functionOutput.str();
}

// Завдання 4
string Task4 (string textFile, string keyFile) {
    stringstream functionOutput;
    ifstream textStream(textFile);
    ifstream keyStream(keyFile);

    if (!textStream || !keyStream) {
        return "Error";
    }

    string text, key;
    getline(textStream, text);
    getline(keyStream, key);

    int textLength = text.length();
    int keyLength = key.length();

    if (keyLength == 0) {
        return "Error";
    }

    char *X = new char[textLength];
    char *Y = new char[textLength];
    char *Z = new char[textLength];

    // Шифрування
    for (int i = 0; i < textLength; ++i) {
        X[i] = text[i];
        Y[i] = X[i] ^ key[i % keyLength];
        if (Y[i] < 32) {
            functionOutput << ".";
        } else {
            functionOutput << Y[i];
        }
    }

    functionOutput << "\n";

    // Дешифрування
    for (int i = 0; i < textLength; ++i) {
        Z[i] = Y[i] ^ key[i % keyLength];
        functionOutput << Z[i];
    }

    delete[] X;
    delete[] Y;
    delete[] Z;

    return functionOutput.str();
}

int main() {
    // Приклади використання функцій
    cout << "Task1(5): " << Task1(5) << endl;
    cout << "Task2(5): " << Task2(5) << endl;
    cout << "Task3(): " << Task3() << endl;
    cout << "Task4(\"text.txt\", \"key.txt\"): " << Task4("text.txt", "key.txt") << endl;

    return 0;
}
