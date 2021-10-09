#include <iostream>
#include <fstream>
#include <string>
#include <cmath>
#include <ctime>

using namespace std;

// UTILITY 

#define ARRAY_SIZE(ARRAY) sizeof(ARRAY) / sizeof(ARRAY[0])

void rand_init(void)
{
    srand(time(NULL));
}

int rand_range(int bottom, int top)
{
    return bottom + rand() % (top - bottom + 1);
}

float rand_range(int bottom, int top, int digits)
{
    return (bottom + rand() % (top - bottom + 1)) / (float)digits;
}

// INITIALIZATION

int* array_initialize_with_random_value_int( size_t l, size_t r)
{
    int* array = new int[l * r];
    rand_init();
    for (size_t i = 0; i < l; ++i)
        for (size_t j = 0; j < r; ++j)
        array[i*r+j] = std::rand()%10;
    return array;
}

float* array_initialize_with_random_value_float(size_t l, size_t r)
{
    float* array = new float[l * r];
    rand_init();
    for (size_t i = 0; i < l; ++i)
        for (size_t j = 0; j < r; ++j)
            array[i * r + j] = std::rand()/.10f;
    return array;
}

// SUM & MULTIPLY

int array_sum(int* array, size_t l, size_t r, size_t from_x, size_t from_y, size_t to_x, size_t to_y, bool (*predicate)(int value))
{
    int sum = 0;
    for (size_t i = from_x; i < to_x; ++i)
        for (size_t j = from_y; j<to_y;j++)
        if (predicate(array[i*r+j]))
            sum += array[i*r+j];

    return sum;
}

float array_sum(float* array, size_t size, size_t from, size_t to, bool (*predicate)(float value))
{
    float sum = 0;
    for (size_t i = from; i < to; ++i)
        if (predicate(array[i]))
            sum += array[i];

    return sum;
}

int array_multiply(int* array, size_t size, size_t from, size_t to, bool (*predicate)(int value))
{
    int res = 1;
    for (size_t i = from; i < to; ++i)
        if (predicate(array[i]))
            res *= array[i];

    return res;
}

float array_multiply(float* array, size_t size, size_t from, size_t to, bool (*predicate)(float value))
{
    float res = 1;
    for (size_t i = from; i < to; ++i)
        if (predicate(array[i]))
            res *= array[i];

    return res;
}

// INSERT / ERASE ELEMENT & SHIFT

void array_right_shift(int* array, size_t size, size_t startIndex)
{
    for (size_t i = size - 1; i > startIndex; --i)
    {
        array[i] = array[i - 1];
    }
}

void array_right_shift(float* array, size_t size, size_t startIndex)
{
    for (size_t i = size - 1; i > startIndex; --i)
    {
        array[i] = array[i - 1];
    }
}

void array_left_shift(int* array, size_t size, size_t startIndex)
{
    for (size_t i = startIndex; i < size - 1; ++i)
    {
        array[i] = array[i + 1];
    }
}

void array_left_shift(float* array, size_t size, size_t startIndex)
{
    for (size_t i = startIndex; i < size - 1; ++i)
    {
        array[i] = array[i + 1];
    }
}

void array_insert(int* array, size_t size, size_t index, int value, int** out_array, size_t* out_size)
{
    int* array_temp = new int[size + 1];

    for (size_t i = 0; i < size + 1; ++i)
        array_temp[i] = array[i];

    delete[] array;

    array_right_shift(array_temp, size + 1, index);

    array_temp[index] = value;

    *out_array = array_temp;
    *out_size = size + 1;
}

void array_insert(float* array, size_t size, size_t index, float value, float** out_array, size_t* out_size)
{
    float* array_temp = new float[size + 1];

    for (size_t i = 0; i < size + 1; ++i)
        array_temp[i] = array[i];

    delete[] array;

    array_right_shift(array_temp, size + 1, index);

    array_temp[index] = value;

    *out_array = array_temp;
    *out_size = size + 1;
}

