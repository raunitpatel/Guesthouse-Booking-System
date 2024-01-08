#include"header.h"
void GuestHouse::bookRoom(Date currentDate){
    // S denotes single room and D denotes double room that the user wants to book
    int S,D;
    Date d1,d2;
    cout<<"Enter the numbers of Single and Double rooms you want to book: ";
    cin>>S>>D;
    cout<<"Enter the date from which you want to check the availability of rooms: ";
    cin>>d1.day>>d1.month>>d1.year;
    cout<<"Enter the date till which you want to check the availability of rooms: ";
    cin>>d2.day>>d2.month>>d2.year;
    int start=convert_date_to_days(d1);
    int current=convert_date_to_days(currentDate);
    // if the booking date is less than the current date then the booking is not done
    if(start<current){
        cout<<"Sorry, wrong dates has been chosen,date should not be of past"<<endl;
        return;
    }
    int end=convert_date_to_days(d2);
    // if the booking end date is less than the booking start date then the booking is not done or less than current date then the booking is not done
    if(end<start || end<current){
        cout<<"Sorry, wrong dates has been chosen"<<endl;
        return;
    }
    pair<int,int> p=countavailableRooms(d1,d2);
    // if the number of rooms requested is greater than the number of rooms available then the booking is not done
    if(S>p.first || D>p.second){
        cout<<"Sorry, we don't have enough rooms available"<<endl;
        return;
    }
    else{
        // the available rooms are displayed on the screen
        cout<<"Following are the available rooms:"<<endl;
        for(int i=0;i<floors.size();i++){
            Room *temp=floors[i].roomlist;
            while(temp!=NULL){
                if(temp->isOccupied==false){
                    if(temp->roomtype=='S'){
                        cout<<temp->roomNumber<<" "<<temp->roomtype<<"\t";
                    }
                    else{
                        cout<<temp->roomNumber<<" "<<temp->roomtype<<"\t";
                    }
                }
                else{
                    bool flag=true;
                    for(int j=0;j<temp->bookingHistory.size();j++){
                        int start1=convert_date_to_days(temp->bookingHistory[j].startDate);
                        int end1=convert_date_to_days(temp->bookingHistory[j].endDate);
                        if(start1<=start<=end1 || start1<=end<=end1){
                            flag=false;
                            break;
                        }
                    }
                    if(flag==true){
                        if(temp->roomtype=='S'){
                            cout<<temp->roomNumber<<" "<<temp->roomtype<<"\t";
                        }
                        else{
                            cout<<temp->roomNumber<<" "<<temp->roomtype<<"\t";
                        }
                    }
                }
                temp=temp->next;
            }
            cout<<endl;
        }
        //guest name is taken as input
        cout<<"Enter the name of the guest:";
        string name;
        // full name is taken as input
        cin.ignore();
        getline(cin,name);
        int totalamount=0;
        // room number is taken as input (room no should be the room no of the available rooms as displayed on the screen)
        cout<<"Enter room numbers of "<<S<<" single rooms and "<<D<<" double rooms you want to book(from the displayed list): ";
        totalamount+=(S*1000+D*2000)*((end-start)+1);
        for(int i=0;i<S+D;i++){
            int roomno;
            cin>>roomno;
            Room* temp=floors[roomno/100-1].roomlist;
            while(temp!=NULL){
                if(temp->roomNumber==roomno){
                    temp->isOccupied=true;
                    // the booking details are stored in the booking record of the room
                    temp->bookingHistory.push_back({d1,d2,name});
                    break;
                }
                temp=temp->next;
            }
        }
        
        // price is calculated based on the number of days and the type of room
        // users are given the option to pay by cash or card and amount paid should be equal to the total amount
        cout<<"Total amount to be paid: "<<totalamount<<endl;
        cout<<"how do you want to pay?\n Press 1. Cash\n Press 2. Card ";
        int choice;
        cin>>choice;
        //Choice 1 is by cash and choice 2 is by card
        if(choice==1){
            cout<<"Enter the amount you want to pay: ";
            int amount;
            cin>>amount;
            if(amount<totalamount){
                cout<<"Sorry, you have to pay the full amount"<<endl;
                cout<<"Please try again"<<endl;
                cout<<"Enter the amount you want to pay: ";
                cin>>amount;
                cout<<"Thank you for booking with us"<<endl;
            }
            else{
                cout<<"Thank you for booking with us"<<endl;
            }
        }
        else{
            cout<<"Enter the card number(10 digit): ";
            string cardno;
            cin>>cardno;
            cout<<"Enter the cvv(3 digit): ";
            string cvv;
            cin>>cvv;
            cout<<"Thank you for booking with us"<<endl;
        }
    }
}
