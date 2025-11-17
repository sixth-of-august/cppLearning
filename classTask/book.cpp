// библиотеки для работы программы
#include <iostream>
#include <vector>
#include <format>
#include <fstream>
#include <stdexcept>
#include <string>

// включаем заголовочный файл
#include "book.h"

// используем пространство имён std
using namespace std;


    // конструктор без параметров
    Book::Book(){
        this->author = "Бьёрн Страуструп";
        this->title = "Изучение языка программирования С++";
        this->pages = 1136; 
        this->publicationYear = 2013; 
        this->readPages = 500;
    }


    // конструктор с параметрами
    Book::Book(string author, string title, int year){ 
        this->author = author;
        this->title = title;
        this->setPublicationYear(year);
    }


    // перегрузка оператора += для сложения количество прочитанных страниц
    Book& Book::operator+=(int readed){
        // записываем новое значение
        setReadedPages(readPages + readed);
        return *this; }


    // перегрузка оператора == для сравнения книг по автору
    // автоматически компилятор создаёт оператор сравнения и сравнивает классы по каждому полю
    bool Book::operator==(const Book &anotherBook) const{
        return (this->author == anotherBook.author) && (this->title == anotherBook.title);
    }


        /** @brief метод для задания значения в поле publicationYear
        @param year год выпуска книги */ 
    void Book::setPublicationYear(int year){
        // проверяем параметр year 
        if(year < 0){
            // если год отрицательный - выдаем ошибку
            throw invalid_argument("yearError: год не может быть отрицательным");
        }
        // задания значения в поле года
        this->publicationYear = year;}


    /** @brief метод для получения значения из поля publicationYear */   
    int Book::getPublicationYear() const {return this->publicationYear; }


    /** @brief метод для задания значения в поле page
        @param page количество  страниц */ 
    void Book::setPages(int page){
        // проверяем параметр page
        if(page <= 0){
            // если количество страниц меньше или равно 0, то выдаём ошибку:
            throw invalid_argument("pageError: число страниц не может быть отрицательным или равно 0");
        }
        // устанавливаем количество страниц
        this->pages = page; }
 

    /** @brief метод для получения значения из поля pages */ 
    int Book::getPages() const {return this->pages;} 

    /** @brief метод для задания значения в поле readPages
        @param readed прочитанное количество страниц */ 
    void Book::setReadedPages(int readed){
        // проверяем параметр readed 
        if(readed < 0){
            // если отрицательное количество страниц - выдаем ошибку
            throw invalid_argument("readedError: количество прочитанных страниц не может быть отрицательным");
        }

        if((this->pages < readed) || (this->pages == 0)){
            throw invalid_argument("readedError: количество прочитанных страниц не может быть больше всех страниц");
        }
        // задания значения в поле readPages
        this->readPages = readed;}


    /** @brief метод для получения значения из поля readPages */   
        int Book::getReadedPages() const {return this->readPages;}


    /** @brief метод для заполнения класса значениями
     * @param author автор произведения
     * @param title название книги
     * @param year год выпуска книги
     * @param pages количество страниц в книге
     * @param readPage количество прочитанных страниц
     * @param ganres жанры произведения
     */
    void Book::writeInBook(string author, string title, int year, int pages, int readPages, vector<string> ganres){
        if(author != ""){this->author = author; }    // задания значения в поле author
        if(title != ""){ this->title = title; }      // задания значения в поле title
        this->setPublicationYear(year);     // задания значения в поле publicationYear
        this->setPages(pages);              // задания значения в поле pages
        this->setReadedPages(readPages);    // задания значения в поле readPages
        this->ganres = ganres;              // задание значение в поле ganres
        }


    /** @brief метод вывода класса на экран */
    string Book::toString() const{
        string output; // возвращаемая строка
        output = format(" Автор:{}\n Название: {}\n Год написания: {}\n Кол-во страниц:{}\n Прочитано: {}", this->author, this->title, this->publicationYear, this->pages, this->readPages);
       
        // выводим жанры произведения на экран
        output = output +  "\n Жанры: ";
        for(size_t i = 0; i < this->ganres.size(); i++){
           output = output + this->ganres[i] + "; ";
        }       
        return output = output + "\n \n";
    }

    /** @brief метод сохранения объекта в файл
     * @param fileName имя сохраняемого файла*/  
    void Book::saveStateToFile(string fileName){
        ofstream myFile(fileName);

        if(myFile.is_open()){
        // запись обьекта в файл
        myFile << this->toString();
    } }

    

        