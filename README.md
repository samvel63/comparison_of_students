# Курсовая работа № 7. Обработка последовательной файловой структуры на языке Си. #
## Вариант 44. Выяснить разницу учеников в p-х классах и 10-х. ##

***

### План: ###

<p>Разработать последовательную структуру данных для представления простейшей базы данных на файлах в СП Си в соответствии с заданным вариантом. Составить программу генерации внешнего текстового файла заданной структуры, содержащего представленый набор записей. Распечатать содержимое сгенерированного файла в виде таблицы и выполнить над ним заданное действие.</p>

***

### О программе: ###

<p>Программа перевод текстовый файл в бинарный, чтобы выполнять необходимые действия. Так же программа может печатать список учеников и в каких классах они учатся. И последнее, что может программа - это вывести разность количества учеников между 10-м классом и всеми другими.</p>

***

### Использование программы: ###

Для начала необходимо собрать программу командой `make`. Далее есть три команды запускающиеся следующим образом `./execute file`, `./print file` и `./generate file1 file2`:

    1. Чтобы использовать `./execute file` и `./print file` нужно перевести текстовый файл в бинарный - для этого есть программа, запускаяющася командой `./generate file1 file2`. file1 переводит в бинарный file2.
    2. Если необходимо распечатать список учеников, то можно использовать программу `./print file`.
    3. Чтобы выполнить вариант задания, необходимо выполнить команду `./execute file`.

Чтобы очистить корень проекта, необходимо ввести команду `make clean`.

***