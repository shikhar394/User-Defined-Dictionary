#include<fstream.h> //file functions
#include<string.h> //strlen() ,strcmpi()
#include<conio.h> //clrscr() ,getch()
#include<stdio.h> //gets()
#include<ctype.h> //tolower()
#include<stdlib.h> //gotoxy()
class dict
{
private :
	char word[20];
	char mean[30];
	char sent[50];
	char syn[10];
	char ant[10];
public:
	char * retword()
	{
		  return word;
	}
	void input(char []);
	void show(char []);
	void box();   //can be made independant not related to class
	void show(char [],int &j);
	void show();
};
void dict::box()   //independant & invoke when reqd
{
	for (int l = 5; l <= 75; l++)
	{
		gotoxy(l, 7);
		cout << (char)205;
		gotoxy(l, 24);
		cout << (char)205;
	}
	for (int k = 3; k <= 24; k++)
	{
		gotoxy(5, k);
		cout << (char)186;
		gotoxy(75, k);
		cout << (char)186;
	}
}
void dict::input(char title[100])
{
	clrscr();
	box();   //it would have invoked even if independant
	gotoxy(29, 6); cout << title << endl;
	gotoxy(10, 10); cout << "Please enter the word you would like to add to the dictionary .\n";
	gotoxy(19, 11);	gets(word);
	gotoxy(19, 12); cout << "Please enter the meaning of the word (" << word << ")." << endl;
	gotoxy(19, 13);	gets(mean);
	gotoxy(19, 14); cout << "Please enter a sentence with the word (" << word << ")." << endl;
	gotoxy(19, 15);	gets(sent);
	gotoxy(19, 16); cout << "Please enter a synonym for the word (" << word << ").\n";
	gotoxy(19, 17);	gets(syn);
	gotoxy(19, 18); cout << "Please enter a amtonym for the word (" << word << ").\n";
	gotoxy(19, 19);	gets(ant);
}
void dict::show(char title[100])
{
	box();
	gotoxy(29, 6); cout << title << endl << endl << endl;
	gotoxy(29, 10);cout << "Word    : " << word << endl;
	gotoxy(29, 11); cout << "Mean    : " << mean << endl;
	gotoxy(29, 12);  cout << "Example : " << sent << endl;
	gotoxy(29, 13); cout << "Synonym : " << syn << endl;
	gotoxy(29, 14); cout << "Antonym : " << ant << endl;
	getch();
	clrscr();
}
void dict::show(char title[100],int &j)
{
	box();
	gotoxy(29, j); cout << title ;j+=4;
	gotoxy(29, j);cout << "Word    : " << word << endl;j++;
	gotoxy(29, j); cout << "Mean    : " << mean << endl;j++;
	gotoxy(29, j);  cout << "Example : " << sent << endl;j++;
	gotoxy(29, j); cout << "Synonym : " << syn << endl;j++;
	gotoxy(29, j); cout << "Antonym : " << ant << endl;j++;
	getch();
}
void dict :: show()
{
	box();
	gotoxy(29,6);cout <<"VIEW ALL WORDS";
	gotoxy(29,7);cout <<"______________"<<endl;
	cout <<"Word -> "<<word <<endl;
	cout <<"Meaning -> "<<mean<<endl;
	cout <<"Example -> "<<sent<<endl;
	cout << "Synonym -> " << syn << endl;
	cout << "Antonym -> " << ant << endl;
	getch();
	clrscr();
}
void addrecs();
int sizefile();
void modrecs();
void searchrecs();
void viewrecs();
void wod();
void main()
{
	clrscr();

	cout << "                          ``..---::///+++ooosss-                         " << endl;
	cout<<"               `..--://++oossssssssssssssssssssssss:                     "<<endl;
	cout<<"      `.-:/+oossssssssssssssssssssssssssssssssssssss+`                   "<<endl;
	cout<<" `-/+ossssssssssssssssss+sssssssssssssssssssssssooo+/o.                  "<<endl;
	cout<<" osssssssssso+sssssssos+  sssssssssooss+/:oo --`- +o so-                 "<<endl;
	cout<<" yyss+++/+os  osssss/`ss++ss/  o+    /s    s/ /:s- + sss:                "<<endl;
	cout<<" shys+     /o+oso//       o  s: o- s  so:: +o :sss- +ssss+`              "<<endl;
	cout<<" +hhss  ss  +  ss  .o  so    oo  + ++ +  o -o Oosso ossssso.             "<<endl;
	cout<<" -hhys  os  :  +  sos  ss  o ss  o o+ +    +++os+. ssssssso-             "<<endl;
	cout<<" `yhhso so  :  + +o/o  +-  o    s+osoosssssssssso/ sssssssss/`           "<<endl;
	cout<<"  /hhys     o  -o  +oso+ooosssssssssssssssssssssssssssssssssss+`         "<<endl;
	cout<<"  `yhhs//+osssssssssssssssssssssssssssssssssssssssssssssssssssso.        "<<endl;
	cout<<"   +hhhssssssssssssssssssssssssssssssssssssssssssssssssssssssssso-       "<<endl;
	cout<<"   .hhhyssssssssssssssssssssssssssssssssssssssssssssssssssssssssss:`     "<<endl;
	cout<<"   ohhhsssssssssssssssssssssssssssssssssssssssssssssssssssssssssss+`     "<<endl;
	cout<<"   .yhhyssssssssssssssssssssssssssssssssssssssssssssssssssssssssssso.    "<<endl;
	cout<<"    ohhhyssssssssssssssssssssssssssssssssssssssssssssssssssssssssssso.   "<<endl;
	cout<<"    .yhhhssssssssssssssssssssssssssssssssssssssssssssooooo+++//::-...`   "<<endl;
	cout<<"     +hhhyssssssssssssssssssssssssssssssoooo++//::---...`````````        "<<endl;
	cout<<"     `yhhhyssssssssssssssssssooo+//::--...````````````````````````       "<<endl;
	cout<<"      :hhhhsssssssssoo+//:--..````````````````````````````````````       "<<endl;
	cout<<"       +hhhyssoo/:-..````````````````````````````````````````````        "<<endl;
	cout<<"       `shhys:.``````````````````````````````````````````````````        "<<endl;
	cout<<"        .yhso```````````````````````````````````....---:::////+++:       "<<endl;
	cout<<"         .yss-````````````...---:::////++++ooossssssssssssssssssss/      "<<endl;
	cout<<"          .sss+///+++ooossssssssssssssssssssssssoooo+++/////::::---`     " <<endl;
	cout<<"           `:+oosssssssssoooo+++///:::---...``                           "<<endl;

        dict d;
	d.box();
	int ch = 1;
	int count =0;
	while (ch < 6)
	{	clrscr();
		d.box();
		gotoxy(31, 5); cout << "DICTIONARY";
		gotoxy(31, 6);	cout <<"__________";
		gotoxy(29, 9); cout <<  "1. Show all words" << endl;
		gotoxy(29, 10); cout << "2. Search a word " << endl;
		gotoxy(29, 11); cout << "3. Add a word    " << endl;
		gotoxy(29, 12); cout << "4. Modify a word " << endl;
		gotoxy(29, 13); cout << "5. View your word for the day " << endl;
		gotoxy(29, 14); cout << "6. Exit" << endl;
		gotoxy(29, 17); cout << "Please enter your choice : ";
		cin >> ch;
		switch (ch)
		{
		case 1:
			viewrecs();
			break;
		case 2:
			searchrecs();
			break;
		case 3:
			addrecs();
			break;
		case 4:
			modrecs();
			break;
		case 5:
			wod();
			break;

		}
	}
}
void viewrecs()
{
	clrscr();
	dict d;
	fstream f;
	int j=10;
	char title[] = "VIEW RECORDS";
	f.open("dict.dat", ios::in | ios::binary);
	while (f != 0)
	{
		f.read((char*)&d, sizeof(d));
		if (f.eof())
		{
			gotoxy(29,21);cout << "No more words.";j++;
			gotoxy(29,22);cout <<"Thank You.";
			break;
		}
		d.show(title);
	}
	f.close();
	getch();
	clrscr();
}
void searchrecs()
{
	clrscr();
	dict d;
	fstream f;
	char title[] = "SEARCH RECORDS";
	int dum = 0, du = 0;
	char ch,found;
	char sword[20];
	d.box();
	gotoxy(10,15);cout << "Enter word you would like to search for : ";
	gotoxy(10,16);gets(sword);
	getch();
	clrscr();
	f.open("dict.dat", ios::in | ios::binary);
	while (f)
	{
		f.read((char*)&d ,sizeof(d));
		{
			if (strcmpi(d.retword(), sword) == 0)
			{
				d.show(title);
				found = 'y';
			}
		}
	}
	if (found != 'y')
	{
		d.box();
		gotoxy(10,10);
		cout << "The word you looked for is not present in the dictionary .";
		gotoxy(10,11);cout <<"Would you like to add it ?";
		gotoxy(10,12);cout <<"Press 'y' to enter .";
		cin >> ch;
		ch = tolower(ch);
		if (ch == 'y')
			addrecs();
	}
	f.close();
	getch();
	clrscr();
}
void addrecs()
{
	clrscr();
	dict d;
	fstream f;
	char title[] = "ADD RECORDS";
	char i = 'y';
	f.open("dict.dat", ios::app | ios::binary);
	while (i == 'y')
	{
		d.input(title);
		f.write((char*)&d, sizeof(d));
		       gotoxy(10,21);cout << "Would you like to add more words ?.Press y to add more words : ";
		cin >> i;
		i = tolower(i);
	}
	f.close();
	getch();
	clrscr();
}
void modrecs()
{
	clrscr();
	dict d;
	char title[] = "MODIFY RECORDS";
	fstream f, f1;
	char sword[20];
	cout << "Enter the word you want to modify .";
	gets(sword);
	f.open("dict.dat", ios::in | ios::binary);
	f1.open("temp.dat", ios::out | ios::binary);
	while (f)
	{
		f.read((char*)&d, sizeof(d));
		if (f.eof())
			break;
		if (strcmp(sword, d.retword()) == 0)
		{
			d.input(title);
		}
		f1.write((char*)&d, sizeof(d));
	}
	f1.close();
	f.close();
	remove("dict.dat");
	rename("temp.dat", "dict.dat");

}
void wod()
{
	clrscr();
	randomize();
	dict d;
	fstream f;
	int size = sizefile();
	int a = random(size-1);
	char title[] = "WORD OF THE DAY";
	f.open("dict.dat", ios::in | ios::binary);
	f.seekg((a)*sizeof(d));
	f.read((char*)&d,sizeof(d));
	d.show(title);
	f.close();
	getch();
	clrscr();
}
int sizefile()
{
	int count=0;
	fstream f;
	dict d;
	f.open("dict.dat", ios::in | ios::binary);
	while (f)
	{
		f.read((char*)&d,sizeof(d));
		if (f.eof())
			break;
		else
			count++;
	}
	return count;
}

