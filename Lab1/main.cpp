#include <iostream>
#include <string>
using namespace std;

#include "Playlist.h"
Playlist* playlistNode;

void PrintMenu(string);

int main() {
    string title;
    cout << "Enter playlist's title:" << endl;
    getline(cin, title);
    playlistNode = new Playlist();
    cout << endl;
    PrintMenu(title);

    return 0;
}

void PrintMenu(string playlistTitle)
{
    cout << playlistTitle << " PLAYLIST MENU" << endl;
    cout << "a - Add song" << endl;
    cout << "d - Remove song" << endl;
    cout << "c - Change position of song" << endl;
    cout << "s - Output songs by specific artist" << endl;
    cout << "t - Output total time of playlist (in seconds)" << endl;
    cout << "o - Output full playlist" << endl;
    cout << "q - Quit" << endl;
    cout << endl;
    cout << "Choose an option:";
    cout << endl;

    string userOption;
    getline(cin, userOption);

    if (userOption == "a")
    {
        cout << "ADD SONG" << endl;
        string id;
        string name;
        string artist;
        int length;

        cout << "Enter song's unique ID:" << endl;
        getline(cin, id);
        cout << "Enter song's name:" << endl;
        getline(cin, name);
        cout << "Enter artist's name:" << endl;
        getline(cin, artist);
        cout << "Enter song's length (in seconds):" << endl;
        cin >> length;
        cin.ignore();

        PlaylistNode* newNode = new PlaylistNode(id, name, artist, length);
        playlistNode->push_back(newNode);
        cout << endl;
        //Call menu again
        PrintMenu(playlistTitle);
    }
    else if (userOption == "d")
    {
        cout << "REMOVE SONG" << endl;
        cout << "Enter song's unique ID:" << endl;
        string id;
        getline(cin, id);
        PlaylistNode* removedSong = playlistNode->remove(id);
        if (removedSong)
        {
            cout << '"' << removedSong->GetSongName() << '"' << " removed." << endl;
        }
        else
        {
            cout << "Song with unique ID " << id << " not found!" << endl;
        }
        cout << endl;
        //Call menu again
        PrintMenu(playlistTitle);
    }
    else if (userOption == "c")
    {
        cout << "CHANGE POSITION OF SONG" << endl;
        int currPos;
        int updatedPos;
        cout << "Enter song's current position:" << endl;
        cin >> currPos;
        cout << "Enter new position for song:" << endl;
        cin >> updatedPos;
        cin.ignore();

        playlistNode->changePos(currPos, updatedPos);
        cout << endl;
        //Call menu again
        PrintMenu(playlistTitle);
    }
    else if (userOption == "s")
    {
        cout << "OUTPUT SONGS BY SPECIFIC ARTIST" << endl;
        cout << "Enter artist's name:" << endl;
        string artistName;
        getline(cin, artistName);
        cout << endl;
        playlistNode->printByArtist(artistName);
        //Call menu again
        PrintMenu(playlistTitle);
    }
    else if (userOption == "t")
    {
        cout << "OUTPUT TOTAL TIME OF PLAYLIST (IN SECONDS)" << endl;
        cout << "Total time: " << playlistNode->totalTimeSeconds() << " seconds" << endl;
        cout << endl;
        //Call menu again
        PrintMenu(playlistTitle);
    }
    else if (userOption == "o")
    {
        playlistNode->print(playlistTitle);
        //Call menu again
        PrintMenu(playlistTitle);
    }
    else if (userOption == "q")
    {
        //Exit program
        return;
    }
    else
    {
        cout << "Invalid selection." << endl;
        //Call menu again
        PrintMenu(playlistTitle);
    }
}

