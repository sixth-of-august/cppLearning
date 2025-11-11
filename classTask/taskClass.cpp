/* автор - Лесков. Н. 
    класс - книга*/

#include <iostream>
#include <format>
#include "book.h" // подлкючаем класс для работы

using namespace std;

int main(){

    // создание экземпляров класса
    Book warAndPiece("Лев Николаевич Толстой", "Война и Мир", 1865); // вызов конструктора с параметрами
    // использования метода set
    warAndPiece.setPages(1400); warAndPiece.ganres = {"Роман-Эпопея", "Исторический роман"};
    
    Book newBook, straustrupbook;
    straustrupbook.newBook("", "Тур по с++", 2013, 254, 100, {"Пособие по С++", "Справочник"});

    // динамическое создания переменной
    Book* warAndPiece2 = new Book(); // динамическое создание объекта (1 конструктор)
    // проверка оператора присваивания
    warAndPiece2 = &warAndPiece;     

    vector<Book> bookAr; bookAr.resize(5); // создание динамического массива, конструктор не создаётся
    bookAr[0] = straustrupbook; // добавление элемента в массив
    bookAr[0].toString(); // вызов метода у элемента из массива

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
    warAndPiece.toString();
    newBook.toString();

    delete warAndPiece2; // очистка памяти после работы конструктора
    return 0;
}

// компиляция файла -- g++ taskClass.cpp book.h -o task.exe -std=c++20