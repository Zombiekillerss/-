- Класс называется Listnum – односвязный список в котором лежат числовые значения(аналог массива чисел). Внутри этого класса есть приватный класс Node, 
который используется для элементов списка. Внутри класса Node есть число number – оно и является числом элемента списка и есть указатель на следующий 
элемент списка. Также есть приватный переменная size, которая хранит длину списка и есть указатель на голову этого списка.
> Конструктор класса Listnum
> Listnum()
- Длинна списка равна нулю указатель на голову равен nullptr
> Деструктор класса Listnum ~Listnum()
- Вызывается метод clear()
>1.void push_back(); // добавление в конец списка
- Создается указатель на голову основного списка. Программа двигает этот указатель до конца и выделяет память для последнего элемента списка и 
вставляет этот элемент в конец созданного указателя.
>2. void push_front(); // добавление в начало списка
- Создается новый указатель у которого следующий указатель равен голове. Потом перезаписывается голова на этот указатель
>3. void pop_back(); // удаление последнего элемента
- Создается указатель на голову. Потом программа двигает этот указатель до конца и в конец вставляет созданный элемент
>4. void pop_front(); // удаление первого элемента
- В указатель записывается следующий элемент головы. Удаляется голова и перезаписывается на указатель
>5. void insert() // добавление элемента по индексу (вставка перед
- элементом, который был ранее доступен по этому индексу)
если индекс перед которым вставляется элемент равен нулю или длине списка при увеличении индекса на 1, то выполняются методы push_front или push_back. Иначе
двигается созданный указатель на голову до индекса-1, и следующий элемент нового указателя равен следующему элементу созданного указателя, и следующий элемент 
созданного указателя обновляется на новый указатель
>6. int get_elem(); // получение элемента по индексу
- Двигает созданный указатель на голову и выводит его значение числа
>7. void remove(); // удаление элемента по индексу
- Двигает созданный указатель, меняет ему указатель на след элемент(сохраняя предыдущий следующий элемент) и удаляет сохраненный указатель
>8. size_t get_size(); // получение размера списка
- Выводит size.
>9. void clear(); // удаление всех элементов списка
- Пока size не равен нулю выполняется pop_front
>10. void set(); // замена элемента по индексу на передаваемый
- элемент
двигает созданный указатель до индекса и меняет значение числа в сдвинутом созданным указателем
>11. bool isEmpty(); // проверка на пустоту списка
- Если голова равна nullptr то выводится 1 – то есть список пусть иначе 0 – не пуст
>12. Перегрузка оператора вывода <<
- Создается список класса Listnum. Голова этого списка равна голове основного списка и выводится значение числа потом если следующий элемент есть, то выводится после 
значения числа запятая, иначе ничего не выводится. И также этот список двигается
>16. void push_front(); // вставка другого списка в начало
- Создается список и в него вставляется методом push_back элементы списка, который нужно вставить перед основным, потом вставляется в этот список методом push_back элементы 
основного списка. Потом очищается основной список методом clear и в голову основного списка вставляется голова созданного списка
