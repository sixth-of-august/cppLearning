// модуль с функцией для вычисления арифметической прогрессии
// директива для отмены повторной вставки модулей в коде
#pragma once

namespace pw{ //namespace progression work
/** @brief функция для вычисления суммы прогрессии n-членов
   @param first Первый член прогрессии
   @param diff Разница между элементами прогрессии
   @param amount Количество прогрессии
   @return Сумма n-членов прогрессии*/
double getProgression(double first, double diff, int amount);
}