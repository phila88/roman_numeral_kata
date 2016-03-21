#include <iostream>
#include <unordered_map>
#include <assert.h>

using namespace std;

static unordered_map<int,string> arabic_to_roman;
static unordered_map<string,int> roman_to_arabic;

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

void buildArabicHash(){
		// reverse roman hash pairs
    for(auto it : arabic_to_roman)
        roman_to_arabic[it.second] = it.first;
}

int convertRomanToArabic(std::string str){
    if(str.length() < 4){
        auto it = roman_to_arabic.find(str);
        if(it != roman_to_arabic.end())
            return it->second;
        else {
            return 0; // base case
        }
    }
		else if(str.length() >= 4){
        //cout<<">= 4"<<endl;
        auto it = roman_to_arabic.find(str.substr(0,4));  // check 4 letter numerals first
        if(it != roman_to_arabic.end()){
            //cout<<"4 letter roman"<<endl;
            if(str.length() == 4)
                return it->second;
            else
                return it->second + convertRomanToArabic(str.substr(4,str.length() - 4));
        }
				else{
            it = roman_to_arabic.find(str.substr(0,3)); // then check 3 letter numerals
            if(it != roman_to_arabic.end()){
                //cout<<"3 letter roman"<<endl;
                    return it->second + convertRomanToArabic(str.substr(3,str.length() - 3));
						}
				}
		}
}

int main()
{
    // Build Roman Numeral Hash
    buildRomanHash();
		// Build Arabic Hash
    buildArabicHash();

    // Tests
    // Arabic to Roman
    assert((convertArabicToRoman(1) == "I") && "Not I");
    assert((convertArabicToRoman(3) == "III") && "Not III");
    assert((convertArabicToRoman(9) == "IX") && "Not IX");
    assert((convertArabicToRoman(1066) == "MLXVI") && "Not MLXVI");
    assert((convertArabicToRoman(1989) == "MCMLXXXIX") && "Not MCMLXXXIX");

    // Roman to Arabic
    assert((convertRomanToArabic("I") == 1) && "Not 1");
    assert((convertRomanToArabic("III") == 3) && "Not 3");
    assert((convertRomanToArabic("IX") == 9) && "Not 9");
		assert((convertRomanToArabic("VIII") == 8) && "Not 8");
		assert((convertRomanToArabic("MMMII") == 3002) && " Not 3002");
    
    cout << "PASS" << endl;
    return 0;
}

