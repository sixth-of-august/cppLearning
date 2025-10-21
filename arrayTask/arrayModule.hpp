#include <iostream> // библиотека ввода и вывода
#include <format> //  модуль для использования функции формат
#include <cstdlib> // для работы функции srand 
#include <vector> //  модуль для использования векторов
#include <fstream> // библиотека для хранения потока файлов

#pragma once // защита от повторного включения кода
using namespace std; // используем пространство имён

namespace amn{ //пространство имён "array module namespace"

/**
 @brief Функция суммирования чисел в массиве
 @param array Массив в котором проимходит суммирование
 @param n Количество элементов массива
 @return Сумма элементов массива
 */  
template <typename E> // создаём шаблон для функции
double sumArr(E *array, size_t n){
    double temp = 0; // инициализируем временную переменную для хранения суммы
    if(n <= 0){
        throw invalid_argument("sumArr Error: Количество элементов суммы не может быть <= 0");
    }

    for(size_t i = 0; i < n; i++){
        temp = temp + array[i]; // суммируем элементы
    }
    return temp; // возвращаем сумму
    }

/**
 @brief Процедура вывода массива на экран
 @param array Выводимый на экран массив
 @param n Количество элементов в массиве
 */  
template <typename E> // создаём шаблон для функции
void printArr(E *array, size_t n){

    if(n <= 0){
    throw invalid_argument("printArr Error: Количество элементов суммы не может быть <= 0");
    }

for(size_t i = 0; i < n; i++){ // проходимся циклом по элементам
    cout << format("{:.4} ", array[i]); // выводим элементы на экран
} cout << endl;}

/**
 @brief Процедура заполнения массива в указанном диапазоне
 @param array Заполняемый массив
 @param n Количество элементов в массиве
 @param minValue Минимальная граница
 @param maxValue Максимальная граница
 */  
template <typename E> // создаём шаблон для функции
void fillArr(E *array, size_t n, double minValue, double maxValue){

    if(n <= 0){
    throw invalid_argument("fillArr Error: Количество элементов суммы не может быть <= 0");
    }
    
    // проверка на то, что нижняя граница не больше верхней
    if(minValue > maxValue){
        double temp = minValue;
        minValue = maxValue;
        maxValue = temp;
    } // код в скобках выполняет перестановку значений

    // включаем блок кода в проверку
        for(size_t i = 0; i < n; i++){
        // заполнение массива случайными значениями
        array[i] = minValue + (double)rand() / RAND_MAX *(maxValue - minValue); }
        cout << endl; }// переход на новую строку после вывода 

/**
 @brief Процедура заполнения массива вручную
 @param array Заполняемый массив
 @param n Количество элементов в массиве
 */  
template <typename E> // создаём шаблон для функции
void fillArrHand(E* &array, size_t n){

    if(n <= 0){
        throw invalid_argument("fillArrHand Error: Количество элементов суммы не может быть <= 0");
    }

    for(size_t i = 0; i < n; i++){
        cout << format("Введите значение элемента [{}]: ", i + 1) ;
        cin >> array[i]; // заполнение переменной
    };

 }
/**
 @brief Процедура заполнения массива из файла
 @param array Заполняемый массив
 @param fileName Имя файла из которого берутся значения
 @param N Количество элементов в массиве
 */  
template <typename E> // создаём шаблон для функции
void fillArrFile(E* &array, char fileName[], size_t &N){

    if(N <= 0){
        throw invalid_argument("fillArrFile Error: Количество элементов суммы не может быть <= 0");
    }

    ifstream openFile(fileName); // открываем файл для чтения
    double num = 0; N = 0;

    while(openFile >> num){
       N++; // считаем количество элементов
    }
    array = new E[N];
    
    openFile.clear(); // сбрасываем позицию в файле
    openFile.seekg(0); // переходим к началу файла

    for(size_t i = 0; i < N; i++){
        openFile >> array[i]; // записываем символы из файла
    }

    openFile.close(); // закрываем файл
} }

namespace vamn{ //пространство имён "vector array module namespace"

/** @brief процедура вывода вектора на экран
 *  @param array выводимый вектор на экран
 */
template <typename E> // создаём шаблон функции
void arrayPrint(const vector<E> array){

    if(array.size() <= 0){
        throw invalid_argument("arrayPrint Error: Вектор неинициализирован");
    }

    for(size_t i = 0; i < array.size(); i++){
    cout << format("{:.3}", array[i]) << "\t"; } 
    cout << endl;}

/**
 @brief Процедура заполнения массива (вектор) в указанном диапазоне
 @param array Заполняемый массив
 @param minValue Минимальная граница
 @param maxValue Максимальная граница
 */  
template <typename E> // создаём шаблон для функции
void fillArr(vector<E> &array, double minValue, double maxValue){
    
    if(array.size() <= 0){
        throw invalid_argument("fillArr Error: Вектор неинициализирован");
    }

    // проверка на то, что нижняя граница не больше верхней
    if(minValue > maxValue){
        double temp = minValue;
        minValue = maxValue;
        maxValue = temp;
    } // код в скобках выполняет перестановку значений

    // включаем блок кода в проверку
        for(size_t i = 0; i < array.size(); i++){
        // заполнение массива случайными значениями
        array[i] = minValue + (double)rand() / RAND_MAX *(maxValue - minValue); }
        cout << endl; }// переход на новую строку после вывода     

/**
 @brief Процедура заполнения массива из файла
 @param array Заполняемый массив
 @param fileName Имя файла из которого берутся значения
 */  
template <typename E> // создаём шаблон для функции
void fillArrFile(vector<E> &array, char fileName[]){

    if(array.size() <= 0){
        throw invalid_argument("fillArrFile Error: Вектор неинициализирован");
    }

    ifstream openFile(fileName); // открываем файл для чтения
    double num = 0; size_t N = 0;

    while(openFile >> num){
       N++; // считаем количество элементов
    }
    array.resize(N); // выделяем память под массив
    
    openFile.clear(); // сбрасываем позицию в файле
    openFile.seekg(0); // переходим к началу файла

    for(size_t i = 0; i < N; i++){
        openFile >> array[i]; // записываем символы из файла
    }

    openFile.close(); // закрываем файл 
    }

/**
 @brief Функция суммирования чисел в массиве
 @param array Массив в котором проимходит суммирование
 @return Сумма элементов массива
 */  
template <typename E> // создаём шаблон для функции
double arrSum(vector<E> array){

    if(array.size() <= 0){
        throw invalid_argument("arrSum Error: Вектор неинициализирован");
    }

    double temp = 0; // инициализируем временную переменную для хранения суммы
    
    for(size_t i = 0; i < array.size(); i++){
        temp = temp + array[i]; // суммируем элементы
    }
    return temp; }

/**
 @brief Процедура заполнения массива вручную
 @param array Заполняемый массив
 */  
template <typename E> // создаём шаблон для функции
void fillArrHand(vector<E> &array){

    if(array.size() <= 0){
        throw invalid_argument("fillArrHand Error: Вектор неинициализирован");
    }

    for(size_t i = 0; i < array.size(); i++){
        cout << format("Введите значение элемента [{}]: ", i + 1) ;
        cin >> array[i]; // заполнение переменной
    } }
    }