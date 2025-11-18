/* автор - Лесков. Н. 
    класс - книга*/

#include <iostream>
#include <format>
#include <cassert>
#include "book.h" // подлкючаем класс для работы

using namespace std;

int main(){

     /*
    // расскоментировать, чтобы отключить проверки
    #define NDEBUG
    */

    Book testBook;
    // проверка конструктора по умолчания 
    assert(testBook.getPages() == 1136);
    // проверка сеттера и геттера
    testBook.setReadedPages(100); assert(testBook.getReadedPages() == 100);
    // проверка оператора присваивания
    testBook += 100; assert(testBook.getReadedPages() == 200);

    try{ // пробуем выполнить функции
    // создание экземпляров класса
    Book warAndPiece("Лев Николаевич Толстой", "Война и Мир", 1865); // вызов конструктора с параметрами
    // использования метода set
    warAndPiece.setPages(1400); warAndPiece.ganres = {"Роман-Эпопея", "Исторический роман"};
    
    Book newBook, straustrupbook;
    straustrupbook.writeInBook("", "Тур по с++", 2013, 254, 100, {"Пособие по С++", "Справочник"});

    vector<Book> bookAr; bookAr.resize(5); // создание динамического массива (0 конструкторов   )
    bookAr[0] = straustrupbook; // добавление элемента в массив
    cout << bookAr[0].toString(); // вызов метода у элемента из массива

    Book statArray[5]; // статичный массив, вызывается конструктор по умолчанию для каждого ообъекта (5)
    Book *bookArray = new Book[3]; // динамический массив вызывается конструктор по умолчанию для каждого обьекта (3)
    delete[] bookArray;
    
    Book *bookArray[3]; // массив из указателей, не вызывается конструкторов - 3 указателя
    delete[] bookArray;

    cout << statArray[1].toString(); // проверка вызова метода из массива

    // проверка оператора +=
    warAndPiece += 100;

    // проверка оператора сравнения
    if(straustrupbook == newBook){
        cout << "Книги одинаковые" << endl;
        cout << endl;
    } else{
        cout << "Книги различные"  << endl;
        cout << endl;}

    // вывод экземпляров в консоль в консоль
    cout << warAndPiece.toString();
    cout << newBook.toString();

    // проверка метода сохранения в файл
    newBook.saveStateToFile("myFile.txt");

    // ловим ошибку в функции
    } catch (invalid_argument const &error){
    cout << error.what(); }


    return 0;
}

// компиляция файла -- g++ taskClass.cpp book.cpp -o task.exe -std=c++20