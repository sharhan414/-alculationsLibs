#ifndef RESHTRIGFUNC_H
#define RESHTRIGFUNC_H
#include "MathExpFunction.h"
/*

ReshTrigFunc- класс для вычисления тригонометрических фунций из математического выражения.




  */
class CalcMathTrigFunc:public MathExpFunction
{
public:

    CalcMathTrigFunc();
    void CalculateTrigFunc(std::string& mathExp);
    std::string Calculate(const std::string&, std::string&);
//СalcTrigonometricFunc
private:
    double angleToRadians(double&);
    void trigonometr(std::string& mathExp);

    const std::string m_fCos="cos";
    const std::string m_fSin="sin";
    const std::string m_fTag="tag";
    const std::string m_fCTag="ctag";

    const std::string m_fArcCos="arccos";
    const std::string m_fArcSin="arcsin";
    const std::string m_fArcTag="arctag";
    const std::string m_fArcCTag="arcctag";
};

#endif // RESHTRIGFUNC_H
