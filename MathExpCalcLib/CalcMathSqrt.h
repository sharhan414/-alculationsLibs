#ifndef SQRT_H
#define SQRT_H
#include "MathExpFunction.h"

class CalcMathSqrt:public MathExpFunction
{
public:
    CalcMathSqrt();
    void CalculateSqrt(std::string&);
    void CalculateNSqtn(std::string&);
    void Calculate2Sqrt(std::string&);
    std::string getMathSqrtAnswer(std::string&);
    std::string resheniya(std::string& ,std::string&);



    double nsqrt(double x, double y)
    {
        if( y == 0.0 || (x<0 && abs(y)-abs(int(y))==0 && abs(int(y))%2==0))
        {
            m_Error=true;
            return 0;
        }
        return pow(x, 1/y);
    }
    double sqrt(double x)
    {
        if(x<0)
        {
            m_Error=true;
            return 0;
        }
        return pow(x, 0.5);
    }
private:
    std::string m_nSqrt = "nsqrt";
    std::string m_Sqrt = "sqrt";
};

#endif // SQRT_H
