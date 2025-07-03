# Configuración para SDL3 (Windows + MinGW)
CC = g++
CFLAGS = -Iinclude -IC:/SDL3/SDL3-3.2.16/x86_64-w64-mingw32/include -IC:/SDL3/SDL3_image-3.0.0/x86_64-w64-mingw32/include
LDFLAGS = -LC:/SDL3/SDL3-3.2.16/x86_64-w64-mingw32/lib -LC:/SDL3/SDL3_image-3.0.0/x86_64-w64-mingw32/lib -lSDL3 -lSDL3_image

SRC = src/main.cpp src/Game.cpp src/Nave.cpp
OBJ = $(SRC:.cpp=.o)
EXEC = bin/juego.exe

all: $(EXEC)

$(EXEC): $(OBJ)
    @mkdir -p bin
    $(CC) $(OBJ) -o $@ $(LDFLAGS)

%.o: %.cpp
    $(CC) $(CFLAGS) -c $< -o $@

clean:
    del /Q $(OBJ) $(EXEC)