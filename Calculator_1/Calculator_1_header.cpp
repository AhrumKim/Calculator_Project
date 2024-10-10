// Unit3.h

#ifndef Unit3H
#define Unit3H

#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
#include "RzButton.hpp"
#include "RzEdit.hpp"
#include "RzPanel.hpp"
#include <Vcl.ExtCtrls.hpp>
#include <Vcl.Mask.hpp>
#include "RzSpnEdt.hpp"
#include <stack>
#include <string>
#include <vector>

class TForm3 : public TForm
{
__published:
	TRzPanel* RzPanel1;
	TRzButton* btn1;
	TRzButton* btn2;
	TRzButton* btn3;
	TRzButton* btn4;
	TRzButton* btn5;
	TRzButton* btn6;
	TRzButton* btn7;
	TRzButton* btn8;
	TRzButton* btn9;
	TRzButton* btnPluse;
	TRzButton* btnMinus;
	TRzButton* btnMultiply;
	TRzButton* btnResult;
	TRzButton* btnDelete;
	TRzButton* btnDivide;
	TRzButton* btn0;
	TRzButton* btnR;
	TRzButton* btnCancle;
	TRzEdit* edtResult;
	TRzButton* btnDot;
	TRzButton* btnT1;
	TRzButton* btnT2;
	void __fastcall btnResultClick(TObject* Sender);



private:
	String m_strValue;
	std::stack<int> m_snData;
	std::stack<String> m_scData;

	std::vector<int> m_vnData;



public:
	__fastcall TForm3(TComponent* Owner);
	int __fastcall getPrecedence(char op);
	double TForm3::performOperation(char op, double num1, double num2);
	double calculateResult(const String& expression);


};

extern PACKAGE TForm3* Form3;

#endif

