//------------------------------------------------------------------------------------------------
//2024.3.4 월 56
// VS 17.9.0, Release/x64,project 속성 - std::c++latest
//------------------------------------------------------------------------------------------------

//창 크기 : (80 x 25)
//(1 / 1)
//
//소스파일 save  기능

#include"save.h"


int main()

{
	cout << "2024 STL" << endl;

	save("환경.cpp");

}
void save(string_view fileName)
{
	// 읽을 파일을 연다
	ifstream in{ fileName.data()};
	if (!in)
	{
		cout << "파일을 열지 못함";
		exit(0);
	}
	// 쓸 파일을 덧붙이기 모드로 연다
	ofstream out("2024 1 월56목78 강의저장.txt", ios::app);
	//저장한 시간을 파일에 기록한다
	auto now = chrono::system_clock::now();
	cout << now << endl;
	auto time = chrono::system_clock::to_time_t(now);	//utc
	auto lt = localtime(&time); 	//현지 시간으로 변환

	auto old = out.imbue(locale("ko_KR"));
	out << endl << endl;
	out << "============================" << endl;
	out << fileName << put_time(lt, ",  저장시간: %x %A %X") << endl;
	out << "============================" << endl;
	out.imbue(old);
	// 읽을파일의 모든 내용을 읽어 쓸 파일에 덧붙인다
	vector<char> v{ istreambuf_iterator<char>{in},{} };
	copy(v.begin(), v.end(), ostreambuf_iterator<char>{out});
	for (char c : v)
		cout << c;

}

