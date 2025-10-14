#include <iostream> // библиотека ввода и вывода
#include <format> //  модуль для использования функции формат
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
        cout << endl; } }// переход на новую строку после вывода 