// NOD.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>

#ifdef _WIN32
#include <windows.h>
#endif

bool FixFlow()
{
    if (std::cin.fail()) {
        std::cin.clear();
        std::cin.ignore();
        fflush(stdin);
        return true;
        //        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }
    else
    {
        return false;
    }
}


template <typename T>
void Input(T& side1, const std::string& message)
{
    do
    {
        std::cout << message << '\n';
        std::cin >> side1;
    } while (FixFlow());
}

void  SwapIfALessB(int& a, int& b)
{
    if (a < b)
    {
        int c = a;
        a = b;
        b = c;
    }
}

int Nod(int a, int b)
{
     SwapIfALessB(a, b);
    if (a % b == 0)
    {
        return b;
    }
    else
    {
        Nod(b, a % b);
    }
}



int main()
{
#ifdef _WIN32
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
#endif
    int a = 0;
    int b = 0;
    Input(a, "Введите первое число ");
    Input(b, "Введите второе число ");
    std::cout << "Наибольший общий делитель равен" << Nod(a, b);
    return 0;
}

// Запуск программы: CTRL+F5 или меню "Отладка" > "Запуск без отладки"
// Отладка программы: F5 или меню "Отладка" > "Запустить отладку"

// Советы по началу работы 
//   1. В окне обозревателя решений можно добавлять файлы и управлять ими.
//   2. В окне Team Explorer можно подключиться к системе управления версиями.
//   3. В окне "Выходные данные" можно просматривать выходные данные сборки и другие сообщения.
//   4. В окне "Список ошибок" можно просматривать ошибки.
//   5. Последовательно выберите пункты меню "Проект" > "Добавить новый элемент", чтобы создать файлы кода, или "Проект" > "Добавить существующий элемент", чтобы добавить в проект существующие файлы кода.
//   6. Чтобы снова открыть этот проект позже, выберите пункты меню "Файл" > "Открыть" > "Проект" и выберите SLN-файл.
