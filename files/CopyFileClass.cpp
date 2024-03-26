#include <fstream>
#include "CopyFileClass.h"

int CopyFileClass::CopyFileVoid(wchar_t* fileName, wchar_t* newFileName) {
    std::wifstream infile{};
    std::wofstream outfile{};

    infile.open(fileName);
    outfile.open(newFileName);

    wchar_t buffer[1000];        //буффер под строку

    while (!infile.eof())        //пока не конец исходного файла
    {
        infile.getline(buffer, sizeof(buffer));  //читаем построчно
        outfile << buffer << std::endl;                  //записываем строку в выходной файл
    }

    infile.close();     //закрываем
    outfile.close();    //файлы

    return 0;
};