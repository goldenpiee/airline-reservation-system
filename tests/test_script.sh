#!/bin/bash

# Определяем путь к исполняемому файлу
EXECUTABLE=./airline_reservation

# Проверяем, существует ли исполняемый файл
if [ ! -f "$EXECUTABLE" ]; then
  echo "Ошибка: Исполняемый файл $EXECUTABLE не найден. Сначала выполните сборку проекта."
  exit 1
fi

# Тестовые сценарии
echo "Запуск тестов..."

# Тест 1: Бронирование билета
echo "Тест 1: Проверка бронирования билета..."
echo -e "1\nJohn\nDoe\n12345\n+123456789\n5\n3\n5\n6" | $EXECUTABLE > tests/output2.txt
if grep -q "Your reservation number is" output2.txt; then
  echo "Тест 1: Успешно"
else
  echo "Тест 1: Неудачно"
fi



echo "Тестирование завершено."
