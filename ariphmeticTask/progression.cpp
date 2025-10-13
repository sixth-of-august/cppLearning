// исполняемый код модуля

#include <iostream> // модуль для основных функций программы
#include <string> // модуль для расширенных ошибок

#include "progression.h" // заголовочный файл программы

using namespace std;

/** @brief функция для вычисления суммы прогрессии n-членов
   @param first Первый член прогрессии
   @param diff Разница между элементами прогрессии
   @param amount Количество прогрессии
   @return Сумма n-членов прогрессии*/
double getProgression(double first, double diff, int amount){

// проверка на положительное количество элементов для суммы
if(amount <= 0){
   // вывод сообщения об ошибке через throw
   throw invalid_argument("Error: Количество элементов суммы не может быть <= 0");
}

// считаем последний член а.прогрессии
double last = first + ((amount - 1) * diff);
return (amount / 2.0) * (first + last); // считаем сумму членов
}