//--------------------------------------BEGIN TESTING--------------------------------------//
/*
    PlaylistNode* song1 = new PlaylistNode("31818", "fantasy", "Mariah Carey", 312, nullptr);
    PlaylistNode* song2 = new PlaylistNode("83292", "First date", "Blink 182", 214, nullptr);
    PlaylistNode* song3 = new PlaylistNode("54391", "Berlin", "Aitana", 199, nullptr);
    PlaylistNode* song4 = new PlaylistNode("12903", "Doing it", "LL cool J", 201, nullptr);
    PlaylistNode* song5 = new PlaylistNode("93124", "Back in Black", "ACDC", 274, nullptr);
    PlaylistNode* song6 = new PlaylistNode("43267", "Chiquitita", "ABBA", 300, nullptr);
    PlaylistNode* song7 = new PlaylistNode("74829", "Do you go up", "Daniel Caesar", 244, nullptr);
    PlaylistNode* song8 = new PlaylistNode("31255", "Dancing Queen", "ABBA", 153, nullptr);
    PlaylistNode* song9 = new PlaylistNode("541367", "HeartBreak Anniversary", "Khai", 180, nullptr);
    PlaylistNode* song10 = new PlaylistNode("75421", "One of us", "ABBA", 120, nullptr);
   
        head = song1;
        tail = song1;
        tail->SetNext(nullptr);
        cout << endl << "SONG ADDED" << endl;
                               
        tail->SetNext(song2);
        tail = song2;
        cout << endl << "SONG ADDED" << endl;

        tail->SetNext(song3);
        tail = song3;
        cout << endl << "SONG ADDED" << endl;

        tail->SetNext(song4);
        tail = song4;
        cout << endl << "SONG ADDED" << endl;

        tail->SetNext(song5);
        tail = song5;
        cout << endl << "SONG ADDED" << endl;

        tail->SetNext(song6);
        tail = song6;
        cout << endl << "SONG ADDED" << endl;

        tail->SetNext(song7);
        tail = song7;
        cout << endl << "SONG ADDED" << endl;

        tail->SetNext(song8);
        tail = song8;
        cout << endl << "SONG ADDED" << endl;

        tail->SetNext(song9);
        tail = song9;
        cout << endl << "SONG ADDED" << endl;

        tail->SetNext(song10);
        tail = song10;
        cout << endl << "SONG ADDED" << endl;

cout << "-------------------------testing the output all nodes-------------------" << endl;

    PlaylistNode* temp = head;
    int songNum = 1;

    cout << playlistName << " - OUTPUT FULL PLAYLIST" << endl;

    while (temp != nullptr) {
        cout << songNum << endl;
        temp->PrintPlaylistNode();
        temp = temp->GetNext();
        songNum++;
    }
/*
cout << "-------------------------testing the remove function on BERLIN-------------------" << endl;

    PlaylistNode* prevNode = head;
    PlaylistNode* toRemove = prevNode->GetNext();  
    
    if (head->GetID() == "54391") {
        head = head->GetNext();
        delete prevNode;
        exit;
    }

    while(toRemove != nullptr) {
        if (toRemove->GetID() == "54391") {
            name = toRemove->GetSongName();

            PlaylistNode* post = toRemove->GetNext();
            post->InsertAfter(prevNode);

            toRemove = nullptr;
            delete toRemove;

        } else {
            prevNode = prevNode->GetNext();
            toRemove = toRemove->GetNext();
        }
    } 


cout << "-------------------------testing the artist only function w/ ABBA-------------------" << endl;

    PlaylistNode* artistLocator = head;

        while (artistLocator != nullptr) {
            if (artistLocator->GetArtistName() == "ABBA") {
                artistLocator->PrintPlaylistNode();
            }
            
            artistLocator = artistLocator->GetNext();
        }

cout << "-------------------------testing the total time function -------------------" << endl;

        cout << "OUTPUT TOTAL TIME OF PLAYLIST (IN SECONDS)" << endl << "Total Time: ";

        PlaylistNode* timeGetter = head;
        int seconds = 0;

        while (timeGetter != nullptr) {
            seconds += timeGetter->GetSongLength();
            timeGetter = timeGetter->GetNext();
        }

        cout << seconds << " seconds";


cout << "-------------------------testing the output all nodes-------------------" << endl;

    PlaylistNode* temp2 = head;
    int num = 1;

    cout << playlistName << " - OUTPUT FULL PLAYLIST" << endl;

    while (temp2 != nullptr) {
        cout << num << endl;
        temp2->PrintPlaylistNode();
        temp2 = temp2->GetNext();
        num++;
    }

 
cout << "-------------------------testing the change position function-------------------" << endl;

    int currPos, newPos, numOfNodes =0, i=0;

    PlaylistNode* counterNode = head;
    while(counterNode != nullptr) {                         //made to know if song will be added to tail 
        numOfNodes++;
        counterNode = counterNode->GetNext();
    }

    // cout << "CHANGE POSITION OF SONG" << endl << "Enter song's current position:" << endl;
    // cin >> currPos;
    // cout << "Enter new position for song:" << endl;
    // cin >> newPos;
    currPos = 3;
    newPos = 4;

    if (currPos < 1) {currPos = 1;} if (currPos > numOfNodes) { currPos = numOfNodes;}
    if (newPos < 1) { newPos = 1;}
    if (newPos > numOfNodes) { newPos = numOfNodes;}


    PlaylistNode* secondLastNode = head;
    for (i=0; i<numOfNodes -2; ++i){
        secondLastNode = secondLastNode->GetNext();
    }


    if (currPos == newPos) {                                    //make sure to not swap a node with itself
        exit;
    } else if (currPos == 1){                                   //moving the head node

        PlaylistNode* tempHead = head;                          //hold head in temp node
        head = head->GetNext();                                 //make 2nd node the head node
        
        if (newPos == numOfNodes) {                             //if head is moved to the tail node
            tail->SetNext(tempHead);
            tail = tempHead;
            tail->SetNext(nullptr);
        } else {                                                //if head is move anywhere else
            cout << "NEED TO FIX";
        }

    } else if (currPos == numOfNodes) {                         //moving the tail node
        
        PlaylistNode* tempTail = tail;                          //sets 2nd last to tail * stores tail
        tail = secondLastNode;
        secondLastNode->SetNext(nullptr);

        if (newPos == 1) {                                      //if tail is moved to the head
            tempTail->SetNext(head);
            head = tempTail;
        } else {                                                //if tail is moved anywhere else
            cout << "NEED TO FIX";
        }

    } else {                                                    //moving any other node
        
    }
    


cout << "-------------------------testing the output all nodes-------------------" << endl;

    PlaylistNode* temp2 = head;
    int num = 1;

    cout << playlistName << " - OUTPUT FULL PLAYLIST" << endl;

    while (temp2 != nullptr) {
        cout << num << endl;
        temp2->PrintPlaylistNode();
        temp2 = temp2->GetNext();
        num++;
    }

    return 0;} */
