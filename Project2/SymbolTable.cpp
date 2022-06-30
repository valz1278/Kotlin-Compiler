#include "SymbolTable.hpp"

SymbolTable::SymbolTable()
{
  index = 0;
}

int SymbolTable::insert(string id, int data_type, int identifier_type, values value, bool initialized)
{
  if (doesExist(id))
    return -1;
  symbols.push_back(id);
  table_map[id].id = id;
  table_map[id].data_type = data_type;
  table_map[id].id_type = identifier_type;
  table_map[id].value = value;
  table_map[id].initialized = initialized;
  index++;
  return 1;
}

int SymbolTable::insert(string id, int data_type, int size)
{
  if(doesExist(id))
    return -1;

  values value;
  value.arguments = vector<identifierData>(size);
  for(int i = 0; i < size; i++){
    value.arguments[i].data_type = data_type;
    value.arguments[i].id_type = 1;
  }
  
  symbols.push_back(id);
  table_map[id].id = id;
  table_map[id].data_type = 5;
  table_map[id].id_type = 1;
  table_map[id].value = value;
  table_map[id].array_value_type = data_type;
  table_map[id].array_size = size;
  table_map[id].initialized = false;
  index++;
  return 1;
}

identifierData *SymbolTable::lookup(string id)
{
  if (doesExist(id))
    return new identifierData(table_map[id]);
  else
    return NULL;
}

void SymbolTable::dump()
{
  cout << "id\tdata_type\tid_type\t\tvalues" << endl;

  for (int i = 0; i < index; ++i)
  {
    string temp;
    identifierData data = table_map[symbols[i]];
    temp = data.id + "\t";

    if (data.data_type == 1)
      temp += "int";
    else if (data.data_type == 2)
      temp += "float";
    else if (data.data_type == 3)
      temp += "bool";
    else if (data.data_type == 4)
      temp += "string";
    else if (data.data_type == 5)
      temp += "array";
    else if (data.data_type == 6)
      temp += "void";

    temp += "\t\t";

    if (data.id_type == 1)
      temp += "variable";
    else if (data.id_type == 2)
      temp += "constant";
    else if (data.id_type == 3)
      temp += "constant";

    temp += "\t";

    if (data.initialized)
    {
      if (data.data_type == 1)
        temp += to_string(data.value.i_val);
      else if (data.data_type == 2)
        temp += to_string(data.value.d_val);
      else if (data.data_type == 3)
        temp += (data.value.b_val) ? "true" : "false";
      else if (data.data_type == 4)
        temp += data.value.s_val;
      
    }

    if (data.id_type == 3)
    {
      temp += "{ ";
      for (int i = 0; i < data.value.arguments.size(); ++i)
      {
        if (data.value.arguments[i].data_type == 1)
          temp += "int ";
        else if (data.value.arguments[i].data_type == 2)
          temp += "float ";
        else if (data.value.arguments[i].data_type == 3)
          temp += "bool ";
        else if (data.value.arguments[i].data_type == 4)
          temp += "string ";
        
      }
      temp += "}";
    }

    if (data.data_type == 5)
    {
      temp += "{ ";
      if (data.value.arguments[0].data_type == 1)
        temp += "int, ";
      else if (data.value.arguments[0].data_type == 2)
        temp += "float, ";
      else if (data.value.arguments[0].data_type == 3)
        temp += "bool, ";
      else if (data.value.arguments[0].data_type == 4)
        temp += "string, ";
      temp += to_string(data.value.arguments.size()) + " }";
    }
    cout << temp << endl;
  }
  cout << endl;
}

bool SymbolTable::doesExist(string id)
{
  return table_map.find(id) != table_map.end();
}

void SymbolTable::setReturnType(int type)
{
  table_map[symbols[symbols.size() - 1]].data_type = type;
}

void SymbolTable::addArgument(string id, identifierData data)
{
  table_map[symbols[symbols.size() - 1]].value.arguments.push_back(data);
}

