CC = g++

OPTIONS = -Wall -std=c++17
SOURCE = src/bin/*.cpp
LINKING = -lallegro_monolith
TARGET = frogger

cleanrun: $(TARGET)

$(TARGET) : $(SOURCE)
	@$(CC) $(OPTIONS) -o $(TARGET) $(SOURCE) $(LINKING)
	@./$(TARGET)
	@del $(TARGET).exe $(TARGET).out