#pragma once
/// <summary>
/// —труктура однонапр. списка с дисциплиной FIFO
/// </summary>
struct FIFOElem {
    int value;
    FIFOElem* next;

    FIFOElem(int k) { value = k; next = nullptr; } //конструктор
};

// заголовки методов, обеспечивающие работу со множеством .cpp файлов
FIFOElem* MakeFIFO();
void FIFOPrintFromFirst(FIFOElem*);
void FIFOPrintFromLast(FIFOElem*);
void FIFORemove(FIFOElem*&, int);
int FIFOCount(FIFOElem*, int);