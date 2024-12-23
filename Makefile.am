AUTOMAKE_OPTIONS = foreign subdir-objects

bin_PROGRAMS = airline_reservation
airline_reservation_SOURCES = src/main.cpp

# Установка исполняемого файла в папку bin
BUILDDIR = bin
install-exec-hook:
	mkdir -p $(DESTDIR)$(BUILDDIR)
	mv $(DESTDIR)airline_reservation $(DESTDIR)$(BUILDDIR)/

EXTRA_DIST = INSTALL README.md Doxyfile src/ include/ docs/



# Зависимость от создания bin
$(BUILDDIR):
	mkdir -p $(BUILDDIR)

# Цели
.PHONY: docs test clean distclean-local analyze-code help

docs:
	@echo "Building documentation..."
	doxygen Doxyfile

test:
	@echo "Running tests..."
	bash tests/test_script.sh

clean-local:
	rm -rf build/ bin/ docs/html docs/latex airline_reservation *.o

# Расширяем стандартный distclean
distclean-local:
	rm -rf Makefile Makefile.in config.h config.h.in config.log config.status \
	       configure autom4te.cache aclocal.m4 depcomp install-sh missing \
	       airline_reservation.tar.gz compile

analyze-code:
	@echo "Подсчёт строк кода:"
	@wc -l src/*.cpp
	@echo "Поиск функции main:"
	@grep -n "main" src/*.cpp

# Справка
help:
	@echo "Доступные команды:"
	@echo "  make            - Сборка проекта"
	@echo "  make clean      - Очистка временных файлов"
	@echo "  make distclean  - Полная очистка проекта"
	@echo "  make test       - Запуск тестов"
	@echo "  make docs       - Генерация документации"
	@echo "  make install    - Установка проекта"
	@echo "  make dist       - Создание архива дистрибутива"
	@echo "  make help       - Показать эту справку"

# Обработка неизвестных целей
.DEFAULT:
	@echo "Ошибка: Неизвестная команда '$@'."
	@echo "Введите 'make help' для просмотра списка доступных команд."