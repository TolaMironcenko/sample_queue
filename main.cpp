//Напишите программу,
//которая читает из файла последовательность целых
//чисел и помещает все четные числа в одну очередь,
//а нечетные – в другую. Содержимое каждой очереди распечатать.
//Для реализации АТД Очередь использовать динамическое распределение памяти.
//
//Под динамическим распределением понимается не использование
//динамического массива, а работа с указателями.
//Вариант с динамическим массивом принят не будет.

#include <iostream>
#include <fstream>

using namespace std;

struct digit{
    int info;
    digit *next;
}; //структура для хранения значений очереди

struct Queue{
    digit *BeginQ;
    digit *EndQ;
}; //структура для хранения указателей начала и конца очереди

void init(Queue &Q){
    Q.BeginQ = nullptr;
    Q.EndQ = nullptr;
} // функция инициализации очереди

bool empty(Queue &Q){
    return (Q.BeginQ == nullptr);
} // функция проверки пустоты очереди

void push(int val, Queue &Q){
    digit *p = new digit;
    p->info = val;
    p->next = nullptr;
    if(empty(Q))
        Q.BeginQ = p;
    else
        Q.EndQ->next = p;
    Q.EndQ = p;
} // функция заталкивания элемента в очередь

int pop(Queue &Q){
    if (!empty(Q)) {
        int val;
        digit *p;
        p = Q.BeginQ;
        val = Q.BeginQ->info;
        Q.BeginQ = p->next;
        if (Q.BeginQ == nullptr)
            Q.EndQ = nullptr;
        delete p;
        return val;
    } else {cout<<"очередь пустая"<<endl;return 0;}
} // функция выьягивания элемента из очереди

int front(Queue &Q){
    if(empty(Q)){cout<<"очередь пустая"<<endl;return 0;}else{return Q.BeginQ->info;}
} // функция возвращающая первый элемент в очереди

void DeleteQ(Queue Q){
    while(!empty(Q)){
        pop(Q);
    }
}

int main() {
    int buff;
    Queue *chet = new Queue;  //обьявление четной очереди
    Queue *nechet = new Queue;  //обьявление нечетной очереди
    init(*chet); //инициализация четной очереди
    init(*nechet); //инициализация нечетной очереди

//    cout<<empty(*chet)<<endl<<empty(*nechet)<<endl;

    ifstream fin;
    fin.open("input.txt");

    while (fin>>buff){
        if(buff % 2 == 0){
            push(buff, *chet);
        }else{
            push(buff, *nechet);
        }
    } //цикл проверяет и записывает число в нужную очередь

//    cout<<empty(*chet)<<endl<<empty(*nechet)<<endl;
//    cout<<endl<<front(*chet)<<" "<<front(*nechet)<<endl<<back(*chet)<<" "<<back(*nechet)<<endl;

    cout<<"четные числа:"<<endl; //вывод четной очереди
    while (!empty(*chet)){
        cout<<pop(*chet)<<" ";
    }

    cout<<endl;

    cout<<"нечетные числа:"<<endl; //вывод нечетной очереди
    while (!empty(*nechet)){
        cout<<pop(*nechet)<<" ";
    }

    DeleteQ(*chet);
    DeleteQ(*nechet);

    return 0;
}
