#include <iostream>
#include <string>
#include <QString>
#include <QDebug>
#include "mathexpressions.h"
using namespace std;

int main()
{
    string s="12*3-34/2+3+sqrt(64)+5!+4nsqrt(16)";



QString str="12×3-34÷2+3+√(64)+sin(30)+5!";
MathExpressions calc;
/*
MathExpressions::ReplacingSigns(str);
string st=str.toStdString();
cout<<"st:"<<st<<endl;
*/
cout<<"-------------"<<endl;
calc.CalculateMathExp(s);
cout<<"-------------"<<endl;
    cout<<"Answer:"<<s<<endl;


    return 0;
}
