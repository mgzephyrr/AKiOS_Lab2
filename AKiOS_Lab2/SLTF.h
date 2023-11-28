#pragma once
/// <summary>
/// ��������� ����������������� ���������������� �� ���� ����� ������ � ����������� FIFO
/// </summary>
struct SLTFElem {
	std::string name;
	int ratingPlace;

	SLTFElem* nextByName;
	SLTFElem* nextByRating;

	SLTFElem(std::string _name, int _ratingPlace) { name = _name; ratingPlace = _ratingPlace; nextByName = nextByRating = nullptr; } //�����������
};

// ��������� �������, �������������� ������ �� ���������� .cpp ������
std::tuple<SLTFElem*, SLTFElem*> MakeSLTF();
void SLTFPrintFromFirst(SLTFElem*, SLTFElem*);
void SLTFPrintFromLast(SLTFElem*, SLTFElem*);
void SLTFRemove(SLTFElem*&, SLTFElem*&, std::string, int);
int SLTFCount(SLTFElem*, std::string, int);