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

    // 20,30.40,50,60,70,80,90,100
    arabic_to_roman.insert(make_pair<int,string>(20,"XX"));
    arabic_to_roman.insert(make_pair<int,string>(30,"XXX"));
    arabic_to_roman.insert(make_pair<int,string>(40,"XL"));
    arabic_to_roman.insert(make_pair<int,string>(50,"L"));
    arabic_to_roman.insert(make_pair<int,string>(60,"LX"));
    arabic_to_roman.insert(make_pair<int,string>(70,"LXX"));
    arabic_to_roman.insert(make_pair<int,string>(80,"LXXX"));
    arabic_to_roman.insert(make_pair<int,string>(90,"XC"));
    arabic_to_roman.insert(make_pair<int,string>(100,"C"));

    // 200,300,400,500,600,700,800,900,1000,2000,3000
    arabic_to_roman.insert(make_pair<int,string>(200,"CC"));
    arabic_to_roman.insert(make_pair<int,string>(300,"CCC"));
    arabic_to_roman.insert(make_pair<int,string>(400,"CD"));
    arabic_to_roman.insert(make_pair<int,string>(500,"D"));
    arabic_to_roman.insert(make_pair<int,string>(600,"DC"));
    arabic_to_roman.insert(make_pair<int,string>(700,"DCC"));
    arabic_to_roman.insert(make_pair<int,string>(800,"DCCC"));
    arabic_to_roman.insert(make_pair<int,string>(900,"CM"));
    arabic_to_roman.insert(make_pair<int,string>(1000,"M"));
    arabic_to_roman.insert(make_pair<int,string>(2000,"MM"));
    arabic_to_roman.insert(make_pair<int,string>(3000,"MMM"));
}

string convertArabicToRoman(int num){
		string output = "";

    int thous = num / 1000;
    //cout << "thous: " << thous;
    if(thous > 0)
        output += arabic_to_roman.find(thous * 1000)->second;

    int hund = num % 1000 / 100;
    //cout << " hundreds: " << hund;
    if(hund > 0)
        output += arabic_to_roman.find(hund * 100)->second;

    int tens = num % 100 / 10;
    //cout << " tens: " << tens;
    if(tens > 0)
        output += arabic_to_roman.find(tens * 10)->second;

    int ones = num % 10 / 1;
    //cout << " ones: " << ones << endl;
    if(ones > 0)
        output += arabic_to_roman.find(ones)->second;

    return output;
}

int main()
{
    // Build Roman Numeral Hash
    buildRomanHash();

    // Tests
    assert((convertArabicToRoman(1) == "I") && "Not I");
		assert((convertArabicToRoman(3) == "III") && "Not III");
    assert((convertArabicToRoman(9) == "IX") && "Not IX");
    assert((convertArabicToRoman(1066) == "MLXVI") && "Not MLXVI");
    assert((convertArabicToRoman(1989) == "MCMLXXXIX") && "Not MCMLXXXIX");

    cout << "PASS" << endl;
    return 0;
}

