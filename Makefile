CXX = g++
CXXFLAGS = -Wall -std=c++17 -I. -I./livro -I./acoesLivro -I./listacadastral -I./button -I./buttonImg -I./baselist -I./cestas -I./Jogo -I./database -I/usr/local/include
LIBRARIES = -lsfml-graphics -lsfml-window -lsfml-system -lpqxx -lpq
EXECUTABLE = bibliotecaria-leila

# Arquivos-fonte
SOURCES = main.cpp baselist/baselist.cpp button/button.cpp buttonimg/BotaoImagem.cpp listacadastral/lista.cpp livro/livro.cpp livro/acoesLivro.cpp cestas/cesta.cpp Jogo/jogo.cpp database/connection.cpp
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
