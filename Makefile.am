AUTOMAKE_OPTIONS = foreign subdir-objects

bin_PROGRAMS = airline_reservation
airline_reservation_SOURCES = src/Flight.cpp src/main.cpp

AM_CPPFLAGS = -Iinclude

# Тестовая программа Google Test
check_PROGRAMS = run_tests
run_tests_SOURCES = src/Flight.cpp tests/test_flight.cpp

run_tests_LDFLAGS = -pthread
run_tests_LDADD = -lgtest -lgtest_main

TESTS = run_tests
TESTS_ENVIRONMENT =

# ------------------------------------------------------------------------------
# Установка исполняемого файла в папку bin
# ------------------------------------------------------------------------------
BUILDDIR = bin
install-exec-hook:
	mkdir -p $(DESTDIR)$(BUILDDIR)
	mv $(DESTDIR)airline_reservation $(DESTDIR)$(BUILDDIR)/

# ------------------------------------------------------------------------------
# Дополнительные файлы/папки для включения в дистрибутив
# ------------------------------------------------------------------------------
EXTRA_DIST = INSTALL README.md Doxyfile src/ include/ docs/ tests/

# ------------------------------------------------------------------------------
# Цели (docs, test, clean, distclean, analyze-code, help)
# ------------------------------------------------------------------------------
.PHONY: docs test clean-local distclean-local analyze-code help

docs:
	@echo "Генерация документации..."
	doxygen Doxyfile

test:
	@echo "Запуск тестов (Google Test)..."
	$(MAKE) check

clean-local:
	rm -rf build/ bin/ docs/html docs/latex airline_reservation run_tests *.o

# Расширяем стандартную цель distclean
distclean-local:
	rm -rf Makefile Makefile.in config.h config.h.in config.log config.status \
	       configure autom4te.cache aclocal.m4 depcomp install-sh missing \
	       airline_reservation.tar.gz compile

analyze-code:
	@echo "Подсчёт строк кода:"
	@wc -l src/*.cpp
	@wc -l include/*.h
	@echo "Поиск функции main:"
	@grep -n "main" src/*.cpp

help:
	@echo "Доступные команды:"
	@echo "  make            - Сборка проекта"
	@echo "  make check      - Сборка и запуск тестов (Google Test)"
	@echo "  make clean      - Очистка временных файлов"
	@echo "  make distclean  - Полная очистка проекта"
	@echo "  make test       - Альтернативная команда для запуска тестов"
	@echo "  make docs       - Генерация документации Doxygen"
	@echo "  make install    - Установка проекта"
	@echo "  make dist       - Создание архива дистрибутива"
	@echo "  make help       - Показать эту справку"

# Обработка неизвестных целей
.DEFAULT:
	@echo "Ошибка: Неизвестная команда '$@'."
	@echo "Введите 'make help' для просмотра списка доступных команд."
