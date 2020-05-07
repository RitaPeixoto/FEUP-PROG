#include "2011-4.h"



Message::Message(time_t timeMsg, string content) {
	date = timeMsg;
	this->content = content;

}


time_t Message::getDate() const{
	return date;
}


string Message::getContent() const {
	return content;
}

ostream& operator<<(ostream& os, Message& message) {
	os << message.getDate()<< message.getContent();
}

vector<Message> User::getMessages(string subject) const {



}

int main() {

}


