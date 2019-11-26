ifdef ComSpec
	REMOVE = del /F /Q
	LINKING = -lallegro_monolith
	TARGET_END = exe
else
	REMOVE = rm -f
	LINKING = -lallegro -lallegro_primitives -lallegro_image
	TARGET_END = out
endif

CC = g++

OPTIONS = -Wall -std=c++17
SOURCE = src/bin/allegro_wrappers/*.cpp src/bin/gamelogic/*.cpp src/bin/gui/*.cpp src/bin/main.cpp
TARGET = frogger
#OLD_SOURCE = src_old/bin/*.cpp
#OLD_TARGET = frogger

all: compile run clean

compile: $(SOURCE)
	@$(CC) $(OPTIONS) -o $(TARGET) $(SOURCE) $(LINKING)
	
run: $(SOURCE)
	@./$(TARGET)

clean: $(SOURCE)
	@$(REMOVE) $(TARGET).$(TARGET_END)

#old: $(OLD_TARGET)

#$(OLD_TARGET) : $(OLD_SOURCE)
#	@$(CC) $(OPTIONS) -o $(OLD_TARGET) $(OLD_SOURCE) $(LINKING)
#	@./$(OLD_TARGET).$(TARGET_END)
#	@$(REMOVE) $(OLD_TARGET).$(TARGET_END)
