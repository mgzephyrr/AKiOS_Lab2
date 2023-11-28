#include "includes.h"

// � ������ ����� ��������� ��� �������, ���������� �� ������-������ ����������������� �������������� �� ���� ����� ������ (���������� FIFO)

/// <summary>
/// ������� ��� ������� �������� ����������������� �������������� �� ���� ����� ������ � ����������� FIFO
/// </summary>
/// <returns> ������, � ������� ��������� ��� ��������� �� ������ � ����� ������ ���������� "������" </returns>
tuple<SLTFElem*, SLTFElem*> MakeSLTF() {
    string name;
    int ratingPlace;
    SLTFElem* headByName = nullptr;
    SLTFElem* headByRating = nullptr;
    SLTFElem* current = nullptr;

    cout << "������� ��� �������� (0 - ����� �����): > ";
    cin >> name; // ����� ������ ���� ��� �����, ����� ������ ��������, ����� ����� ����� 0 � �������� � ���� ������ ������ ������

    if (name != "0") { // ���� ����� �� ����
        cout << "������� ����� �������� � ��������: > ";
        cin >> ratingPlace; // ����� ����� ���������� ���� ��������

        SLTFElem* temp = new SLTFElem(name, ratingPlace);
        headByName = temp; // ������ ������ �� ����� �� ������ �������
        headByRating = temp; // ������ ������ �� �������� �� ������ �������
        current = temp; // ������ ��������������� ��������� �� ��� �� ������ �������

        cout << "������� ��� �������� (0 - ����� �����): > ";
        cin >> name; // ����� ������ ���� ��� �����, ����� ������ ��������, ����� ����� ����� 0 � �������� � ���� ������ ������ ���� � 1 ���������
    }

    while (name != "0") // ���� ����� �� ����
    {
        cout << "������� ����� �������� � ��������: > ";
        cin >> ratingPlace;

        SLTFElem* temp = new SLTFElem(name, ratingPlace); // ������ ����� ��������� � ��������� ����������

        if (name < headByName->name) { // ���� ������� ������ (�����������������) ������ ������� � ������ (���������� �� ������)
            temp->nextByName = headByName; // ���������� ������ ������ �� 2 ����� � ������ (������� ����� ������ ��� ���������� ��������)
            headByName = temp; // ������� �� ������ ���������� ������ ��� ��������� ��������
        }
        else { // ������ ��� �����
            current = headByName; // ��������������� ��������� ������ �� ������ ������ �� ������, ����� �� �� ��������
            while (current->nextByName != nullptr && current->nextByName->name < name) { // ���� ��������� ����� current ������� ������ (�����������������) ��� �������� ��������
                current = current->nextByName; // "����� ������" �� ������ (�������� ���������� �� ������)
            }
            // ������ �� ����� ���������� current ����� ����� ������, ���� ����� �������� ������� � ������� ��������� �� ������

            temp->nextByName = current->nextByName; // �������� ������ �� ��������� ����� current ������� ��������� 
            current->nextByName = temp; // ����������� �������� ����� ������� ���� ������ �� �������
        }

        if (ratingPlace < headByRating->ratingPlace) { // ���� ������� ������ ������ ������� � ������ (���������� �� ��������)
            temp->nextByRating = headByRating; // ���������� ������ ������ �� 2 ����� � ������ (������� ����� ������ ��� ���������� ��������)
            headByRating = temp; // ������� �� �������� ���������� ������ ��� ��������� ��������
        }
        else { // ������ ��� �����
            current = headByRating; // ��������������� ��������� ������ �� ������ ������ �� ��������, ����� �� �� ��������
            while (current->nextByRating != nullptr && current->nextByRating->ratingPlace < ratingPlace) { // ���� ��������� ����� current ������� ������ ��� �������� ��������
                current = current->nextByRating; // "����� ������" �� ������ (�������� ���������� �� ��������)
            }
            // ������ �� ����� ���������� current ����� ����� ������, ���� ����� �������� ������� � ������� ��������� �� ��������

            temp->nextByRating = current->nextByRating; // �������� ������ �� ��������� ����� current ������� ��������� 
            current->nextByRating = temp; // ����������� �������� ����� ������� ���� ������ �� �������
        }

        cout << "������� ��� �������� (0 - ����� �����): > ";
        cin >> name;
    }

    return { headByName, headByRating };
}

