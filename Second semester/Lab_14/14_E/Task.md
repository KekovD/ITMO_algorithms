# Секретная служба
Вы - секретный агент. Долгое время в городе N орудует банда злодеев.  
  
Недавно сообщили примерное местонахождение подозреваемых, поэтому вы выдвинулись на место и живете в находящемся рядом доме, чтобы собрать личные
данные всех его жителей.  
  
Тихой ночью вы пробираетесь в каждую квартиру и ищете их документы. Если данные жильцов некорректны, это значит, что проживающий в этой квартире человек
что-то скрывает.  
  
Вам необходимо проверить данные всех жильцов, чтобы сообщить о всех подозреваемых начальству.  
  
Данные состоят из ФИО, возраста, номера телефона, и адреса проживания Ниже приведены корректные данные документов:  
  
ФИО - это последовательность из трех слов, состоящая только из латинских букв. Каждое слово должно начинаться с заглавной буквы.  
  
Возраст - это 2 цифры. Может иметь вид: 02  
  
Номер телефона - это последовательности из 11 цифр. Ниже приведены корректные способы номеров телефона:  
  
+7(967)645-7442  
+79676567442  
79676557542   
89686557442  
+7(967)-666-74-42
  
Адрес задается следующим правилом: g.(3 заглавные буквы, которые характеризуют город)  
  
ul.(слово, характеризующее улицу, и начинающееся с заглавной буквы, и состоящее только из латинских символов)  
  
d.(последовательность цифр, длины больше 1).

## Входные данные
В первой строке задано число M -- количество жильцов.  
  
Далее идет M строк, каждая из которых содержит в себе данные жильцов.  

## Выходные данные
Выведите M строк, в каждой строке выведите YES, если данные жильца корректны, иначе выведите NO.

### STDIN
1  
Bak Ve Qd 67 +84717214117 g.MWN, ul.Mhowfwnyepb, d.87

### STDOUT
NO
