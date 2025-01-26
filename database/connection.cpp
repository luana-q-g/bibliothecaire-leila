#include <iostream>
#include <pqxx/pqxx>
#include <string>
#include "connection.h"

#ifndef DATABASE_CPP
#define DATABASE_CPP

using namespace std;
using namespace pqxx;

DatabaseConnection::DatabaseConnection(){
    setConnection();
    dropTables();
    createTables();       

    populateCategories();
    populateLivros();
}

void DatabaseConnection::setConnection(){
    conn = new connection(
        "dbname = poo user = leila password = leila \
        hostaddr = 127.0.0.1 port = 5432");

}

connection * DatabaseConnection::getConnection(){
    return conn;
}

void DatabaseConnection::disconnect(){
    conn->disconnect();
}

void DatabaseConnection::dropTables(){
    string sql;
    sql = "DROP TABLE Livro;" \
    "DROP TABLE Categoria;";

    query(sql);
}

void DatabaseConnection::createTables(){
    string sql_categoria;
    string sql_livro;

    sql_categoria = "CREATE TABLE IF NOT EXISTS Categoria(" \
    "nome varchar(15) primary key," \
    "cor varchar(30) );";

    sql_livro = "CREATE TABLE IF NOT EXISTS Livro("  \
    "id serial primary key not null," \
    "nome varchar(60) not null," \
    "autor varchar(50)," \
    "editora varchar(20)," \
    "ano_lancamento int," \
    "nome_categoria varchar(15) references Categoria(nome));";

    query(sql_categoria);
    query(sql_livro);
    cout << "Table created successfully" << endl;
}

result DatabaseConnection::query(string strSQL){
    //SetConnection();
    work trans(*conn);

    result res=trans.exec(strSQL);

    trans.commit();
    return res;
}

result DatabaseConnection::showQuery(string strSQL){
    //SetConnection();
    nontransaction nontrans(*conn);

    result res=nontrans.exec(strSQL);

    for (const auto& row : res) {
        for (const auto& field : row) {
            cout << field.c_str() << "\t";  // Exibe os campos do registro
        }
        cout << endl;  // Nova linha após cada registro
    }

    return res;
}

void DatabaseConnection::populateCategories(){
    string sql;

    sql = "INSERT INTO categoria values('Litterature', 'Blue');" \
    "INSERT INTO categoria values('Philosophie', 'Green');" \
    "INSERT INTO categoria values('Geographie', 'Yellow');" \
    "INSERT INTO categoria values('Histoire', 'Red');" \
    "INSERT INTO categoria values('Mathematiques', 'Cyan');" \
    "INSERT INTO categoria values('Psychologie', 'Magenta');" \
    "INSERT INTO categoria values('Informatique', 'Black');" \
    "INSERT INTO categoria values('Chimie', 'Orange');" \
    "INSERT INTO categoria values('Art', 'Purple');";

    query(sql);
}

