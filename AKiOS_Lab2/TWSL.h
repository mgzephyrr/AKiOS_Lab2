#pragma once
/// <summary>
/// ��������� ���������������� ���������������� ������ � ����������� FIFO
/// </summary>
struct TWSLElem {
    int value;
    TWSLElem* prev;
    TWSLElem* next;

    TWSLElem(int k) { value = k, prev = next = nullptr; } //�����������
};

// ��������� �������, �������������� ������ �� ���������� .cpp ������
std::tuple<TWSLElem*, TWSLElem*> MakeTWSL();
void TWSLPrintFromFirst(TWSLElem*);
void TWSLPrintFromLast(TWSLElem*);
void TWSLRemove(TWSLElem*&, TWSLElem*&, int);
int TWSLCount(TWSLElem*, int);