#include "csv.hpp"
#include "gift.hpp"

int main()
{
	fstream kids,wishes,inventory("./data/inventory.csv"),settings("./data/settings.dat"),destination,list("./data/list.csv");
	list.close();
	if(!settings.tellg())
		settings<<"100 10 Nokia_2.2";
	char key;
	bool open=true,done=false;
	string firstname,lastname,city,country,good,temp;
	csvInput csvBuffer;
	Gift gift;
	while(open)
	{
		kids.open("./data/kids.csv",ios_base::app);
		wishes.open("./data/wishes.csv",ios_base::app);
		inventory.open("./data/inventory.csv",ios_base::app);
		settings.open("./data/settings.dat");
		destination.open("./data/destination.csv",ios_base::app);
		xmasTree();
		cout<<"\033[0;32m####################\033[0m\n";
		cout<<"\033[0;32m#\033[0m\033[0;31mXMas Administrator\033[0m\033[0;32m#\033[0m\n";
		cout<<"\033[0;32m####################\033[0m\n\n";
		cout<<"1->Show kids list\n";
		cout<<"2->Add kid on list\n";
		cout<<"3->Show inventory list\n";
		cout<<"4->Add item on inventory\n";
		cout<<"5->Make the wish list\n";
		cout<<"6->Show the wish list\n";
		cout<<"7->Show destination\n";
		cout<<"8->Add destination\n";
		cout<<"9->Exit\n";
		cout<<"Default - non numerici->Change settings\n\n";
		if(done)
		{
			cout<<"\033[0;31m#The wish list is DONE!#\033[0m\n\n";
			done=false;
		}
		cout<<"Option: ";cin>>key;
		switch(key)
		{
		case '1':
			system("@cls||clear");
			cout<<"Kids List:\n\n";
			csvBuffer.show("./data/kids.csv");
			cin.get();
			cin.get();
			break;
		case '2':
			system("@cls||clear");
			cout<<"First Name: ";cin>>firstname;
			cout<<"Last Name: ";cin>>lastname;
			cout<<"Letter Color: ";cin>>temp;
			cout<<"City: ";cin>>city;
			cout<<"Country: ";cin>>country;
			Good:
			cout<<"Good or Bad: ";
			cin>>good;
			transform(good.begin(),
                 good.end(),
                 good.begin(),
                 ::tolower);
			try
			{
				if(good!="good"&&good!="bad")
					throw good;
			}
			catch(string)
			{
				cout<<"Retype this parameter!\n";
				goto Good;
			}
			kids<<firstname<<','<<lastname<<','<<temp<<','<<city<<','<<country<<','<<good<<'\n';
			cin.get();
			cout<<"Wishes: ";getline(cin,temp);
			for(size_t i=0;i<temp.length()-1;++i)
				if(temp[i]==' '&&temp[i+1]!=' ')
					temp[i]=',';
			wishes<<temp<<'\n';
			break;
		case '3':
			system("@cls||clear");
			cout<<"Inventory List:\n\n";
			csvBuffer.show("./data/inventory.csv");
			cin.get();
			cin.get();
			break;
		case '4':
			system("@cls||clear");
			cout<<"Object name: ";cin>>temp;
			for(size_t i=0;i<temp.length()-1;++i)
				if(temp[i]==' '&&temp[i+1]!=' ')
					temp[i]=',';
			Error:
			inventory<<temp<<',';
			cout<<"Price: ";cin>>temp;
			try
			{
				if(!stold(temp))
					throw temp;
			}
			catch(string)
			{
				cout<<"Error! The value is not real!\n";
				goto Error;
			}
			inventory<<temp<<'\n';
			break;
		case '5':
			system("@cls||clear");
			if(kids.tellg()&&wishes.tellg()&&inventory.tellg())
				gift.makeGift("./data/kids.csv","./data/wishes.csv","./data/inventory.csv","./data/settings.dat","./data/list.csv","good");
			done=true;
			break;
		case '6':
			system("@cls||clear");
			cout<<"Wish List:\n\n";
			csvBuffer.show("./data/list.csv");
			cin.get();
			cin.get();
			break;
		case '7':
			system("@cls||clear");
			cout<<"Destination:\n\n";
			csvBuffer.show("./data/destinations.csv");
			cin.get();
			cin.get();
			break;
		case '8':
			system("@cls||clear");
			cout<<"Add a country: ";getline(cin,temp);
			for(size_t i=0;i<temp.length()-1;++i)
				if(temp[i]==' '&&temp[i+1]!=' ')
					temp[i]='_';
			destination<<temp<<',';
			cout<<"Add a city: ";getline(cin,temp);
			for(size_t i=0;i<temp.length()-1;++i)
				if(temp[i]==' '&&temp[i+1]!=' ')
					temp[i]='_';
			destination<<temp<<'\n';
			break;
		case '9':
			open=false;
			break;
		default:
			system("@cls||clear");
			GOOD:
			cout<<"Budget for good kids: ";cin>>temp;
			try
			{
				if(!stold(temp))
					throw temp;
			}
			catch(string)
			{
				cout<<"Error! The value is not real!\n";
				goto GOOD;
			}
			settings<<temp<<' ';
			BAD:
			cout<<"Budget for bad kids: ";cin>>temp;
			try
			{
				if(!stold(temp))
					throw temp;
			}
			catch(string)
			{
				cout<<"Error! The value is not real!\n";
				goto BAD;
			}
			settings<<temp<<' ';
			cin.get();
			cout<<"Default Gift: ";getline(cin,temp);
			for(size_t i=0;i<temp.length()-1;++i)
				if(temp[i]==' '&&temp[i+1]!=' ')
					temp[i]='_';
			settings<<temp;
			break;
		}
		system("@cls||clear");
		destination.close();
		settings.close();
		kids.close();
		wishes.close();
		inventory.close();
	}
	return 0;
}