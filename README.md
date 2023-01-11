# cpp-sqlite-tutorial

C++17 version of the [SQLite C](https://zetcode.com/db/sqlitec/) tutorial by [Jan Bodnar](https://twitter.com/janbodnar)

## Build Instructions
1. Clone this repo.
2. Configure the project: `cmake -B out/`
3. Build the project: `cmake --build out/`
4. (Optional) Run unit tests: `cmake --test-dir out/ --output-on-failure`

### Example

```
cpp-sqlite-tutorial$ cmake -B out/
-- The C compiler identification is GNU 9.4.0
-- The CXX compiler identification is GNU 9.4.0
-- Detecting C compiler ABI info

(...)

-- Configuring done
-- Generating done
-- Build files have been written to: /home/jasleon/Documents/cpp-sqlite-tutorial/out
cpp-sqlite-tutorial$ cmake --build out/
[  4%] Building C object CMakeFiles/sqlite3.dir/_deps/sqlite_content-src/sqlite3.c.o
cc1: warning: command line option ‘-Wnon-virtual-dtor’ is valid for C++/ObjC++ but not for C
[  8%] Linking C static library libsqlite3.a
[  8%] Built target sqlite3

(...)

[100%] Linking CXX executable unit_arith
[100%] Built target unit_arith
cpp-sqlite-tutorial$ ./out/app/3_insert_data
[OK] Program finished!
```

Note: `(...)` is not the actual output on the console.

## SQLite Examples

The SQLite examples of the tutorial are in the `app` folder and start with a number.

```
cpp-sqlite-tutorial$ tree app
app
├── 3_insert_data.cpp
├── calc.cpp
├── cli.cpp
└── CMakeLists.txt

0 directories, 4 files
```

I recommend using the [DB Browser for SQLite](https://sqlitebrowser.org/) for visualization.
