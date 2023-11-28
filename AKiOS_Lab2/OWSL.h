#pragma once
/// <summary>
/// Структура однонаправленного отсортированного списка с дисциплиной FIFO
/// </summary>
struct OWSLElem {
    int value;
    OWSLElem* next;

    OWSLElem(int k) { value = k; next = nullptr; } //конструктор
};

// заголовки методов, обеспечивающие работу со множеством .cpp файлов
OWSLElem* MakeOWSL();
void OWSLPrintFromFirst(OWSLElem*);
void OWSLPrintFromLast(OWSLElem*);
void OWSLRemove(OWSLElem*&, int);
int OWSLCount(OWSLElem*, int);