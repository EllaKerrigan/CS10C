#include <iostream>
#include <string>

#include "Playlist.h"

using namespace std;

//CONSTRUCTORS
PlaylistNode::PlaylistNode() {
    this->uniqueID = "none";
    this->songName = "none"; 
    this->artistName = "none";
    this->songLength = 0;
    this->nextNodePtr = nullptr;
}

PlaylistNode::PlaylistNode(string uniqueID, string songName, string artistName, int songLength)
{
    this->uniqueID = uniqueID;
    this->songName = songName;
    this->artistName = artistName;
    this->songLength = songLength;
    nextNodePtr = nullptr;
}

void PlaylistNode::InsertAfter(PlaylistNode* newNode)
{
    PlaylistNode* tempNode = nextNodePtr;
    nextNodePtr = newNode;
    newNode->SetNext(tempNode);
}

//MUTATORS
void PlaylistNode::SetNext(PlaylistNode* newNode)
{
    nextNodePtr = newNode;
}


//ACCESSORS
string PlaylistNode::GetID() const
{
    return uniqueID;
}

string PlaylistNode::GetSongName() const
{
    return songName;
}

string PlaylistNode::GetArtistName() const
{
    return artistName;
}

int PlaylistNode::GetSongLength() const
{
    return songLength;
}

PlaylistNode* PlaylistNode::GetNext() const
{
    return nextNodePtr;
}

void PlaylistNode::PrintPlaylistNode() const
{
    cout << "Unique ID: " << uniqueID << endl;
    cout << "Song Name: " << songName << endl;
    cout << "Artist Name: " << artistName << endl;
    cout << "Song Length (in seconds): " << songLength << endl;
}


//Playlist class implementations 
Playlist::Playlist(){
    this->head = nullptr;
    this->tail = nullptr;
} 


void Playlist::print(string userTitle) const
{
    cout << userTitle << " - OUTPUT FULL PLAYLIST" << endl;

    if (!empty())
    {
        int num = 1;
        PlaylistNode* newNode = this->head;
        while(newNode != nullptr)
        {
            cout << num << "." << endl;
            newNode->PrintPlaylistNode();
            cout << endl;
            ++num;
            newNode = newNode->GetNext();
        }
    }else{
        cout << "Playlist is empty" << endl;
        cout << endl;
        }  
}

bool Playlist::empty() const
{
    return this->head == nullptr;
}

void Playlist::push_back(PlaylistNode * newNode)
{
    if (!empty())
    {
        this->tail->SetNext(newNode);
        this->tail = newNode;
    }else
    {
       this->head = newNode;
       this->tail = newNode;
    }
}

PlaylistNode* Playlist::remove(string userId)
{
    PlaylistNode* currVal = this->head;
    PlaylistNode* prevVal = nullptr;

    while (currVal != nullptr && currVal->GetID() != userId)
    {
        prevVal = currVal;
        currVal = currVal->GetNext();
    }
    if (currVal != nullptr)
    {
        if (prevVal != nullptr)
        {
            prevVal->SetNext(currVal->GetNext());
        }
        else
        {
            this->head = currVal->GetNext();
        }

        if (!currVal->GetNext())
        {
            this->tail = prevVal;
        }

        return currVal;
    }
    else
    {
        return nullptr;
    }
    
}

void Playlist::changePos(int origPos, int newPos)
{
    PlaylistNode* currVal = this->head;
    PlaylistNode* prevVal = nullptr;
    int initialIndex = 1;
    
    if (origPos <= 0)
    {
        cout << "Invalid current position." << endl;
        return;
    }
    
    while (initialIndex < origPos)
    //Find the pointer you want to shift over 
    {
        if (currVal != nullptr)
        {
            prevVal = currVal;
            currVal = currVal->GetNext();
            ++initialIndex;
            if (currVal == nullptr)
            {
                cout << "Invalid current position." << endl;
                return;
            }
        }
        else
        {
            cout << "Invalid current position." << endl;
            return;
        }
    }

    if (prevVal != nullptr)
    {
        prevVal->SetNext(currVal->GetNext());
    }
    else
    {
        this->head = currVal->GetNext();
    }

    if (currVal == this->tail)
    {
        this->tail = prevVal;
    }

    if (newPos <= 1) 
    {
        if (empty())
        {
            this->tail = currVal;
        }

        currVal->SetNext(head);
        this->head = currVal;
        cout << '"' << currVal->GetSongName() << '"' << " moved to position 1" << endl;
    }
    else {
        if (empty()) 
        {
            push_back(currVal);
            cout << '"' << currVal->GetSongName() << '"' << " moved to position 1" << endl;
        }
        else
        {
            int newPosIndex = 2;
            PlaylistNode *prevNode = this->head;
            PlaylistNode *newNode = this->head->GetNext();
            while (newPosIndex < newPos && newNode != nullptr)
            {
                prevNode = newNode;
                newNode = newNode->GetNext();
                ++newPosIndex;
            }

            prevNode->InsertAfter(currVal);

            if (newNode == nullptr) 
            {
                this->tail = currVal;
            }
            cout << '"' << currVal->GetSongName() << '"' << " moved to position " << newPosIndex << endl;
        }
    }
}

void Playlist::printByArtist(string artist) const
{
    int positionCounter = 1;
    PlaylistNode* newNode = head;
    while (newNode != nullptr)
    {
        if (newNode->GetArtistName() == artist)
        {
            cout << positionCounter << "." << endl;
            newNode->PrintPlaylistNode();
            cout << endl;
        }

        ++positionCounter;
        newNode = newNode->GetNext();
    }
}

int Playlist::totalTimeSeconds() const
{
    int totalTime = 0;
    PlaylistNode* newNode = this->head;
    while (newNode != nullptr)
    {
        totalTime += newNode->GetSongLength();
        newNode = newNode->GetNext();
    }
    return totalTime;
}