// parser.cpp : Defines the entry point for the console application.
//

//#include "stdafx.h"
#include <fstream>
#include <string>
#include <iostream>
#include <sstream>
#include <map>
#include <vector>
using namespace std;


int main()
{
	string ifile, ofile;
	cout << "Type \'def\' to select default names: musicIn.txt music<song-count>.txt; \n";
	cout << "Enter input and output file name: ";
	cin >> ifile;
	if (ifile == "def" ) {
		ifile = "musicIn.txt";
		ofile = "music.txt";
	} else
		cin >> ofile;

	ifstream fin(ifile);
	ofstream fout(ofile);
	if (!fin.is_open()) {
		cout << "fraier\n";
		return 0;
	}
	map<string, vector<string>> data;
	string artist, song, line;
	while (getline(fin, line)) {
		istringstream ss(line);
		getline(ss, song, '\t');
		getline(ss, artist, '\t');
		data[artist].push_back(song);
	}
	int songsCount = 0;
	for (const auto& artist : data) {
		fout << artist.first << '\n';
		songsCount += artist.second.size();
		for (const auto& song : artist.second) {
			fout << " -> " << song << '\n';
		}
		fout << '\n';
	}
	cout << "Artist number: " << data.size() <<endl;
	cout << "Songs number: " << songsCount << endl;
	string newName(ofile.begin(), ofile.end() - 4);
	newName += std::to_string(songsCount);
	newName += ".txt";
	if (!std::rename(ofile.c_str(), newName.c_str()))
		cout << "fraier\n";
	system("pause");
    return 0;
}

