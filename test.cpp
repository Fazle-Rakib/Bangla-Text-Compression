#include <bits/stdc++.h>
using namespace std;
vector<int> encoding(string s1)
{
	cout << "Encoding\n";
	unordered_map<string, int> table;
	for (int i = 0; i <= 255; i++) {
		string ch = "";
		ch += char(i);
		table[ch] = i;
	}

	string p = "", c = "";
	p += s1[0];
	int code = 256;
	vector<int> output_code;
	cout << "String\tOutput_Code\tAddition\n";
	for (int i = 0; i < s1.length(); i++) {
		if (i != s1.length() - 1)
			c += s1[i + 1];
		if (table.find(p + c) != table.end()) {
			p = p + c;
		}
		else {
			cout << p << "\t" << table[p] << "\t\t"
				<< p + c << "\t" << code << endl;
			output_code.push_back(table[p]);
			table[p + c] = code;
			code++;
			p = c;
		}
		c = "";
	}
	cout << p << "\t" << table[p] << endl;
	output_code.push_back(table[p]);
	return output_code;
}

void decoding(vector<int> op)
{
	cout << "\nDecoding\n";
	unordered_map<int, string> table;
	for (int i = 0; i <= 255; i++) {
		string ch = "";
		ch += char(i);
		table[i] = ch;
	}
	int old = op[0], n;
	string s = table[old];
	string c = "";
	c += s[0];
	cout << s;
	int count = 256;
	for (int i = 0; i < op.size() - 1; i++) {
		n = op[i + 1];
		if (table.find(n) == table.end()) {
			s = table[old];
			s = s + c;
		}
		else {
			s = table[n];
		}
		cout << s;
		c = "";
		c += s[0];
		table[count] = table[old] + c;
		count++;
		old = n;
	}
}
bool getFileContent(string fileName,vector<int> &output_code_com)
{
    ifstream in(fileName.c_str());
    if(!in)
    {
        cerr << "Can't Open";
        return false;
    }
    string s;
    while(getline(in,s))
    {
        if(s.size() > 0)
        {
            stringstream geek(s);
            int x = 0;
            geek >> x;
            output_code_com.push_back(x);
        }
    }
    in.close();
    return true;
}
int main()
{
    std::ifstream t("File.txt");
    std::stringstream buffer;
    buffer << t.rdbuf();
	string s = buffer.str();
	vector<int> output_code = encoding(s);
	ofstream output_file("./com.txt");
	ostream_iterator<int> output_iterator(output_file,"\n");
	copy(output_code.begin(),output_code.end(),output_iterator);
	cout << "Output Codes are: ";

	vector<int>output_code_com;
	bool result = getFileContent("./com.txt",output_code_com);
	for (int i = 0; i < output_code_com.size(); i++) {
		cout << output_code_com[i] << " ";
	}
	cout << endl;
	decoding(output_code_com);
}

