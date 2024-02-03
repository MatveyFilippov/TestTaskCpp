//  Created by Матвей Филиппов 22БИ-2 (2024-02-03).
//  Вариант 1

#include <iostream>


/**
 Функция оптимизирует ввод данных пользователем
 
 @param prompt промпт для вывода в консоль (подсказка для пользователя)
 @return значение которое ввёл пользователь
  */
template <typename T>
T input(const std::string prompt) {
    T inputted(0.0);
    std::cout << prompt;
    std::cin >> inputted;
    return inputted;
}

/**
 Создаёт рандомное целочисленное число в заданном диапазоне
 
 @param min нижняя граница для выбора
 @param max верхняя граница для выбора
 @return рандомное целочисленное число
 */
int getRandomNumber(const int min, const int max){
    int random_result = min + std::rand() % max;
    return random_result;
}

/**
 Заполняет двумерный целочисленный массив значениями от 10 до 50
 
 @param array двумерный целочисленный массив для заполнения
 @param rows кол-во строк в двумерном массиве
 @param columns кол-во столбцов в двумерном массиве
 */
void fillTwoDimensionalArray(int **array, const int rows, const int columns) {
    for (int i = 0; i < rows; ++i) {
        // fillArray(array[i], columns);  // Простой вариант
        
        for (int j = 0; j < columns; ++j) {
            array[i][j] = getRandomNumber(10, 50);
        }
    }
}

/**
 Выводит в консоль двумерный целочисленный массив
 
 @param array двумерный целочисленный массив для выводв
 @param rows кол-во строк в двумерном массиве
 @param columns кол-во столбцов в двумерном массиве
 */
void printTwoDimensionalArray(int **array, const int rows, const int columns) {
    std::cout << "\nYour filled array:\n\n";
    for (int i = 0; i < rows; ++i) {  // Интересный/красивый вывод двумерного массива ввиде таблицы
        std::cout << "|";
        for (int j = 0; j < columns; ++j) {
            std::cout << array[i][j] << "|";
        }
        if (i != rows-1) {
            std::cout << "\n|";
            int n = 0;
            while (n < columns) {
                std::cout << "--|";
                n++;
            }
        }
        std::cout << "\n";
    }
}

/**
 Высчитывает сумму элементов на главной диагонале матрицы (двумерном квадратном массиве)
 
 @param matrix двумерный целочисленный массив (матрицы)
 @param size размер двумерного целочисленного массива (матрицы)
 */
int getSumOfMainDiagonal(int **matrix, const int size) {
    int sum = 0;
    for (int i = 0; i < size; i++) {
        sum += matrix[i][i];
    }
    return sum;
}

int main(int argc, const char * argv[]) {
    std::srand(static_cast<unsigned int>(time(nullptr)));  // Инициализация рандомайзера
    
    /* Task1 */
    const int score_array_rows_task1 = input<int>("Write num of rows in array: ");  // Получение кол-ва строк
    const int score_array_columns_task1 = input<int>("Write num of columns in array: ");  // Получение кол-ва столбцов
    
    // Объявление двумерного данимического массива пользователя
    int **ptr2arr_task1 = new int*[score_array_rows_task1];  // Выделение памяти для строк массива пользователя
    for (int i = 0; i < score_array_rows_task1; ++i) {
        ptr2arr_task1[i] = new int[score_array_columns_task1];  // Выделение памяти для столбцов массива пользователя
    }
    
    fillTwoDimensionalArray(ptr2arr_task1, score_array_rows_task1, score_array_columns_task1);  // Заполнение двумерного массива пользователя
    printTwoDimensionalArray(ptr2arr_task1, score_array_rows_task1, score_array_columns_task1);  // Вывод двумерного массива пользователя
    
    // Удалиение (освобождение памяти) двумерного массива пользователя
    for (int i = 0; i < score_array_rows_task1; ++i) {
        delete[] ptr2arr_task1[i];  // Освобождение памяти столбцов массива пользователя
        ptr2arr_task1[i] = nullptr;  // Удаление столбцов массива пользователя
    }
    delete[] ptr2arr_task1;  // Освобождение пямяти строк массива пользователя
    ptr2arr_task1 = nullptr;  // Удаление строк массива пользователя
    
    
    const int size_of_matrix_taks1 = input<int>("\nWrite size of matrix: ");  // Получение кол-ва строк и столбцов для матрицы (размера)
    
    // Объявление матрицы
    int **ptr2mat_task1 = new int*[size_of_matrix_taks1];  // Выделение памяти для строк матрицы
    for (int i = 0; i < size_of_matrix_taks1; ++i) {
        ptr2mat_task1[i] = new int[size_of_matrix_taks1];  // Выделение памяти для столбцов матрицы
    }
    
    fillTwoDimensionalArray(ptr2mat_task1, size_of_matrix_taks1, size_of_matrix_taks1);  // Заполнение двумерного массива пользователя
    printTwoDimensionalArray(ptr2mat_task1, size_of_matrix_taks1, size_of_matrix_taks1);  // Вывод двумерного массива пользователя
    
    const int sum_of_main_diag = getSumOfMainDiagonal(ptr2mat_task1, size_of_matrix_taks1);  // Вычисление суммы элементов для главной диагонали матрицы
    std::cout << "\nSum of main diagonal for your array is " << sum_of_main_diag << std::endl;  // Вывод полученной суммы
    
    // Удалиение (освобождение памяти) матрицы
    for (int i = 0; i < size_of_matrix_taks1; ++i) {
        delete[] ptr2mat_task1[i];  // Освобождение памяти столбцов матрицы
        ptr2mat_task1[i] = nullptr;  // Удаление столбцов матрицы
    }
    delete[] ptr2mat_task1;  // Освобождение пямяти строк матрицы
    ptr2mat_task1 = nullptr;  // Удаление строк матрицы
    /* End of task1 */
    
    return 0;
}
