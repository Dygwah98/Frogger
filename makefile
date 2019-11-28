ifdef ComSpec
	REMOVE = del /F /Q
	LINKING = -lallegro_monolith
	TARGET_END = .exe
else
	REMOVE = rm -f
	LINKING = -lallegro -lallegro_primitives -lallegro_image -lallegro_font -lallegro_ttf
	TARGET_END = ""
endif

CC = g++

OPTIONS = -Wall -std=c++17
SOURCE = src/bin/allegro_wrappers/*.cpp src/bin/gamelogic/*.cpp src/bin/gui/*.cpp src/bin/main.cpp
TARGET = frogger

all: compile run clean

compile: $(SOURCE)
	@$(CC) $(OPTIONS) -o $(TARGET) $(SOURCE) $(LINKING)
	
run: $(SOURCE)
	@./$(TARGET)

clean: $(SOURCE)
	@$(REMOVE) $(TARGET)$(TARGET_END)