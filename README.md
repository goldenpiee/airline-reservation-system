# Airline Reservation System

Программа для управления бронированием авиабилетов. Этот проект позволяет пользователям бронировать, изменять и отменять билеты на рейсы. Система предоставляет возможность выбора мест, указания предпочтений по питанию и просмотра информации о бронированиях.

---

## Особенности

- **Бронирование билетов**:

  - Ввод информации о пассажире.
  - Выбор места из доступных.
  - Выбор типа питания: вегетарианское, не вегетарианское, или без питания.

- **Управление бронированием**:

  - Отмена бронирования.
  - Изменение выбранного места.

- **Информация о бронированиях**:

  - Просмотр деталей пассажиров по номеру бронирования.
  - Отображение всех активных бронирований.

- **Документация**:

  - Генерация документации с помощью **Doxygen**.
  - HTML и PDF версии.

---

## Установка

### Требования:

- **Компилятор C++**: GCC 7.5 или новее.
- **Autotools**: `autoconf`, `automake`, `libtool`.
- **Doxygen**: для генерации документации.
- **Graphviz**: для построения графиков в документации.

### Шаги установки:

1. **Клонируйте репозиторий**:

   ```bash
   git clone <URL>
   cd airline_reservation
   ```

2. **Сборка проекта**:

   ```bash
   autoreconf --install
   ./configure
   make
   ```

3. **Установка**:

   ```bash
   sudo make install
   ```

---

## Запуск

После сборки запустите исполняемый файл:

```bash
./airline_reservation
```

---

## Команды Makefile

Проект поддерживает следующие команды Makefile:

| Команда          | Описание                                                |
| ---------------- | ------------------------------------------------------- |
| `make`           | Сборка проекта.                                         |
| `make install`   | Установка программы в `/usr/local/bin`.                 |
| `make uninstall` | Удаление программы из `/usr/local/bin`.                 |
| `make docs`      | Генерация документации (HTML и LaTeX).                  |
| `make test`      | Запуск тестов.                                          |
| `make clean`     | Очистка временных файлов.                               |
| `make distclean` | Полная очистка проекта, включая сгенерированные файлы.  |
| `make dist`      | Создание архива проекта (`airline_reservation.tar.gz`). |

---

## Документация

Для генерации документации выполните:

```bash
make docs
```

После этого:

- **HTML-документация**: откройте `docs/html/index.html`.
- **LaTeX-документация**: скомпилируйте `docs/latex/refman.tex` в PDF.

---

## Тестирование

Для запуска тестов выполните:

```bash
make test
```

Пример вывода тестов сохраняется в `test_output.txt`.

---

## Структура проекта

```
airline_reservation/
├── src/                # Исходные файлы C++
│   └── main.cpp        # Основная логика программы
├── include/            # Заголовочные файлы
├── docs/               # Генерация документации (HTML и LaTeX)
├── tests/              # Скрипты для тестирования
│   └── test_script.sh  # Тесты для программы
├── Makefile.am         # Настройки сборки проекта
├── configure.ac        # Конфигурация Autotools
└── Doxyfile            # Конфигурация для Doxygen
```

---

## Пример использования

1. После запуска программы вам будет предложено меню:

   ```
   Welcome to Airline Reservation System
   1. Book Ticket
   2. Cancel Ticket
   3. Change Reservation
   4. Passenger Details
   5. Get Booking Details
   6. Exit
   ```

2. Выберите опцию, например, бронирование билета (`1`):

   ```
   Enter your first name: John
   Enter your last name: Doe
   Enter your ID: 12345
   Enter your phone number: +123456789
   Available seats:
   |1| |2| |3| ...
   Enter the seat number: 5
   Choose your food preference:
   1. Veg
   2. Non-Veg
   3. No Food
   Your reservation number is: 1001
   ```

3. Все действия записываются в систему, а пользователю отображается номер бронирования.

---

## Контрибьютинг

Если вы хотите внести свой вклад в проект:

1. Форкните репозиторий.
2. Создайте новую ветку для изменений:
   ```bash
   git checkout -b feature/your-feature
   ```
3. Сделайте изменения и закоммитьте их:
   ```bash
   git commit -m "Добавил новую функцию."
   ```
4. Отправьте изменения в ваш форк и создайте Pull Request.

---

## Лицензия

Этот проект распространяется под лицензией **MIT**.

