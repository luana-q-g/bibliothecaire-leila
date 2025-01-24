CXX = g++
CXXFLAGS = -Wall -std=c++17 -I. -I./livro -I./listacadastral -I./button -I./baselist -I./cestas -I./Jogo
LIBRARIES = -lsfml-graphics -lsfml-window -lsfml-system
EXECUTABLE = bibliotecaria-leila

# Arquivos-fonte
SOURCES = main.cpp baselist/baselist.cpp button/button.cpp listacadastral/lista.cpp livro/livro.cpp livro/tipoLivro.cpp cestas/cesta.cpp Jogo/jogo.cpp
OBJECTS = $(SOURCES:.cpp=.o)

# Alvo padrão (Recompila sempre)
.PHONY: all
all: clean $(EXECUTABLE)

# Linkagem final
$(EXECUTABLE): $(OBJECTS)
	$(CXX) $(CXXFLAGS) $(OBJECTS) -o $@ $(LIBRARIES)

# Regra de compilação para os objetos (Recompila sempre)
%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Executar (Recompila sempre antes de rodar)
.PHONY: run
run: all
	./$(EXECUTABLE)

# Limpeza
.PHONY: clean
clean:
	rm -f $(OBJECTS) $(EXECUTABLE)
