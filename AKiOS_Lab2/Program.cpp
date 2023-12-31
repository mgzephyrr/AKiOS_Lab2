#include "includes.h"

/// <summary>
/// ������� ��� ������������ ������ ��������� � ����������� LIFO
/// </summary>
void LIFOOperations() {
    int value; // ���������� ��� �������� ����� ������������
    LIFOElem* tail = MakeLIFO(); // ������ ������ � ����������� LIFO, ��������� ��� "�����" � ���������� tail    

    __try {
        cout << endl << "����� ������ � ������:" << endl;
        LIFOPrintFromFirst(tail);

    }
    __except (GetExceptionCode() == EXCEPTION_ACCESS_VIOLATION ? EXCEPTION_EXECUTE_HANDLER : EXCEPTION_CONTINUE_SEARCH) {
        cout << "������ ����!" << endl;
    }
    
    __try {
        cout << endl << "����� ������ � �����:" << endl;
        LIFOPrintFromLast(tail);

    }
    __except (GetExceptionCode() == EXCEPTION_ACCESS_VIOLATION ? EXCEPTION_EXECUTE_HANDLER : EXCEPTION_CONTINUE_SEARCH) {
        cout << "������ ����!" << endl;
    }
    
    cout << "\n������� �������� - ����� ����� - ��� ������ (0 - �����): > "; 
    cin >> value; // ����� ������ ���� ��� �����, ����� ������ ��������, ����� ����� ����� 0

    while (value != 0) // ���� �� ������ 0, ����� ���������� ������ �������� � ������
    {
        int count = LIFOCount(tail, value);

        cout << endl << "���������� ��������� " << value << " = " << count << endl;

        cout << "������� �������� - ����� ����� - ��� ������ (0 - �����): > ";
        cin >> value;
    }

    cout << "\n������� �������� - ����� ����� - ��� �������� (0 - �����): > ";
    cin >> value; // ����� ������ ���� ��� �����, ����� ������ ��������, ����� ����� ����� 0

    while (value != 0) // ���� �� ������ 0, ������ �������� �� ������ � ������ ���, ����� ��������� ���� ��������
    {
        LIFORemove(tail, value);

        __try {
            cout << endl << "����� ������ � ������:" << endl;
            LIFOPrintFromFirst(tail);

        }
        __except (GetExceptionCode() == EXCEPTION_ACCESS_VIOLATION ? EXCEPTION_EXECUTE_HANDLER : EXCEPTION_CONTINUE_SEARCH) {
            cout << "������ ����!" << endl;
        }

        __try {
            cout << endl << "����� ������ � �����:" << endl;
            LIFOPrintFromLast(tail);

        }
        __except (GetExceptionCode() == EXCEPTION_ACCESS_VIOLATION ? EXCEPTION_EXECUTE_HANDLER : EXCEPTION_CONTINUE_SEARCH) {
            cout << "������ ����!" << endl;
        }

        cout << "������� �������� - ����� ����� - ��� �������� (0 - �����): > ";
        cin >> value;
    }
}

/// <summary>
/// ������� ��� ������������ ������ ��������� � ����������� FIFO
/// </summary>
void FIFOOperations() {
    int value; // ���������� ��� �������� ����� ������������
    FIFOElem* head = MakeFIFO(); // ������ ������ � ����������� FIFO, ��������� ��� "������" � ���������� head

    try {
        cout << endl << "����� ������ � ������:" << endl;
        FIFOPrintFromFirst(head);
    }
    catch (const char* error_message) {
        cout << error_message << endl;
    }

    try {
        cout << endl << "����� ������ � �����:" << endl;
        FIFOPrintFromLast(head);
    }
    catch (const char* error_message) {
        cout << error_message << endl;
    }

    cout << "\n������� �������� - ����� ����� - ��� ������ (0 - �����): > ";
    cin >> value; // ����� ������ ���� ��� �����, ����� ������ ��������, ����� ����� ����� 0

    while (value != 0) // ���� �� ������ 0, ����� ���������� ������ �������� � ������
    {
        int count = FIFOCount(head, value);

        cout << endl << "���������� ��������� " << value << " = " << count << endl;

        cout << "������� �������� - ����� ����� - ��� ������ (0 - �����): > ";
        cin >> value;
    }

    cout << "\n������� �������� - ����� ����� - ��� �������� (0 - �����): > ";
    cin >> value; // ����� ������ ���� ��� �����, ����� ������ ��������, ����� ����� ����� 0

    while (value != 0) // ���� �� ������ 0, ������ �������� �� ������ � ������ ���, ����� ��������� ���� ��������
    {
        FIFORemove(head, value);

        try {
            cout << endl << "����� ������ � ������:" << endl;
            FIFOPrintFromFirst(head);
        }
        catch (const char* error_message) {
            cout << error_message << endl;
        }

        try {
            cout << endl << "����� ������ � �����:" << endl;
            FIFOPrintFromLast(head);
        }
        catch (const char* error_message) {
            cout << error_message << endl;
        }

        cout << "������� �������� - ����� ����� - ��� �������� (0 - �����): > ";
        cin >> value;
    }
}

