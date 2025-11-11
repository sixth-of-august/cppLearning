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

    vector<Book> bookAr; bookAr.resize(5); // создание динамического массива, конструктор не создаётся
    bookAr[0] = straustrupbook; // добавление элемента в массив
    cout << bookAr[0].toString(); // вызов метода у элемента из массива

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

    newBook.saveStateToFile("myFile.txt");
    return 0;
}

// компиляция файла -- g++ taskClass.cpp book.h -o task.exe -std=c++20