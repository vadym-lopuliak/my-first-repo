#include <math.h>
#include <cstdlib>
#include <time.h>
#include <iostream>
#include <fstream>
#include <sstream>
using namespace std;

// У всіх завданнях забороняється змінювати сигнатуру функції!

// Структура для зберігання даних про студентів
struct Student {
    string name;
    string surname;
    int mark1;
    int mark2;
    int mark3;
    float rating;
};

// Функція виводу інформації про студента на рядковий потік functionOutput
void PrintStudent (Student& student, stringstream& functionOutput) {
    functionOutput << "Name: " << student.name << "\n";
    functionOutput << "Surname: " << student.surname << "\n";
    functionOutput << "Mark 1: " << student.mark1 << "\n";
    functionOutput << "Mark 2: " << student.mark2 << "\n";
    functionOutput << "Mark 3: " << student.mark3 << "\n";
    functionOutput << "Rating: " << student.rating << "\n";
}

// Структура вузла списку
struct Node {
	Student data; 
    Node* next; 
};

// Функція додавання вузла до списку на місце, яке визначене вказівником p
void Add(Node*& p, Student d) {
	Node* temp = p;
    p = new Node;
    p->data = d;
    p->next = temp;
}

// Функція виводу даних із вузла, який визначений вказівником p, на рядковий 
// потік functionOutput
// Функція повинна реалізувати вивід за допомогою функції PrintStudent
void Show(Node* p, stringstream& functionOutput) {
    if (p)
        PrintStudent(p->data, functionOutput);
    else
        functionOutput << "Елемент не існує" << endl;
}

// Функція виводу даних зі списку, голова якого визначена вказівником p, на 
// рядковий потік functionOutput
void ShowList(Node* p, stringstream& functionOutput) {
while (p) {
        PrintStudent(p->data, functionOutput);
        functionOutput << "\n";
        p = p->next;
    }
}
// Функція повертає вказівник на n-ий вузол списку, голова якого визначена 
// вказівником p
Node* Find(Node* p, int n) {
  for (int i = 1; i < n && p; i++) {
        p = p->next;
    }
    return p;
}
// Функція повертає вказівник на останній вузол списку, голова якого визначена 
// вказівником p
Node* FindLast(Node* p) {
   while (p && p->next) {
        p = p->next;
    }
    return p;
}
// Функція реалізує видалення вузла, який визначений вказівником p
void Remove(Node*& p) {
     if (p) {
        Node* temp = p->next;
        delete p;
        p = temp;
    }
}
// Функція реалізує видалення списку, голова якого визначена вказівником p
void RemoveAll(Node*& p) {
     Node* t; 
while (p)  { 
    t = p->next; 
    delete p; 
    p = t; 
} 

}

// Функція повертає довжину (кількість вузлів) списку, голова якого визначена 
// вказівником p
int Length(Node* p) {
    int length = 0;
    while (p) {
        length++;
        p = p->next;
    }
    return length;
}

// Функція реалізує впорядкування списку студентів за прізвищем згідно абетки,
// голова списку визначена вказівником p 
void SortList(Node*& p) {
    // Розмістіть тут ваш код
    int length = Length(p);
    for (int i = 0; i < length - 1; i++) {
        Node* current = p;
        Node* next = p->next;

        for (int j = 0; j < length - i - 1; j++) {
            if (current->data.surname > next->data.surname) {
                Student temp = current->data;
                current->data = next->data;
                next->data = temp;
            }

            current = next;
            next = next->next;
        }
    }
}

