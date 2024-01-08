#include"header.h"
void GuestHouse::displayMenu(){
    int choice;
    //this is the current date
    Date currentDate;
    cout<<"Enter today's date(DD<space>MM<space>YYYY): ";
    cin>>currentDate.day>>currentDate.month>>currentDate.year;
    pair<int,int> p;
    cout<<"==================================================================================================================================================="<<endl;
    cout<<"==============================================WELCOME TO IIT GUWAHATI GUESTHOUSE BOOKING SYSTEM===================================================="<<endl;
    cout<<"==================================================================================================================================================="<<endl;
    cout<<"==================================================READ INSRUCTIONS CAREFULLY BEFORE BOOKING========================================================"<<endl;
    cout<<"We have 3 floors in our guesthouse and 10 rooms on each floor"<<endl;
    cout<<"Prices for single rooms are Rs.1000 per day and for double rooms are Rs.2000 per day"<<endl;
    cout<<"All dates should be entered in the format DD<space>MM<space>YYYY and we have assumed that each month has 30 days"<<endl;
    cout<<"==================================================================================================================================================="<<endl;
    do{
        cout<<endl;
        cout<<"Today's Date: "<<currentDate.day<<"-"<<currentDate.month<<"-"<<currentDate.year<<endl<<endl;
        cout<<"============MENU============"<<endl;
        cout<<"1. Print GuestHouse Status"<<endl;
        cout<<"2. Count Available Rooms"<<endl;
        cout<<"3. Book Rooms"<<endl;
        cout<<"4. Check Booking History of a room"<<endl;
        cout<<"5. Modify Booking"<<endl;
        cout<<"6. Change Today's Date"<<endl;
        cout<<"7. Exit"<<endl;
        cout<<"Enter your choice: ";
        cin>>choice;
        switch(choice){
            case 1:
                printGuestHouseStatus();
                break;
            case 2:
                cout<<"Enter the start date: ";
                Date d1;
                cin>>d1.day>>d1.month>>d1.year;
                cout<<"Enter the end date: ";
                Date d2;
                cin>>d2.day>>d2.month>>d2.year;
                p=countavailableRooms(d1,d2);
                cout<<"Total number of Single rooms available:"<<p.first<<endl;
                cout<<"Total number of Double rooms available:"<<p.second<<endl;
                break;
            case 3:
                bookRoom(currentDate);
                break;
            case 4:
                int n;
                cout<<"Enter the room number: ";
                cin>>n;
                showBookingHistory(n);
                break;
            case 5:
                modifyBooking();
                break;
            case 6:
                cout<<"Enter the new date: ";
                cin>>currentDate.day>>currentDate.month>>currentDate.year;
                make_room_available_by_checking_current_date_and_end_date(currentDate);
                break;
            case 7:
                cout<<"Thank you for staying at IIT Guwahati's Guestouse "<<endl;
                break;
            default:
                cout<<"Invalid choice"<<endl;
                break;
        }
    cout<<"==================================================================================================================================================="<<endl;
    }while(choice!=7);
}
