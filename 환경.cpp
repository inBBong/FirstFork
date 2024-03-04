//------------------------------------------------------------------------------------------------
//2024.3.4 �� 56
// VS 17.9.0, Release/x64,project �Ӽ� - std::c++latest
//------------------------------------------------------------------------------------------------

//â ũ�� : (80 x 25)
//(1 / 1)
//
//�ҽ����� save  ���

#include"save.h"


int main()

{
	cout << "2024 STL" << endl;

	save("ȯ��.cpp");

}
void save(string_view fileName)
{
	// ���� ������ ����
	ifstream in{ fileName.data()};
	if (!in)
	{
		cout << "������ ���� ����";
		exit(0);
	}
	// �� ������ �����̱� ���� ����
	ofstream out("2024 1 ��56��78 ��������.txt", ios::app);
	//������ �ð��� ���Ͽ� ����Ѵ�
	auto now = chrono::system_clock::now();
	cout << now << endl;
	auto time = chrono::system_clock::to_time_t(now);	//utc
	auto lt = localtime(&time); 	//���� �ð����� ��ȯ

	auto old = out.imbue(locale("ko_KR"));
	out << endl << endl;
	out << "============================" << endl;
	out << fileName << put_time(lt, ",  ����ð�: %x %A %X") << endl;
	out << "============================" << endl;
	out.imbue(old);
	// ���������� ��� ������ �о� �� ���Ͽ� �����δ�
	vector<char> v{ istreambuf_iterator<char>{in},{} };
	copy(v.begin(), v.end(), ostreambuf_iterator<char>{out});
	for (char c : v)
		cout << c;

}

