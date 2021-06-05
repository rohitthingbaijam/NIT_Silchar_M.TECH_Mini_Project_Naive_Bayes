//NAME:ROHIT THINGBAIJAM
//SCHOLAR ID. : 2022120
//M.TECH FIRST SEM(2020-2022)
//COMPUTER SCIENCE AND ENGINEERING

#include <iostream>
#include <fstream>
#include <list>
#include <string>

using namespace std;

ifstream file;
list<string>  TestData, Spam1, NotSpam1,column1,column2,column3,temp;
string str; 
char ch;
int count1=0,count2=0;
float NoOfSpam=1,NoOfNotSpam=1;


bool search(string str){

	for(string i : temp){
		
		if(i == str)
			return true;
	}
	return false;
}



int main()
{

    
    file.open("Spam.txt");
    while(!file.eof())
	{
    	file>>str;
    	Spam1.push_back(str);
	}
	file.close();
	
	
	
	
	
	file.open("NotSpam.txt");
	while(!file.eof())
	{
		file>>str;
		NotSpam1.push_back(str);
	}
	file.close();
	
	

	
	
	file.open("TestData.txt");
	while(!file.eof())
	{
		file>>str;
		TestData.push_back(str);
	}
	file.close();

	
	
	int frequency[TestData.size()];
	
	
	
	 file.open("spam.txt");
	 file.get(ch);
    while(file)
	{
    	if( ch == '\n')
    	NoOfSpam++;
    	file.get(ch);
	}
	file.close();
	
	
	cout<<"No. of training patterns for Spam :"<<NoOfSpam<<endl;
	
	
	file.open("NotSpam.txt");
	 file.get(ch);
    while(file)
	{
    	if( ch == '\n')
    	NoOfNotSpam++;
    	file.get(ch);
	}
	file.close();
	
	
	cout<<"No. of training patterns for not spam :"<<NoOfNotSpam<<endl<<endl<<endl;
	cout<<"Total no. of training patterns :"<<(NoOfNotSpam+NoOfSpam)<<endl<<endl<<endl;		
			
	float probSpam =(float) ((NoOfSpam+1)/(2+(NoOfSpam+NoOfNotSpam)));
	cout<<"Prio probability of class spam:"<<probSpam<<endl;
	float probNotSpam = (float)((NoOfNotSpam+1)/(2+(NoOfSpam+NoOfNotSpam)));
	cout<<"Prio probability of class not spam:"<<probNotSpam<<endl<<endl<<endl;
	
	
	for(int x=0;x<TestData.size();x++)
		{
			switch(x)
			{
				case 0: 
						file.open("column1.txt");
						while(!file.eof()){
						file>>str;
						column1.push_back(str);
						
						}
						file.close();
						for(string i : column1)
						{
						if(!search(i))
						temp.push_back(i);
						}
						frequency[x]=(temp.size());
						temp.clear();
						cout<<"No. of values in first attribute :"<<frequency[x]<<endl;
						break;
						
						
				case 1:file.open("column2.txt");
						while(!file.eof()){
						file>>str;
						column2.push_back(str);
						
						}
						file.close();
						for(string i : column2)
						{
						if(!search(i))
						temp.push_back(i);
						}
						
						frequency[x]=(temp.size());
						temp.clear();
						cout<<"No. of values in second attribute :"<<frequency[x]<<endl;
						break;
						
				case 2:file.open("column3.txt");
						while(!file.eof()){
						file>>str;
						column3.push_back(str);
						
						}
						file.close();
						for(string i : column3)
						{
						if(!search(i))
						temp.push_back(i);
						}
						frequency[x]=(temp.size());
						temp.clear();
						cout<<"No. of values in third attribute :"<<frequency[x]<<endl<<endl<<endl;
						break;
						
				deafult: break;
			}
		}
	

	for(string i : TestData)
	{
		int noOfWords = 0;
		
		for(string j : Spam1)
		{
			if(i == j)
				noOfWords++;
		}
		
		count1 +=1;
		count2 +=1;
		probSpam *= (float)(noOfWords + 1) / (float)(frequency[count1-1]  + NoOfSpam);
		
		noOfWords = 0;
		
		for(string j : NotSpam1)
		{
			if(i == j)
				noOfWords++;
		}
		
		
		probNotSpam *= (float)(noOfWords + 1) / (float)(frequency[count2-1]  + NoOfNotSpam);
		
	}
	
	cout<<"Posterior Probability of spam  :"<<probSpam<<endl
			<<"Posterior Probability of not spam  :"<<probNotSpam<<endl<<endl<<endl;
	if(probSpam > probNotSpam)
		cout<<"The recall pattern is Spam";
	else cout<<"The recall pattern is Not spam";
    return 0;
    
}