/*
            PlaylistNode* movingNode = head;
            for (i=0; i<songCurrPos; ++i) {
                movingNode = movingNode->GetNext();
            }

            PlaylistNode* nodeBefore = head;
            for (i=0; i<songNewPos-1; ++i) {
                nodeBefore = nodeBefore->GetNext();
            }

            PlaylistNode* secondToLastNode = head;
            while(secondToLastNode->GetNext() != tail) {
                secondToLastNode = secondToLastNode->GetNext();
            }

            PlaylistNode* insertAfterNode = head;
            for (i=0; i<songNewPos; ++i){
                insertAfterNode = insertAfterNode->GetNext();
            }

            if (songCurrPos == 1) {                             //if moving the head
                delete head;
                head = movingNode->GetNext();
                movingNode->InsertAfter(insertAfterNode);
                if (insertAfterNode == tail) {                  //if moving the head to tail position
                    tail = movingNode;
                    tail->SetNext(nullptr);
                }
            } else if (songCurrPos >= numOfNodes) {             //if moving the tail
                delete tail;
                tail = secondToLastNode;
                movingNode->InsertAfter(insertAfterNode);
                if (insertAfterNode == head) {                  //if moving the tail to head position
                    movingNode->SetNext(head->GetNext());
                    head = movingNode;
                }
            } else {
                cout << "OTHER" << endl;
            }
*/