#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include<cctype>
#include"windows.h"
using namespace std;
char n[255]{ 0 };
char O[255]{ 0 };
uint64_t m{ 0 }, of{ 0 }, h{ 0 };
const int sizeBook = 10;
int Indik, A;
class Abonent {
	int sizeName;
	int sizeOtherInfo;
	char* Name;
	uint64_t mobPh;
	uint64_t officePh;
	uint64_t homePh;
	char* otherInfo;
public:
	/*Abonent(const char* n, uint64_t m, uint64_t of, uint64_t h, const char* O) : sizeName{(int) strlen(n) + 1 }, sizeOtherInfo { (int)strlen(O) + 1 }, Name{ n ? new char[(int)strlen(n) + 1] : nullptr }, mobPh{ m }, officePh{ of },
																			homePh{ h }, otherInfo{ O ? new char[(int)strlen(O) + 1] : nullptr }	{}*/
	Abonent() { sizeName = 0; sizeOtherInfo = 0; Name = nullptr; mobPh = 0; officePh = 0; homePh = 0; otherInfo = nullptr; }
	Abonent& operator = (const Abonent& otherAbonent) {   // �������������� � ����������� ����������� �� ��������
		this->sizeName = otherAbonent.sizeName;
		this->Name = new char[sizeName];
		strcpy(Name, otherAbonent.Name);
		this->mobPh = otherAbonent.mobPh;
		this->officePh = otherAbonent.officePh;
		this->homePh = otherAbonent.homePh;
		this->sizeOtherInfo = otherAbonent.sizeOtherInfo;
		this->otherInfo = new char[sizeOtherInfo];
		strcpy(otherInfo, otherAbonent.otherInfo);
		return *this;
	}

	void SetName (const char* n) {
		sizeName = (int)strlen(n) + 1;
		Name = new char[sizeName];
		strcpy(Name, n);
	}
	char* GetName() {
		return Name;
	}
	void SetMobPh(uint64_t m) {
		mobPh = m;
	}
	uint64_t GetMobPh() {
		return mobPh;
	}
	void SetOfficePh(uint64_t of) {
		officePh = of;
	}
	uint64_t GetOfficePh() {
		return officePh;
	}
	void SetHomePh(uint64_t h) {
		homePh = h;
	}
	uint64_t GetHomePh() {
		return homePh;
	}
	void SetOtherInf(const char* O) {
		sizeOtherInfo = (int)strlen(O) + 1;
		otherInfo = new char[sizeOtherInfo];
		strcpy(otherInfo, O);
	}
	char* GetOtherInf() {
		return otherInfo;
	}
	int SerchByName(const char* otherName) {
		return _stricmp(Name, otherName);
	}
	void Print() {
		if (Name) {
			cout << "�������: ";
			for (int i = 0; i < sizeName; i++)	{	cout << Name[i];	}
				cout << endl;
		}
		else { cout << "��� �����" << endl; }
		cout << "��������� �������: " << mobPh << endl;
		cout << "������� �������: " << officePh << endl;
		cout << "�������� �������: " << homePh << endl;
		if (otherInfo) {
			cout << "�������������� ���������� � ��������: ";
			for (int i = 0; i < sizeOtherInfo; i++) { cout << otherInfo[i]; }
			cout << endl;
		}
		else { cout << "��� ����������" << endl; }
	}
		~Abonent() { delete[] Name; delete[] otherInfo;	}
};
Abonent PhoneBook[sizeBook];
int main() {
	setlocale(LC_ALL, "");
	int ind = 0;
	cout << "�����������! �������� ��������: " << endl;
	do {
		cout << "1 - �������� �������" << endl << "2 - ������� �������" << endl << "3 - ������ ������� �� ���" << endl;
		cout << "4 - �������� ���� ���������" << endl << "0 - ������� ����������" << endl;
		cin >> Indik; cin.ignore(32767, '\n');
		system ("cls");
		switch (Indik) {
		case 1: {
			do {
				cout << "������� 1, ����� �������� �������" << endl << "������� 0 ��� �������� � ���������� ����" << endl;
				cin >> A; cin.ignore(32767, '\n');
				system("cls");
				if (A == 1) {
					
					cout << "������� ���, ������� � �������� ��������: "; 	gets_s(n);
					PhoneBook[ind].SetName(n);
					cout << "��������� �������: "; 							cin >> m; cin.ignore(32767, '\n');
					PhoneBook[ind].SetMobPh(m);
					cout << "������� �������: ";							cin >> of; cin.ignore(32767, '\n');
					PhoneBook[ind].SetOfficePh(of);
					cout << "�������� �������: ";							cin >> h; cin.ignore(32767, '\n');
					PhoneBook[ind].SetHomePh(h);
					cout << "�������������� ���������� �� ��������: ";		gets_s(O);
					PhoneBook[ind].SetOtherInf(O);
					PhoneBook[ind].Print();
					ind++;
					//sizeBook++;
				}
			} while (A == 1);
			//sizeBook--;
		}
		break;
		case 2: { 
			cout << "����� ������� �������? �������� �����" << endl << "������� 0 ��� �������� � ���������� ����" << endl;
			for (int i = 0; i < sizeBook; i++) {
				cout << i + 1 << " "; 
				PhoneBook[i].Print(); cout << endl;
			}
			cin >> A; cin.ignore(32767, '\n');
			if (A > 0 || A <= sizeBook) {
				//if (sizeBook == 1) { 
				//	Abonent* New_PhoneBook = new Abonent[sizeBook];
				//	New_PhoneBook[0];
				//	delete[] PhoneBook;
				//	PhoneBook = New_PhoneBook;
				//}
				//else {
				//	--sizeBook;
				//	Abonent* New_PhoneBook = new Abonent[sizeBook];
				//	int z = 0;
				//	for (int j = 0; j <= sizeBook; j++) {
				//		if (j == A-1) { continue; }
				//		else {
				//			New_PhoneBook[z] = PhoneBook[j];
				//			z++;
				//		}
				//	}
				//	delete[] PhoneBook; 
				//	PhoneBook = New_PhoneBook; // �� ������ ����� ���������� ����������, ������?
				//}

			}
		}
		cout << endl << "������� ������";
		Sleep(1000);	system("cls");
		break;
		case 3: {
			do 	{ cout << "������� 1 ��� ������ �������� �� ���" << endl << "������� 0 ��� �������� � ���������� ����" << endl;
				cin >> A; cin.ignore(32767, '\n');
				system("cls");
				if (A == 1) {
					cout << "������� ���, ������� � �������� ��������: "; 	gets_s(n);
					for (int i = 0; i < ind; i++) {
						int serch = PhoneBook[i].SerchByName(n);
						if (serch) continue;
						else PhoneBook[i].Print();
					}
				}
			} while (A == 1);
		}
		break;
		case 4: {
			for (int i = 0; i < ind; i++) {
				cout << i + 1 << " "; 
				PhoneBook[i].Print(); cout << endl;
			}
			do {
				cout << "������� 0 ��� �������� � ���������� ����" << endl;
				cin >> A; 	cin.ignore(32767, '\n');
			} while (A != 0);
		}
		break;
		default: cout << "����� �������!";
			break;
		}
	} while (Indik>0 && Indik<5);
	//delete[] PhoneBook;
	return 0;
}