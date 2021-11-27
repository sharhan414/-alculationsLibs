#include "arifdeyst.h"
#include "resheniy.h"
#include <algorithm>
#include <iostream>
using namespace std;
ArifDeyst::ArifDeyst()
{

}
void ArifDeyst::raspredDeystAndValues(vector<string>& ValuesArifDeyst,vector<char>& ArifDeyst,string& TextAfidDeyst)
{
    string m = "+-*/",s="";
    int k = 0;
    for (size_t i = 0; i != TextAfidDeyst.size(); ++i)
    {
        if (find(m.begin(), m.end(), TextAfidDeyst[i]) != m.end() && i!=0 )
        {
            ArifDeyst.push_back(TextAfidDeyst[i]);

            for (size_t j = k; j != i; ++j)
            {
                s += TextAfidDeyst[j];
                if (i < TextAfidDeyst.size() - 1)
                    k = i + 1;
            }

            ValuesArifDeyst.push_back(s);
            s = "";
        }
    }
    for (size_t j = k; j != TextAfidDeyst.size(); ++j)
        s += TextAfidDeyst[j];

    ValuesArifDeyst.push_back(s);
}

void ArifDeyst::ReshArifDeystUmnjAndDeln(vector<double>& v, vector<char>& w)
{
    string m = "*/";
    int a = 0,k=0;
    for (size_t i = 0; i != w.size(); ++i)
        if (w[i] == m.back() || w[i] == m.front())
            ++k;

    while(a<k)
    {
        for (size_t i = 0; i != w.size(); ++i)
        {
            if (w[i] == m.front())
            {
                v[i] = v[i] * v[i + 1];
                v.erase(v.begin() + i + size_t(1));
                w.erase(w.begin() + i);
                ++a;
                break;
            }
            else if (w[i] ==m.back())
            {
                v[i] = v[i]/v[i + 1];
                v.erase(v.begin() + i + size_t(1));
                w.erase(w.begin() + i);
                ++a;
                break;
            }
        }
    }
}

// функция для решения + - действий
double ArifDeyst::ReshArifDeystPlusAndMinus(vector<double>& Otvetes, vector<char>& w)
{
    int a = 0, k = 0;
    for (size_t i = 0; i != w.size(); ++i)
        if (w[i] == '+' || w[i] == '-' )
            ++k;

    while (a < k)
    {
        for (size_t i = 0; i != w.size(); ++i)
        {
            if (w[i] == '+')
            {
                Otvetes[i] = Otvetes[i] + Otvetes[i + 1];
                Otvetes.erase(Otvetes.begin() + i + 1);
                w.erase(w.begin() + i);
                ++a;
                break;
            }
            else if (w[i] == '-')
            {
                Otvetes[i] = Otvetes[i] - Otvetes[i + 1];
                Otvetes.erase(Otvetes.begin() + i + 1);
                w.erase(w.begin() + i);
                ++a;
                break;
            }
        }
    }
return Otvetes.front();
}
//new
//new
void ArifDeyst::getArifSignsForExp(string &text,vector<char>& ArithmeticSigns)
{
    text+='|';
    for(uint64_t i=1;i<text.size();++i)
    {
        if(text[i]=='+')
        {
            ArithmeticSigns.push_back('+');
            text[i]='|';
        }
        else if(text[i]=='*')
        {
            ArithmeticSigns.push_back('*');
            text[i]='|';
        }
        else if(text[i]=='/')
        {
            ArithmeticSigns.push_back('/');
            text[i]='|';
        }
        else if(text[i]=='-')
        {
            if(text[i-1]!='|')
            {
                ArithmeticSigns.push_back('-');
                text[i]='|';
            }
        }

    }

}

void ArifDeyst::getValuesForExp(string &text,vector<string>& ValuesForExp)
{
    while(!text.empty())
    {
        auto iter=find(text.begin(),text.end(),'|');
        string val(text.begin(),iter);
        ValuesForExp.push_back(val);
        text.erase(text.begin(),iter+1);


    }
}

void ArifDeyst::getDatesForExp(string& text,vector<string>& ValuesForExp,vector<char>& ArithmeticSigns)
{

    getArifSignsForExp(text,ArithmeticSigns);
    getValuesForExp(text,ValuesForExp);
}
/////
/// \brief ArifDeyst::arif_detstvie
/// \param otvet
/// \param TextAfidDeyst
///////////
void ArifDeyst::arif_detstvie(double& Answer,string text)
{
/*
    vector<string> ValuesArifDeyst; //будет содержать числа по их порядку в TextAfidDeyst без ариф. действий
    vector<char> ArifDeyst;//будет содержать ариф. действия по их порядку в TextAfidDeyst
    vector<double> Otvetes;
    raspredDeystAndValues(ValuesArifDeyst,ArifDeyst,TextAfidDeyst); //

    for(uint64_t i=0;i!=ValuesArifDeyst.size();++i)
    {
        Otvetes.push_back(Resheniy::stdString_toDouble(ValuesArifDeyst[i]));
    }
    ReshArifDeystUmnjAndDeln(Otvetes,ArifDeyst);//решаеть ариф.действия умножение и деление
    Answer=ReshArifDeystPlusAndMinus(Otvetes,ArifDeyst);//решаеть ариф.действия сложение и вычитание

*/


    vector<char> ArithmeticSigns;
    vector<string> ValuesForExp;
    getDatesForExp(text,ValuesForExp,ArithmeticSigns);
    vector<double> Otvetes;

   // raspredDeystAndValues(ValuesForExp,ArithmeticSigns,text); //

    for(uint64_t i=0;i!=ValuesForExp.size();++i)
    {
        Otvetes.push_back(Resheniy::stdString_toDouble(ValuesForExp[i]));
    }

    ReshArifDeystUmnjAndDeln(Otvetes,ArithmeticSigns);//решаеть ариф.действия умножение и деление
    Answer=ReshArifDeystPlusAndMinus(Otvetes,ArithmeticSigns);//решаеть ариф.действия сложение и вычитание

}
