// библиотеки для работы программы
#include <vector>
#include <string>

// используем пространство имён std
using namespace std;
// директива для защиты от повторного включения
#pragma once

// класс книги
class Book{
    // открытые поля класса
    public:
    string title;  // название книги
    string author; // автор книги
    vector<string> ganres = {"Пособие", "Справочник"};      // жанры книги
    
    // закрытые поля класса
    private: 
    int publicationYear = 1000;     // год публикации
    int pages = 0;                  // количество страниц
    int readPages = 0;              // количество прочитанных страниц

    public: 
    /** @brief метод для задания значения в поле publicationYear
        @param year год выпуска книги */ 
    void setPublicationYear(int year);


    /** @brief метод для получения значения из поля publicationYear */   
    int getPublicationYear() const;


    /** @brief метод для задания значения в поле page
        @param page количество  страниц */ 
    void setPages(int page);
 

    /** @brief метод для получения значения из поля pages */   
    // если метод не меняет поля класса, то его лучше сделать констнантой 
    int getPages() const; 

    /** @brief метод для задания значения в поле readPages
        @param readed прочитанное количество страниц */ 
    void setReadedPages(int readed);


    /** @brief метод для получения значения из поля readPages */   
        int getReadedPages() const;


    /** @brief метод для заполнения класса значениями
     * @param author автор произведения
     * @param title название книги
     * @param year год выпуска книги
     * @param pages количество страниц в книге
     * @param readPage количество прочитанных страниц
     * @param ganres жанры произведения
     */
    void writeInBook(string author, string title, int year, int pages, int readPages, vector<string> ganres);


    /** @brief метод вывода класса на экран */
    string toString() const;

    /** @brief метод сохранения объекта в файл
     * @param fileName имя сохраняемого файла*/  
    void saveStateToFile(string fileName);


    // конструктор класса без параметров
    Book();


    // конструктор класса с параметрами
    Book(string author, string title, int year);


    // перегрузка оператора += для сложения количество прочитанных страниц
    Book& operator+=(int readed);

    // перегрузка оператора == для сравнения книг по автору
    // автоматически компилятор создаёт оператор сравнения и сравнивает классы по каждому полю
    bool operator==(const Book &anotherBook) const;
    
};