#include <iostream>
#include <cstdint>

/// <summary>
/// Точка
/// </summary>
struct Point
{
    /// <summary>
    /// Позиция по оси X
    /// </summary>
    double_t x;

    /// <summary>
    /// Позиция по оси Y
    /// </summary>
    double_t y;

    Point(double_t x, double_t y): x(x), y(y)
    { }
};

/// <summary>
/// Меняет значения местами
/// </summary>
/// <typeparam name="T">Тип данных значений</typeparam>
/// <param name="first">Указатель на первое значение</param>
/// <param name="second">Указатель на второе значение</param>
template<typename T>
void swap(T *first, T *second)
{
    T third = *first;
    *first = *second;
    *second = third;
}

/// <summary>
/// Умножает все элементы массива на 2
/// </summary>
/// <typeparam name="T">Тип данных элементов</typeparam>
/// <param name="array">Указатель на массив</param>
/// <param name="size">Размер массива</param>
template<typename T>
void multiply(T* array, const size_t& size)
{
    for (size_t i = 0; i < size; i++)
        array[i] = array[i] * 2;
}

/// <summary>
/// Изменяет значения позиции точки на заданные значения
/// </summary>
/// <param name="point">Указатель на точку</param>
/// <param name="x">Заданное значение позиции по оси X</param>
/// <param name="y">Заданное значение позиции по оси Y</param>
void point_set(struct Point* point, const double_t &x, const double_t &y)
{
    point->x = x;
    point->y = y;
}

int main(void)
{
    {
        // Задание 1: Основы ссылок
        int64_t value = 8;

        int64_t* pointer_to_value = &value;
        std::cout << "value = " << *pointer_to_value << std::endl;

        (*pointer_to_value) *= 2;
        std::cout << "value = " << *pointer_to_value << "\n\n";
    }

    {
        // NOTE: Задание 2: Ссылки в функциях
        int64_t first_value = 1, second_value = 2;

        std::cout << "first_value = " << first_value << std::endl;
        std::cout << "second_value = " << second_value << "\n\n";

        swap<int64_t>(&first_value, &second_value);

        std::cout << "first_value = " << first_value << std::endl;
        std::cout << "second_value = " << second_value << "\n\n";
    }

    {
        // Задание 3: Ссылки и массивы
        const size_t array_size = 5;
        int64_t array[array_size] = { 1, 2, 3, 4, 5 };

        std::cout << "array = [ ";
        for (size_t i = 0; i < array_size; i++)
            std::cout << array[i] << ", ";
        std::cout << "]" << std::endl;

        multiply<int64_t>(array, array_size);

        std::cout << "array = [ ";
        for (size_t i = 0; i < array_size; i++)
            std::cout << array[i] << ", ";
        std::cout << "]" << "\n\n";
    }

    {
        // Задание 4: Ссылки и структуры
        struct Point point(2, 4);
        std::cout << "point = { " << point.x << ", " << point.y << " }" << std::endl;

        point_set(&point, 4, 3.14);
        std::cout << "point = { " << point.x << ", " << point.y << " }" << "\n\n";
    }
}