/// <summary>
/// ������� ��� ������������ ������ ��������� � ����������� ����������� ��������������� ������
/// </summary>
void OWSLOperations() {
    int value; // ���������� ��� �������� ����� ������������
    OWSLElem* head = MakeOWSL(); // ������ ������ � ����������� "����������� ��������������� ������", ��������� ��� "������" � ���������� head

    cout << endl << "����� ������ � ������:" << endl;
    OWSLPrintFromFirst(head);

    cout << endl << "����� ������ � �����:" << endl;
    OWSLPrintFromLast(head);

    cout << "\n������� �������� - ����� ����� - ��� ������ (0 - �����): > ";
    cin >> value; // ����� ������ ���� ��� �����, ����� ������ ��������, ����� ����� ����� 0

    while (value != 0) // ���� �� ������ 0, ����� ���������� ������ �������� � ������
    {
        int count = OWSLCount(head, value);

        cout << endl << "���������� ��������� " << value << " = " << count << endl;

        cout << "������� �������� - ����� ����� - ��� ������ (0 - �����): > ";
        cin >> value;
    }

    cout << "\n������� �������� - ����� ����� - ��� �������� (0 - �����): > ";
    cin >> value; // ����� ������ ���� ��� �����, ����� ������ ��������, ����� ����� ����� 0

    while (value != 0) // ���� �� ������ 0, ������ �������� �� ������ � ������ ���, ����� ��������� ���� ��������
    {
        OWSLRemove(head, value);

        cout << endl << "����� ������ � ������:" << endl;
        OWSLPrintFromFirst(head);

        cout << endl << "����� ������ � �����:" << endl;
        OWSLPrintFromLast(head);

        cout << "������� �������� - ����� ����� - ��� �������� (0 - �����): > ";
        cin >> value;
    }
}

/// <summary>
/// ������� ��� ������������ ������ ��������� � ����������� ���������� ��������������� ������
/// </summary>
void TWSLOperations() {
    int value; // ���������� ��� �������� ����� ������������
    tuple<TWSLElem*, TWSLElem*> ends = MakeTWSL(); // ������ ������ � ����������� "���������� ��������������� ������"
    TWSLElem* head = get<0>(ends); // ��� ���������� ������� ������� ����� � ������� ������� ��� "������", ��� � "�����"
    TWSLElem* tail = get<1>(ends); // �������, �� ������ ��������� ������ � ����� ����������� - �� ������ ������� ������ � �� ���������

    cout << endl << "����� ������ � ������:" << endl;
    TWSLPrintFromFirst(head);

    cout << endl << "����� ������ � �����:" << endl;
    TWSLPrintFromLast(tail);

    cout << "\n������� �������� - ����� ����� - ��� ������ (0 - �����): > ";
    cin >> value; // ����� ������ ���� ��� �����, ����� ������ ��������, ����� ����� ����� 0

    while (value != 0) // ���� �� ������ 0, ����� ���������� ������ �������� � ������
    {
        int count = TWSLCount(head, value);

        cout << endl << "���������� ��������� " << value << " = " << count << endl;

        cout << "������� �������� - ����� ����� - ��� ������ (0 - �����): > ";
        cin >> value;
    }

    cout << "\n������� �������� - ����� ����� - ��� �������� (0 - �����): > ";
    cin >> value; // ����� ������ ���� ��� �����, ����� ������ ��������, ����� ����� ����� 0

    while (value != 0) // ���� �� ������ 0, ������ �������� �� ������ � ������ ���, ����� ��������� ���� ��������
    {
        TWSLRemove(head, tail, value);

        cout << endl << "����� ������ � ������:" << endl;
        TWSLPrintFromFirst(head);

        cout << endl << "����� ������ � �����:" << endl;
        TWSLPrintFromLast(tail);

        cout << "������� �������� - ����� ����� - ��� �������� (0 - �����): > ";
        cin >> value;
    }
}

/// <summary>
/// ������� ��� ������������ ������ ��������� � ����������� ���������������� ������ � ����������� ��������� �� ���� ������

