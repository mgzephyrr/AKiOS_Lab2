#include "includes.h"

// В ДАННОМ ФАЙЛЕ НАХОДЯТСЯ ВСЕ ФУНКЦИИ, ОТВЕЧАЮЩИЕ ЗА БИЗНЕС-ЛОГИКУ ОДНОНАПРАВЛЕННОГО СОРТИРОВАННОГО ПО ДВУМ ПОЛЯМ СПИСКА (ДИСЦИПЛИНА FIFO)

/// <summary>
/// Функция для полного создания однонаправленного сортированного по двум полям списка с дисциплиной FIFO
/// </summary>
/// <returns> кортеж, в котором находятся два указателя на разные с точки зрения сортировки "головы" </returns>
tuple<SLTFElem*, SLTFElem*> MakeSLTF() {
    string name;
    int ratingPlace;
    SLTFElem* headByName = nullptr;
    SLTFElem* headByRating = nullptr;
    SLTFElem* current = nullptr;

    cout << "Введите имя студента (0 - конец ввода): > ";
    cin >> name; // прошу первый ввод вне цикла, чтобы учесть ситуацию, когда сразу ввели 0 и оставить в этом случае список пустым

    if (name != "0") { // если ввели не ноль
        cout << "Введите место студента в рейтинге: > ";
        cin >> ratingPlace; // после имени обязателем ввод рейтинга

        SLTFElem* temp = new SLTFElem(name, ratingPlace);
        headByName = temp; // ставлю голову по имени на первый элемент
        headByRating = temp; // ставлю голову по рейтингу на первый элемент
        current = temp; // ставлю вспомогательный указатель на тот же первый элемент

        cout << "Введите имя студента (0 - конец ввода): > ";
        cin >> name; // прошу первый ввод вне цикла, чтобы учесть ситуацию, когда сразу ввели 0 и оставить в этом случае список лишь с 1 элементом
    }

    while (name != "0") // если ввели не ноль
    {
        cout << "Введите место студента в рейтинге: > ";
        cin >> ratingPlace;

        SLTFElem* temp = new SLTFElem(name, ratingPlace); // создаю новый экземпляр с заданными значениями

        if (name < headByName->name) { // если элемент меньше (лексикографически) самого первого в списке (сортировка по именам)
            temp->nextByName = headByName; // предыдущая голова встает на 2 место в списке (следует после только что введенного значения)
            headByName = temp; // головой по именам становится только что введенное значение
        }
        else { // больше или равно
            current = headByName; // вспомогательный указатель встает на голову списка по именам, чтобы ее не потерять
            while (current->nextByName != nullptr && current->nextByName->name < name) { // пока следующий после current элемент меньше (лексикографически) чем заданное значение
                current = current->nextByName; // "бежим вперед" по списку (согласно сортировке по именам)
            }
            // сейчас мы стоим указателем current прямо перед местом, куда нужно вставить элемент в цепочку элементов по именам

            temp->nextByName = current->nextByName; // передаем ссылку на следующий после current элемент нынешнему 
            current->nextByName = temp; // предыдущему элементу перед текущим даем ссылку на текущий
        }

        if (ratingPlace < headByRating->ratingPlace) { // если элемент меньше самого первого в списке (сортировка по рейтингу)
            temp->nextByRating = headByRating; // предыдущая голова встает на 2 место в списке (следует после только что введенного значения)
            headByRating = temp; // головой по рейтингу становится только что введенное значение
        }
        else { // больше или равно
            current = headByRating; // вспомогательный указатель встает на голову списка по рейтингу, чтобы ее не потерять
            while (current->nextByRating != nullptr && current->nextByRating->ratingPlace < ratingPlace) { // пока следующий после current элемент меньше чем заданное значение
                current = current->nextByRating; // "бежим вперед" по списку (согласно сортировке по рейтингу)
            }
            // сейчас мы стоим указателем current прямо перед местом, куда нужно вставить элемент в цепочку элементов по рейтингу

            temp->nextByRating = current->nextByRating; // передаем ссылку на следующий после current элемент нынешнему 
            current->nextByRating = temp; // предыдущему элементу перед текущим даем ссылку на текущий
        }

        cout << "Введите имя студента (0 - конец ввода): > ";
        cin >> name;
    }

    return { headByName, headByRating };
}

