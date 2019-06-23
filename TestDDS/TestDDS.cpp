#include "pch.h"
#include "CppUnitTest.h"
#include "..\src\dds.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace TestDDS
{
	TEST_CLASS(TestDDS)
	{
	public:
		
		TEST_METHOD(TestMethod1)
		{
		}
	};

	TEST_CLASS(TestCalcDDtablePBN)
	{
	public:
		TEST_METHOD(BasicTest)
		{
			int i;
			ddTableDealPBN pbn = ddTableDealPBN();
			ddTableResults res;

			//pbn = { "E:AT5.AJT.A632.KJ7 Q763.KQ9.KQJ94.T 942.87653..98653 KJ8.42.T875.AQ42" };
			//pbn = {"" }; //also works
			strcpy_s(pbn.cards, 80, "E:AT5.AJT.A632.KJ7 Q763.KQ9.KQJ94.T 942.87653..98653 KJ8.42.T875.AQ42");

			ULONGLONG start = GetTickCount64();

			i = CalcDDtablePBN(pbn, &res);

			if (i != 1)
			{
				Logger::WriteMessage("Error in CalcDDtablePBN");
			}
			Assert::AreEqual(i, 1, L"Error in CalcDDtablePBN", LINE_INFO());

			ULONGLONG finish = GetTickCount64();

			long totalticks = finish - start;

			float seconds = totalticks / 1000;
			long ms = (totalticks % 1000);

			int minutes = (int)seconds / 60;

			int remaining = ((int)seconds % 60);

			char sMessage[80];

			char sTemp[80];
			sprintf_s(sTemp, 80, "Double dummy solve Took: %d", minutes);
			strcpy_s(sMessage, 80, sTemp);
			sprintf_s(sTemp, 80, ".%d", remaining);
			strcat_s(sMessage, 80, sTemp);
			sprintf_s(sTemp, 80, "%d", ms);
			strcat_s(sMessage, 80, sTemp);

			Logger::WriteMessage(sMessage);

			//verify results
			sprintf_s(sTemp, 80, "Spades (NESW): %d %d %d %d ", res.resTable[0][0], res.resTable[0][1], res.resTable[0][2], res.resTable[0][3]);
			Logger::WriteMessage(sTemp);
			sprintf_s(sTemp, 80, "Hearts (NESW): %d %d %d %d ", res.resTable[1][0], res.resTable[1][1], res.resTable[1][2], res.resTable[1][3]);
			Logger::WriteMessage(sTemp);
			sprintf_s(sTemp, 80, "Diamonds (NESW): %d %d %d %d ", res.resTable[2][0], res.resTable[2][1], res.resTable[2][2], res.resTable[2][3]);
			Logger::WriteMessage(sTemp);
			sprintf_s(sTemp, 80, "Clubs (NESW): %d %d %d %d ", res.resTable[3][0], res.resTable[3][1], res.resTable[3][2], res.resTable[3][3]);
			Logger::WriteMessage(sTemp);
			sprintf_s(sTemp, 80, "No Trumps (NESW): %d %d %d %d ", res.resTable[4][0], res.resTable[4][1], res.resTable[4][2], res.resTable[4][3]);
			Logger::WriteMessage(sTemp);

			Assert::AreEqual(res.resTable[0][0], 8, L"Error in CalcDDtablePBN", LINE_INFO());
			Assert::AreEqual(res.resTable[3][2], 5, L"Error in CalcDDtablePBN", LINE_INFO());
			Assert::AreEqual(res.resTable[4][2], 9, L"Error in CalcDDtablePBN", LINE_INFO());
			Assert::AreEqual(res.resTable[1][3], 8, L"Error in CalcDDtablePBN", LINE_INFO());

		}

		TEST_METHOD(PerfectDeal)
		{
			int i;
			ddTableDealPBN pbn = ddTableDealPBN();
			ddTableResults res;

			//pbn = { "N:AT5.AJT.A632.KJ7 Q763.KQ9.KQJ94.T 942.87653..98653 KJ8.42.T875.AQ42" };
			//pbn = {"" }; //also works
			strcpy_s(pbn.cards, 80, "N:AKQJT98765432... .AKQJT98765432.. ..AKQJT98765432. ...AKQJT98765432");

			ULONGLONG start = GetTickCount64();

			i = CalcDDtablePBN(pbn, &res);

			if (i != 1)
			{
				Logger::WriteMessage("Error in CalcDDtablePBN");
			}
			Assert::AreEqual(i, 1, L"Error in CalcDDtablePBN", LINE_INFO());

			ULONGLONG finish = GetTickCount64();

			long totalticks = finish - start;

			float seconds = totalticks / 1000;
			long ms = (totalticks % 1000);

			int minutes = (int)seconds / 60;

			int remaining = ((int)seconds % 60);

			char sMessage[80];

			char sTemp[80];
			sprintf_s(sTemp, 80, "Double dummy solve Took: %d", minutes);
			strcpy_s(sMessage, 80, sTemp);
			sprintf_s(sTemp, 80, ".%d", remaining);
			strcat_s(sMessage, 80, sTemp);
			sprintf_s(sTemp, 80, "%d", ms);
			strcat_s(sMessage, 80, sTemp);

			Logger::WriteMessage(sMessage);

			//verify results
			sprintf_s(sTemp, 80, "Spades (NESW): %d %d %d %d ", res.resTable[0][0], res.resTable[0][1], res.resTable[0][2], res.resTable[0][3]);
			Logger::WriteMessage(sTemp);
			sprintf_s(sTemp, 80, "Hearts (NESW): %d %d %d %d ", res.resTable[1][0], res.resTable[1][1], res.resTable[1][2], res.resTable[1][3]);
			Logger::WriteMessage(sTemp);
			sprintf_s(sTemp, 80, "Diamonds (NESW): %d %d %d %d ", res.resTable[2][0], res.resTable[2][1], res.resTable[2][2], res.resTable[2][3]);
			Logger::WriteMessage(sTemp);
			sprintf_s(sTemp, 80, "Clubs (NESW): %d %d %d %d ", res.resTable[3][0], res.resTable[3][1], res.resTable[3][2], res.resTable[3][3]);
			Logger::WriteMessage(sTemp);
			sprintf_s(sTemp, 80, "No Trumps (NESW): %d %d %d %d ", res.resTable[4][0], res.resTable[4][1], res.resTable[4][2], res.resTable[4][3]);
			Logger::WriteMessage(sTemp);

			Assert::AreEqual(res.resTable[0][0], 13, L"Error in CalcDDtablePBN", LINE_INFO());
			Assert::AreEqual(res.resTable[3][2], 0, L"Error in CalcDDtablePBN", LINE_INFO());
			Assert::AreEqual(res.resTable[4][2], 0, L"Error in CalcDDtablePBN", LINE_INFO());
			Assert::AreEqual(res.resTable[0][1], 0, L"Error in CalcDDtablePBN", LINE_INFO());

		}


		TEST_METHOD(BasicTestVB)
		{
			int i;
			ddTableDealPBN pbn = ddTableDealPBN();
			ddTableResults res;

			//pbn = { "E:AT5.AJT.A632.KJ7 Q763.KQ9.KQJ94.T 942.87653..98653 KJ8.42.T875.AQ42" };
			//pbn = {"" }; //also works
			strcpy_s(pbn.cards, 80, "E:AT5.AJT.A632.KJ7 Q763.KQ9.KQJ94.T 942.87653..98653 KJ8.42.T875.AQ42");

			ULONGLONG start = GetTickCount64();

			i = CalcDDtablePBNVB(&pbn, &res);

			if (i != 1)
			{
				Logger::WriteMessage("Error in CalcDDtablePBN");
			}
			Assert::AreEqual(i, 1, L"Error in CalcDDtablePBN", LINE_INFO());

			ULONGLONG finish = GetTickCount64();

			long totalticks = finish - start;

			float seconds = totalticks / 1000;
			long ms = (totalticks % 1000);

			int minutes = (int)seconds / 60;

			int remaining = ((int)seconds % 60);

			char sMessage[80];

			char sTemp[80];
			sprintf_s(sTemp, 80, "Double dummy solve Took: %d", minutes);
			strcpy_s(sMessage, 80, sTemp);
			sprintf_s(sTemp, 80, ".%d", remaining);
			strcat_s(sMessage, 80, sTemp);
			sprintf_s(sTemp, 80, "%d", ms);
			strcat_s(sMessage, 80, sTemp);

			Logger::WriteMessage(sMessage);

			//verify results
			sprintf_s(sTemp, 80, "Spades (NESW): %d %d %d %d ", res.resTable[0][0], res.resTable[0][1], res.resTable[0][2], res.resTable[0][3]);
			Logger::WriteMessage(sTemp);
			sprintf_s(sTemp, 80, "Hearts (NESW): %d %d %d %d ", res.resTable[1][0], res.resTable[1][1], res.resTable[1][2], res.resTable[1][3]);
			Logger::WriteMessage(sTemp);
			sprintf_s(sTemp, 80, "Diamonds (NESW): %d %d %d %d ", res.resTable[2][0], res.resTable[2][1], res.resTable[2][2], res.resTable[2][3]);
			Logger::WriteMessage(sTemp);
			sprintf_s(sTemp, 80, "Clubs (NESW): %d %d %d %d ", res.resTable[3][0], res.resTable[3][1], res.resTable[3][2], res.resTable[3][3]);
			Logger::WriteMessage(sTemp);
			sprintf_s(sTemp, 80, "No Trumps (NESW): %d %d %d %d ", res.resTable[4][0], res.resTable[4][1], res.resTable[4][2], res.resTable[4][3]);
			Logger::WriteMessage(sTemp);

			Assert::AreEqual(res.resTable[0][0], 8, L"Error in CalcDDtablePBN", LINE_INFO());
			Assert::AreEqual(res.resTable[3][2], 5, L"Error in CalcDDtablePBN", LINE_INFO());
			Assert::AreEqual(res.resTable[4][2], 9, L"Error in CalcDDtablePBN", LINE_INFO());
			Assert::AreEqual(res.resTable[1][3], 8, L"Error in CalcDDtablePBN", LINE_INFO());

		}
	};
}
