//
// Created by Abdullah Anwar on 11/15/24.
//

#ifndef FEEDBACK_H
#define FEEDBACK_H
#include <iostream>
#include <fstream>
#include <string>
using namespace std;
struct Feedback {
    int orderId;
    string feedback, date;
    float rating;
};
Feedback *feedback = new Feedback[10];
int feedbackCount = 0;

void loadFeedback() {
    ifstream file("Feedback.txt");
    while(file.good()) {
        file >> feedback[feedbackCount].date;
        file.ignore();
        getline(file, feedback[feedbackCount].feedback);
        file >> feedback[feedbackCount].orderId;
        file >> feedback[feedbackCount].rating;
    }
    feedbackCount++;

    for(int i = 0; i < feedbackCount; i++) {

        cout<<feedback[i].date<<endl;
        cout<<feedback[i].feedback<<endl;
        cout<<feedback[i].orderId<<endl;
        cout<<feedback[i].rating<<endl;
    }
}

void writeDataToFile(){

    Feedback f;

    cout<<"Enter the orderID:"; cin>>f.orderId;
    cout<<"Enter the Feedback:"; cin>>f.feedback;
    cout<<"Enter the date:"; cin>>f.date;
    cin.clear();
    cin.ignore();
    cout<<"Enter the rating out of 10:"; cin>>f.rating;

    ofstream MyFile;
    MyFile.open("Feedback.txt", ios::app);
    MyFile<<f.date<<endl;
    MyFile<<f.feedback<<endl;
    MyFile<<f.orderId<<endl;
    MyFile<<f.rating<<endl;
    MyFile.close();
    cout<<"\nRecord Added\n";
}
#endif //FEEDBACK_H
