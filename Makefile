# Название исполняемого файла
TARGET = my_sfml_project

# Компилятор
CXX = g++

# Флаги компилятора
CXXFLAGS = -std=c++17 -Wall -Iinclude -I/path/to/sfml/include

# Флаги компоновщика для SFML
LDFLAGS = -lsfml-graphics -lsfml-window -lsfml-system

# Папки
SRC_DIR = src
OBJ_DIR = obj

# Файлы
SRC = $(wildcard $(SRC_DIR)/*.cpp)
OBJ = $(patsubst $(SRC_DIR)/%.cpp,$(OBJ_DIR)/%.o,$(SRC))

# Правило сборки
all: $(TARGET)

# Сборка исполняемого файла
$(TARGET): $(OBJ)
	$(CXX) $^ -o $@ $(LDFLAGS)

# Сборка объектных файлов
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp | $(OBJ_DIR)
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Создание папки obj
$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

# Очистка
clean:
	rm -rf $(OBJ_DIR) $(TARGET)

# Файлы, которые Make не должен удалять
.PHONY: all clean
