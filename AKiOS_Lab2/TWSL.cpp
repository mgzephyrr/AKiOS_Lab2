#include "includes.h"

// � ������ ����� ��������� ��� �������, ���������� �� ������-������ ���������������� �������������� ������ (���������� FIFO)

/// <summary>
/// ������� ��� �������� ����������� ���������������� ������
/// </summary>
/// <returns> ������ � ����� �����������: ������ � ����� ������ </returns>
tuple<TWSLElem*, TWSLElem*> MakeTWSL() {
    int value;
    TWSLElem* head = nullptr;
    TWSLElem* tail = nullptr;
    TWSLElem* current = nullptr;

    cout << "������� �������� - ����� ����� (0 - ����� �����): > ";
    cin >> value; // ����� ������ ���� ��� �����, ����� ������ ��������, ����� ����� ����� 0 � �������� � ���� ������ ������ ������

    if (value != 0) {
        TWSLElem* temp = new TWSLElem(value);
        head = temp; // ������ ������ �� ������ �������
        current = temp; // ������ ��������������� ��������� �� ��� �� ������ �������
        tail = temp; // ������ ����� �� ������ �������

        cout << "������� �������� - ����� ����� (0 - ����� �����): > ";
        cin >> value; // ����� ������ ���� ��� �����, ����� ������ ��������, ����� ����� ����� 0 � �������� � ���� ������ ������ ���� � 1 ���������
    }

    while (value != 0)
    {
        TWSLElem* temp = new TWSLElem(value); // ������ ����� ��������� � �������� ���������
        if (value < head->value) { // ���� ������� ������ ������ ������� � ������
            temp->next = head; // ���������� ������ ������ �� 2 ����� � ������ (������� ����� ������ ��� ���������� ��������)
            head->prev = temp; // ���������� ������ ��� ������ �� ����� ������
            head = temp; // ������� ���������� ������ ��� ��������� ��������
        }
        else { // ������ ��� �����
            current = head; // ��������������� ��������� ������ �� ������ ������, ����� �� �� ��������
            while (current->next != nullptr && current->next->value < value) { // ���� ��������� ����� current ������� ������ ��� �������� ��������
                current = current->next; // "����� ������" �� ������
            }
            // ������ �� ����� ���������� current ����� ����� ������, ���� ����� �������� �������

            temp->next = current->next; // �������� ������ �� ��������� ����� current ������� ��������� 
            temp->prev = current; // �������� ������ �������� ������ �� ��� ����������
            current->next = temp; // ����������� �������� ����� ������� ���� ������ �� �������

            if (temp->next != nullptr) { // ���� �������� ������� �� � �����
                temp->next->prev = temp;
            }
            else { // ���� �������� ������� � �����
                tail = temp;
            }
        }

        cout << "������� �������� - ����� ����� (0 - ����� �����): > ";
        cin >> value;
    }

    return { head, tail };
}

/// <summary>
/// ������� ��� ������ ������ � ����������� FIFO, � ���������� ������� (�� �����������)
/// </summary>
/// <param name="head"> "������" ������, ������� ����� ������� � ������� </param>
void TWSLPrintFromFirst(TWSLElem* head) {
    if (head == nullptr) { // ���� ������ ������
        cout << "������ ����!" << endl;
        return;
    }

    //else ������ ������ �� �����������
    while (head != nullptr) {
        cout << head->value << " ";
        head = head->next;
    }
}

/// <summary>
/// ������� (�����������!) ��� ������ ������ � ����������� FIFO, � �������� ������� (�� ��������)
/// </summary>
/// <param name="tail"> ����� ������ </param>
void TWSLPrintFromLast(TWSLElem* tail) {
    if (tail == nullptr) { // ���� ������ ������
        cout << "������ ����!" << endl;
        return;
    }

    //else ������ ������ �� ��������
    while (tail != nullptr) {
        cout << tail->value << " ";
        tail = tail->prev;
    }
}

/// <summary>
/// ������� ��� �������� ���� ��������� ���������� �������� �� ������ � ����������� FIFO
/// </summary>
/// <param name="head"> ������ � ������ ������� </param>
/// <param name="EV"> ��������, ������� ����� ������� �� ������ </param>
void TWSLRemove(TWSLElem*& head, TWSLElem*& tail, int EV)
{
    TWSLElem* current = head;
    TWSLElem* next;
    bool flag = false; // ����, ������������ ������� ���-�� � ����� ��� ���

    //�������� ������������ �������� � ��������� ��������� � ������ ������� � ������, �.�. ������� � �������� �� ������ � �� �������� ����������
    //��������� �� ������, �.�. ��� �������� � �����������
    while (head != nullptr && head->value == EV) { // ���� ������ �� ������ � �������� ������� �������� ����� ����, ������� �������
        head = current->next; // ����� "�������" ��������� ������� � ������
        if (head != nullptr) // ���� � ������ �������� ��������
            head->prev = nullptr; // ������� ��������� �� ���������� ������� ������
        delete current; // ������ ������� �� ��������� �� ������� "������"
        current = head; // ����� ��������� ��������������� ��������� �� ��� �������� "������"
        flag = true;// ������� ��� �����
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
            if (current->next != nullptr) { // ���� � ������ ������� �� 1 �������
                current->next->prev = current; // ��������� ���������� � ������� ��������
            }
            next = current->next; // ��������� �� ����. �������
            flag = true; // ������� ��� �����
        }
        else {
            current = next; // ������ ��������������� ���������� �� �������, ������� ����� ����� ���, ������� ������ ����� ��������� �� ��������
            next = next->next; // ��������� �� ����. �������
        }
    }

    tail = current; // �.�. ����� ����������� ����� �����, current ����� ����� �� ��������� ��������, �� ����� ���������������� � ��������� ������ ��������� �������

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
int TWSLCount(TWSLElem* head, int value) {
    int count = 0;
    while (head != nullptr) { // ���� �� ����� �� ����� ������
        if (head->value == value)
            count++;

        head = head->next;
    }

    return count;
}