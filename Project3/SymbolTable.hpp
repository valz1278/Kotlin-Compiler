#include <iostream>
#include <map>
#include <vector>

using namespace std;

struct values;
struct identifierData;

struct values {
  int int_value = 0;
  double double_value = 0;
  bool bool_value = false;
  string string_value = "";
  vector<identifierData> arguments;
};

struct identifierData {
  string id = "";
  int data_type = 1; /* 1: int, 2: real, 3: bool, 4: string, 5: array, 6: void */
  int id_type = 1; /* 1: variable, 2: constant, 3: function, 4: literals */
  values value;
  int array_value_type = 1;
  int array_size = 0;
  bool initialized = false;
  int index = 0;
};

class SymbolTable {
  public:
    vector<string> id_vector;
    map<string, identifierData> id_map;
    int index;
    SymbolTable();
    int insert(string id, int data_type, int size);
    int insert(string id, int data_type, int identifier_type, values value, bool initialized);
    void dump();
    identifierData* lookup(string id);
    bool doesExist(string id);
    void setReturnType(int type);
    void addArgument(string id, identifierData data);
};

string stringDataType(int data_type);
string stringIdType(int id_type);