//---------------------------------------------------------------------------

#ifndef TestH
#define TestH
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
#include "RzButton.hpp"
#include "RzPanel.hpp"
#include <Vcl.ExtCtrls.hpp>
#include "RzEdit.hpp"
#include <Vcl.Mask.hpp>
//---------------------------------------------------------------------------
class TForm2 : public TForm
{
__published:	// IDE-managed Components
    TRzPanel* RzPanel1;
    TRzPanel* RzPanel2;
    TRzButton* btn1;
    TRzButton* btn2;
    TRzButton* btn3;
    TRzButton* btn4;
    TRzButton* btn5;
    TRzButton* btn6;
    TRzButton* btn7;
    TRzButton* btn8;
    TRzButton* btn9;
    TRzButton* btnClear;
    TRzButton* btnMod;
    TRzButton* btnPluse;
    TRzButton* btnMinus;
    TRzButton* btnDelete;
    TRzButton* btnMulti;
    TRzEdit* edtResult;
    TRzEdit* edtExp;
    TRzButton* btn0;
    TRzButton* btnDot;
    TRzButton* btnEqul;
    void __fastcall btnClick(TObject* Sender);
private:	// User declarations
public:		// User declarations
    __fastcall TForm2(TComponent* Owner);
    bool m_bDot;
    int m_nMode;

    int m_nValue1, m_nValue2;
    double m_dValue1, m_dValue2;

    int __fastcall Calculate(int nValue1, int nValue2, int nMode);
    double __fastcall Calculate(double nValue1, double nValue2, int nMode);
};
//---------------------------------------------------------------------------
extern PACKAGE TForm2* Form2;
//---------------------------------------------------------------------------
#endif