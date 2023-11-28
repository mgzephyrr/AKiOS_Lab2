#pragma once
/// <summary>
/// Структура однонаправленного списка со структурой LIFO
/// </summary>
struct LIFOElem {
    int value;
    LIFOElem* next;

    LIFOElem(int k) { value = k; next = nullptr; } //конструктор
};

// заголовки методов, обеспечивающие работу со множеством .cpp файлов
LIFOElem* AddToLIFO(LIFOElem* tail, int value);
LIFOElem* MakeLIFO();
void LIFOPrintFromFirst(LIFOElem*);
void LIFOPrintFromLast(LIFOElem*);
void LIFORemove(LIFOElem*&, int);
int LIFOCount(LIFOElem*, int);