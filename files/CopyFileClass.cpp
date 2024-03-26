#include <fstream>
#include "CopyFileClass.h"

int CopyFileClass::CopyFileVoid(wchar_t* fileName, wchar_t* newFileName) {
    std::wifstream infile{};
    std::wofstream outfile{};

    infile.open(fileName);
    outfile.open(newFileName);

    wchar_t buffer[1000];        //������ ��� ������

    while (!infile.eof())        //���� �� ����� ��������� �����
    {
        infile.getline(buffer, sizeof(buffer));  //������ ���������
        outfile << buffer << std::endl;                  //���������� ������ � �������� ����
    }

    infile.close();     //���������
    outfile.close();    //�����

    return 0;
};