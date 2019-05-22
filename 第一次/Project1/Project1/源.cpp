#include<iostream>
#include<stdlib.h>
#include<string>
#include<sstream>
using namespace std;
char putin[100];
char *keyword[6] = { (char *)"for",(char *)"if",(char *)"then",(char *)"else",(char *)"while",(char *)"do" };
char id[50];
string sid;
int taken ;
char c;
int num;
int p = 0;
void check() {
	char ch;
	ch = putin[p];
	int j = 0;
	int n = 0;
	int m = 0;
	for (m = 0; m < 50; m++) {
		id[m] = NULL;
	}
	taken = -1;
	while (ch == ' ' || ch == '/n') {
		p++;
		ch = putin[p];
	}
	if ((ch >= 'a'&&ch <= 'z')||(ch >= 'A'&&ch <= 'Z')) {
		while (ch != ' '&&ch !='/n'&& ((ch >= 'a'&&ch <= 'z') || (ch >= 'A'&&ch <= 'Z'))) {
			id[j++]= ch;
			p++;
			ch = putin[p];
		}
		for (n = 0; n < 6; n++) {
			if (!strcmp(id, keyword[n])) {
				taken = n + 1;
				break;
			}
			else {
				taken = 10;
				continue;
			}
		}	
	}
	else if(ch >= '0'&&ch <= '9') {
		while (ch != ' '&&ch != '/n') {
			if (!(ch >= '0'&&ch <= '9')) {
				taken = 11;
				stringstream sst;
				sst << string(id);
				sst >> num;
				break;
			}
			else {
				id[j++] = ch;
				p++;
				ch = putin[p];
			}
		}
		if ((ch >= 'a'&&ch <= 'z') || (ch >= 'A'&&ch <= 'Z')) {
			taken = -1;
		}
	}
	else if (!((ch >= 'a'&&ch <= 'z') || (ch >= 'A'&&ch <= 'Z') || (ch >= '0'&&ch <= '9'))) {
		switch (ch) {
			case '+': {
				taken = 13;
				id[0] = ch;
				p++;
			};
					  break;
			case '-': {
				taken = 14;
				id[0] = ch;
				p++;
			};
					  break;
			case '*': {
				taken = 15;
				id[0] = ch;
				p++;
			};
					  break;
			case '/': {
				taken = 16;
				id[0] = ch;
				p++;
			};
					  break;
			case ':': {
				id[0] = ch;
				if (putin[++p] == '=') {
					taken = 18;
					id[1] = putin[p];
					p++;
				}
				else {
					taken = 17;
				}
			};
					  break;
			case '<': {
				id[0] = ch;
				if (putin[++p] == '>') {
					taken = 21;
					id[1] = putin[p];
					p++;
				}
				else if (putin[++p] == '=') {
					taken = 22;
					id[1] = putin[p];
					p++;
				}
				else {
					taken = 20;
				}
			};
					  break;
			case '>': {
				id[0] = ch;
				if (putin[++p] == '=') {
					taken = 24;
					id[1] = putin[p];
					p++;
				}
				else {
					taken = 23;
				}
			};
					  break;
			case '=': {
				taken = 25;
				id[0] = ch;
				p++;
			};
					  break;
			case ';': {
				taken = 26;
				id[0] = ch;
				p++;
			};
					  break;
			case '(': {
				taken = 27;
				id[0] = ch;
				p++;
			};
					  break;
			case ')': {
				taken = 28;
				id[0] = ch;
				p++;
			};
					  break;
			case '#': {
				taken = 0;
				id[0] = ch;
				p++;
			};
					  break;
		}
	}
	sid = string(id);
}
int main()
{
	int i = 0;
	cout << "请输入 以#作为结尾" << endl;
	cin>>noskipws >> c;
	while (c != '#') {
		putin[i++] = c;
		cin >>noskipws>> c;
	}
	putin[i++] = c;
	do {
		check(); 
		switch (taken) {
		case 11: printf("(11, %d)\n ", num); break;
		case -1: printf("error!\n"); break;
		default: printf("(%d,%s)\n", taken, id);
		}
	} while (taken != 0);
	system("Pause");
}