#include <iostream>
#include <vector>
#include <fstream>
#include <stdlib.h>

using namespace std;

vector<int> load_file(const string& _filename);
bool max_search(const vector<int>& _vec, int& _max_val);

string filename;

int max_val;

int main(){
	vector<int> elements;
	cout << "Filename: ";
	cin >> filename;
	elements = load_file(filename);
	if (max_search(elements, max_val))
		cout << "Found a most common number!\nThe number is: " << max_val;
	else
		cout << "Sorry, I couldn't find a single number :(\n";
}

vector<int> load_file(const string& _filename) {
	vector<int> _vec;
	ifstream _inputf(_filename.c_str());
	if (_inputf.fail()) {
		cout << "Couldn't open " << _filename << " file";
		exit(1);
	}
	int data;
	while (_inputf >> data) {
		cout << data << ' ';
		_vec.push_back(data);
	}
	_inputf.close();
	return _vec;
}

bool max_search(const vector<int>& _vec, int& _max_val) {
	bool _exist = false;
	int _temp = 0;
	int _tempmax = 0;
	int _tempcount = 0;
	int _maxcount = 0;
	for (unsigned int i = 0; i < _vec.size(); i++) {
		_temp = _vec[i];
		_tempcount = 0;
		for (unsigned int j = i; j < _vec.size(); j++) {
			if (_vec[j] == _temp) {
				_tempcount++;
				_tempmax = _vec[j];
			}
		}
		if (_tempcount > _maxcount) {
			_maxcount = _tempcount;
			_max_val = _tempmax;
			_exist = true;
		}
	}
	return _exist;
}