void array_erase(int* array, size_t size, size_t index, int** out_array, size_t* out_size)
{
    int* array_temp = new int[size - 1];

    array_left_shift(array, size, index);

    for (size_t i = 0; i < size - 1; ++i)
        array_temp[i] = array[i];

    delete[] array;

    *out_array = array_temp;
    *out_size = size - 1;
}

void array_erase(float* array, size_t size, size_t index, float** out_array, size_t* out_size)
{
    float* array_temp = new float[size - 1];

    array_left_shift(array, size, index);

    for (size_t i = 0; i < size - 1; ++i)
        array_temp[i] = array[i];

    delete[] array;

    *out_array = array_temp;
    *out_size = size - 1;
}

// SORTING

void array_bubble_sort(int* array, size_t size)
{
    for (size_t j = 1; j < size; ++j)
        for (size_t i = 0; i < size - j; ++i)
        {
            if (array[i + 1] < array[i])
            {
                int temp = array[i + 1];
                array[i + 1] = array[i];
                array[i] = temp;
            }
        }
}

void array_bubble_sort(float* array, size_t size)
{
    for (size_t j = 1; j < size; ++j)
        for (size_t i = 0; i < size - j; ++i)
        {
            if (array[i + 1] < array[i])
            {
                float temp = array[i + 1];
                array[i + 1] = array[i];
                array[i] = temp;
            }
        }
}

void array_selection_sort(int* array, size_t size)
{
    for (size_t i = 0; i < size; ++i)
    {
        size_t min_index = i;

        for (size_t j = i + 1; j < size; ++j)
        {
            if (array[j] < array[min_index])
                min_index = j;
        }

        if (min_index != i)
        {
            int temp = array[i];
            array[i] = array[min_index];
            array[min_index] = temp;
        }
    }
}

void array_selection_sort(float* array, size_t size)
{
    for (size_t i = 0; i < size; ++i)
    {
        size_t min_index = i;

        for (size_t j = i + 1; j < size; ++j)
        {
            if (array[j] < array[min_index])
                min_index = j;
        }

        if (min_index != i)
        {
            float temp = array[i];
            array[i] = array[min_index];
            array[min_index] = temp;
        }
    }
}

void array_shaker_sort(int* array, size_t size)
{
    int control = size - 1;
    int left = 0;
    int right = size - 1;
    do {
        for (int i = left; i < right; i++) {
            if (array[i] > array[i + 1])
            {
                int temp = array[i];
                array[i] = array[i + 1];
                array[i + 1] = temp;
                control = i;
            }
        }
        right = control;
        for (int i = right; i > left; i--) {
            if (array[i] < array[i - 1])
            {
                int temp = array[i];
                array[i] = array[i - 1];
                array[i - 1] = temp;
                control = i;
            }
        }
        left = control;
    } while (left < right);
}

void array_shaker_sort(float* array, size_t size)
{
    int control = size - 1;
    int left = 0;
    int right = size - 1;
    do {
        for (int i = left; i < right; i++) {
            if (array[i] > array[i + 1])
            {
                float temp = array[i];
                array[i] = array[i + 1];
                array[i + 1] = temp;
                control = i;
            }
        }
        right = control;
        for (int i = right; i > left; i--) {
            if (array[i] < array[i - 1])
            {
                float temp = array[i];
                array[i] = array[i - 1];
                array[i - 1] = temp;
                control = i;
            }
        }
        left = control;
    } while (left < right);
}

// LINEAR-SEARCH

size_t array_find_max_value_index(int* array, size_t size)
{
    size_t maxIndex = 0;
    for (size_t i = 0; i < size; ++i)
    {
        if (array[i] > array[maxIndex])
            maxIndex = i;
    }

    return maxIndex;
}

size_t array_find_max_value_index(float* array, size_t size)
{
    size_t maxIndex = 0;
    for (size_t i = 0; i < size; ++i)
    {
        if (array[i] > array[maxIndex])
            maxIndex = i;
    }

    return maxIndex;
}

size_t array_find_min_value_index(int* array, size_t size)
{
    size_t minIndex = 0;
    for (size_t i = 0; i < size; ++i)
    {
        if (array[i] < array[minIndex])
            minIndex = i;
    }

    return minIndex;
}

