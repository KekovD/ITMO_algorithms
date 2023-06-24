# Простое двоичное дерево поиска
Реализуйте двоичное дерево поиска.

## Входные данные
Описание операций с деревом, количество которых не превышает 100. В каждой строке находится одна из следующих операций:

- insert x \- добавить в дерево ключ x.
- delete x \- удалить из дерева ключ x. Если ключа x в дереве нет, то ничего делать не надо.
- exists x \- если ключ x есть в дереве, выведите true, если нет - false.
- next x \- выведите минимальный элемент в дереве, строго больший x, или none если такого. нет
- prev x \- выведите максимальный элемент в дереве, строго меньший x, или none, если такого нет.

В дерево помещаются и извлекаются только целые числа, не превышающие по модулю 10^9

## Выходные данные
Выведите последовательно результат выполнения всех операций exists, next, prev. Следуйте формату выходных данных из примера.

### STDIN
insert 2  
insert 5  
insert 3  
exists 2  
exists 4  
next 4  
prev 4  
delete 5  
next 4  
prev 4  

### STDOUT
true  
false  
5  
3  
none  
3

## Примечание
Необходимо написать своё бинарное дерево.