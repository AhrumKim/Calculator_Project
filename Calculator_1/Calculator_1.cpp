#include <vcl.h>
#pragma hdrstop
#include "Unit3.h"
#include <string>
#include <stack>

//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "RzButton"
#pragma link "RzEdit"
#pragma link "RzPanel"
#pragma link "RzSpnEdt"
#pragma resource "*.dfm"
TForm3* Form3;

//---------------------------------------------------------------------------
__fastcall TForm3::TForm3(TComponent* Owner)
	: TForm(Owner)
{
	m_strValue = "";
}
//-----------------------------------------------------------------------------
// 1. 입력된 스트링을 멤버 스트링에 대입한다.
// 2. 멤버 스트링을 숫자와 기호(사칙연산자 or 괄호) 로 구분하여 파싱한다.
//    이 과정에서 괄호 안의 연산은 먼저 진행한 뒤 숫자로 치환 해 둔다.
//    괄호를 제외하고는 그대로 써도 컴파일러에서 알아서 연산순서를 맞추어 주기 때문에 굳이 재배치 할 필요는 없다.
// 3. 별도의 배열에 순서대로 배치 한 숫자를 숫자대로 배치 한 연산자에 맞추어 연산한다.
// 4. 결과를 입력창에 그대로 출력한다.
//-----------------------------------------------------------------------------

double TForm3::calculateResult(const String& expression)
{
	std::stack<double> numbers;  // 숫자를 저장하는 스택
	std::stack<char> operators;  // 연산자를 저장하는 스택

	String currentNumber = "";  // 현재 숫자를 저장하는 변수

	//특수 문자 기준으로 스택에 값 저장(후입선출)
	for (int i = 1; i <= expression.Length(); ++i)
	{
		char ch = expression[i];

		//연산자 기준으로 나눔
		if (ch == '+' || ch == '-' || ch == '*' || ch == '/' || ch == '%' || ch == '(' || ch == ')')
		{
			if (!currentNumber.IsEmpty())
			{
				double num = StrToFloat(currentNumber);     //변환
				numbers.push(num);     //저장
				currentNumber = "";
			}

			if (ch == ')')
			{
				// 괄호 처리
				while (!operators.empty() && operators.top() != '(')
				{
					char op = operators.top();
					operators.pop();

					double num2 = numbers.top();
					numbers.pop();

					double num1 = numbers.top();
					numbers.pop();

					numbers.push(performOperation(op, num1, num2));//연산자 계산
				}

				operators.pop(); // 스택에서 '(' 제거
			}
			else
			{
				// 우선순위에 따라 다른 연산자 처리
				while (!operators.empty() && getPrecedence(operators.top()) >= getPrecedence(ch))//우선순위 클때
				{
					char op = operators.top();
					operators.pop();

					double num2 = numbers.top();
					numbers.pop();

					double num1 = numbers.top();
					numbers.pop();

					numbers.push(performOperation(op, num1, num2));//연산자 계산
				}

				operators.push(ch);  //연산자 삽입
			}
		}
		//0~9까지 숫자와 '.'점까지 값 저장
		else if (ch >= '0' && ch <= '9' || ch == '.')
		{
			currentNumber += ch;
		}
	}
	//값 변화(float형으로)

	if (!currentNumber.IsEmpty())
	{
		double num = StrToFloat(currentNumber);

		numbers.push(num);
	}
	//연산자와 숫자 확인
	while (!operators.empty())
	{
		char op = operators.top();
		operators.pop();

		double num2 = numbers.top();
		numbers.pop();

		double num1 = numbers.top();
		numbers.pop();

		numbers.push(performOperation(op, num1, num2));
	}

	if (!numbers.empty())
		return numbers.top();
	else
		return 0.0;
}
//-----------------------------------------------------------------------------

	//우선 순위 설정
int TForm3::getPrecedence(char op)
{
	// 연산자의 우선순위 반환
	if (op == '+' || op == '-')
		return 1;
	else if (op == '*' || op == '/' || op == '%')
		return 2;
	else
		return 0; // 다른 문자에 대한 기본 우선순위
}

//-----------------------------------------------------------------------------
//연산자 계산
double TForm3::performOperation(char op, double num1, double num2)
{
	// 주어진 연산자에 따라 산술 연산 수행
	switch (op)
	{
	case '+':
		return num1 + num2;
	case '-':
		return num1 - num2;
	case '*':
		return num1 * num2;
	case '/':
		return num1 / num2;
	case '%':
		return fmod(num1, num2);
	default:
		return 0.0; // 다른 경우에 대한 처리 필요
	}
}

//-----------------------------------------------------------------------------
//계산기 버튼
void __fastcall TForm3::btnResultClick(TObject* Sender)
{
	// variable  변수
	String strVal;


	// implement  기능C
	if (Sender == NULL) return; // 예외처리
	strVal = "";

	if (Sender == btn0) {
		strVal = "0";
		m_strValue += strVal;
	}
	else if (Sender == btn1)
	{
		strVal = "1";
		m_strValue += strVal;
	}
	else if (Sender == btn2)
	{
		strVal = "2";
		m_strValue += strVal;
	}
	else if (Sender == btn3)
	{
		strVal = "3";
		m_strValue += strVal;
	}
	else if (Sender == btn4)
	{
		strVal = "4";
		m_strValue += strVal;
	}
	else if (Sender == btn5)
	{
		strVal = "5";
		m_strValue += strVal;
	}
	else if (Sender == btn6)
	{
		strVal = "6";
		m_strValue += strVal;
	}
	else if (Sender == btn7)
	{
		strVal = "7";
		m_strValue += strVal;
	}
	else if (Sender == btn8)
	{
		strVal = "8";
		m_strValue += strVal;
	}
	else if (Sender == btn9)
	{
		strVal = "9";
		m_strValue += strVal;
	}
	else if (Sender == btnDot)
	{
		strVal = ".";
		m_strValue += strVal;
	}
	else if (Sender == btnPluse)
	{
		strVal = "+";
		m_strValue += strVal;

	}
	else if (Sender == btnT1)
	{
		strVal = "(";
		m_strValue += strVal;

	}
	else if (Sender == btnT2)
	{
		strVal = ")";
		m_strValue += strVal;

	}

	else if (Sender == btnMinus)
	{
		strVal = "-";
		m_strValue += strVal;
	}
	else if (Sender == btnMultiply)
	{
		strVal = "*";
		m_strValue += strVal;
	}
	else if (Sender == btnR)
	{
		strVal = "%";
		m_strValue += strVal;
	}
	else if (Sender == btnDivide)
	{
		strVal = "/";
		m_strValue += strVal;
	}

	else if (Sender == btnDelete)
	{
		//문자열 마지막 삭제
		if (!m_strValue.IsEmpty())
		{
			m_strValue = m_strValue.SubString(0, m_strValue.Length() - 1);
		}
	}


	else if (Sender == btnCancle)
	{
		// 전체 삭제
		if (!m_strValue.IsEmpty())
		{
			m_strValue = m_strValue.SubString(m_strValue.Length(), m_strValue.Length());
		}
	}

	else if (Sender == btnResult)
	{
		strVal = "=";
		m_strValue += strVal;

		double result = calculateResult(m_strValue);
		m_strValue = FloatToStr(result);

	}

	edtResult->Text = m_strValue;  // 값표시

}
