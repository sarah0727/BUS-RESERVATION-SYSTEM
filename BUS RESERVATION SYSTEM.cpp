#include<conio.h>
#include<cstdio>
#include<iostream>
#include<string.h>
#include<cstdlib>
using namespace std;
static int p=0;
class a
{
	private:
		
		char busn[50],driver[10],arrival[5],depart[5],from[10],to[10],seat[8][4][10];
	
	public:
		
		void install();
		void allotment();
		void empty();
		void show();
		void avail();
		void position(int i);
}
bus[10];
void vline(char ch)
{
	for(int i=80;i>0;i--)
	
	cout<<ch;
}

void a::install() //TO ALLOW USER TO ENTER THE DETAILS OF THE BUS

{
	
	cout<<"ENTER BUS NUMBER: \t";
	cin>>bus[p].busn;
	
	cout<<"\n ENTER THE NAME OF DRIVER:";
	cin>>bus[p].driver;
	
	cout<<"\n ARRIVAL TIME: \t";
	cin>>bus[p].arrival;
	
	cout<<"\n DEPARTURE:    \t";
	cin>>bus[p].depart;
	
	cout<<"\n FROM:          \t";
	cin>>bus[p].from;
	
	cout<<"\n To:             \t";
	cin>>bus[p].to;
	
	bus[p].empty();
	
	p++;
}

void a::allotment() //TO CHECK WHETHER THE SEAT IS AVAILABLE OR NOT
{
	int seat;
	char number[5];
	top:
		cout<<"BUS NUMBER: ";
		cin>>number;
		int n;
		for(n=0;n<=p;n++)
		{
			if(strcmp(bus[n].busn,number)==0)
			break;
		}
		while(n<=p)
		{
			cout<<"\n SEAT NUMBER: ";
			cin>>seat;
			
			if(seat>32)
			{
				
				cout<<"\n THERE ARE ONLY 32 SEATS AVAILABLE IN THIS BUS. ";
			}
			else
			{
			if(strcmp(bus[n].seat[seat/4][(seat%4)-1],"EMPTY")==0)
			  {
			  	
			  	cout<<"\n ENTER PASSENGER'S NAME: ";
			  	cin>>bus[n].seat[seat/4][(seat%4)-1];
			  	break;
			  	
				}
				else
				  cout<<"\n THE SEAT NUMBER IS ALREADY RESERVED.\n ";
				  
			}
		}
		if(n>p)
		{
			cout<<"ENTER CORRECT BUS NUMBER: \n";
			goto top;
		}
}

void a::empty()
{
	for(int i=0;i<8;i++)
	{
		for(int j=0;j<4;j++)
		{
			strcpy(bus[p].seat[i][j],"EMPTY");
		}
	}
}

void a::show() 
{
	
	int n;
	char number[5];
	cout<<"\n ENTER BUS NUMBER: ";
	cin>>number;
	
	for(n=0;n<=p;n++)
	{
		
		if(strcmp(bus[n].busn,number)==0)
		break;
	}
	while(n<=p)
	{
		
		vline('*');
		cout<<"\n BUS NUMBER  :\t"<<bus[n].busn<<endl;
		cout<<" NAME OF DRIVER:\t"<<bus[n].driver<<endl;
		cout<<" ARRIVAL TIME  :\t"<<bus[n].arrival<<endl;
		cout<<" DEPARTURE TIME:\t"<<bus[n].depart<<endl;
		cout<<" FROM : "<<bus[n].from<<"\t TO :"<<bus[n].to<<endl;
		
		vline('*');
		
		bus[0].position(n);
		
		int a=1;
		for(int i=0;i<8;i++)
		{
			for(int j=0;j<4;j++)
			{
				 a++;
				 if(strcmp(bus[n].seat[i][j],"EMPTY")!=0)
				 cout<<"\n THE SEAT NUMBER "<<(a-1)<<" IS RESERVED FOR "<<bus[n].seat[i][j]<<". \n";
				 
			}
		}
		break;
	}
	 if(n>p)
	   cout<<"ENTER CORRECT BUS NUMBER : ";
}

void a::position(int l)

{
	 int s=0;p=0;
	 
	 for(int i=0;i<8;i++)
	 {
	 	 cout<<endl;
	 	 
	 	 for(int j=0;j<4;j++)
	 	 {
			
	 	 s++;
	 	 
			if(strcmp(bus[l].seat[i][j]," EMPTY")==0)
	 	 {
	 	 	
	 	 	 cout.width(5);
	 	 	 
	 	 	 cout.fill('  ');
	 	 	 
	 	 	 cout<<s<<".";
	 	 	 
	 	 	 cout.width(10);
	 	 	 
	 	 	 cout.fill('  ');
	 	 	 
	 	 	 cout<<bus[l].seat[i][j];
	 	 	 
	 	 	 p++;
	 	 	 
	 	 }
	 	
	 	else
	 	{
	 		 cout.width(5);
	 	 	 
	 	 	 cout.fill('  ');
	 	 	 
	 	 	 cout<<s<<".";
	 	 	 
	 	 	 cout.width(10);
	 	 	 
	 	 	 cout.fill('  ');
	 	 	 
	 	 	 cout<<bus[l].seat[i][j];
		 }
	 }
 }
 
 cout<<" \n THERE ARE "<<p<< " SEATS EMPTY IN THE BUS NUMBER "<<bus[l].busn;
}

void a::avail()
{
	
	  for(int n=0;n<p;n++)
	  
	  {
	  	  vline('*');
	  	  
	  	  cout<<"\n BUS NUMBER  :\t"<<bus[n].busn<<endl;
		    cout<<" NAME OF DRIVER:\t"<<bus[n].driver<<endl;
		    cout<<" ARRIVAL TIME  :\t"<<bus[n].arrival<<endl;
		    cout<<" DEPARTURE TIME:\t"<<bus[n].depart<<endl;
		    cout<<" FROM : "<<bus[n].from<<"\t TO :"<<bus[n].to<<endl;
		    
		    vline('*');
		    
		    vline('_');
		    
	  }
}

int main()
{
	 
	 system("cls");
	 int w;
	 
	 while(1)
	  {
	  	 
	  	   //system('cls')
	  	
	  	cout<<endl;
	  	cout<<"\t \t (1). INSTALL"<<endl;
	  	cout<<"\t \t (2). RESERVATION"<<endl;
	  	cout<<"\t \t (3). SHOW"<<endl;
	  	cout<<"\t \t (4). BUSES AVAILABLE"<<endl;
	  	cout<<"\t \t (5). EXIT"<<endl;
	  	
	  	cout<<"\t \t      ENTER YOUR CHOICE: ";
	  	cin>>w;
	  	
	  	switch(w)
	  	
	  	{
	  		  case 1: bus[p].install();
	  		          
									break;
					
					case 2: bus[p].allotment();
					
					        break;
					        
					case 3: bus[p].show();
					        
									break;
					
					case 4: bus[p].avail();
					        
									break;
					
					case 5: exit(0);        
			}
		
		}
		return 0;
}
