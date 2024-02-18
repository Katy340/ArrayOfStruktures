/*������� 14
1. ������� ��������� � ������ N���, ���������� ��������� ����:
�	N�M� - �������, ���;
�	��L� - ����� ��������;
�	�DAY - ���� �������� (������ �� ���� �����).
2. �������� ���������, ����������� ��������� ��������:
�	���� � ���������� ������ � ������ �L���N���, ��������� �� ������ ��������� ���� N���; ������ ������ ���� ����������� �� ���� ������ ������ ������ ��������;
�	����� �� ����� ���������� � ��������, ��� ������� ������� � ����������;
�	���� ������ ���, ������ �� ������� ��������������� ���������.*/

#include <iostream>
#include <string>
#include <algorithm> // ��� ������������� ������� ���������� std::sort
#include<iomanip>

using namespace std;

// �������� ��������� NOTE
struct NOTE
{
    wstring NAME;    // �������, ���
    string TELE;    // ����� ��������
    int BDAY[3];    // ���� �������� (������ �� ���� �����)
};

// ������� ��� ��������� �� ���� ������ ������ ������ ��������
bool compareTele(const NOTE &note1, const NOTE &note2) {
    string tele1_prefix = note1.TELE.substr(0, 3);
    string tele2_prefix = note2.TELE.substr(0, 3);
    return tele1_prefix < tele2_prefix;
}

int main() {
    const int MAX_NOTES = 2;
    NOTE notes[MAX_NOTES];

    // ���� ������ � ����������
    for (int i = 0; i < MAX_NOTES; i++) {
        wcout << L"Enter record #" << i + 1 << L":" << endl;
        wcout << L"\tName: ";

        getline(wcin, notes[i].NAME);


        cout << "\tPhone number: ";
        getline(cin, notes[i].TELE);

        cout << "\tBirthday (day month year): ";
        cin >> notes[i].BDAY[0] >> notes[i].BDAY[1] >> notes[i].BDAY[2];
        cin.ignore(); // ������� ����� �����

        cout << endl; // ��������� ������ ������ ��� ��������� ����������� ��������������
    }

    // ���������� ������� ������� �� ���� ������ ������ ������ ��������
    sort(notes, notes + MAX_NOTES, compareTele);

    // ����� ��������������� �������
    wcout << L"Sorted records by phone number:" << endl;
        for (int i = 0; i < MAX_NOTES; i++) {
    wcout << setw(15) << left << notes[i].NAME.c_str() << setw(15) << left << notes[i].TELE.c_str() << setw(15) << left << notes[i].BDAY[0] << L" " << setw(2) << left << notes[i].BDAY[1] << L" " << setw(4) << left << notes[i].BDAY[2] << endl;
    }


    // ����� �� �������
    wcout << L"Enter surname for search: ";
    wstring search_name;

    getline(wcin, search_name);

    bool found = false;
    for (int i = 0; i < MAX_NOTES; i++) {
        if (notes[i].NAME == search_name) {
            wcout << L"Information about the person with surname " << search_name << L":" << endl;
            wcout << L"Name: " << notes[i].NAME << endl;
            cout << "Phone number: " << notes[i].TELE << endl;
            cout << "Birthday: " << notes[i].BDAY[0] << " " << notes[i].BDAY[1] << " " << notes[i].BDAY[2] << endl;
            found = true;
            break;
        }
    }

    // ���� ������ �� �������
    if (!found) {
        wcout << L"No person with surname " << search_name << L" found." << endl;
    }

    return 0;
}
