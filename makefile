CC = g++

OPTIONS = -Wall -std=c++17
SOURCE = src/bin/allegro_wrappers/*.cpp src/bin/gamelogic/*.cpp src/bin/gui/*.cpp src/bin/main.cpp
LINKING = -lallegro_monolith
TARGET = frogger

run: $(TARGET)

$(TARGET) : $(SOURCE)
	@$(CC) $(OPTIONS) -o $(TARGET) $(SOURCE) $(LINKING)
	#@./$(TARGET)
	@del $(TARGET).exe $(TARGET).out
