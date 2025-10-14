/* Задание: 
Даны натуральное число n, действительные числа a1,..., an. Вычислить:
а) a1 + ... + an 
    */

#include <iostream> // библиотека ввода вывода
#include <format> // библиотека для работы функции format
#include <cstdlib> // для работы функции srand 
#include <ctime> // для работы функции ctime
#include <cassert> // для работы проверок через assert
#include "arrayModule.hpp"

using namespace std; // используем пространство имёт std 
using namespace amn; // собственное пространство имён

// главный код
int main(){
  
    srand(time(NULL)); // рандомизируем генератор

    size_t N = 0; // переменная для хранения размерности массива 
    double max = 0, min = 0; // переменные для диапазона значений
    double result = 0.0; // переменная для хранения значения суммы
    char fileName[] = "array.txt"; // переменная с именем файла
    double *array; // указатель на массив
    
    // просьба ввести размерность массива
    cout << "Введите размерность массива: " << endl;
    cin >> N; array = new double[N]; // выделение памяти массива 
    fillArrHand(array, N); // заполнение массива от руки

    // вывод массива на экран
    cout << "Ваш массив: " << endl;
    printArr(array, N);

    result = sumArr(array, N);
    
    // считаем сумму и выводим результат
    cout << format("Ваша сумма элементов = {:.4}", result) << endl;

    // записываем границы для заполнения массива случайными числами
    cout << "Заполнение массива случайными цифрами из диапазона" << endl;
    cout << "Введите нижнюю границу: " << endl; cin >> min;
    cout << "Введите верхнюю границу: " << endl; cin >> max;

    fillArr(array, N, min, max); // заполняем массив случайными значениями из диапазона
    // вывод массива на экран
    cout << "Ваш массив: " << endl;
    printArr(array, N);

    result = sumArr(array, N);
    // считаем сумму и выводим результат
    cout << format("Ваша сумма элементов = {:.4}", result) << endl;

    // заполнение массива из файла
    cout << "Заполнение массива из файла" << endl;
    fillArrFile(array, fileName, N); // заполняем файл

    cout << "Ваш массив: " << endl;
    printArr(array, N); // Выводим массив на экран 

    result = sumArr(array, N);
    // считаем сумму и выводим результат
    cout << format("Ваша сумма элементов = {:.4}", result) << endl;

   // очищение памяти массивов
    delete[] array;  array = NULL;

    return 0; // корректно завершаем работу программы
}

/* Компиляциия в консоли: 
g++ arrayTask.cpp arrayModule.cpp -o program.exe -std=c++20
./program.exe  */