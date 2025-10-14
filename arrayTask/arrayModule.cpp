#include <iostream> // библиотека ввода и вывода
#include <format> //  модуль для использования функции формат
#include <fstream>
#include "arrayModule.hpp" // заголовочный файл

namespace amn{ //пространство имён "array module namespace"

/**
 @brief Процедура заполнения массива в указанном диапазоне
 @param array Заполняемый массив
 @param n Количество элементов в массиве
 @param minValue Минимальная граница
 @param maxValue Максимальная граница
 */  
void fillArr(double *array, size_t n, double minValue, double maxValue){

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
 @brief Процедура заполнения массива из файла
 @param array Заполняемый массив
 @param fileName Имя файла из которого берутся значения
 @param N Количество элементов в массиве
 */  
void fillArrFile(double* &array, char fileName[], size_t &N){ 
    ifstream openFile(fileName); // открываем файл для чтения
    size_t num = 0; N = 0;

    // запоминаем позицию до подсчёта элементогв файла 
    streampos pos = openFile.tellg();

    while(openFile >> num){
       N = N + 1; // считаем количество элементов
    }
    array = new double[N];

    openFile.seekg(pos); // переходим к началу файла
 
    for(size_t i = 0; i < N; i++){
        openFile >> array[i]; // записываем символы из файла
    }

    openFile.close(); // закрываем файл
} }