size_t array_find_min_value_index(float* array, size_t size)
{
    size_t minIndex = 0;
    for (size_t i = 0; i < size; ++i)
    {
        if (array[i] < array[minIndex])
            minIndex = i;
    }

    return minIndex;
}

size_t array_find(int* array, size_t size, bool (*predicate)(int value))
{
    for (size_t i = 0; i < size; ++i)
        if (predicate(array[i]))
            return i;

    return -1;
}

size_t array_find(float* array, size_t size, bool (*predicate)(float value))
{
    for (size_t i = 0; i < size; ++i)
        if (predicate(array[i]))
            return i;

    return -1;
}

size_t array_find_reverse(int* array, size_t size, bool (*predicate)(int value))
{
    for (size_t i = size - 1; i >= 0; --i)
        if (predicate(array[i]))
            return i;

    return -1;
}

size_t array_find_reverse(float* array, size_t size, bool (*predicate)(float value))
{
    for (size_t i = size - 1; i >= 0; --i)
        if (predicate(array[i]))
            return i;

    return -1;
}

// BINARY_SEARCH

size_t array_bsearch(int* array, size_t size, int value)
{
    size_t left = 0;
    size_t right = size;
    size_t middle = 0;

    while (left <= right)
    {
        middle = (left + right) / 2;

        if (array[middle] < value)
            left = middle + 1;
        else if (array[middle] > value)
            right = middle - 1;
        else
            return middle;
    }

    return -1;
}

size_t array_bsearch(float* array, size_t size, float value)
{
    size_t left = 0;
    size_t right = size;
    size_t middle = 0;

    while (left <= right)
    {
        middle = (left + right) / 2;

        if (array[middle] < value)
            left = middle + 1;
        else if (array[middle] > value)
            right = middle - 1;
        else
            return middle;
    }

    return -1;
}

// COUNT ELEMENTS

size_t array_count(int* array, size_t size, bool (*predicate)(int value))
{
    size_t count = 0;
    for (size_t i = 0; i < size; ++i)
        if (predicate(array[i]))
            count++;

    return count;
}

size_t array_count(float* array, size_t size, bool (*predicate)(float value))
{
    size_t count = 0;
    for (size_t i = 0; i < size; ++i)
        if (predicate(array[i]))
            count++;

    return count;
}

// INPUT / OUTPUT

void array_std_input(int* array, size_t size)
{
    std::cout << "Enter " << size << "elements" << std::endl;

    for (size_t i = 0; i < size; ++i)
    {
        std::cout << "array[" << i << "] = " << array[i];
        std::cin >> array[i];
    }
}

void array_std_input(float* array, size_t size)
{
    std::cout << "Enter " << size << "elements" << std::endl;

    for (size_t i = 0; i < size; ++i)
    {
        std::cout << "array[" << i << "] = " << array[i];
        std::cin >> array[i];
    }
}

void array_file_input(int** out_array, size_t* out_size, const char* fileName)
{
    std::ifstream file(fileName);
    std::string value;
    size_t size;


    file >> value;

    size = std::stoll(value);

    int* array = new int[size];

    for (size_t i = 0; i < size; ++i)
    {
        file >> value;
        array[i] = std::stoi(value);
    }

    file.close();

    *out_size = size;
    *out_array = array;
}

void array_file_input(float** out_array, size_t* out_size, const char* fileName)
{
    std::ifstream file(fileName);
    std::string value;
    size_t size;


    file >> value;

    size = std::stoll(value);

    float* array = new float[size];

    for (size_t i = 0; i < size; ++i)
    {
        file >> value;
        array[i] = std::stof(value);
    }

    file.close();

    *out_size = size;
    *out_array = array;
}

void array_binfile_input(int** out_array, size_t* out_size, const char* fileName)
{
    std::ifstream file(fileName);

    size_t size;

    file.read(reinterpret_cast<char*>(&size), sizeof(size_t));

    int* array = new int[size];

    for (size_t i = 0; i < size; ++i)
    {
        file.read(reinterpret_cast<char*>(&array[i]), sizeof(int));
    }

    file.close();

    *out_array = array;
}

