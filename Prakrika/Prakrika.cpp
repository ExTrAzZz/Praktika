#include <iostream>
#include <conio.h>
#include <string>
#include <fstream>
#include <vector>
using namespace std;

int linear_search(vector<string> vect, string item)
{
    for (int i = 0; i < vect.size(); i++)
    {
        if (vect[i] == item)
        {
            return i; // элемент найден
        }
    }
    return -1;
}
int binary_search(vector<string> vect, string item)
{
    int low = 0;
    int high = vect.size() - 1;
    int mid;
    while (low <= high) 
    { // нахождение элемента-границы
        mid = (low + high) / 2;
        if(vect[mid] < item) 
        {
            low = mid + 1;
        } // обращаемся выше элемента-границы
        else if (vect[mid] > item) 
        {
            high = mid - 1; // обращаемся ниже элемента-границы
        }
        else  //элемент найден
            return mid;
    }
    return -1; // элемент не найден
}

int main()
{
    setlocale(LC_ALL, "Russian");
    int num, indItem;
    string item;
    cout << "Вас приветствует программа бинарного и линейного поиска." << endl;
    cout << "Введите элемент  поиска: ";
    cin >> item; // Элемент который ищем
    cout << "Выберите метод поиска (бинарный(1), линейный(2)): ";
    cin >> num;
    if ((num == 1) or (num == 2)) // Выбор поиска
    {
        string* FileName = new string;
        string ReFile;
        while (true)
        {
            cout << "Введите имя файла: ";
            cin >> *FileName; // Ввод имени файла
            ifstream PerFile(*FileName);
            if (!PerFile.is_open()) // Неоткрыт файл?
            {
                cout << "Файл с заданным именем не найден" << endl;
                delete FileName;
                string* FileName = new string;
            }
            else
            {
                PerFile.close(); // Закрыть файл
                ReFile = *FileName;
                break;
            }
        }
        ifstream PerFile(ReFile);
        int i = 0;
        string s;
        vector<string> myVector;
        while (!PerFile.eof()) // Пока не конец файла
        {
            PerFile >> s;
            myVector.insert(myVector.end(), s);
            i++;
        }
        PerFile.close();
        switch (num) // Выбор линейный или бинарный
        {
            case 1:
                indItem = binary_search(myVector, item);
                break;
            case 2:
                indItem = linear_search(myVector, item);
                break;
        }
        if (indItem != -1)
        {
            cout << "Элемент " + myVector[indItem]+" был найден в последовательности.";
        }
        else cout << "Нету такого элемента";

    }
    else
    {
        cout << "Ошибка ввода";
        return -1;
        exit;
    }
    _getch();
}