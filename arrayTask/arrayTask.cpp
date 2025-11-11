/* Задание: 
Даны натуральное число n, действительные числа a1,..., an. Вычислить:
а) a1 + ... + an 
    */

#include <iostream> // библиотека ввода вывода
#include <format> // библиотека для работы функции format
#include <cstdlib> // для работы функции srand 
#include <ctime> // для работы функции ctime
#include <cassert> // для работы проверок через assert
#include <vector> // библиотека для работы векторов
#include "arrayModule.hpp" // пользовательский модуль

using namespace std; // используем пространство имёт std 
using namespace amn; // собственное пространство имён
using namespace vamn; // собственное пространство имён

// главный код
int main(){
  
    /*
    // расскоментировать, чтобы отключить проверки
    #define NDEBUG
    */

    // проверка через подстановки в вектора
    vector<int> arrayNew = {1, 2, 3}; assert(arrSum(arrayNew) == 6);
    arrayNew = {1, 1, 1}; assert(arrSum(arrayNew) == 3);
    arrayNew = {0, 0, 0}; assert(arrSum(arrayNew) == 0);

    // проверка через подстановки в вектор вещественных чисел
    vector<double> arrayReal = {1.2, 1.5, 1.3}; assert(arrSum(arrayReal) == 4);
    arrayReal = {1.5, 1.5, 1.5}; assert(arrSum(arrayReal) == 4.5);

    srand(time(NULL)); // рандомизируем генератор

    size_t N = 0; // переменная для хранения размерности массива 
    double max = 0, min = 0; // переменные для диапазона значений
    double result = 0.0; // переменная для хранения значения суммы
    char fileName[] = "array.txt"; // переменная с именем файла
    double *array; // указатель на массив
    vector<double> arrayV; // вектор массива
    
    try{

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
    cout << format("Ваша сумма элементов = {:.4}", result) << endl << endl;

    // заполнение массивов с использованием векторов
    cout << "Заполнение массивов с использованием векторов" << endl;
    cout << "Заполнение массивов вручную: " << endl;
    
    // просьба ввести размерность массива
    cout << "Введите размерность массива: " << endl;
    cin >> N; arrayV.resize(N); // выделение памяти под вектор
    fillArrHand(arrayV); // заполняем вектор вручную
    cout << "Ваш массив: " << endl;
    arrayPrint(arrayV); // Выводим массив на экран 

    result = arrSum(arrayV); // считаем результат
    // считаем сумму и выводим результат
    cout << format("Ваша сумма элементов = {:.4}", result) << endl;

     // записываем границы для заполнения массива случайными числами
    cout << "Заполнение массива случайными цифрами из диапазона" << endl;
    cout << "Введите нижнюю границу: " << endl; cin >> min;
    cout << "Введите верхнюю границу: " << endl; cin >> max;

    fillArr(arrayV, min, max); // заполняем массив случайными значениями из диапазона
    // вывод массива на экран
    cout << "Ваш массив: " << endl;
    arrayPrint(arrayV);

        // заполнение массива из файла
    cout << "Заполнение массива из файла" << endl;
    fillArrFile(arrayV, fileName); // заполняем файл

    cout << "Ваш массив: " << endl;
    arrayPrint(arrayV); // Выводим массив на экран 

    result = sumArr(array, N);
    // считаем сумму и выводим результат
    cout << format("Ваша сумма элементов = {:.4}", result) << endl << endl; }
    
    // ловим ошибку в случае исключительной ситуации
    catch (invalid_argument const &error){
    // выводим текст оишбки в консоль
    cout << "Произошла ошибка по время вызова функции ..." << error.what() << endl;
}

   // очищение памяти массивов
    delete[] array;  array = NULL;

    return 0; // корректно завершаем работу программы
}

/* Компиляциия в консоли: 
g++ arrayTask.cpp -o program.exe -std=c++20
./program.exe  */