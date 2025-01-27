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
    "nome varchar(100) not null," \
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

    // for (const auto& row : res) {
    //     for (const auto& field : row) {
    //         cout << field.c_str() << "\t";  // Exibe os campos do registro
    //     }
    //     cout << endl;  // Nova linha após cada registro
    // }

    return res;
}

void DatabaseConnection::populateCategories(){
    string sql;

    sql = "INSERT INTO categoria values('Litterature', 'Orange');" \
    "INSERT INTO categoria values('Philosophie', 'Purple');" \
    "INSERT INTO categoria values('Geographie', 'Red');" \
    "INSERT INTO categoria values('Histoire', 'Cyan');" \
    "INSERT INTO categoria values('Mathematiques', 'Yellow');" \
    "INSERT INTO categoria values('Psychologie', 'Magenta');" \
    "INSERT INTO categoria values('Informatique', 'Black');" \
    "INSERT INTO categoria values('Chimie', 'Blue');" \
    "INSERT INTO categoria values('Art', 'Green');";

    query(sql);
}

void DatabaseConnection::populateLivros(){
    string sql;

    sql = "INSERT INTO Livro (nome, autor, nome_categoria, ano_lancamento, editora) values('Libras: connaissance au-delà des signes', 'Maria Cristina da Cunha', 'Litterature', 2011, 'Pearson');" \
    "INSERT INTO Livro (nome, autor, nome_categoria, ano_lancamento, editora) values('Communication et langage', 'Thelma de Carvalho Guimarães', 'Litterature', 2012, 'Pearson');" \
    "INSERT INTO Livro (nome, autor, nome_categoria, ano_lancamento, editora) values('Théorie de la littérature I', 'Pedro Paulo da Silva', 'Litterature', 2009, 'Pearson');" \
    "INSERT INTO Livro (nome, autor, nome_categoria, ano_lancamento, editora) values('Langue latine', 'Charlene Martins Miotti', 'Litterature', 2010, 'Pearson');";

    // Philosophie
    sql = sql+"INSERT INTO Livro (nome, autor, nome_categoria, ano_lancamento, editora) values('Introduction à la philosophie', 'João Mattar', 'Philosophie', 2010, 'Pearson');" \
    "INSERT INTO Livro (nome, autor, nome_categoria, ano_lancamento, editora) values('Éthique', 'Maria Thereza Pompa Antunes', 'Philosophie', 2012, 'Pearson');" \
    "INSERT INTO Livro (nome, autor, nome_categoria, ano_lancamento, editora) values('Courants modernes de philosophie', 'José Ferraz Neto', 'Philosophie', 2013, 'Pearson');" \
    "INSERT INTO Livro (nome, autor, nome_categoria, ano_lancamento, editora) values('Généalogie de la morale', 'Friedrich Nietzsche', 'Philosophie', 1887, 'Vozes');";

    // Géographie
    sql = sql+"INSERT INTO Livro (nome, autor, nome_categoria, ano_lancamento, editora) values('Hydrologie', 'Diego Barreto de Oliveira', 'Geographie', 2015, 'Pearson');" \
    "INSERT INTO Livro (nome, autor, nome_categoria, ano_lancamento, editora) values('Espace géographique: enseignement et représentation', 'Rosangela Doin de Almeida', 'Geographie', 1989, 'Contexto');" \
    "INSERT INTO Livro (nome, autor, nome_categoria, ano_lancamento, editora) values('Pensée géographique brésilienne', 'Ruy Moreira', 'Geographie', 2008, 'Contexto');" \
    "INSERT INTO Livro (nome, autor, nome_categoria, ano_lancamento, editora) values('Mondialisation et espace géographique', 'Eustáquio de Sene', 'Geographie', 2004, 'Contexto');";

    // Histoire
    sql = sql+"INSERT INTO Livro (nome, autor, nome_categoria, ano_lancamento, editora) values('À l époque des épices: l empire du poivre et du sucre', 'Fábio Pestana', 'Histoire', 2006, 'Contexto');" \
    "INSERT INTO Livro (nome, autor, nome_categoria, ano_lancamento, editora) values('Dictionnaire des dates de l histoire du Brésil', 'Circe Bittencour', 'Histoire', 2007, 'Contexto');" \
    "INSERT INTO Livro (nome, autor, nome_categoria, ano_lancamento, editora) values('Histoire du café', 'Ana Luiza Martins', 'Histoire', 2008, 'Contexto');" \
    "INSERT INTO Livro (nome, autor, nome_categoria, ano_lancamento, editora) values('Les premières civilisations', 'Jaime Pinsky', 'Histoire', 2011, 'Contexto');";

    // Mathématiques
    sql = sql+"INSERT INTO Livro (nome, autor, nome_categoria, ano_lancamento, editora) values('Géométrie analytique: un traitement vectoriel', 'Ivan de Camargo', 'Mathematiques', 2005, 'Pearson');" \
    "INSERT INTO Livro (nome, autor, nome_categoria, ano_lancamento, editora) values('Mathématiques financières', 'André Wakamatsu', 'Mathematiques', 2018, 'Pearson');" \
    "INSERT INTO Livro (nome, autor, nome_categoria, ano_lancamento, editora) values('Méthodes numériques en équations différentielles', 'Marina Vargas', 'Mathematiques', 2021, 'Intersaberes');" \
    "INSERT INTO Livro (nome, autor, nome_categoria, ano_lancamento, editora) values('Géométries non euclidiennes', 'Nelson Pereira', 'Mathematiques', 2020, 'Intersaberes');";

    // Psychologie
    sql = sql+"INSERT INTO Livro (nome, autor, nome_categoria, ano_lancamento, editora) values('Théories de la personnalité', 'Howard S. Friedman', 'Psychologie', 2003, 'Pearson');" \
    "INSERT INTO Livro (nome, autor, nome_categoria, ano_lancamento, editora) values('Introduction à la psychologie', 'Charles G. Morris', 'Psychologie', 2004, 'Pearson');" \
    "INSERT INTO Livro (nome, autor, nome_categoria, ano_lancamento, editora) values('La psychanalyse dans les trames de la ville', 'Bernardo Tanis', 'Psychologie', 2009, 'Pearson');" \
    "INSERT INTO Livro (nome, autor, nome_categoria, ano_lancamento, editora) values('Burnout: quand le travail menace le bien-être des travailleurs', 'Ana Maria Benevides Pereira', 'Psychologie', 2014, 'Pearson');";

    // Informatique
    sql = sql+"INSERT INTO Livro (nome, autor, nome_categoria, ano_lancamento, editora) values('Apprenez la programmation orientée objet en 21 jours', 'Anthony Sintes', 'Informatique', 2002, 'Pearson');" \
    "INSERT INTO Livro (nome, autor, nome_categoria, ano_lancamento, editora) values('Formation en langage C++: module 1', 'Victorine Viviane Mizrahi', 'Informatique', 1996, 'Pearson');" \
    "INSERT INTO Livro (nome, autor, nome_categoria, ano_lancamento, editora) values('Manuel complet de Linux: guide de l administrateur', 'Evi Nemeth', 'Informatique', 2004, 'Pearson');" \
    "INSERT INTO Livro (nome, autor, nome_categoria, ano_lancamento, editora) values('Compilateurs: principes, techniques et outils', 'Alfred V. Alho', 'Informatique', 2007, 'Pearson');";

    // Chimie
    sql = sql+"INSERT INTO Livro (nome, autor, nome_categoria, ano_lancamento, editora) values('Chimie organique', 'Bianca Sandrino', 'Chimie', 2020, 'Intersaberes');" \
    "INSERT INTO Livro (nome, autor, nome_categoria, ano_lancamento, editora) values('Chimie quantique: origines et applications', 'Liziane Barbara Bugalski', 'Chimie', 2019, 'Intersaberes');" \
    "INSERT INTO Livro (nome, autor, nome_categoria, ano_lancamento, editora) values('Manuel de l air comprimé et des gaz', 'John P. Rollins', 'Chimie', 2003, 'Pearson');" \
    "INSERT INTO Livro (nome, autor, nome_categoria, ano_lancamento, editora) values('Études d électrochimie: réactions chimiques et énergie', 'Ana Luiza Lorenzen', 'Chimie', 2017, 'Intersaberes');";

    // Art
    sql = sql+"INSERT INTO Livro (nome, autor, nome_categoria, ano_lancamento, editora) values('Esthétique et histoire de l art', 'Humberta Gomes Machado Porto', 'Art', 2016, 'Pearson');" \
    "INSERT INTO Livro (nome, autor, nome_categoria, ano_lancamento, editora) values('Histoire du cinéma mondial', 'Fernando Mascarello', 'Art', 2014, 'Papirus');" \
    "INSERT INTO Livro (nome, autor, nome_categoria, ano_lancamento, editora) values('Beethoven: les nombreuses facettes d un génie', 'João Mauricio Galindo', 'Art', 2019, 'Contexto');" \
    "INSERT INTO Livro (nome, autor, nome_categoria, ano_lancamento, editora) values('Le cinéma de Quentin Tarantino', 'Mauro Baptista', 'Art', 2018, 'Papirus');";

    query(sql);
}

#endif