/// <summary>
/// Функция для вывода списка с двумя значимыми полями с дисциплиной FIFO, в нормальном порядке (по возрастанию)
/// </summary>
/// <param name="headByName"> голова списка по именам </param>
/// <param name="headByRating"> голова списка по рейтингу </param>
void SLTFPrintFromFirst(SLTFElem* headByName, SLTFElem* headByRating) {
    cout << "Вывод по имени: ";
    if (headByName == nullptr) { // если список пустой
        cout << "Список пуст!" << endl;
    }
    else { // вывожу список по возрастанию (по именам)
        while (headByName != nullptr) {
            cout << "(" << headByName->name << " " << headByName->ratingPlace << "); ";
            headByName = headByName->nextByName;
        }
    }  

    cout << "\nВывод по рейтингу: ";
    if (headByRating == nullptr) { // если список пустой
        cout << "Список пуст!" << endl;
    }
    else { // вывожу список по возрастанию (по рейтингу)
        while (headByRating != nullptr) {
            cout << "(" << headByRating->name << " " << headByRating->ratingPlace << "); ";
            headByRating = headByRating->nextByRating;
        }
    } 
}

void SLTFPrintFromLast(SLTFElem* headByName, SLTFElem* headByRating) {
    cout << "Вывод по имени: ";

    if (headByName == nullptr) { // если список пустой
        cout << "Список пуст!" << endl;
    }
    else {
        SLTFElem* start = headByName; // вспомогательный указатель, который будет идти по списку с начала, пока не дойдет до элемента, который только что был выведен в консоль
        SLTFElem* current; // указатель на последний выведенный в консоль элемент

        while (start->nextByName != nullptr) { // пока не дойду до последнего в списке элемента (по именам), "бегу вперед"
            start = start->nextByName;
        }

        current = start; 
        cout << "(" << current->name << " " << current->ratingPlace << "); "; // вывожу последний элемент списка

        while (current != headByName) { // пока не выведу первый элемент списка

            start = headByName; // встаю на начало списка (по именам)

            while (start->nextByName != current) { // "бегу вперед" по списку, пока следующий элемент не окажется только что выведенным
                start = start->nextByName;
            }

            current = start; // переставляю указатель, т.к. сейчас выведу значение именно этого узла

            cout << "(" << current->name << " " << current->ratingPlace << "); "; // вывожу значение в консоль
        }
    }

    cout << "\nВывод по рейтингу: ";

    if (headByRating == nullptr) { // если список пустой
        cout << "Список пуст!" << endl;
    }
    else {
        SLTFElem* start = headByRating; // вспомогательный указатель, который будет идти по списку с начала, пока не дойдет до элемента, который только что был выведен в консоль
        SLTFElem* current; // указатель на последний выведенный в консоль элемент

        while (start->nextByRating != nullptr) { // пока не дойду до последнего в списке элемента (по рейтингу), "бегу вперед"
            start = start->nextByRating;
        }

        current = start;
        cout << "(" << current->name << " " << current->ratingPlace << "); "; // вывожу последний элемент списка

        while (current != headByRating) { // пока не выведу первый элемент списка

            start = headByRating; // встаю на начало списка (по рейтингу)

            while (start->nextByRating != current) { // "бегу вперед" по списку, пока следующий элемент не окажется только что выведенным
                start = start->nextByRating;
            }

            current = start; // переставляю указатель, т.к. сейчас выведу значение именно этого узла

            cout << "(" << current->name << " " << current->ratingPlace << "); "; // вывожу значение в консоль
        }
    }
}

