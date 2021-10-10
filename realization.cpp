#include <iostream>

using namespace std;


void RandomInit(void)
{
    srand(time(NULL));
}


int** initialize_array(size_t r, size_t c) {
    int** arr = new int* [r];
    for (int i = 0; i < r; i++) {
        arr[i] = new int[c];
    }
    return arr;
}


void input_array(int** array,size_t r, size_t c) {

    for (int i = 0; i < r; i++) {
        for (int j = 0; j < r; j++) {
            cin >> array[i][j];
        }
    }
}
void output_array(int** array, size_t r, size_t c) {
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            cout << array[i][j] << " ";
        }
        cout << "\n";
    }
}

int** random_array(size_t r, size_t c) {
    RandomInit();
    int** arr = new int* [r];
    for (int i = 0; i < r; i++) {
        arr[i] = new int[c];
    }
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            arr[i][j] = 0 + rand() % 10;
        }
    }
    return arr;
}
template<typename T>
T* matrix_to_array(T** arr, size_t r, size_t c)
{
    int* newArr = new T[r * c];

    for (size_t i = 0; i < r; ++i)
    {
        for (size_t j = 0; j < c; ++j)
        {
            newArr[i *c + j] = arr[i][j];
        }
    }

    return newArr;

}


#pragma region SumAndProduct
template<typename T>
T row_sum(T** arr, size_t r, size_t c, size_t row) {
    int sum = 0;
    for (int i = 0; i < c; i++) {
        sum += arr[row][i];
    }
    return sum;
}




template<typename T>
T column_sum(T** arr, size_t r, size_t c, size_t column) {
    int sum = 0;
    for (int i = 0; i < r; i++) {
        sum += arr[i][column];
    }
    return sum;
}




template<typename T>
T main_diagonal_sum(T** arr, size_t r, size_t c) {
    T sum = 0;
    for (int i = 0; i < r; ++i) {
        sum += arr[i][i];
    }
    return sum;
}






template<typename T>
T second_diagonal_sum(T** arr, size_t r, size_t c) {
    T sum = 0;
    for (int i = 0; i < r; ++i) {
        sum += arr[r + i][i];
    }
    return sum;
}




template<typename T>
T row_product(T** arr, size_t r, size_t c, size_t row) {
    int sum = 0;
    for (int i = 0; i < c; i++) {
        sum *= arr[row][i];
    }
    return sum;
}




template<typename T>
T column_product(T** arr, size_t r, size_t c, size_t column) {
    int sum = 0;
    for (int i = 0; i < r; i++) {
        sum *= arr[i][column];
    }
    return sum;
}






template<typename T>
T main_diagonal_product(T** arr, size_t r, size_t c) {
    T sum = 0;
    for (int i = 0; i < r; ++i) {
        sum *= arr[i][i];
    }
    return sum;
}






template<typename T>
T second_diagonal_product(T** arr, size_t r, size_t c) {
    T sum = 0;
    for (int i = 0; i < r; ++i) {
        sum *= arr[r + i][i];
    }
    return sum;
}




#pragma endregion

#pragma region MinAndMax

//Возвращает массив с двумя элементами, строкой и колонкой элемента
template<typename T>
int* IndexOfMinInRow(T** arr, size_t r, size_t c, size_t row) {
    int* min = new int[2];
    min[0] = row;
    min[1] = 0;
    for (int i = 0; i < c; i++) {
        if (arr[min[0]][min[1]] < arr[row][i]) {
            min[1] = i;
        }
    }
    return min;
}

//Возвращает массив с двумя элементами, строкой и колонкой элемента
template<typename T>
int* IndexOfMinInCollumn(T** arr, size_t r, size_t c, size_t Collumn) {
    int* min = new int[2];
    min[0] = 0;
    min[1] = Collumn;
    for (int i = 0; i < c; i++) {
        if (arr[min[0]][min[1]] < arr[i][Collumn]) {
            min[0] = i;
        }
    }
    return min;
}

template<typename T>
int* IndexOfMaxInRow(T** arr, size_t r, size_t c, size_t row) {
    int* min = new int[2];
    min[0] = row;
    min[1] = 0;
    for (int i = 0; i < c; i++) {
        if (arr[min[0]][min[1]] > arr[row][i]) {
            min[1] = i;
        }
    }
    return min;
}