/// <summary>
/// ������� ��� ������ ������ � ����� ��������� ������ � ����������� FIFO, � ���������� ������� (�� �����������)
/// </summary>
/// <param name="headByName"> ������ ������ �� ������ </param>
/// <param name="headByRating"> ������ ������ �� �������� </param>
void SLTFPrintFromFirst(SLTFElem* headByName, SLTFElem* headByRating) {
    cout << "����� �� �����: ";
    if (headByName == nullptr) { // ���� ������ ������
        cout << "������ ����!" << endl;
    }
    else { // ������ ������ �� ����������� (�� ������)
        while (headByName != nullptr) {
            cout << "(" << headByName->name << " " << headByName->ratingPlace << "); ";
            headByName = headByName->nextByName;
        }
    }  

    cout << "\n����� �� ��������: ";
    if (headByRating == nullptr) { // ���� ������ ������
        cout << "������ ����!" << endl;
    }
    else { // ������ ������ �� ����������� (�� ��������)
        while (headByRating != nullptr) {
            cout << "(" << headByRating->name << " " << headByRating->ratingPlace << "); ";
            headByRating = headByRating->nextByRating;
        }
    } 
}

void SLTFPrintFromLast(SLTFElem* headByName, SLTFElem* headByRating) {
    cout << "����� �� �����: ";

    if (headByName == nullptr) { // ���� ������ ������
        cout << "������ ����!" << endl;
    }
    else {
        SLTFElem* start = headByName; // ��������������� ���������, ������� ����� ���� �� ������ � ������, ���� �� ������ �� ��������, ������� ������ ��� ��� ������� � �������
        SLTFElem* current; // ��������� �� ��������� ���������� � ������� �������

        while (start->nextByName != nullptr) { // ���� �� ����� �� ���������� � ������ �������� (�� ������), "���� ������"
            start = start->nextByName;
        }

        current = start; 
        cout << "(" << current->name << " " << current->ratingPlace << "); "; // ������ ��������� ������� ������

        while (current != headByName) { // ���� �� ������ ������ ������� ������

            start = headByName; // ����� �� ������ ������ (�� ������)

            while (start->nextByName != current) { // "���� ������" �� ������, ���� ��������� ������� �� �������� ������ ��� ����������
                start = start->nextByName;
            }

            current = start; // ����������� ���������, �.�. ������ ������ �������� ������ ����� ����

            cout << "(" << current->name << " " << current->ratingPlace << "); "; // ������ �������� � �������
        }
    }

    cout << "\n����� �� ��������: ";

    if (headByRating == nullptr) { // ���� ������ ������
        cout << "������ ����!" << endl;
    }
    else {
        SLTFElem* start = headByRating; // ��������������� ���������, ������� ����� ���� �� ������ � ������, ���� �� ������ �� ��������, ������� ������ ��� ��� ������� � �������
        SLTFElem* current; // ��������� �� ��������� ���������� � ������� �������

        while (start->nextByRating != nullptr) { // ���� �� ����� �� ���������� � ������ �������� (�� ��������), "���� ������"
            start = start->nextByRating;
        }

        current = start;
        cout << "(" << current->name << " " << current->ratingPlace << "); "; // ������ ��������� ������� ������

        while (current != headByRating) { // ���� �� ������ ������ ������� ������

            start = headByRating; // ����� �� ������ ������ (�� ��������)

            while (start->nextByRating != current) { // "���� ������" �� ������, ���� ��������� ������� �� �������� ������ ��� ����������
                start = start->nextByRating;
            }

            current = start; // ����������� ���������, �.�. ������ ������ �������� ������ ����� ����

            cout << "(" << current->name << " " << current->ratingPlace << "); "; // ������ �������� � �������
        }
    }
}

