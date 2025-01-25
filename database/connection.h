#ifndef DATABASE_H
#define DATABASE_H

#include <iostream>
#include <pqxx/pqxx>

using namespace std;
using namespace pqxx;


class DatabaseConnection {
private:
    connection * conn;

public:
    DatabaseConnection();

    void setConnection();

    connection * getConnection();

    void disconnect();

    void dropTables();

    void createTables();

    result query(string strSQL);

    result showQuery(string strSQL);

    void populateCategories();
    void populateLivros();
};

#endif