/// </summary>
void SLTFOperations() {
    string name; // ���������� ��� �������� ����� ������������
    int ratingPlace; // ���������� ��� �������� ����� ������������
    tuple<SLTFElem*, SLTFElem*> heads = MakeSLTF(); // ������ ������ � ����������� "���������������� ������ � ����������� ��������� �� ���� ������"
    SLTFElem* headByName = get<0>(heads); // ��� ��� ������������ � ������ ���� ��� ��������� �� ��������� ��������, � ����������� �� �������� ���� ����� ��������������
    SLTFElem* headByRating = get<1>(heads); // �� �� ������ ��������� � ��������� "������" ��� ������ �� ����������
    // �����! ������ ����� - ����, ������������ ���� � �� �� ������, �� �� ���� ���� ���������� �� ��������� �������, ����������
    // �����������, �� ����� ������ �� ��� ���� ������ ����� ����� �� ���������, ������� ����� ��� ���������� �� ���������

    cout << endl << "����� ������ � ������:" << endl;
    SLTFPrintFromFirst(headByName, headByRating);

    cout << endl << "����� ������ � �����:" << endl;
    SLTFPrintFromLast(headByName, headByRating);

    cout << "\n\n������� ��� �������� ��� ������ (0 - ����� �����): > ";
    cin >> name; // ����� ������ ���� ��� �����, ����� ������ ��������, ����� ����� ����� 0

    while (name != "0") // ���� �� ������ 0, ����� ���������� ������ �������� � ������
    { // ���� ��� ���� �������, �� ������������ ������ ������ ������� ������� ��������. ����������� ��������� ���� �� �������� �� ���������������
        cout << "������� ����� �������� � �������� ��� ������: > ";
        cin >> ratingPlace;

        int count = SLTFCount(headByName, name, ratingPlace);

        cout << endl << "���������� ��������� " << "(" << headByName->name << " " << headByName->ratingPlace << ")" << " = " << count << endl;

        cout << "\n\n������� ��� �������� ��� ������ (0 - ����� �����): > ";
        cin >> name;
    }

    cout << "������� ��� �������� ��� �������� (0 - ����� �����): > ";
    cin >> name; // ����� ������ ���� ��� �����, ����� ������ ��������, ����� ����� ����� 0

    while (name != "0") // ���� �� ������ 0, ������ �������� �� ������ � ������ ���, ����� ��������� ���� ��������
    { // ����������� ��������� ���� �� �������� �� ���������������
        cout << "������� ����� �������� � �������� ��� ��������: > ";
        cin >> ratingPlace;

        SLTFRemove(headByName, headByRating, name, ratingPlace);

        cout << endl << "����� ������ � ������:" << endl;
        SLTFPrintFromFirst(headByName, headByRating);

        cout << endl << "����� ������ � �����:" << endl;
        SLTFPrintFromLast(headByName, headByRating);

        cout << "������� ��� �������� ��� �������� (0 - ����� �����): > ";
        cin >> name;
    }
}

void AVLTreeOperations() {
    int value; // ���������� ��� �������� ����� ������������
    AVLTreeNode* root = MakeAVLTree(); // ������ �������� ���������������� �������� ������ � ���������� ���������� root ��� ������

    cout << "\n����� ��������� ������ � ������� �����������: ";
    if (!root)
        cout << "������ �����!" << endl;
    else
        PrintTreeByAscending(root);

    cout << "\n����� ��������� ������ � ������� ��������: ";
    if (!root)
        cout << "������ �����!" << endl;
    else
        PrintTreeByDescending(root);

    cout << "\n������� �������� - ����� ����� - ��� ������ (0 - �����): > ";
    cin >> value;

    while (value != 0) // ���� �� ������ 0, ����� ���������� ������ �������� � ������
    {
        int count = FindValue(root, value);

        cout << endl << "���������� ��������� " << value << " = " << count << endl;

        cout << "������� �������� - ����� ����� - ��� ������ (0 - �����): > ";
        cin >> value;
    }

    cout << "\n������� �������� - ����� ����� - ��� �������� (0 - �����): > ";
    cin >> value;

    while (value != 0) // ���� �� ������ 0, ������ �������� �� ������ � ������ ���, ����� ��������� ���� ��������
    {
        root = RemoveValue(root, value);

        cout << "\n����� ��������� ������ � ������� �����������: ";
        if (!root)
            cout << "������ �����!" << endl;
        else
            PrintTreeByAscending(root);

        cout << "\n����� ��������� ������ � ������� ��������: ";
        if (!root)
            cout << "������ �����!" << endl;
        else
            PrintTreeByDescending(root);

        cout << "\n������� �������� - ����� ����� - ��� �������� (0 - �����): > ";
        cin >> value;
    }

    DeleteTree(root); // � ����� ������ ��������� ������ ������ �� ������
}

int main() {
    // ������ ������� ������������ ����� ������ ��������� ���� ���������� (����� - 6)

    system("chcp 1251 >> null"); // ������� ��� ����, ����� ������� ����� �������� ����� �� ���������� string � �������

    cout << "���������� LIFO\n" << endl;
    LIFOOperations();

    system("cls"); // ������� ������� ����� ����, ��� ���������� ����������

    cout << "���������� FIFO\n" << endl;
    FIFOOperations();

    system("cls"); // ������� ������� ����� ����, ��� ���������� ����������

    cout << "���������������� ������ � ����������� ��������� �� �����\n" << endl;
    OWSLOperations();

    system("cls"); // ������� ������� ����� ����, ��� ���������� ����������

    cout << "��������������� ������ � ����������� ��������� �� �����\n" << endl;
    TWSLOperations();

    system("cls"); // ������� ������� ����� ����, ��� ���������� ����������

    cout << "���������������� ������ � ����������� ��������� �� ���� ������\n" << endl;
    SLTFOperations();

    system("cls"); // ������� ������� ����� ����, ��� ���������� ����������

    cout << "��������-���������������� �������� ������\n" << endl;
    AVLTreeOperations();
}