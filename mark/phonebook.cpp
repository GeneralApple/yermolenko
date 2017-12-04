#include <iostream>
#include <string>
#include <map>

using namespace std;

int main()
  {
    string cmd, name, phone;
    map< string, string > book;

    while( cin >> cmd )
      {
        if ( cmd == "add" )
          {
            cin >> name >> phone;
            book[ name ] = phone;
            cout << "Added" << endl;
          }
        else if ( cmd == "find" )
          {
            cin >> name;
            try {
              string v = book.at(name);
              cout << name << "'s phone is " << v << endl;
            }
            catch (const out_of_range &e) {
              cout << name << " not found" << endl;
            }
          }
        else if ( cmd == "del" )
          {
            cin >> name;
            book.erase( name );
            cout << "Deleted" << endl;
          }
        else if ( cmd == "view" )
          {
            for( auto &kv : book )
              cout << kv.first << "\t " << kv.second << endl;
          }
        else if ( cmd == "quit" )
          return 0;
        else
          cerr << "Bad command '" << cmd << "'" << endl;
    }

    return 0;
  }