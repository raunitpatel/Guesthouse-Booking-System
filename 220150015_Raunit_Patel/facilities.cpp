#include"header.h"
int convert_date_to_days(Date d){
    return d.year*365+d.month*30+d.day;
}
void GuestHouse::showRoomDetails(Room &room){
    cout<<"Room Number: "<<room.roomNumber<<endl;
    cout<<"Room Type: "<<room.roomtype<<endl;
    cout<<"Room Status: "<<(room.isOccupied?"Occupied":"Vacant")<<endl;
}
void GuestHouse::printGuestHouseStatus(){
    cout<<"============================"<<endl;
    for(int i=0;i<floors.size();i++){
        cout<<"=         Floor "<<i+1<<"          ="<<endl;
        cout<<"============================"<<endl;
        Room *temp=floors[i].roomlist;
        while(temp!=NULL){
            // the details of each room are displayed by calling the showRoomDetails function for each room
            showRoomDetails(*temp);
            cout<<"============================"<<endl;
            temp=temp->next;
        }
    }
}
pair<int,int> GuestHouse::countavailableRooms(Date startdate,Date enddate){
    int countS=0,countD=0;
    for(int i=0;i<floors.size();i++){
        Room *temp=floors[i].roomlist;
        while(temp!=NULL){
            if(temp->isOccupied==false){
                if(temp->roomtype=='S')
                    countS++;
                else
                    countD++;
            }
            else{
                // if the room is occupied then the start date and end date of the booking record is compared with the start date and end date of the booking
                // if the booking record is not in the range of the start date and end date then the room is available
                bool flag=true;
                for(int j=0;j<temp->bookingHistory.size();j++){
                    int start=convert_date_to_days(startdate);
                    int end=convert_date_to_days(enddate);
                    int start1=convert_date_to_days(temp->bookingHistory[j].startDate);
                    int end1=convert_date_to_days(temp->bookingHistory[j].endDate);
                    if((start1 <= start && start <= end1) || (start1 <= end && end <= end1) || (start <= start1 && end1 <= end) || (start <= end1 && end1 <= end)){
                        flag=false;
                        break;
                    }
                }
                if(flag==true){
                    if(temp->roomtype=='S')
                        countS++;
                    else
                        countD++;
                }
            }
            temp=temp->next;
        }
    }
    return {countS,countD};
}
void GuestHouse::showBookingHistory(int roomno){
    cout<<"Booking History of Room "<<roomno<<endl;
    Room *temp=floors[(roomno/100)-1].roomlist;
    while(temp!=NULL){
        if(temp->roomNumber==roomno){
            if(temp->bookingHistory.size()==0){
                cout<<"No Booking History"<<endl;
                return;
            }
            else{
                for(int i=0;i<temp->bookingHistory.size();i++){
                cout<<"============================"<<endl;
                cout<<"Booking "<<i+1<<endl;
                cout<<"Guest Name: "<<temp->bookingHistory[i].guestname<<endl;
                cout<<"Start Date: "<<temp->bookingHistory[i].startDate.day<<"-"<<temp->bookingHistory[i].startDate.month<<"-"<<temp->bookingHistory[i].startDate.year<<endl;
                cout<<"End Date: "<<temp->bookingHistory[i].endDate.day<<"-"<<temp->bookingHistory[i].endDate.month<<"-"<<temp->bookingHistory[i].endDate.year<<endl;
                cout<<"============================"<<endl;
            }
            }
        }
        temp=temp->next;
    }
}


void GuestHouse::make_room_available_by_checking_current_date_and_end_date(Date currentDate){
    int current=convert_date_to_days(currentDate);
    for(int i=0;i<floors.size();i++){
        Room *temp=floors[i].roomlist;
        while(temp!=NULL){
            if(temp->isOccupied==true){
                for(int j=0;j<temp->bookingHistory.size();j++){
                    int end=convert_date_to_days(temp->bookingHistory[j].endDate);
                    if(end<current){
                        temp->bookingHistory.erase(temp->bookingHistory.begin()+j);
                    }
                }
                if(temp->bookingHistory.size()==0){
                    temp->isOccupied=false;
                }
            }
            temp=temp->next;
        }
    }
}

void GuestHouse::modifyBooking(){
    cout<<"Enter the room number you want to modify and name:";
    int roomno;
    string name;
    cin>>roomno;
    cin.ignore();
    getline(cin,name);
    Room* temp=floors[roomno/100-1].roomlist;
    while(temp!=NULL){ 
        if(temp->roomNumber==roomno){
            for(int i=0;i<temp->bookingHistory.size();i++){
                if(temp->bookingHistory[i].guestname==name){
                    cout<<"Enter the new start date and end date(DD<space>MM<space>YYYY): ";
                    Date d1,d2;
                    cin>>d1.day>>d1.month>>d1.year>>d2.day>>d2.month>>d2.year;
                    int start=convert_date_to_days(d1);
                    int end=convert_date_to_days(d2);
                    if(end<start){
                        cout<<"Sorry, wrong dates has been chosen"<<endl;
                        return;
                    }
                    pair<int,int> p=countavailableRooms(d1,d2);
                    if(temp->roomtype=='S'){
                        if(p.first==0){
                            cout<<"Sorry, we don't have enough rooms available"<<endl;
                            return;
                        }
                    }
                    else{
                        if(p.second==0){
                            cout<<"Sorry, we don't have enough rooms available"<<endl;
                            return;
                        }
                    }
                    temp->bookingHistory[i].startDate=d1;
                    temp->bookingHistory[i].endDate=d2;
                    cout<<"Booking has been modified"<<endl;
                    return;
                }
            }
            cout<<"Sorry, no such booking exists"<<endl;
            return;
        }
        temp=temp->next;
    }
}

