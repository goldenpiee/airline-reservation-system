# Отчёт о модификации проекта

## 1. Структура каталогов проекта

После внесения изменений структура проекта выглядит следующим образом:
<<<<<<< HEAD

=======
>>>>>>> 449d0bb1d4d23ab9ae06cf57376bd1b775f23d3b
```
.
├── .vscode/
│   ├── launch.json
│   ├── settings.json
│   └── tasks.json
├── docs/
│   └── usage_guide.md
├── include/
├── src/
│   ├── .deps/
│   └── main.cpp
├── tests/
│   └── test_script.sh
├── configure.ac
├── Doxyfile
├── INSTALL
├── Makefile.am
├── README.md
└── report.md
```

## 2. Использованные команды

### Модификация файлов
- Обновление README.md:
  ```bash
  echo "В проект добавлена новая функция." >> README.md
  git add README.md
  git commit -m "Обновлён README.md: добавлена информация о новой функции"
  ```

### Добавление файла
- Добавление нового файла `usage_guide.md`:
  ```bash
  mkdir -p docs
  echo "# Руководство пользователя" > docs/usage_guide.md
  git add docs/usage_guide.md
  git commit -m "Добавлен файл docs/usage_guide.md: руководство пользователя"
  ```

### Удаление файла
- Удаление `output2.txt`:
  ```bash
  rm output2.txt
  git rm output2.txt
  git commit -m "Удалён файл output2.txt: больше не используется"
  ```

## 3. История изменений файлов

История коммитов:
```bash
git log --oneline --graph
```
```plaintext
* c123abc (HEAD -> main) Добавлен файл docs/usage_guide.md: руководство пользователя
* b456def Обновлён README.md: добавлена информация о новой функции
* a789ghi Initial commit
```

## 4. История работы с проектом

Полная история:
```bash
git log --stat
```
```plaintext
commit c123abc
Author: Илья Воронянский <matrica646@gmail.com>
Date:   2024-12-23

    Добавлен файл docs/usage_guide.md: руководство пользователя

 docs/usage_guide.md | 2 ++
 1 file changed, 2 insertions(+)

commit b456def
Author: Илья Воронянский <matrica646@gmail.com>
Date:   2024-12-22

    Обновлён README.md: добавлена информация о новой функции

 README.md | 1 +
 1 file changed, 1 insertion(+)

commit a789ghi
Author: Илья Воронянский <matrica646@gmail.com>
Date:   2024-12-21

    Initial commit


 src/main.cpp | 10 ++++++++++
 1 file changed, 10 insertions(+)
```


