#include<iostream>
#include<string>
#include<vector>
#include<map>
#include <string>
using namespace std;
// this struct is used to store the date(DD-MM-YYYY)
struct Date{
    int year;
    int month;
    int day;
};
// this class is used to implement the guesthouse management system
class GuestHouse{
    private:
        // this struct is used to store the booking record of the guests
        struct BookingRecord{
            Date startDate;
            Date endDate;
            string guestname;
        };
        // this struct is used to store the details of the rooms and its booking record and is used to implement the linked list
        struct Room{
            int roomNumber;
            bool isOccupied;
            char roomtype;
            vector<BookingRecord> bookingHistory;
            Room *next;
        };
        // this struct is used to implement Floors where each floor has a linked list of rooms
        struct Floor{
            Room *roomlist;
            Floor():roomlist(NULL){};
        };
        // this vector is used to store the floors of the guesthouse
        vector<Floor> floors;
        public:
            // this is the constructor of the class which is used to initialize the guesthouse with the given number of floors and rooms per floor
            GuestHouse(int no_of_floors,int roomsPerFloor);
            // this is the destructor of the class which is used to delete the booking record of each room after the guesthouse is closed
            ~GuestHouse();
            // this function is used to display the details of a room which is passed as an argument to this function
            void showRoomDetails(Room &room);
            // this function is used to show booking history of a room
            void showBookingHistory(int roomno);
            // this function is used to display the details of all the rooms in the guesthouse
            void printGuestHouseStatus();
            // this function is used to count the number of available rooms in the guesthouse and returns count of single and double rooms
            pair<int,int> countavailableRooms(Date startdate,Date enddate);
            // this function is used to book the rooms in the guesthouse
            void bookRoom(Date currentDate);
            //this function is used when current date is changed and then by comparing the current date with the end date of the booking record
            // of each room, the rooms are made available
            void make_room_available_by_checking_current_date_and_end_date(Date currentDate);
            //this function is used to modify the booking details of a room
            void modifyBooking();
            //this function is used to display the menu of the guesthouse booking system and the user can choose from the options
            void displayMenu();                
};
int convert_date_to_days(Date d);