/// <summary>
/// Функция для удаления всех вхождений введенных значений из списка с дисциплиной FIFO
/// </summary>
/// <param name="headByName"> первый в списке элемент по именам </param>
/// <param name="headByRating"> первый в списке элемент по рейтингу </param>
/// <param name="name"> имя удаляемого </param>
/// <param name="ratingPlace"> рейтинг удаляемого </param>
void SLTFRemove(SLTFElem*& headByName, SLTFElem*& headByRating, string name, int ratingPlace)
{
    SLTFElem* current = headByName;
    SLTFElem* next;
    bool flag = false; // флаг, показывающий удалили что-то в итоге или нет

    //отдельно рассматриваю ситуацию с удалением элементов с первой позиции в списке, т.к. подходы к удалению из начала и из середины отличаются
    //смешивать их нельзя, т.к. это приведет к исключениям
    while (headByName != nullptr && headByName->name == name && headByName->ratingPlace == ratingPlace) { // пока список не пустой и значения первого элемента равно тому, которое удаляем
        headByName = current->nextByName; // делаю "головой" по именам следующий элемент в списке

        //ВАЖНО! удалять тут же из памяти элемент пока нельзя, т.к. иначе порушатся связи в списке по рейтингу. 
        //Этот элемент все равно пройдет проверку ниже, где я удалю его связи по рейтингу, а затем удалю его и из памяти

        current = headByName; // удаляю элемент по указателю на прошлую "голову"
        flag = true; // элемент был удалён (косвенно)
    }

    // если к этому моменту список пуст, то current будет указывать на пустое место в памяти, у которого нет "next"
    if (current != nullptr)
        next = current->nextByName;
    else
        next = nullptr;

    // пока не дойдем до конца списка (идём не с первого, а со второго элемента, так как первый был проверен в прошлом цикле и он точно не должен быть удалён)
    while (next != nullptr) {
        if (headByName->name == name && headByName->ratingPlace == ratingPlace) { //если текущий элемент надо удалять
            current->nextByName = next->nextByName; // убираем ссылку на удаляемый элемент из предыдущего элемента, вместо этого туда встает следующий за удаляемым

            //ВАЖНО! удалять тут же из памяти элемент пока нельзя, т.к. иначе порушатся связи в списке по рейтингу. 
            //Этот элемент все равно пройдет проверку ниже, где я удалю его связи по рейтингу, а затем удалю его и из памяти

            next = current->nextByName; // переходим на след. элемент
            flag = true; // элемент был удалён (косвенно)
        }
        else {
            current = next; // встаем вспомогательным указателем на элемент, который стоит перед тем, который сейчас будем проверять на удаление
            next = next->nextByName; // переходим на след. элемент
        }
    }

    if (flag) { // если что-то нужно удалить по настоящему
        current = headByRating;

        //отдельно рассматриваю ситуацию с удалением элементов с первой позиции в списке, т.к. подходы к удалению из начала и из середины отличаются
        //смешивать их нельзя, т.к. это приведет к исключениям
        while (headByRating != nullptr && headByRating->name == name && headByRating->ratingPlace == ratingPlace) {
            headByRating = current->nextByRating; // делаю "головой" по рейтингу следующий элемент в списке
            delete current; // ПО-НАСТОЯЩЕМУ удаляю тот элемент, который должен был
            current = headByRating; // удаляю элемент по указателю на прошлую "голову"
            flag = true; // элемент был удалён
        }

        // если к этому моменту список пуст, то current будет указывать на пустое место в памяти, у которого нет "next"
        if (current != nullptr)
            next = current->nextByRating;
        else
            next = nullptr;

        // пока не дойдем до конца списка (идём не с первого, а со второго элемента, так как первый был проверен в прошлом цикле и он точно не должен быть удалён)
        while (next != nullptr) { 
            if (headByRating->name == name && headByRating->ratingPlace == ratingPlace) { //если текущий элемент надо удалять
                current->nextByRating = next->nextByRating; // убираем ссылку на удаляемый элемент из предыдущего элемента, вместо этого туда встает следующий за удаляемым
                delete next; // ПО-НАСТОЯЩЕМУ удаляю тот элемент, который должен был
                next = current->nextByRating; // переходим на след. элемент
                flag = true; // элемент был удалён
            }
            else {
                current = next; // встаем вспомогательным указателем на элемент, который стоит перед тем, который сейчас будем проверять на удаление
                next = next->nextByRating; // переходим на след. элемент
            }
        }

        cout << "Элементы удалены!" << endl;
    }   
    else
        cout << "Нет элемента для удаления!" << endl;
}

/// <summary>
/// Метод для подсчёта количества элементов в списке
/// </summary>
/// <param name="headByName"> первый в списке элемент по именам </param>
/// <param name="headByRating"> первый в списке элемент по рейтингу </param>
/// <param name="name"> имя искомого </param>
/// <param name="ratingPlace"> рейтинг искомого </param>
int SLTFCount(SLTFElem* headByName, string name, int ratingPlace) {
    int count = 0;
    while (headByName != nullptr) { // пока не дошли до конца списка
        if (headByName->name == name && headByName->ratingPlace == ratingPlace)
            count++;

        headByName = headByName->nextByName;
    }

    return count;
}