//Возвращает массив с двумя элементами, строкой и колонкой элемента
template<typename T>
int* IndexOfMinInMainDiagonal(T** arr, size_t r, size_t c) {
    int* min = new int[2];
    min[0] = 0;
    min[1] = 0;
    for (int i = 0; i < c; i++) {
        if (arr[min[0]][min[1]] > arr[i][i]) {
            min[0] = i;
            min[1] = i;
        }
    }
    return min;
}

//Возвращает массив с двумя элементами, строкой и колонкой элемента
template<typename T>
int* IndexOfMaxInMainDiagonal(T** arr, size_t r, size_t c) {
    int* min = new int[2];
    min[0] = 0;
    min[1] = 0;
    for (int i = 0; i < c; i++) {
        if (arr[min[0]][min[1]] < arr[i][i]) {
            min[0] = i;
            min[1] = i;
        }
    }
    return min;
}

//Возвращает массив с двумя элементами, строкой и колонкой элемента
template<typename T>
int* IndexOfMinInSecondDiagonal(T** arr, size_t r, size_t c) {
    int* min = new int[2];
    min[0] = 0;
    min[1] = r;
    for (int i = 0; i < c; i++) {
        if (arr[min[0]][min[1]] > arr[r-i][i]) {
            min[0] = i;
            min[1] = r-i;
        }
    }
    return min;
}

//Возвращает массив с двумя элементами, строкой и колонкой элемента
template<typename T>
int* IndexOfMaxInSecondDiagonal(T** arr, size_t r, size_t c) {
    int* min = new int[2];
    min[0] = 0;
    min[1] = r;
    for (int i = 0; i > c; i++) {
        if (arr[min[0]][min[1]] < arr[r - i][i]) {
            min[0] = i;
            min[1] = r - i;
        }
    }
    return min;
}

#pragma endregion

#pragma region Transformations

template<typename T>
T** Transposition(T** arr, size_t r, size_t c) {
    int** transposedArray = initialize_array(r, c);
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            transposedArray[j][i] = arr[i][j];
        }
    }
    return transposedArray;
}

template<typename T>
T** RemoveRow(T** arr, size_t r, size_t c, size_t row) {
    int** newArr = initialize_array(r - 1, c);
    size_t x = 0;
    size_t y = 0;
    for (int i = 0; i < r; i++) {
        if (i != row) {
            for (int j = 0; j < c; j++) {
                newArr[x][y] = arr[i][j];
                y++;
            }
            y = 0;
            x++;
        }
    }
    return newArr;
}


template<typename T>
T** RemoveColumn(T** arr, size_t r, size_t c, size_t column) {
    int** newArr = initialize_array(r, c-1);
    size_t x = 0;
    size_t y = 0;
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            if (j != column) {
                newArr[x][y] = arr[i][j];
                 y++;
            } 
        }
        y = 0;
        x++;
    }
    return newArr;
}


template<typename T>
T** RemoveRowAndColumn(T** arr, size_t r, size_t c,size_t row, size_t column) {
    T** newArr = initialize_array(r - 1, c-1);
    size_t x = 0;
    size_t y = 0;
    for (int i = 0; i < r; i++) {
        if (i != row) {
            for (int j = 0; j < c; j++) {
                if (j != column) {
                    newArr[x][y] = arr[i][j];
                    y++;
                }
            }
            y = 0;
            x++;
        }

    }
    return newArr;
}

template<typename T>
bool IsEqual(T** arr1, T** arr2, size_t r, size_t c) {
    
    for (int i = 0; i < r; ++i) {
        for (int j = 0; j < c; ++j) {
            if (arr1[i][j] != arr2[i][j]) {
                return false;
            }
        }
   }
    return true;
}

#pragma endregion





int main() 
{
    int r, c;
    cin >> r >> c;
    int** arr = initialize_array(r, c);
    int** transposedArr = initialize_array(r, c);
    arr = random_array(r, c);
    output_array(arr, r, c);
    cout << endl;
    transposedArr = Transposition(arr, r, c);
    output_array(transposedArr, r, c);
    cout << endl;

    if (IsEqual(arr, transposedArr, r, c)) {
        cout << "Maxtrix is symmetric"<<endl;
    }
    else {
        cout << "Maxtrix is'n symmetric"<<endl;
    }

    int* min = new int[2];
    min = IndexOfMinInMainDiagonal(arr, r, c);


    int** arr1 = initialize_array(r - 1, c - 1);
    arr1 = RemoveRowAndColumn(arr, r, c, min[0], min[1]);

    output_array(arr1, r-1, c-1);
    cout << endl;


    system("pause");
    return 0;
}