void array_binfile_input(float** out_array, size_t* out_size, const char* fileName)
{
    std::ifstream file(fileName);

    size_t size;

    file.read(reinterpret_cast<char*>(&size), sizeof(size_t));

    float* array = new float[size];

    for (size_t i = 0; i < size; ++i)
    {
        file.read(reinterpret_cast<char*>(&array[i]), sizeof(float));
    }

    file.close();

    *out_array = array;
}

void array_std_output(int* array, size_t lines, size_t rows)
{
    for (size_t i = 0; i < lines; ++i) {
        for (size_t j = 0; j < rows; ++j)
            cout << array[i * rows + j] << " ";
        cout << endl;
    }
}

void array_std_output(float* array, size_t lines, size_t rows)
{
    for (size_t i = 0; i < lines; ++i) {
        for (size_t j = 0; j < rows; ++j)
            cout << array[i * rows + j] << " ";
        cout << endl;
    }
}

void array_file_output(int* array, size_t size, const char* fileName)
{
    std::ofstream file(fileName);
    std::string value;

    value = std::to_string(size);

    file.write(value.c_str(), value.size());
    file.put('\n');

    for (size_t i = 0; i < size; ++i)
    {
        value = std::to_string(array[i]);
        file.write(value.c_str(), value.size());
        file.put('\n');
    }

    file.close();
}

void array_file_output(float* array, size_t size, const char* fileName)
{
    std::ofstream file(fileName);
    std::string value;

    value = std::to_string(size);

    file.write(value.c_str(), value.size());
    file.put('\n');

    for (size_t i = 0; i < size; ++i)
    {
        value = std::to_string(array[i]);
        file.write(value.c_str(), value.size());
        file.put('\n');
    }

    file.close();
}

void array_binfile_output(int* array, size_t size, const char* fileName)
{
    std::ofstream file(fileName);

    file.write(reinterpret_cast<char*>(&size), sizeof(size_t));

    for (size_t i = 0; i < size; ++i)
    {
        file.write(reinterpret_cast<char*>(&array[i]), sizeof(int));
    }

    file.close();
}

void array_binfile_output(float* array, size_t size, const char* fileName)
{
    std::ofstream file(fileName);

    file.write(reinterpret_cast<char*>(&size), sizeof(size_t));

    for (size_t i = 0; i < size; ++i)
    {
        file.write(reinterpret_cast<char*>(&array[i]), sizeof(float));
    }

    file.close();
}

template<typename T>
T* Transpose(T* array, size_t l, size_t r) {
    T* transposedArray = new T[l * r];
    for (size_t i = 0; i < l; ++i)
        for (size_t j = 0; j < r; ++j)
            transposedArray[j * r + i] = array[i * r + j];
    return transposedArray;
}

template<typename T>
int MinRow(T* array, size_t l, size_t r) {
    T temp = numeric_limits<T>().max();
    int tempid = 0;
    for (size_t i = 0; i < l; ++i) {
        if (array[i * r + i] <= temp) {
            temp = array[i * r + i];
            tempid = r;
        }
    }
    return tempid;
}


// PREDICATES

bool predicate_true(int value)
{
    return true;
}

bool predicate_true(float value)
{
    return true;
}

bool predicate_false(int value)
{
    return false;
}

bool predicate_false(float value)
{
    return false;
}

bool predicate_positive(int value)
{
    return value >= 0;
}

bool predicate_positive(float value)
{
    return value >= 0.f;
}

bool predicate_negative(int value)
{
    return value < 0;
}

bool predicate_negative(float value)
{
    return value < 0.f;
}

int main(void)
{
    size_t lines, rows;
    cin >> lines >> rows;
    int* arr = array_initialize_with_random_value_int(lines, rows);
    array_std_output(arr, lines, rows);
    arr = Transpose(arr, lines, rows);
    array_std_output(arr, lines, rows);

    int minRow = MinRow(arr, lines, rows);


    cout << minRow;





}