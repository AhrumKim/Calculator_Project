#include <vcl.h>
#pragma hdrstop

#include "Test.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "RzButton"
#pragma link "RzPanel"
#pragma link "RzEdit"
#pragma resource "*.dfm"
TForm2* Form2;
//---------------------------------------------------------------------------
__fastcall TForm2::TForm2(TComponent* Owner)
    : TForm(Owner)
{
    m_bDot = false; // 소수인지
    // 사칙연산 모드 0 나눗셈, 1 곱셈, 2 덧셈, 3 뺄셈
    // -1 사칙연산 버튼으로 결과가 나왔을 때 다음버튼 눌를 시 edtResult 초기화
    // -2 Equal 버튼으로 결과가 나왔을때 다음 버튼 클릭시  전부초기화
    m_nMode = 0;  // Default = 0 으로한다 귀찮음

    m_nValue1, m_nValue2 = 0;
    m_dValue1, m_dValue2 = 0.;
}
//---------------------------------------------------------------------------
void __fastcall TForm2::btnClick(TObject* Sender)
{
    // variable
    String strValue;
    String strToken;
    String strRetText;
    String strExpText;
    String strEqulText;
    int nValue1, nValue2, nRet;
    double dValue1, dValue2, dRet;

    // implement
    if (Sender == NULL) return;

    strValue = "";
    strToken = "";
    strRetText = "";
    strExpText = "";
    strEqulText = "";

    nValue1 = 0;
    nValue2 = 0;

    dValue1 = 0.;
    dValue2 = 0.;

    nRet = 0;
    dRet = 0;

    if (Sender == btn0)
    {
        strValue = "0";
        if (edtResult->Text == "0") return;
        else
        {
            if (m_nMode == -1) // 사칙연산 끝날 시.
            {
                edtResult->Text = "0";
                m_nMode = 0;
                return;
            }
            if (m_nMode == -2) // = 로 끝날 시.
            {
                edtExp->Text = "";
                edtResult->Text = "0";
                m_nMode = 0;
                return;
            }
            strRetText = edtResult->Text;
            strRetText += strValue;
            edtResult->Text = strRetText;
        }
    }
    else if (Sender == btn1)
    {
        strValue = "1";
        if (edtResult->Text == "0")
        {
            edtResult->Text = strValue;
            m_nMode = 0;
        }
        else
        {
            if (m_nMode == -1)
            {
                edtResult->Text = "1";
                m_nMode = 0;
                return;
            }
            if (m_nMode == -2) // = 로 끝날 시.
            {
                edtExp->Text = "";
                edtResult->Text = "1";
                m_nMode = 0;
                return;
            }
            strRetText = edtResult->Text;
            strRetText += strValue;
            edtResult->Text = strRetText;
        }
    }
    else if (Sender == btn2)
    {
        strValue = "2";
        if (edtResult->Text == "0")
        {
            edtResult->Text = strValue;
            m_nMode = 0;
        }
        else
        {
            if (m_nMode == -1)
            {
                edtResult->Text = "2";
                m_nMode = 0;
                return;
            }
            if (m_nMode == -2) // = 로 끝날 시.
            {
                edtExp->Text = "";
                edtResult->Text = "2";
                m_nMode = 0;
                return;
            }
            strRetText = edtResult->Text;
            strRetText += strValue;
            edtResult->Text = strRetText;
        }
    }
    else if (Sender == btn3)
    {
        strValue = "3";
        if (edtResult->Text == "0")
        {
            edtResult->Text = strValue;
            m_nMode = 0;
        }
        else
        {
            if (m_nMode == -1)
            {
                edtResult->Text = "3";
                m_nMode = 0;
                return;
            }
            if (m_nMode == -2) // = 로 끝날 시.
            {
                edtExp->Text = "";
                edtResult->Text = "3";
                m_nMode = 0;
                return;
            }
            strRetText = edtResult->Text;
            strRetText += strValue;
            edtResult->Text = strRetText;
        }
    }
    else if (Sender == btn4)
    {
        strValue = "4";
        if (edtResult->Text == "0")
        {
            edtResult->Text = strValue;
            m_nMode = 0;
        }
        else
        {
            if (m_nMode == -1)
            {
                edtResult->Text = "4";
                m_nMode = 0;
                return;
            }
            if (m_nMode == -2) // = 로 끝날 시.
            {
                edtExp->Text = "";
                edtResult->Text = "4";
                m_nMode = 0;
                return;
            }
            strRetText = edtResult->Text;
            strRetText += strValue;
            edtResult->Text = strRetText;
        }
    }
    else if (Sender == btn5)
    {
        strValue = "5";
        if (edtResult->Text == "0")
        {
            edtResult->Text = strValue;
            m_nMode = 0;
        }
        else
        {
            if (m_nMode == -1)
            {
                edtResult->Text = "5";
                m_nMode = 0;
                return;
            }
            if (m_nMode == -2) // = 로 끝날 시.
            {
                edtExp->Text = "";
                edtResult->Text = "5";
                m_nMode = 0;
                return;
            }
            strRetText = edtResult->Text;
            strRetText += strValue;
            edtResult->Text = strRetText;
        }
    }
    else if (Sender == btn6)
    {
        strValue = "6";
        if (edtResult->Text == "0")
        {
            edtResult->Text = strValue;
            m_nMode = 0;
        }
        else
        {
            if (m_nMode == -1)
            {
                edtResult->Text = "6";
                m_nMode = 0;
                return;
            }
            if (m_nMode == -2) // = 로 끝날 시.
            {
                edtExp->Text = "";
                edtResult->Text = "6";
                m_nMode = 0;
                return;
            }
            strRetText = edtResult->Text;
            strRetText += strValue;
            edtResult->Text = strRetText;
        }
    }
    else if (Sender == btn7)
    {
        strValue = "7";
        if (edtResult->Text == "0")
        {
            edtResult->Text = strValue;
            m_nMode = 0;
        }
        else
        {
            if (m_nMode == -1)
            {
                edtResult->Text = "7";
                m_nMode = 0;
                return;
            }
            if (m_nMode == -2) // = 로 끝날 시.
            {
                edtExp->Text = "";
                edtResult->Text = "7";
                m_nMode = 0;
                return;
            }
            strRetText = edtResult->Text;
            strRetText += strValue;
            edtResult->Text = strRetText;
        }
    }
    else if (Sender == btn8)
    {
        strValue = "8";
        if (edtResult->Text == "0")
        {
            edtResult->Text = strValue;
            m_nMode = 0;
        }
        else
        {
            if (m_nMode == -1)
            {
                edtResult->Text = "8";
                m_nMode = 0;
                return;
            }
            if (m_nMode == -2) // = 로 끝날 시.
            {
                edtExp->Text = "";
                edtResult->Text = "8";
                m_nMode = 0;
                return;
            }
            strRetText = edtResult->Text;
            strRetText += strValue;
            edtResult->Text = strRetText;
        }
    }
    else if (Sender == btn9)
    {
        strValue = "9";
        if (edtResult->Text == "0")
        {
            edtResult->Text = strValue;
            m_nMode = 0;
        }
        else
        {
            if (m_nMode == -1)
            {
                edtResult->Text = "9";
                m_nMode = 0;
                return;
            }
            if (m_nMode == -2) // = 로 끝날 시.
            {
                edtExp->Text = "";
                edtResult->Text = "9";
                m_nMode = 0;
                return;
            }
            strRetText = edtResult->Text;
            strRetText += strValue;
            edtResult->Text = strRetText;
        }
    }
    else if (Sender == btnDot)
    {
        strRetText = edtResult->Text;
        strRetText += ".";
        edtResult->Text = strRetText;
        m_bDot = true;
    }
    else if (Sender == btnMod)
    {
        if (m_nMode == -1)
        {
            strExpText = edtResult->Text;
            strExpText += "";
            strExpText += "/";
            edtExp->Text = strExpText;
            edtResult->Text = "0";
        }
        m_nMode = 0;
        if (edtExp->Text == "")
        {
            strExpText = edtResult->Text;
            strExpText += "";
            strExpText += "/";
            edtExp->Text = strExpText;
            edtResult->Text = "0";
        }
        else
        {
            if (edtResult->Text == "0" || edtResult->Text == "0.0")
            {
                edtResult->Text = "0으로 나눌 수 없습니다.";
                return;
            }
            else
            {
                if (m_bDot == false)
                {
                    strExpText = edtExp->Text;
                    strExpText.Delete(strExpText.Length(), 1);
                    nValue1 = strExpText.ToInt();

                    strRetText = edtResult->Text;
                    nValue2 = strRetText.ToInt();

                    nRet = Calculate(nValue1, nValue2, 0);

                    strRetText = IntToStr(nRet);
                    edtResult->Text = strRetText;

                    strExpText = IntToStr(nRet);
                    strExpText += "";
                    strExpText += "/";
                    edtExp->Text = strExpText;
                }
                else
                {
                    strExpText = edtExp->Text;
                    strExpText.Delete(strExpText.Length(), 1);
                    dValue1 = strExpText.ToDouble();

                    strRetText = edtResult->Text;
                    dValue2 = strRetText.ToDouble();

                    dRet = Calculate(dValue1, dValue2, 0);


                    strRetText = FloatToStr((float)dRet);
                    edtResult->Text = strRetText;

                    strExpText = FloatToStr((float)dRet);
                    strExpText += "";
                    strExpText += "/";
                    edtExp->Text = strExpText;
                }
                m_nMode = -1;
            }
        }
    }
    else if (Sender == btnMulti)
    {
        if (m_nMode == -1)
        {
            strExpText = edtResult->Text;
            strExpText += "";
            strExpText += "x";
            edtExp->Text = strExpText;
            edtResult->Text = "0";
        }
        m_nMode = 1;
        if (edtExp->Text == "")
        {
            strExpText = edtResult->Text;
            strExpText += "";
            strExpText += "x";
            edtExp->Text = strExpText;
            edtResult->Text = "0";
        }
        else
        {
            if (m_bDot == false)
            {
                strExpText = edtExp->Text;
                strExpText.Delete(strExpText.Length(), 1);
                nValue1 = strExpText.ToInt();

                strRetText = edtResult->Text;
                nValue2 = strRetText.ToInt();

                nRet = Calculate(nValue1, nValue2, 1);

                strRetText = IntToStr(nRet);
                edtResult->Text = strRetText;

                strExpText = IntToStr(nRet);
                strExpText += "";
                strExpText += "x";
                edtExp->Text = strExpText;
            }
            else
            {
                strExpText = edtExp->Text;
                strExpText.Delete(strExpText.Length(), 1);
                dValue1 = strExpText.ToDouble();

                strRetText = edtResult->Text;
                dValue2 = strRetText.ToDouble();

                dRet = Calculate(dValue1, dValue2, 1);


                strRetText = FloatToStr((float)dRet);
                edtResult->Text = strRetText;

                strExpText = FloatToStr((float)dRet);
                strExpText += "";
                strExpText += "*";
                edtExp->Text = strExpText;
            }
            m_nMode = -1;
        }
    }
    else if (Sender == btnPluse)
    {
        if (m_nMode == -1)
        {
            strExpText = edtResult->Text;
            strExpText += "";
            strExpText += "+";
            edtExp->Text = strExpText;
            edtResult->Text = "0";
        }
        m_nMode = 2;
        if (edtExp->Text == "")
        {
            strExpText = edtResult->Text;
            strExpText += "";
            strExpText += "+";
            edtExp->Text = strExpText;
            edtResult->Text = "0";
        }
        else
        {
            if (m_bDot == false)
            {
                strExpText = edtExp->Text;
                strExpText.Delete(strExpText.Length(), 1);
                nValue1 = strExpText.ToInt();

                strRetText = edtResult->Text;
                nValue2 = strRetText.ToInt();

                nRet = Calculate(nValue1, nValue2, 2);

                strRetText = IntToStr(nRet);
                edtResult->Text = strRetText;

                strExpText = IntToStr(nRet);
                strExpText += "";
                strExpText += "+";
                strExpText += "";
                edtExp->Text = strExpText;
            }
            else
            {
                strExpText = edtExp->Text;
                strExpText.Delete(strExpText.Length(), 1);
                dValue1 = strExpText.ToDouble();

                strRetText = edtResult->Text;
                dValue2 = strRetText.ToDouble();

                dRet = Calculate(dValue1, dValue2, 2);


                strRetText = FloatToStr((float)dRet);
                edtResult->Text = strRetText;

                strExpText = FloatToStr((float)dRet);
                strExpText += "";
                strExpText += "+";
                edtExp->Text = strExpText;
            }
            m_nMode = -1;
        }
    }
    else if (Sender == btnMinus)
    {
        if (m_nMode == -1)
        {
            strExpText = edtResult->Text;
            strExpText += "";
            strExpText += "-";
            edtExp->Text = strExpText;
            edtResult->Text = "0";
        }
        m_nMode = 3;
        if (edtExp->Text == "")
        {
            strExpText = edtResult->Text;
            strExpText += "";
            strExpText += "-";
            edtExp->Text = strExpText;
            edtResult->Text = "0";
        }
        else
        {
            if (m_bDot == false)
            {
                strExpText = edtExp->Text;
                strExpText.Delete(strExpText.Length(), 1);
                nValue1 = strExpText.ToInt();

                strRetText = edtResult->Text;
                nValue2 = strRetText.ToInt();

                nRet = Calculate(nValue1, nValue2, 3);

                strRetText = IntToStr(nRet);
                edtResult->Text = strRetText;

                strExpText = IntToStr(nRet);
                strExpText += "";
                strExpText += "-";
                edtExp->Text = strExpText;
            }
            else
            {
                strExpText = edtExp->Text;
                strExpText.Delete(strExpText.Length(), 1);
                dValue1 = strExpText.ToDouble();

                strRetText = edtResult->Text;
                dValue2 = strRetText.ToDouble();

                dRet = Calculate(dValue1, dValue2, 3);


                strRetText = FloatToStr((float)dRet);
                edtResult->Text = strRetText;

                strExpText = FloatToStr((float)dRet);
                strExpText += "";
                strExpText += "-";
                edtExp->Text = strExpText;
            }
            m_nMode = -1;
        }
    }
    else if (Sender == btnEqul) //  결과 도출.
    {
        if (m_nMode == -2)
        {
            if (m_bDot == false)
            {
            }
            else
            {
            }

        }
        if (edtExp->Text == "")
        {
            strRetText = edtResult->Text;
            if (strRetText.SubString(strRetText.Length(), 1) == ".")
            {
                strRetText = edtResult->Text;
                strRetText.Delete(strRetText.Length(), 1);
                strExpText = strRetText;
                strExpText += "";
                strExpText += "=";
                edtExp->Text = strExpText;
                edtResult->Text = strRetText;
            }
            strExpText = edtResult->Text;
            strExpText += "";
            strExpText += "=";
            edtExp->Text = strExpText;
            m_nMode = -1;
        }
        else
        {
            String strMode;
            String strSub;
            int nNum;
            if (m_bDot == false)
            {
                strExpText = edtExp->Text;
                strExpText.Delete(strExpText.Length(), 1);
                m_nValue1 = strExpText.ToInt();

                strRetText = edtResult->Text;
                m_nValue2 = strRetText.ToInt();

                strMode = edtExp->Text;
                strMode.Trim();
                nNum = strMode.Length();
                strSub = strMode.SubString(nNum, 1);
                if (wcscmp(strSub.c_str(), L"/") == 0)
                {
                    nRet = Calculate(m_nValue1, m_nValue2, 0);
                }
                else if (wcscmp(strSub.c_str(), L"x") == 0)
                {
                    nRet = Calculate(m_nValue1, m_nValue2, 1);
                }
                else if (wcscmp(strSub.c_str(), L"+") == 0)
                {
                    nRet = Calculate(m_nValue1, m_nValue2, 2);
                }
                else if (wcscmp(strSub.c_str(), L"-") == 0)
                {
                    nRet = Calculate(m_nValue1, m_nValue2, 3);
                }

                strRetText = IntToStr(nRet);
                edtResult->Text = strRetText;


                strEqulText = edtExp->Text;
                strEqulText += "";
                strEqulText += IntToStr(m_nValue2);
                strEqulText += "";
                strEqulText += "=";
                strEqulText += IntToStr(nRet);

                edtExp->Text = strEqulText;
            }
            else
            {
                strExpText = edtExp->Text;
                strExpText.Delete(strExpText.Length(), 1);
                m_dValue1 = strExpText.ToInt();

                strRetText = edtResult->Text;
                m_dValue2 = strRetText.ToInt();

                strMode = edtExp->Text;
                strMode.Trim();
                nNum = strMode.Length();
                strSub = strMode.SubString(nNum, 1);
                if (wcscmp(strSub.c_str(), L"/") == 0)
                {
                    dRet = Calculate(m_dValue1, m_dValue2, 0);
                }
                else if (wcscmp(strSub.c_str(), L"x") == 0)
                {
                    dRet = Calculate(m_dValue1, m_dValue2, 1);
                }
                else if (wcscmp(strSub.c_str(), L"+") == 0)
                {
                    dRet = Calculate(m_dValue1, m_dValue2, 2);
                }
                else if (wcscmp(strSub.c_str(), L"-") == 0)
                {
                    dRet = Calculate(m_dValue1, m_dValue2, 3);
                }

                strRetText = FloatToStr((float)dRet);
                edtResult->Text = strRetText;


                strEqulText = edtExp->Text;
                strEqulText += "";
                strEqulText += FloatToStr((float)m_dValue2);
                strEqulText += "";
                strEqulText += "=";
                strEqulText += FloatToStr((float)dRet);

                edtExp->Text = strEqulText;
            }
            m_nMode = -2;
        }
    }
    else if (Sender == btnDelete) // 삭제
    {
        strRetText = edtResult->Text;
        if (strRetText.Length() > 1)
        {
            strRetText.Delete(strRetText.Length(), 1);
            edtResult->Text = strRetText;
        }
        else
        {
            edtResult->Text = "0";
        }

    }
    else //if(Sender == btnClear) 클리어
    {
        edtResult->Text = "0";
        edtExp->Text = "";
        m_bDot = false;
        m_nMode = -1;
    }
    return;
}
//---------------------------------------------------------------------------
int __fastcall TForm2::Calculate(int nValue1, int nValue2, int nMode)
{
    // variable
    int nRet;

    // implement
    if (nMode == 0) // 나눗셈
    {
        if (nValue1 == 0) return 0;

        nRet = nValue1 / nValue2;
    }
    else if (nMode == 1) // 곱셉
    {
        if (nValue1 == 0) return 0;
        if (nValue2 == 0) return 0;

        return nValue1 * nValue2;
    }
    else if (nMode == 2) // 덧셈
    {
        nRet = nValue1 + nValue2;
    }
    else //if (nMode == 3) 뺄셈
    {
        nRet = nValue1 - nValue2;
    }

    return nRet;
}
//---------------------------------------------------------------------------
double __fastcall TForm2::Calculate(double dValue1, double dValue2, int nMode)
{
    // variable
    double dRet;

    // implement
    if (nMode == 0) // 나눗셈
    {
        if (dValue1 == 0.0) return 0.0;

        dRet = dValue1 / dValue2;
    }
    else if (nMode == 1) // 곱셉
    {
        if (dValue1 == 0.0) return 0.;
        if (dValue2 == 0.0) return 0.;

        dRet = dValue1 * dValue2;
    }
    else if (nMode == 2) // 덧셈
    {
        dRet = dValue1 + dValue2;
    }
    else //if (nMode == 3) 뺄셈
    {
        dRet = dValue1 - dValue2;
    }

    return dRet;
}
//---------------------------------------------------------------------------