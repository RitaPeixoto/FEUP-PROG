#pragma once
#include<vector>
#include<string>
#include<sstream>
using namespace std;




class User {
private:  string name;  
vector<Message> messages; 
public:  User(string name);  
		 string getName() const; 
		 vector<Message> getMessages() const;  
		 vector<Message> getMessages(string subject) const;  
		 void addMessage(Message message); 
};


class Message {
friend ostream& operator<<(ostream& os, Message& message); 
private:  time_t date; //time_t é um inteiro sem sinal
		  string content; 
public:  Message(time_t timeMsg, string content);  
		 time_t getDate() const;  
		 string getContent() const;
};