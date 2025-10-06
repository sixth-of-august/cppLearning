// директива для отмены повторной вставки модулей в коде
#pragma ONCE

#include <iostream>

#include "progression.h"

/* @brief функция для вычисления суммы прогрессии n-членов
   @param first Первый член прогрессии
   @param diff Разница между элементами прогрессии
   @param amount Количество прогрессии
   @return Сумма n-членов прогрессии*/
double getProgression(double first, double diff, double amount){

// считаем последний член а.прогрессии
double last = first +(amount - 1) * diff;
return amount / 2 * (first + last); // считаем сумму членов
}
