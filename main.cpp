
#include <iostream>
#include <vector>
#include <cstdlib> //для rand

class ArrayInt3D {
protected:
    int nr, nc, nd;  // рядки, стовпці, глибина
    std::vector<std::vector<std::vector<int>>> a;  // тривимірний масив

public:
    ArrayInt3D(int N_Rows, int N_Columns, int N_Depth) : nr(N_Rows), nc(N_Columns), nd(N_Depth) {
        a.resize(nr, std::vector<std::vector<int>>(nc, std::vector<int>(nd)));
        std::cout << nr << "x" << nc << "x" << nd << std::endl;

        for (int i = 0; i < nr; ++i)
            for (int j = 0; j < nc; ++j)
                for (int k = 0; k < nd; ++k) {
                    std::cout << "a[" << i << "][" << j << "][" << k << "]: ";
                    std::cin >> a[i][j][k];
                }
    }

    ArrayInt3D(int NR, int NC, int ND, int max) : nr(NR), nc(NC), nd(ND) {
        a.resize(nr, std::vector<std::vector<int>>(nc, std::vector<int>(nd)));
        for (int i = 0; i < nr; ++i)
            for (int j = 0; j < nc; ++j)
                for (int k = 0; k < nd; ++k)
                    a[i][j][k] = rand() % (max + 1);
    }

    ArrayInt3D(int NR, int NC, int ND, int min, int max) : nr(NR), nc(NC), nd(ND) {
        a.resize(nr, std::vector<std::vector<int>>(nc, std::vector<int>(nd)));
        for (int i = 0; i < nr; ++i)
            for (int j = 0; j < nc; ++j)
                for (int k = 0; k < nd; ++k)
                    a[i][j][k] = min + rand() % (max - min + 1);
    }

    void ArrayInt_Out(const std::string& info) {
        std::cout << info << std::endl;
        for (int i = 0; i < nr; ++i) {
            for (int j = 0; j < nc; ++j) {
                for (int k = 0; k < nd; ++k)
                    std::cout << a[i][j][k] << "\t";
                std::cout << std::endl;
            }
            std::cout << std::endl;
        }
    }

    int Min_Array(int& kr, int& kc, int& kd) {
        int min = 2147483647; // маскимальне інтовське значення
        kr = kc = kd = 0;
        for (int i = 0; i < nr; ++i)
            for (int j = 0; j < nc; ++j)
                for (int k = 0; k < nd; ++k)
                    if (a[i][j][k] < min) {
                        min = a[i][j][k];
                        kr = i;
                        kc = j;
                        kd = k;
                    }
        return min;
    }

    int Max_Array(int& kr, int& kc, int& kd) {
        int max = -2147483648; // мінимальне інтовське занчення
        kr = kc = kd = 0;
        for (int i = 0; i < nr; ++i)
            for (int j = 0; j < nc; ++j)
                for (int k = 0; k < nd; ++k)
                    if (a[i][j][k] > max) {
                        max = a[i][j][k];
                        kr = i;
                        kc = j;
                        kd = k;
                    }
        return max;
    }

    void Set_Element(int kr, int kc, int kd, int elem) {
        if (kr >= 0 && kr < nr && kc >= 0 && kc < nc && kd >= 0 && kd < nd)
            a[kr][kc][kd] = elem;
    }

    int Get_Element(int kr, int kc, int kd) {
        if (kr >= 0 && kr < nr && kc >= 0 && kc < nc && kd >= 0 && kd < nd)
            return a[kr][kc][kd];
    }
};

int main() {
    // тест рандомного масиву
    ArrayInt3D arr = ArrayInt3D(2,3,4,1,10);
    arr.ArrayInt_Out("test");

    // min ta max
    int minRow, minCol, minDepth;
    int maxRow, maxCol, maxDepth;

    int minValue = arr.Min_Array(minRow, minCol, minDepth);
    std::cout << "Мінімальне значення: " << minValue << " на позиції [" << minRow << "][" << minCol << "][" << minDepth << "]" << std::endl;


    int maxValue = arr.Max_Array(maxRow, maxCol, maxDepth);
    std::cout << "Максимальне значення: " << maxValue << " на позиції [" << maxRow << "][" << maxCol << "][" << maxDepth << "]" << std::endl;

    //тест гетеров та сетеров
    arr.Set_Element(1, 1, 1, 100); // Встановлення
    int getElementValue = arr.Get_Element(1, 1, 1);
    std::cout << "Значення встановленого елементу: " << getElementValue << std::endl;

    arr.ArrayInt_Out("test 2");



    return 0;
}
