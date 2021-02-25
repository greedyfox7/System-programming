#!/bin/bash

main () {

echo 'Текущий каталог'
pwd

file_exist ()
{
	echo 'Текущие файлы в каталоге'
	ls
	echo 'Введите имя файла'
	read filename
	if [ ! -f $filename ] 
	then echo 'Такого файла нет, повторите попытку'
	file_exist
	fi
}

file_exist

echo "Вы выбрали файл $filename"
echo 'Введите дату, чтобы определить, изменялось ли содержимое файла после указанной даты  Год-Месяц-Дата Час:Минута'
read date

MOD_DATE=$(date -r "$filename" +%s)
CHECK_DATE=$(date -d "$date" +%s)

if [ "$MOD_DATE" -gt "$CHECK_DATE" ]
then
    echo "Содержимое файла ($filename) МЕНЯЛОСЬ! После введенной вами даты ($date)"
    exit 120
else
    echo "Содержимое файла ($filename) не изменялось, после введенной вами даты ($date)"
fi

choice()
{
echo 'Хотите начать сначала? Если нет - вы выйдите из цикла. Введите y/n'
read ans

if [ $ans = y ]; then
    main
elif [ $ans = n ]; then
    :
else
    echo "Answer 'y' or 'n'"
    choice
fi
}
choice

}

echo 'Вас приветсвует Савельев Д.С. гр.747'
echo 'Название программы: проверка модификации файла, после указанной даты'
echo 'В данной программе, вы должны выбрать файл, который хотите проверить, а затем ввести дату, для проверки'

main
