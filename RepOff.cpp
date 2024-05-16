#define _CRT_SECURE_NO_WARNINGS 
#include <iostream>
#include <string>
#include <string.h>
#include <sstream>
#include <Windows.h>
#include <vector>

using namespace std;

string ClearStr(string DirtStr) 
{
    setlocale(LC_ALL, "Russian");
    string result; // переменная вывода чистой строки
    string nStr(DirtStr); // переменная для работы с заданой строкой
    char num; // переменная для посимвольной обработки
    bool flag = false; // переменная для контроля кл-ва пробелов

    for (int i = 0; i < size(nStr); i++)// цикл по символам строки удаляющий лишние символы и пробелы
    {
        num = nStr[i];
        if ((num > 96 && num < 123) || (num > 128 && num < 155) || (num > -65 && num < 0) || num == -72 || num == -88) // обработка значений строк для русского и латинского алфавитов // -72 == ё  // -88 == Ё
        {
            result += num; // записываем в строку символ
            flag = true; // значит можно ставить пробел
        }
        else
            if (flag)
            {
                result += " "; // добавление разделителя
                flag = false; // нельзя ставить пробел
            }
    }

    // напишем обработчик повторяющихся слов
    string pice; // переменная для принятия слов из n2Str
    stringstream n2Str(result); // переменная для простой передачи слов
    vector<string> stor, ban;
    result = ""; // очищаем переменную для последующего использования

    while (n2Str >> pice) // по разделителю получаем слова
        stor.push_back(pice); // заполняем вектор всеми словами

    for (int i = 0; i < size(stor); i++) // 
    {
        char* pi1 = new char[stor[i].size()]; // костыль, но надо же как-то использовать указаные функции
        int dubl = 0;
        
        strcpy(pi1, stor[i].c_str()); // создадим динамический массив символов
        for (int j = 0; j < size(stor); j++) // запишем в него нашу строку
        {
            char* pi2 = new char[stor[j].size()]; 
            strcpy(pi2, stor[j].c_str()); 

            if (strcmp(pi1, pi2) == 0) // проверяем одинаковы ли строки
                dubl++;
        }
        if (dubl==1) // если повторений в тексте больше чем 1
            result += stor[i] + " ";
    }
    
    return result;
}

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    setlocale(LC_ALL, "Russian");
    string str, NeatStr;
    cout << "Введите строку: ";
    getline(cin, str); // ввод строки

    NeatStr = ClearStr(str); // обработка строки

    cout <<"\n" << "Обработаная строка: " << NeatStr; // вывод строки
}