// Завдання 1
// 
// Функція приймає у якості аргументів: 
// * рядок адреси (назви) файлу, який містить дані про студентів (інформація 
//   про окремого студента записується з нового рядка, дані про студента 
//   розділені пробілами та наведені у порядку слідування полів структури 
//   Student (див. вище)); 
// * ціле число nodeToShow, яке вказує номер вузла списку, який необхідно буде 
//   показати за допомогою функції Show (див. тіло функції);
// * ціле число addAfterNodeNum, яке вказує номер вузла списку, після якого 
//   необхідно буде додати новий елемент списку, який міститиме дані останнього 
//   доданого при формуванні списку студента (див. тіло функції);
// * ціле число deleteNodeNum, яке вказує номер вузла списку, який необхідно 
//   буде видалити за допомогою функції Delete (див. тіло функції).
// 
// У випадку коректного відкривання і зчитування файлу та коректних значень 
// nodeToShow, addAfterNodeNum, deleteNodeNum, функція повинна повертати рядок,
// який міститиме демонстрацію усіх реалізованих функцій (див. вище) для роботи 
// зі списком (заготовки для виводу наявні у тілі функції). Наприклад:
// Task1("testfiles/list3.txt", 3, 1, 4) - "Whole list:\nName: Lorem\nSurname: Ipsum\nMark 1: 4\nMark 2: 8\nMark 3: 1\nRating: 4.6\n\nName: Dolor\nSurname: Sit\nMark 1: 7\nMark 2: 1\nMark 3: 2\nRating: 2.1\n\nName: Amet\nSurname: Nihil\nMark 1: 9\nMark 2: 6\nMark 3: 4\nRating: 3.4\n\n\nThe 3 node:\nName: Amet\nSurname: Nihil\nMark 1: 9\nMark 2: 6\nMark 3: 4\nRating: 3.4\n\n\nNode added after the 1 node:\nName: Lorem\nSurname: Ipsum\nMark 1: 4\nMark 2: 8\nMark 3: 1\nRating: 4.6\n\nName: Amet\nSurname: Nihil\nMark 1: 9\nMark 2: 6\nMark 3: 4\nRating: 3.4\n\nName: Dolor\nSurname: Sit\nMark 1: 7\nMark 2: 1\nMark 3: 2\nRating: 2.1\n\nName: Amet\nSurname: Nihil\nMark 1: 9\nMark 2: 6\nMark 3: 4\nRating: 3.4\n\n\nThe last element:\nName: Amet\nSurname: Nihil\nMark 1: 9\nMark 2: 6\nMark 3: 4\nRating: 3.4\n\n\nThe 4 node removed:\nName: Lorem\nSurname: Ipsum\nMark 1: 4\nMark 2: 8\nMark 3: 1\nRating: 4.6\n\nName: Amet\nSurname: Nihil\nMark 1: 9\nMark 2: 6\nMark 3: 4\nRating: 3.4\n\nName: Dolor\nSurname: Sit\nMark 1: 7\nMark 2: 1\nMark 3: 2\nRating: 2.1\n\n\nLength: 3\n\n\nSorted list:\nName: Lorem\nSurname: Ipsum\nMark 1: 4\nMark 2: 8\nMark 3: 1\nRating: 4.6\n\nName: Amet\nSurname: Nihil\nMark 1: 9\nMark 2: 6\nMark 3: 4\nRating: 3.4\n\nName: Dolor\nSurname: Sit\nMark 1: 7\nMark 2: 1\nMark 3: 2\nRating: 2.1\n\n\nWhole list removed:\n\n" (без лапок)
// Читабельний варіант виводу знаходиться у файлі example.txt у корені проекту
// 
// У випадку відсутності файлу або неможливості відкрити його для роботи 
// функція має повертати вивід: 
// "No such file or file is corrupted" (без лапок). 
// 
// У випадку некоректних значень параметрів функції, функція має повертати вивід
// "Error" (без лапок).


string Task1(string textFile, int nodeToShow, int addAfterNodeNum, int deleteNodeNum) {
    stringstream functionOutput;

    Student student;
    Node* header = nullptr, * current = nullptr;

    // Відкриття файлу та перевірка на його наявність
    ifstream file(textFile);
    if(nodeToShow <=0 || addAfterNodeNum <= 0 || deleteNodeNum <= 0 ){
	    return "Error";
    }

    if (!file.is_open()) {
        return "No such file or file is corrupted";
    }

    string name, surname;
    int mark1, mark2, mark3;
    float rating;
    int counter = 1; 

    while (true) {
        if(!(file>> student.name)) break; 
        file >> student.surname;
        file>> student.mark1;
        file>> student.mark2 ;
        file>> student.mark3;
        file>> student.rating;

        // Додавання студента в список   
        if (counter == 1)
        {
            Add(header, student);
            counter++; 
        }
        else{
            Add(FindLast(header)->next,student);
        }
        
    }
    file.close();

    // Виведення всього списку
    functionOutput << "Whole list:" << endl;
    ShowList(header, functionOutput);
    functionOutput<< "\n";
 
    // Виведення вузла за номером nodeToShow
    functionOutput << "The " << nodeToShow << " node:" << endl;
    Node* nodeToDisplay = Find(header, nodeToShow);
            
    Show(nodeToDisplay, functionOutput);
    functionOutput<< "\n";functionOutput<< "\n";

    // Додавання вузла після вузла за номером addAfterNodeNum та виведення
    // всього списку для демонстрації результатів
    functionOutput << "Node added after the " << addAfterNodeNum << " node:" << endl;
    Add(Find(header, addAfterNodeNum)->next, student); 
     
    ShowList(header, functionOutput);
    functionOutput<< "\n";

    // Виведення останнього вузла списку
    functionOutput << "The last element:" << endl;
    Node* lastNode = FindLast(header);
    
    Show(lastNode, functionOutput);
    functionOutput<< "\n"; functionOutput<< "\n";
    // Видалення вузла за номером deleteNodeNum та виведення
    // всього списку для демонстрації результатів
    functionOutput << "The " << deleteNodeNum << " node removed:" << endl;
    if(deleteNodeNum == 1){ 
        Remove(header); 
    }
    else{
            Remove(Find(header, deleteNodeNum - 1)->next);
    }
    ShowList(header, functionOutput);
    functionOutput<< "\n";
    

    // Виведення довжини списку (кількості елементів)
    functionOutput << "Length: " << Length(header) << endl;
    functionOutput<< "\n";functionOutput<< "\n";
    // Виведення списку, відсортованого за прізвищами студентів згідно абетки
    functionOutput << "Sorted list:" << endl;
    SortList(header); 
    ShowList(header, functionOutput);
    functionOutput<< "\n";
    // Видалення всього списку та виведення
    // всього списку для демонстрації результатів
    functionOutput << "Whole list removed:" << endl;
    RemoveAll(header);
    ShowList(header, functionOutput);
    functionOutput<< "\n";
    return functionOutput.str();
}



