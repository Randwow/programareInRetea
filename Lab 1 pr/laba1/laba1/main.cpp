//
//  main.cpp
//  laba1
//
//  Created by Nikita Makeev on 2/7/22.
//

#include <iostream>
#include <thread>
using namespace std;

void foo(int Z)
{
    for (int i = 0; i < Z; i++) {
        cout << "Поток использует функцию"
            " указатель как вызываемый \n";
    }
}

// Вызываемый объект 1
class thread_obj {
public:
    void operator()(int x)
    {
        for (int i = 0; i < x; i++)
            cout << "Поток использует функцию"
            " объект как вызываемый \n";
    }
};

int main()
{
    setlocale(LC_ALL, "Russian");

    cout << "Потоки 1, 2 , 3  "
        "работают независимо" << endl;

    

    thread th1(foo, 3);


    thread th2(thread_obj(), 3);

    // Определение выражения лямбда
    auto f = [](int x) {
        for (int i = 0; i < x; i++)
            cout << "Поток использует лямбду"
            " выражение как вызываемое \n";
    };

    // Этот поток запускается с использованием
    // выражения лямбда как вызываемого

    thread th3(f, 3);

    // Ожидание завершения потоков

    // Ожидание завершения потока 1

    th1.join();

    // Ожидание завершения потока 2
    th2.join();

    // Ожидание завершения потока 3
    th3.join();

    return 0;
}

