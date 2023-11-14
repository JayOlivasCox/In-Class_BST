#include <iostream>

#include "WordTree.h"

using namespace std;

int main() {
    WordTree t;
    string str = "";

    cout<<"Menu:\na: add\nd: print number of distinct words\no: print the number of occurrrances\np: print tree alphabetically\nr: remove\nt: print total number of words inserted\nq: quit\n";

    while(str!="q"){

        cout << "Enter a choice: \n"; 
        
        getline(cin, str);
        if(str=="q"||str=="Q"){
            break;
        }
        if(str=="a"||str=="A"){
            string toAdd;
            cout << "Enter string to add : ";
            getline(cin, toAdd);
            t.add(toAdd);
        }
        else if(str=="d"||str=="D"){
            cout << "Distinct: " << t.distinctWords() << endl;
        }
        else if(str=="o"||str=="O"){
            string toSearch;
            cout << "Enter string to search : ";
            getline(cin, toSearch);

            cout << "Total " << toSearch << "s: " << t.findOccurrences(toSearch) << endl;
        }
        else if(str=="p"||str=="P"){
            t.print();
            cout << endl;
        }
        else if(str=="r"||str=="R"){
            string toRemove;
            cout << "Enter string to remove : ";
            getline(cin, toRemove);
            t.remove(toRemove);
        }
        else if(str=="t"||str=="T"){
            cout << "Total: " << t.totalWords() << endl;
        }
    
    }
    
}
