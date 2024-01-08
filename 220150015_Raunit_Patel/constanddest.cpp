#include"header.h"
GuestHouse::GuestHouse(int no_of_floors,int roomsPerFloor){
    floors.resize(no_of_floors);
    for(int i=0;i<no_of_floors;i++){
        for(int j=0;j<roomsPerFloor;j++){
            Room * node=new Room();
            // the room number is given as FloorNumber*100+RoomNumber
            // in linked list in each iteration the head is changed to the new node and the next of the new node is the previous head
            node->roomNumber=(i+1)*100+(10-j);
            if(j<5)
                node->roomtype='S';
            else{
                node->roomtype='D';
            }
            node->next=floors[i].roomlist;
            floors[i].roomlist=node;
        }
    }
}
GuestHouse::~GuestHouse(){
    for(int i=0;i<floors.size();i++){
        Room *temp=floors[i].roomlist;
        while(temp!=NULL){
            Room* temp2=temp;
            delete temp2;
            temp=temp->next;
        }
    }
    cout << "Destructor called\n";
}