/// <summary>
/// ������� ��� �������� ���� ��������� ��������� �������� �� ������ � ����������� FIFO
/// </summary>
/// <param name="headByName"> ������ � ������ ������� �� ������ </param>
/// <param name="headByRating"> ������ � ������ ������� �� �������� </param>
/// <param name="name"> ��� ���������� </param>
/// <param name="ratingPlace"> ������� ���������� </param>
void SLTFRemove(SLTFElem*& headByName, SLTFElem*& headByRating, string name, int ratingPlace)
{
    SLTFElem* current = headByName;
    SLTFElem* next;
    bool flag = false; // ����, ������������ ������� ���-�� � ����� ��� ���

    //�������� ������������ �������� � ��������� ��������� � ������ ������� � ������, �.�. ������� � �������� �� ������ � �� �������� ����������
    //��������� �� ������, �.�. ��� �������� � �����������
    while (headByName != nullptr && headByName->name == name && headByName->ratingPlace == ratingPlace) { // ���� ������ �� ������ � �������� ������� �������� ����� ����, ������� �������
        headByName = current->nextByName; // ����� "�������" �� ������ ��������� ������� � ������

        //�����! ������� ��� �� �� ������ ������� ���� ������, �.�. ����� ��������� ����� � ������ �� ��������. 
        //���� ������� ��� ����� ������� �������� ����, ��� � ����� ��� ����� �� ��������, � ����� ����� ��� � �� ������

        current = headByName; // ������ ������� �� ��������� �� ������� "������"
        flag = true; // ������� ��� ����� (��������)
    }

    // ���� � ����� ������� ������ ����, �� current ����� ��������� �� ������ ����� � ������, � �������� ��� "next"
    if (current != nullptr)
        next = current->nextByName;
    else
        next = nullptr;

    // ���� �� ������ �� ����� ������ (��� �� � �������, � �� ������� ��������, ��� ��� ������ ��� �������� � ������� ����� � �� ����� �� ������ ���� �����)
    while (next != nullptr) {
        if (headByName->name == name && headByName->ratingPlace == ratingPlace) { //���� ������� ������� ���� �������
            current->nextByName = next->nextByName; // ������� ������ �� ��������� ������� �� ����������� ��������, ������ ����� ���� ������ ��������� �� ���������

            //�����! ������� ��� �� �� ������ ������� ���� ������, �.�. ����� ��������� ����� � ������ �� ��������. 
            //���� ������� ��� ����� ������� �������� ����, ��� � ����� ��� ����� �� ��������, � ����� ����� ��� � �� ������

            next = current->nextByName; // ��������� �� ����. �������
            flag = true; // ������� ��� ����� (��������)
        }
        else {
            current = next; // ������ ��������������� ���������� �� �������, ������� ����� ����� ���, ������� ������ ����� ��������� �� ��������
            next = next->nextByName; // ��������� �� ����. �������
        }
    }

    if (flag) { // ���� ���-�� ����� ������� �� ����������
        current = headByRating;

        //�������� ������������ �������� � ��������� ��������� � ������ ������� � ������, �.�. ������� � �������� �� ������ � �� �������� ����������
        //��������� �� ������, �.�. ��� �������� � �����������
        while (headByRating != nullptr && headByRating->name == name && headByRating->ratingPlace == ratingPlace) {
            headByRating = current->nextByRating; // ����� "�������" �� �������� ��������� ������� � ������
            delete current; // ��-���������� ������ ��� �������, ������� ������ ���
            current = headByRating; // ������ ������� �� ��������� �� ������� "������"
            flag = true; // ������� ��� �����
        }

        // ���� � ����� ������� ������ ����, �� current ����� ��������� �� ������ ����� � ������, � �������� ��� "next"
        if (current != nullptr)
            next = current->nextByRating;
        else
            next = nullptr;

        // ���� �� ������ �� ����� ������ (��� �� � �������, � �� ������� ��������, ��� ��� ������ ��� �������� � ������� ����� � �� ����� �� ������ ���� �����)
        while (next != nullptr) { 
            if (headByRating->name == name && headByRating->ratingPlace == ratingPlace) { //���� ������� ������� ���� �������
                current->nextByRating = next->nextByRating; // ������� ������ �� ��������� ������� �� ����������� ��������, ������ ����� ���� ������ ��������� �� ���������
                delete next; // ��-���������� ������ ��� �������, ������� ������ ���
                next = current->nextByRating; // ��������� �� ����. �������
                flag = true; // ������� ��� �����
            }
            else {
                current = next; // ������ ��������������� ���������� �� �������, ������� ����� ����� ���, ������� ������ ����� ��������� �� ��������
                next = next->nextByRating; // ��������� �� ����. �������
            }
        }

        cout << "�������� �������!" << endl;
    }   
    else
        cout << "��� �������� ��� ��������!" << endl;
}

/// <summary>
/// ����� ��� �������� ���������� ��������� � ������
/// </summary>
/// <param name="headByName"> ������ � ������ ������� �� ������ </param>
/// <param name="headByRating"> ������ � ������ ������� �� �������� </param>
/// <param name="name"> ��� �������� </param>
/// <param name="ratingPlace"> ������� �������� </param>
int SLTFCount(SLTFElem* headByName, string name, int ratingPlace) {
    int count = 0;
    while (headByName != nullptr) { // ���� �� ����� �� ����� ������
        if (headByName->name == name && headByName->ratingPlace == ratingPlace)
            count++;

        headByName = headByName->nextByName;
    }

    return count;
}