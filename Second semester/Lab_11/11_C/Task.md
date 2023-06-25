# Фейсконтроль
В далекой империи графов намечается большая вечеринка в честь дня рождения императора.  
  
Изначально было запланировано, что прийти на нее смогут только образцовые жители страны графов (пропаганда отрицательных циклов запрещена законом).
Но в последний момент его величеству захотелось прослыть графом прогрессивных взглядов,
и он разрешил вход на вечеринку гражданам с отрицательным циклом длины меньше k.  
  
Также оказалось, что желающих посетить мероприятие слишком много, и императорская стража не сможет проверить всех посетителей без вашей помощи. От вас требуется написать программу, способную определить, достоин ли граф пройти на вечеринку, или нет.
  
__Примечание:__ отрицательных циклов в графах не более одного, каждый приглашенный граф является связным.

## Входные данные
В первой строке записаны числа N и k, где N - число графов в очереди и k - максимальная длина цикла.  
  
Дальше идёт описание N графов:  
  
В первой строке описания каждого графа дается число вершин n≤10^5 и число ребер m≤10^5. Далее в m строках описываются ребра в формате: начало ребра 1≤start,
конец ребра 1≤end и вес ребра 1≤w≤10^6

## Выходные данные
В N строках выведите YES, если очередной гость может пройти на вечеринку, в противном случае выведите NO.

### STDIN
1 3  
6 5  
6 5 2859  
6 3 5706  
5 4 16828  
4 2 2996  
3 1 5437

### STDOUT
YES