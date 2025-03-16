TARGET = $(BIN_DIR)/principal
OBJ_DIR = ../obj
BIN_DIR = ../bin
INC_DIR = ../include
OBJS =  $(OBJ_DIR) main.o \
		$(OBJ_DIR) ArticuloRevista.o \
		$(OBJ_DIR) DTFecha.o DTRefer.o \
  		$(OBJ_DIR) Investigador.o \
		$(OBJ_DIR) Libro.o \
		$(OBJ_DIR) PaginaWeb.o \
		$(OBJ_DIR) Publicacion.o
CFLAGS = -g -Wall -I$(INC_DIR)


$(TARGET) : $(OBJS)
	mkdir -p $(BIN_DIR)
	@g++ $(CFLAGS) $(OBJS) -o $(TARGET)

$(OBJ_DIR)/%.o : %.cpp
	mkdir -p $(OBJ_DIR)
	@g++ -c $(CFLAGS) -c $< -o $@

.PHONY: clean
clean:
	@rm -r $(OBJ_DIR) $(BIN_DIR)