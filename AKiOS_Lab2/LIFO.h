#pragma once
/// <summary>
/// ��������� ����������������� ������ �� ���������� LIFO
/// </summary>
struct LIFOElem {
    int value;
    LIFOElem* next;

    LIFOElem(int k) { value = k; next = nullptr; } //�����������
};

// ��������� �������, �������������� ������ �� ���������� .cpp ������
LIFOElem* AddToLIFO(LIFOElem* tail, int value);
LIFOElem* MakeLIFO();
void LIFOPrintFromFirst(LIFOElem*);
void LIFOPrintFromLast(LIFOElem*);
void LIFORemove(LIFOElem*&, int);
int LIFOCount(LIFOElem*, int);