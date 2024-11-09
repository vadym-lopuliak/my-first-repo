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
	string name = "";
	int year = 0;
	float mark = 0;
};

// Функція виводу інформації про студента на рядковий потік functionOutput
void PrintStudent (Student& student, stringstream& functionOutput) {
    functionOutput << "Name: " << student.name << "\n";
    functionOutput << "Year: " << student.year << "\n";
    functionOutput << "Mark: " << student.mark << "\n";
}

// Структура вузла дерева
struct TreeNode {
    // Розмістіть тут Ваш код
    Student data; 
    TreeNode* right;
    TreeNode* left;  
    
};

// Функція створення вузла дерева, за прізвищем, роком народження та оцінкою
TreeNode* Create(string name, int year, float mark) {
    // Розмістіть тут Ваш код 
    TreeNode *temp = new TreeNode;
    temp->data.name = name;
    temp->data.year = year;
    temp->data.mark = mark;
    temp->left = temp->right = nullptr;
    return temp;
}

// Функція додавання вузла до дерева, яке упорядковане за прізвищами
void AddName(string name, int year, float mark, TreeNode* &v) {
    // Розмістіть тут Ваш код
    if (v == nullptr) {
        v = Create(name, year, mark);
    } 
    else if (name <= v->data.name) {
        AddName(name, year, mark, v->left);
    } 
    else {
        AddName(name, year, mark, v->right);
    }
}


// Функція додавання вузла до дерева, яке упорядковане за роком народження
void AddYear(string name, int year, float mark, TreeNode* &v) {
	// Розмістіть тут Ваш код
    if (v == nullptr) {
        v = Create(name, year, mark);
    } else if (year <= v->data.year) {
        AddYear(name, year, mark, v->left);
    } else {
        AddYear(name, year, mark, v->right);
    }
}

// Функція додавання вузла до дерева, яке упорядковане за оцінками
void AddMark(string name, int year, float mark, TreeNode* &v) {
	// Розмістіть тут Ваш код
    if (v == nullptr) {
        v = Create(name, year, mark);
    } else if (mark <= v->data.mark) {
        AddMark(name, year, mark, v->left);
    } else {
        AddMark(name, year, mark, v->right);
    }
}

// Функція виводу упорядкованих даних із дерева, яке визначене вказівником v, 
// на рядковий потік functionOutput
// Функція повинна реалізувати вивід за допомогою функції PrintStudent
void Show(TreeNode* v, stringstream& functionOutput) {
    // Розмістіть тут Ваш код
    if (v != nullptr) {
        Show(v->left, functionOutput);
        PrintStudent(v->data, functionOutput);
        Show(v->right, functionOutput);
    }
}

// Функція підрахунку кількості елементів дерева, яке визначене вказівником v
int NodesCount(TreeNode* v) {
    // Розмістіть тут Ваш код
    if (v == nullptr) {
        return 0;
    }
    return 1 + NodesCount(v->left) + NodesCount(v->right);
}

// Функція реалізує видалення дерева, яке визначене вказівником v
void DeleteTree(TreeNode* &v) {
    // Розмістіть тут Ваш код
    if (v != nullptr) {
        DeleteTree(v->left);
        DeleteTree(v->right);
        delete v;
        v = nullptr;
    }
}

// Функція копіювання даних з дерева, яке визначене вказівником source,
// у дерево, яке упорядковане за роком народження і визначене 
// вказівником dest.
void TreeCpyYear(TreeNode* source, TreeNode* &dest) {
	// Розмістіть тут Ваш код
    if (source != nullptr) {
        TreeCpyYear(source->left, dest);
        AddYear(source->data.name, source->data.year, source->data.mark, dest);
        TreeCpyYear(source->right, dest);
    }
}


// Функція копіювання даних з дерева, яке визначене вказівником source,
// у дерево, яке упорядковане за оцінками і визначене вказівником dest.
void TreeCpyMark(TreeNode* source, TreeNode* &dest) {
	// Розмістіть тут Ваш код
    if (source != nullptr) {
        TreeCpyMark(source->left, dest);
        AddMark(source->data.name, source->data.year, source->data.mark, dest);
        TreeCpyMark(source->right, dest);
    }
}


