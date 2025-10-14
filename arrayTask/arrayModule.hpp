#include <iostream> // библиотека ввода и вывода
#include <format> //  модуль для использования функции формат
#include <cstdlib> // для работы функции srand 

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
void fillArr(double *array, size_t n, double minValue, double maxValue);

/**
 @brief Процедура заполнения массива вручную
 @param array Заполняемый массив
 @param n Количество элементов в массиве
 */  
template <typename E> // создаём шаблон для функции
void fillArrHand(E* &array, size_t n){
    for(size_t i = 0; i < n; i++){
        cout << format("Введите значение элемента [{}]: ", i + 1) ;
        cin >> array[i]; // заполнение переменной
    };

} }