#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include<cctype>
#include"windows.h"
using namespace std;
char n[255]{ 0 };
char O[255]{ 0 };
uint64_t m{ 0 }, of{ 0 }, h{ 0 };
int sizeBook = 1;
int Indik, A, i, indx = 0;
class Abonent {
	int sizeName;
	int sizeOtherInfo;
	char* Name;
	uint64_t mobPh;
	uint64_t officePh;
	uint64_t homePh;
	char* otherInfo;
public:
	Abonent(const char* n, uint64_t m, uint64_t of, uint64_t h, const char* O) : sizeName{ 0 }, sizeOtherInfo { 0 }, Name{ n ? new char[strlen(n) + 1] : nullptr }, mobPh{ m }, officePh{ of },
																				homePh{ h }, otherInfo{ O ? new char[strlen(O) + 1] : nullptr }	{}
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
	void SetMobPh(uint64_t m) {
		mobPh = m;
	}
	void SetOfficePh(uint64_t of) {
		officePh = of;
	}
	void SetHomePh(uint64_t h) {
		homePh = h;
	}
	void SetOtherInf(const char* O) {
		sizeOtherInfo = (int)strlen(O) + 1;
		otherInfo = new char[sizeOtherInfo];
		strcpy(otherInfo, O);
	}
	int SerchByName(const char* otherName) {
		return _stricmp(Name, otherName);
	}
	inline void Print() {
		if (Name) cout << "�������: " << Name << endl;
		else { cout << "��� �����" << endl; }
		cout << "��������� �������: " << mobPh << endl << "������� �������: " << officePh << endl;
		cout << "�������� �������: " << homePh << endl << "�������������� ���������� � ��������: " << otherInfo << endl;
	}
		~Abonent() { delete[] Name; delete[] otherInfo;	}
};
Abonent* PhoneBook = new Abonent[sizeBook];
int main() {
	setlocale(LC_ALL, "");
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
					PhoneBook[indx].SetName(n);
					cout << "��������� �������: "; 							cin >> m; cin.ignore(32767, '\n');
					PhoneBook[indx].SetMobPh(m);
					cout << "������� �������: ";							cin >> of; cin.ignore(32767, '\n');
					PhoneBook[indx].SetOfficePh(of);
					cout << "�������� �������: ";							cin >> h; cin.ignore(32767, '\n');
					PhoneBook[indx].SetHomePh(h);
					cout << "�������������� ���������� �� ��������: ";		gets_s(O);
					PhoneBook[indx].SetOtherInf(O);
					//PhoneBook[indx].Print();
					sizeBook++; indx++;
				}
			} while (A == 1);
			sizeBook--; indx--;
		}
		break;
		case 2: { 
			cout << "����� ������� �������? �������� �����" << endl << "������� 0 ��� �������� � ���������� ����" << endl;
			for (i = 0; i < sizeBook; i++) {
				cout << i + 1 << " "; PhoneBook[i].Print(); cout << endl;
			}
			cin >> A; cin.ignore(32767, '\n');
			if (A > 0 || A <= i + 1) {
				if (sizeBook == 1) { 
					Abonent* New_PhoneBook = new Abonent[sizeBook];
					New_PhoneBook[0];
					delete[] PhoneBook;
					PhoneBook = New_PhoneBook;
				}
				else {
					--sizeBook;
					Abonent* New_PhoneBook = new Abonent[sizeBook];
					i = 0;
					for (int j = 0; j <= sizeBook; j++) {
						if (j == A-1) { continue; }
						else {
							New_PhoneBook[i] = PhoneBook[j];
							i++;
						}
					}
					delete[] PhoneBook; 
					PhoneBook = New_PhoneBook; // �� ������ ����� ���������� ����������, ������?
				}

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
					for (i = 0; i < sizeBook; i++) {
						int serch = PhoneBook[i].SerchByName(n);
						if (serch) continue;
						else PhoneBook[i].Print();
					}
				}
			} while (A == 1);
		}
		break;
		case 4: {
			for (i = 0; i < sizeBook; i++) {
				cout << i + 1 << " "; PhoneBook[i].Print(); cout << endl;
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
	} while (Indik>0 && Indik<4);
	delete[] PhoneBook;
	return 0;
}