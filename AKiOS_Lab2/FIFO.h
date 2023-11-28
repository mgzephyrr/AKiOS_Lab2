#pragma once
/// <summary>
/// ��������� ��������. ������ � ����������� FIFO
/// </summary>
struct FIFOElem {
    int value;
    FIFOElem* next;

    FIFOElem(int k) { value = k; next = nullptr; } //�����������
};

// ��������� �������, �������������� ������ �� ���������� .cpp ������
FIFOElem* MakeFIFO();
void FIFOPrintFromFirst(FIFOElem*);
void FIFOPrintFromLast(FIFOElem*);
void FIFORemove(FIFOElem*&, int);
int FIFOCount(FIFOElem*, int);