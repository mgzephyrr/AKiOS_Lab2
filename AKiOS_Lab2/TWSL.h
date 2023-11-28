#pragma once
/// <summary>
/// Структура двунаправленного отсортированного списка с дисциплиной FIFO
/// </summary>
struct TWSLElem {
    int value;
    TWSLElem* prev;
    TWSLElem* next;

    TWSLElem(int k) { value = k, prev = next = nullptr; } //конструктор
};

// заголовки методов, обеспечивающие работу со множеством .cpp файлов
std::tuple<TWSLElem*, TWSLElem*> MakeTWSL();
void TWSLPrintFromFirst(TWSLElem*);
void TWSLPrintFromLast(TWSLElem*);
void TWSLRemove(TWSLElem*&, TWSLElem*&, int);
int TWSLCount(TWSLElem*, int);