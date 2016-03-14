#include <iostream>
#include <unordered_map>
#include <assert.h>

using namespace std;

static unordered_multimap<int,string> arabic_to_roman;

void buildRomanHash(){
    // 1 - 10
    arabic_to_roman.insert(make_pair<int,string>(1,"I"));
    arabic_to_roman.insert(make_pair<int,string>(2,"II"));
    arabic_to_roman.insert(make_pair<int,string>(3,"III"));
    arabic_to_roman.insert(make_pair<int,string>(4,"IV"));
    arabic_to_roman.insert(make_pair<int,string>(5,"V"));
    arabic_to_roman.insert(make_pair<int,string>(6,"VI"));
    arabic_to_roman.insert(make_pair<int,string>(7,"VII"));
    arabic_to_roman.insert(make_pair<int,string>(8,"VIII"));
    arabic_to_roman.insert(make_pair<int,string>(9,"IX"));
    arabic_to_roman.insert(make_pair<int,string>(10,"X"));
}

string convertArabicToRoman(int num){
    return arabic_to_roman.find(num)->second;
}

int main()
{
    // Build Roman Numeral Hash
    buildRomanHash();

    // Tests
    assert((convertArabicToRoman(1) == "I") && "Not I");
    
    cout << "PASS" << endl;
    return 0;
}

