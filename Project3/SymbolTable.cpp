#include "SymbolTable.hpp"

SymbolTable::SymbolTable()
{
  index = 0;
}

int SymbolTable::insert(string id, int data_type, int identifier_type, values value, bool initialized)
{
  if (doesExist(id))
    return -1;
  id_vector.push_back(id);
  id_map[id].id = id;
  id_map[id].data_type = data_type;
  id_map[id].id_type = identifier_type;
  id_map[id].value = value;
  id_map[id].initialized = initialized;
  id_map[id].index = index;
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
  
  id_vector.push_back(id);
  id_map[id].id = id;
  id_map[id].data_type = 5;
  id_map[id].id_type = 1;
  id_map[id].value = value;
  id_map[id].array_value_type = data_type;
  id_map[id].array_size = size;
  id_map[id].initialized = false;
  id_map[id].index = index;
  index++;
  return 1;
}

identifierData *SymbolTable::lookup(string id)
{
  if (doesExist(id))
    return new identifierData(id_map[id]);
  else
    return NULL;
}

void SymbolTable::dump()
{
  cout << "id\tdata_type\tid_type\t\tvalues" << endl;

  for (int i = 0; i < index; ++i)
  {
    string temp;
    identifierData data = id_map[id_vector[i]];
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
      temp += "function";

    temp += "\t";

    if (data.initialized)
    {
      if (data.data_type == 1)
        temp += to_string(data.value.int_value);
      else if (data.data_type == 2)
        temp += to_string(data.value.double_value);
      else if (data.data_type == 3)
        temp += (data.value.bool_value) ? "true" : "false";
      else if (data.data_type == 4)
        temp += data.value.string_value;
      
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
  return id_map.find(id) != id_map.end();
}

void SymbolTable::setReturnType(int type)
{
  id_map[id_vector[id_vector.size() - 1]].data_type = type;
}

void SymbolTable::addArgument(string id, identifierData data)
{
  id_map[id_vector[id_vector.size() - 1]].value.arguments.push_back(data);
}

string stringDataType(int data_type)
{
  switch(data_type) {
    case 1: return "int";
    case 2: return "float";
    case 3: return "int"; /*Originally bool*/
    case 4: return "java.lang.String";
    case 5: return "array";
    case 6: return "void";
    default: return "Data type does not exist";
  }
}

string stringIdType(int id_type)
{
  switch(id_type) {
    case 1: return "variable";
    case 2: return "constant";
    case 3: return "function";
    case 4: return "literals";
    default: return "Identifier type does not exist";
  }
}