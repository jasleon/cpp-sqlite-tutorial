#include <sqlite3.h>

#include <iostream>
#include <string>
#include <string_view>
using std::cout;
using std::string;
using std::string_view;

int main() {
  sqlite3 *db = nullptr;
  auto status = sqlite3_open("test.db", &db);
  if (status != SQLITE_OK) {
    const string_view err{sqlite3_errmsg(db)};
    cout << "[ERROR] Opening the database: " << err << '\n';
    sqlite3_close(db);
    return 1;
  }
  const string statement = R"(
        DROP TABLE IF EXISTS Cars;
        CREATE TABLE Cars(Id INT, Name TEXT, Price INT);
        INSERT INTO Cars VALUES(1, 'Audi', 52642);
        INSERT INTO Cars VALUES(2, 'Mercedes', 57127);
        INSERT INTO Cars VALUES(3, 'Skoda', 9000);
        INSERT INTO Cars VALUES(4, 'Volvo', 29000);
        INSERT INTO Cars VALUES(5, 'Bentley', 350000);
        INSERT INTO Cars VALUES(6, 'Citroen', 21000);
        INSERT INTO Cars VALUES(7, 'Hummer', 41400);
        INSERT INTO Cars VALUES(8, 'Volkswagen', 21600);
    )";
  char *errmsg = nullptr;
  status = sqlite3_exec(db, statement.c_str(), nullptr, nullptr, &errmsg);
  if (status != SQLITE_OK) {
    const string_view err{errmsg};
    cout << "[ERROR] Executing multiple SQL statements: " << err << '\n';
    sqlite3_free(errmsg);
    sqlite3_close(db);
    return 2;
  }
  cout << "[OK] Program finished!\n";
  sqlite3_close(db);
}
