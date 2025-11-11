// библиотеки для работы программы
#include <iostream>
#include <vector>
#include <format>
#include <fstream>
#include <string>

// используем пространство имён std
using namespace std;

// директива для защиты от повторного включения
#pragma ONCE;

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
    void setPublicationYear(int year){
        // проверяем параметр year 
        if(year < 0){
            // если год отрицательный - выдаем ошибку
            throw invalid_argument("yearError: год не может быть отрицательным");
        }
        // задания значения в поле года
        this->publicationYear = year;}

    /** @brief метод для получения значения из поля publicationYear */   
    int getPublicationYear(){return this->publicationYear; }

    /** @brief метод для задания значения в поле page
        @param page количество  страниц */ 
    void setPages(int page){
        // проверяем параметр page
        if(page <= 0){
            // если количество страниц меньше или равно 0, то выдаём ошибку:
            throw invalid_argument("pageError: число страниц не может быть отрицательным или равно 0");
        }
        // устанавливаем количество страниц
        this->pages = page; }
 

    /** @brief метод для получения значения из поля pages */   
    // если метод не меняет поля класса, то его лучше сделать констнантой 
    int getPages() const {return this->pages;} 

    /** @brief метод для задания значения в поле readPages
        @param readed прочитанное количество страниц */ 
    void setReadedPages(int readed){
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
        int getReadedPages(){return this->readPages;}


    /** @brief метод для заполнения класса значениями
     * @param author автор произведения
     * @param title название книги
     * @param year год выпуска книги
     * @param pages количество страниц в книге
     * @param readPage количество прочитанных страниц
     * @param ganres жанры произведения
     */
    void newBook(string author, string title, int year, int pages, int readPages, vector<string> ganres){
        try{
        if(author != ""){
        this->author = author; }            // задания значения в поле author
        if(title != ""){
        this->title = title; }              // задания значения в поле title
        this->setPublicationYear(year);     // задания значения в поле publicationYear
        this->setPages(pages);              // задания значения в поле pages
        this->setReadedPages(readPages);    // задания значения в поле readPages
        this->ganres = ganres;              // задание значение в поле ganres

        // ловим ошибку, в случае, если не получается задать значение в какое-то поле
        } catch (invalid_argument const &error){
        // выводим текст ошибки в консоль
        cout << "Произошла ошибка:" << error.what() << endl;} }

    /** @brief метод вывода класса на экран */
    string toString(){
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
    void saveStateToFile(string fileName){
        ofstream myFile(fileName);

        if(myFile.is_open()){
        // запись обьекта в файл
        myFile << this->toString();
    } }

    // конструктор класса без параметров
    Book(){
        this->author = "Бьёрн Страуструп";
        this->title = "Изучение языка программирования С++";
        this->pages = 1136; 
        this->publicationYear = 2013; 
        this->readPages = 500;}

    // конструктор класса с параметрами
    Book(string author, string title, int year){ 
        this->author = author;
        this->title = title;
        this->setPublicationYear(year);
    }

    // перегрузка оператора += для сложения количество прочитанных страниц
    Book& operator+=(int readed){
        // пробуем записать новое значение
        try{setReadedPages(readPages + readed); }
        catch (invalid_argument const &error){
            cout << error.what(); // в случае ошибки - выводим её
        } return *this; }

    // перегрузка оператора == для сравнения книг по автору
    // автоматически компилятор создаёт оператор сравнения и сравнивает классы по каждому полю
    bool operator==(Book const &anotherBook){
        return (this->author == anotherBook.author) && (this->title == anotherBook.title);
    }

    // перегрузка оператора = для присваивания
    // оператор присваивания компилятор создаёт автоматически, передевая значения из одного обьекта в другой
    Book& operator<=(Book const &anotherBook){
        this->author = anotherBook.author; // присваивания поля author
        this->title = anotherBook.title;   // присваивания поля title
        this->pages = anotherBook.pages;   // присваиваивание поля pages
        this->publicationYear = anotherBook.publicationYear; // присваивание поля publicationYear
        this->readPages = anotherBook.readPages; // присваивание поля readPages
        this->ganres = anotherBook.ganres; // присваивание поля ganres
        return *this; }
};