#include "includes.h"

// � ������ ����� ��������� ��� �������, ���������� �� ������-������ ��� ���������� FIFO

/// <summary>
/// ������� ��� ������� �������� ������ � ����������� FIFO
/// </summary>
/// <returns> ��������� �� "������" ������ (�� ������ �������� ������������� �������) </returns>
FIFOElem* MakeFIFO() {
    int value;
    FIFOElem* head = nullptr;
    FIFOElem* current = nullptr;

    cout << "������� �������� - ����� ����� (0 - ����� �����): > ";
    cin >> value; // ����� ������ ���� ��� �����, ����� ������ ��������, ����� ����� ����� 0 � �������� � ���� ������ ������ ������

    if (value != 0) { // ���� ����� �� ����
        FIFOElem* temp = new FIFOElem(value);
        head = temp; // ������ ������ �� ������ �������
        current = temp; // ������ ��������������� ��������� �� ��� �� ������ �������

        cout << "������� �������� - ����� ����� (0 - ����� �����): > ";
        cin >> value; // ����� ������ ���� ��� �����, ����� ������ ��������, ����� ����� ����� 0 � �������� � ���� ������ ������ ���� � 1 ���������
    }

    while (value != 0)
    {
        FIFOElem* temp = new FIFOElem(value); // ������ ����� ��������� � �������� ���������
        current->next = temp; // ��� ������ �� ������ ��� ��������� ������� ���������� �� ������ ������ � ������ 
        current = current->next; // ����� �� ��������� ������� � ������

        cout << "������� �������� - ����� ����� (0 - ����� �����): > ";
        cin >> value;
    }

    return head;
}

/// <summary>
/// ������� ��� ������ ������ � ����������� FIFO, � ���������� ������� (� ������� ����������)
/// </summary>
/// <param name="head"> "������" ������, ������� ����� ������� � ������� </param>
void FIFOPrintFromFirst(FIFOElem* head) {
    if (head == nullptr) { // ���� ������ ������
        cout << "������ ����!" << endl;
        return;
    }

    //else ������ ������ � ������� ���������� �������� �� ����������
    while (head != nullptr) {
        cout << head->value << " ";
        head = head->next;
    }
}

/// <summary>
/// ������� (�����������!) ��� ������ ������ � ����������� FIFO, � �������� ������� (� ���������� ����������)
/// </summary>
/// <param name="head"> "������" ������, ������� ����� ������� � ������� </param>
void FIFOPrintFromLast(FIFOElem* head) {
    if (head == nullptr) { // ���� ������ ������
        cout << "������ ����!" << endl;
        return;
    }

    FIFOElem* start = head; // ��������������� ���������, ������� ����� ���� �� ������ � ������, ���� �� ������ �� ��������, ������� ������ ��� ��� ������� � �������
    FIFOElem* current = head; // ��������� �� ��������� ���������� � ������� �������

    while (current->next != nullptr) { // ���� �� ����� �� ���������� � ������ ��������, "���� ������"
        current = current->next;
    }

    cout << current->value << " "; // ������ ��������� ������� ������

    while (current != head) { // ���� �� ������ ������ ������� ������
        
        start = head; // ����� �� ������ ������

        while (start->next != current) { // "���� ������" �� ������, ���� ��������� ������� �� �������� ������ ��� ����������
            start = start->next;
        }

        current = start; // ����������� ���������, �.�. ������ ������ �������� ������ ����� ����

        cout << current->value << " "; // ������ �������� � �������
    }
}


/// <summary>
/// ������� ��� �������� ���� ��������� ���������� �������� �� ������ � ����������� FIFO
/// </summary>
/// <param name="head"> ������ ��������� � ������ ������� </param>
/// <param name="EV"> ��������, ������� ����� ������� �� ������ </param>
void FIFORemove(FIFOElem*& head, int EV)
{
    FIFOElem* current = head;
    FIFOElem* next;
    bool flag = false; // ����, ������������ ������� ���-�� � ����� ��� ���

    //�������� ������������ �������� � ��������� ��������� � ������ ������� � ������, �.�. ������� � �������� �� ������ � �� �������� ����������
    //��������� �� ������, �.�. ��� �������� � �����������
    while (head != nullptr && head->value == EV) { // ���� ������ �� ������ � �������� ������� �������� ����� ����, ������� �������
        head = current->next; // ����� "�������" ��������� ������� � ������
        delete current; // ������ ������� �� ��������� �� ������� "������"
        current = head; // ����� ��������� ��������������� ��������� �� ��� �������� "������"
        flag = true; // ������� ��� �����
    }

    // ���� � ����� ������� ������ ����, �� current ����� ��������� �� ������ ����� � ������, � �������� ��� "next"
    if (current != nullptr)
        next = current->next;
    else
        next = nullptr;

    // ���� �� ������ �� ����� ������ (��� �� � �������, � �� ������� ��������, ��� ��� ������ ��� �������� � ������� ����� � �� ����� �� ������ ���� �����)
    while (next != nullptr) {
        if (next->value == EV) { //���� ������� ������� ���� �������
            current->next = next->next; // ������� ������ �� ��������� ������� �� ����������� ��������, ������ ����� ���� ������ ��������� �� ���������
            delete next; //������� �������
            next = current->next; // ��������� �� ����. �������
            flag = true; // ������� ��� �����
        }
        else {
            current = next; // ������ ��������������� ���������� �� �������, ������� ����� ����� ���, ������� ������ ����� ��������� �� ��������
            next = next->next; // ��������� �� ����. �������
        }
    }

    if (flag)
        cout << "�������� �������!" << endl;
    else
        cout << "��� �������� ��� ��������!" << endl;
}

/// <summary>
/// ����� ��� �������� ���������� ��������� � ������
/// </summary>
/// <param name="head"> ������ ������ </param>
/// <param name="value"> ������� �������� </param>
/// <returns> ���������� ��������� �������� value � ������ </returns>
int FIFOCount(FIFOElem* head, int value) {
    int count = 0;
    while (head != nullptr) { // ���� �� ����� �� ����� ������
        if (head->value == value)
            count++;

        head = head->next;
    }

    return count;
}