// Завдання 1
// 
// Функція приймає у якості аргументу рядок адреси (назви) файлу, який містить 
// дані про студентів (інформація про окремого студента записується з нового 
// рядка, дані про студента розділені пробілами та наведені у порядку 
// слідування полів структури Student (див. вище)).
// 
// У випадку коректного відкривання і зчитування файлу функція повинна 
// повертати рядок, який містить: 
// * вивід дерева, упорядкованого за прізвищами (за абеткою) студентів 
//   (інформацію про яких зчитано з файлу) та кількість вузлів у ньому з нового 
//   рядка; 
// * вивід дерева, упорядковного за роком народження (за зростанням) студентів 
//   (дані для цього дерева отримати з дерева, упорядкованого за прізвищами) та 
//   кількість вузлів у ньому з нового рядка; 
// * вивід дерева, упорядковного за оцінками (за зростанням) студентів (дані 
//   для цього дерева отримати з дерева, упорядкованого за роком народження) та 
//   кількість вузлів у ньому з нового рядка. 
// Наприклад:
// Task1("testfiles/tree2.txt") - "Sorted by name:\nName: Artemenko\nYear: 1581\nMark: 5\nName: Ivanenko\nYear: 1747\nMark: 3.3\nName: Petrenko\nYear: 1676\nMark: 4.2\nName: Semenenko\nYear: 1492\nMark: 4.1\nCount of nodes = 4\n\nSorted by year:\nName: Semenenko\nYear: 1492\nMark: 4.1\nName: Artemenko\nYear: 1581\nMark: 5\nName: Petrenko\nYear: 1676\nMark: 4.2\nName: Ivanenko\nYear: 1747\nMark: 3.3\nCount of nodes = 4\n\nSorted by mark:\nName: Ivanenko\nYear: 1747\nMark: 3.3\nName: Semenenko\nYear: 1492\nMark: 4.1\nName: Petrenko\nYear: 1676\nMark: 4.2\nName: Artemenko\nYear: 1581\nMark: 5\nCount of nodes = 4\n" (без лапок)
// Читабельний варіант виводу знаходиться у файлі example.txt у корені проекту
// 
// У випадку відсутності файлу або неможливості відкрити його для роботи 
// функція має повертати вивід: 
// "No such file or file is corrupted" (без лапок). 
string Task1(string textFile) {
    stringstream functionOutput;

    ifstream tFile(textFile);
    if (!tFile.is_open()) {
        return "No such file or file is corrupted";
    }

    Student student;
    TreeNode *treeName = nullptr;

    // Побудова дерева за прізвищами
    while (tFile >> student.name >> student.year >> student.mark) {
        AddName(student.name, student.year, student.mark, treeName);
    }

    // Виведення дерева, яке упорядковане за прізвищами
    functionOutput << "Sorted by name:" << endl;
    Show(treeName, functionOutput);
    functionOutput << "Count of nodes = " << NodesCount(treeName) << endl;

    // Створення та виведення дерева, упорядкованого за роком народження
    TreeNode *treeYear = nullptr;
    TreeCpyYear(treeName, treeYear);
    functionOutput << endl << "Sorted by year:" << endl;
    Show(treeYear, functionOutput);
    functionOutput << "Count of nodes = " << NodesCount(treeYear) << endl;

    // Створення та виведення дерева, упорядкованого за оцінками
    TreeNode *treeMark = nullptr;
    TreeCpyMark(treeYear, treeMark);
    functionOutput << endl << "Sorted by mark:" << endl;
    Show(treeMark, functionOutput);
    functionOutput << "Count of nodes = " << NodesCount(treeMark) << endl;

    // Видалення дерев 
    DeleteTree(treeName);
    DeleteTree(treeYear);
    DeleteTree(treeMark);
    Show(treeName, functionOutput);
    Show(treeYear, functionOutput);
    Show(treeMark, functionOutput);
    // Конвертування об'єкту stringstream у рядок для відповідності сигнатурі функції
    return functionOutput.str();
}
