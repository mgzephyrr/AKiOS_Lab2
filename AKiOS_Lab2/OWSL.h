#pragma once
/// <summary>
/// ��������� ����������������� ���������������� ������ � ����������� FIFO
/// </summary>
struct OWSLElem {
    int value;
    OWSLElem* next;

    OWSLElem(int k) { value = k; next = nullptr; } //�����������
};

// ��������� �������, �������������� ������ �� ���������� .cpp ������
OWSLElem* MakeOWSL();
void OWSLPrintFromFirst(OWSLElem*);
void OWSLPrintFromLast(OWSLElem*);
void OWSLRemove(OWSLElem*&, int);
int OWSLCount(OWSLElem*, int);