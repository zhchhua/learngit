#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<iostream>
class myString
{
	public:
		myString();
		myString(const  char* pstr);
		myString(const  myString & rhs);
		~myString();
		const char *c_str()const
		{
			return pstr_;
		}
		int use()
		{
			int len=strlen(pstr_);
			return pstr_[len+1];
		}
		friend std::ostream & operator<<(std::ostream & os,myString & str);
		myString& operator=(const myString &rhs);
		char & operator[](int idx);
	private:
		char * pstr_;
};
myString::myString()
{
	pstr_=new char[2];
	pstr_[1]=1;
}
myString::myString(const char * pstr)
{
	int len=strlen(pstr);
	pstr_=new char[len+1];
	pstr_[len+1]=1;
	strcpy(pstr_,pstr);
}
myString::myString(const myString & rhs)
{
	int len=strlen(rhs.pstr_);
	rhs.pstr_[len+1]++;
	pstr_=rhs.pstr_;
};
myString& myString::operator=(const myString & rhs)
{
	if(this!=&rhs)
	{
		int len=strlen(pstr_);
		if(--pstr_[len+1]==0)
		{
			delete []pstr_;
		}
		pstr_=rhs.pstr_;
		len=strlen(pstr_);
		++pstr_[len+1];
	}
	return *this;
}
myString::~myString()
{
	int len=strlen(pstr_);
	if(--pstr_[len+1]==0)
	{
		delete []pstr_;
	}
}
std::ostream & operator<<(std::ostream & os,myString & rhs)
{
	os<<rhs.pstr_;
	return os;
}
char & myString::operator[](int idx)
{
	static char nullchar='\0';
	int len=strlen(pstr_);
	if(idx<len&&idx>=0)
	{
		if(--pstr_[len+1]!=0)
		{
			char *ptmp=new char[len+2];
			strcpy(ptmp,pstr_);
			pstr_=ptmp;
			pstr_[len+1]=1;
		}
		else
		{
			++pstr_[len+1];
		}
		return pstr_[idx];
	}
	else
	{
		std::cout<<"illegal argument"<<std::endl;
		return nullchar;
	}
}
int main(void)
{
	myString s1;
	std::cout<<s1<<std::endl;
	myString s2="hello,world,cup";
	std::cout<<"s2="<<s2<<",use="<<s2.use()<<std::endl;
	myString s3=s2;
	std::cout<<"s3="<<s3<<",use="<<s3.use()<<std::endl;
	const char *ps2=s2.c_str();
	const char *ps3=s3.c_str();
	printf("ps2=%x\n",ps2);
	printf("ps3=%x\n",ps3);
	std::cout<<s3[0]<<std::endl;
	std::cout<<"s2="<<s2<<",use="<<s2.use()<<std::endl;
	std::cout<<"s3="<<s3<<",use="<<s3.use()<<std::endl;
	ps2=s2.c_str();
	ps3=s3.c_str();
	printf("ps2=%x\n",ps2);
	printf("ps3=%x\n",ps3);
	return 0;
}