void DatabaseConnection::populateLivros(){
    string sql;

    sql = "INSERT INTO Livro (nome, autor, nome_categoria, ano_lancamento, editora) values('Libras: conhecimento além dos sinais', 'Maria Cristina da Cunha', 'Litterature', 2011, 'Pearson');" \
    "INSERT INTO Livro (nome, autor, nome_categoria, ano_lancamento, editora) values('Comunicação e linguagem', 'Thelma de Carvalho Guimarães', 'Litterature', 2012, 'Pearson');" \
    "INSERT INTO Livro (nome, autor, nome_categoria, ano_lancamento, editora) values('Teoria da Literatura I', 'Pedro Paulo da Silva', 'Litterature', 2009, 'Pearson');" \
    "INSERT INTO Livro (nome, autor, nome_categoria, ano_lancamento, editora) values('Língua latina', 'Charlene Martins Miotti', 'Litterature', 2010, 'Pearson');";

    // Filosofia
    sql = sql+"INSERT INTO Livro (nome, autor, nome_categoria, ano_lancamento, editora) values('Introdução à Filosofia', 'João Mattar', 'Philosophie', 2010, 'Pearson');" \
    "INSERT INTO Livro (nome, autor, nome_categoria, ano_lancamento, editora) values('Ética', 'Maria Thereza Pompa Antunes', 'Philosophie', 2012, 'Pearson');" \
    "INSERT INTO Livro (nome, autor, nome_categoria, ano_lancamento, editora) values('Correntes modernas de filosofia', 'José Ferraz Neto', 'Philosophie', 2013, 'Pearson');" \
    "INSERT INTO Livro (nome, autor, nome_categoria, ano_lancamento, editora) values('Genealogia da Mora', 'Friedrich Nietzsche', 'Philosophie', 1887, 'Vozes');";

    // Geografia
    sql = sql+"INSERT INTO Livro (nome, autor, nome_categoria, ano_lancamento, editora) values('Hidrologia', 'Diego Barreto de Oliveira', 'Geographie', 2015, 'Pearson');" \
    "INSERT INTO Livro (nome, autor, nome_categoria, ano_lancamento, editora) values('Espaço Geográfico: ensino e representação', 'Rosangela Doin de Almeida', 'Geographie', 1989, 'Contexto');" \
    "INSERT INTO Livro (nome, autor, nome_categoria, ano_lancamento, editora) values('Pensamento geográfico brasileiro', 'Ruy Moreira', 'Geographie', 2008, 'Contexto');" \
    "INSERT INTO Livro (nome, autor, nome_categoria, ano_lancamento, editora) values('Globalização e espaço geográfico', 'Eustáquio de Sene', 'Geographie', 2004, 'Contexto');";

    // História
    sql = sql+"INSERT INTO Livro (nome, autor, nome_categoria, ano_lancamento, editora) values('No Tempo das Especiarias: o império da pimenta e do açúcar', 'Fábio Pestana', 'Histoire', 2006, 'Contexto');" \
    "INSERT INTO Livro (nome, autor, nome_categoria, ano_lancamento, editora) values('Dicionário de Datas da História do Brasi', 'Circe Bittencour', 'Histoire', 2007, 'Contexto');" \
    "INSERT INTO Livro (nome, autor, nome_categoria, ano_lancamento, editora) values('História do Café', 'Ana Luiza Martins', 'Histoire', 2008, 'Contexto');" \
    "INSERT INTO Livro (nome, autor, nome_categoria, ano_lancamento, editora) values('As Primeiras Civilizações', 'Jaime Pinsky', 'Histoire', 2011, 'Contexto');";

    // Matemática
    sql = sql+"INSERT INTO Livro (nome, autor, nome_categoria, ano_lancamento, editora) values('Geometria Analítica: Um Tratamento Vetoria', 'Ivan de Camargo', 'Mathematiques', 2005, 'Pearson');" \
    "INSERT INTO Livro (nome, autor, nome_categoria, ano_lancamento, editora) values('Matemática financeira', 'André Wakamatsu', 'Mathematiques', 2018, 'Pearson');" \
    "INSERT INTO Livro (nome, autor, nome_categoria, ano_lancamento, editora) values('Métodos numéricos em equações diferenciais', 'Marina Vargas', 'Mathematiques', 2021, 'Intersaberes');" \
    "INSERT INTO Livro (nome, autor, nome_categoria, ano_lancamento, editora) values('Geometrias Não Euclidianas', 'Nelson Pereira', 'Mathematiques', 2020, 'Intersaberes');";

    // Psicologia
    sql = sql+"INSERT INTO Livro (nome, autor, nome_categoria, ano_lancamento, editora) values('Teorias da Personalidade', 'Howard S. Friedman', 'Psychologie', 2003, 'Pearson');" \
    "INSERT INTO Livro (nome, autor, nome_categoria, ano_lancamento, editora) values('Introdução à Psicologia', 'Charles G. Morris', 'Psychologie', 2004, 'Pearson');" \
    "INSERT INTO Livro (nome, autor, nome_categoria, ano_lancamento, editora) values('A Psicanálise nas Tramas da Cidade', 'Bernardo Tanis', 'Psychologie', 2009, 'Pearson');" \
    "INSERT INTO Livro (nome, autor, nome_categoria, ano_lancamento, editora) values('Burnout: quando o trabalho ameaça o bem-estar do trabalhador', 'Ana Maria Benevides Pereira', 'Psychologie', 2014, 'Pearson');";

    // Informática
    sql = sql+"INSERT INTO Livro (nome, autor, nome_categoria, ano_lancamento, editora) values('Aprenda Programação Orientada a Objetos em 21 dias', 'Anthony Sintes', 'Informatique', 2002, 'Pearson');" \
    "INSERT INTO Livro (nome, autor, nome_categoria, ano_lancamento, editora) values('Treinamento em Linguagem C++: módulo 1', 'Victorine Viviane Mizrahi', 'Informatique', 1996, 'Pearson');" \
    "INSERT INTO Livro (nome, autor, nome_categoria, ano_lancamento, editora) values('Manual Completo do Linux: guia do administrador', 'Evi Nemeth', 'Informatique', 2004, 'Pearson');" \
    "INSERT INTO Livro (nome, autor, nome_categoria, ano_lancamento, editora) values('Compiladores: princípios, técnicas e ferramentas', 'Alfred V. Alho', 'Informatique', 2007, 'Pearson');";

    // Química
    sql = sql+"INSERT INTO Livro (nome, autor, nome_categoria, ano_lancamento, editora) values('Química Orgânica', 'Bianca Sandrino', 'Chimie', 2020, 'Intersaberes');" \
    "INSERT INTO Livro (nome, autor, nome_categoria, ano_lancamento, editora) values('Química Quântica: Origens e Aplicações', 'Liziane Barbara Bugalski', 'Chimie', 2019, 'Intersaberes');" \
    "INSERT INTO Livro (nome, autor, nome_categoria, ano_lancamento, editora) values('Manual de Ar Comprimido e Gases', 'John P. Rollins', 'Chimie', 2003, 'Pearson');" \
    "INSERT INTO Livro (nome, autor, nome_categoria, ano_lancamento, editora) values('Estudos de eletroquímica: reações químicas e energia', 'Ana Luiza Lorenzen', 'Chimie', 2017, 'Intersaberes');";

    // Arte
    sql = sql+"INSERT INTO Livro (nome, autor, nome_categoria, ano_lancamento, editora) values('Estética e história da arte', 'Humberta Gomes Machado Porto', 'Art', 2016, 'Pearson');" \
    "INSERT INTO Livro (nome, autor, nome_categoria, ano_lancamento, editora) values('História do cinema mundia', 'Fernando Mascarello', 'Art', 2014, 'Papirus');" \
    "INSERT INTO Livro (nome, autor, nome_categoria, ano_lancamento, editora) values('Beethoven: as muitas faces de um gênio', 'João Mauricio Galindo', 'Art', 2019, 'Contexto');" \
    "INSERT INTO Livro (nome, autor, nome_categoria, ano_lancamento, editora) values('O cinema de Quentin Tarantino', 'Mauro Baptista', 'Art', 2018, 'Papirus');";

    query(sql);
}

#endif