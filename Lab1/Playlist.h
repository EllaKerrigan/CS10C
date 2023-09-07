#include <iostream>

#include <string>

using namespace std;

#ifndef _PLAYLIST_H
#define _PLAYLIST_H


class PlaylistNode
{

public:

    PlaylistNode();
    PlaylistNode(string, string, string, int);
    void InsertAfter(PlaylistNode*);
    void SetNext(PlaylistNode*);
    string GetID() const;
    string GetSongName() const;
    string GetArtistName() const;
    int GetSongLength() const;
    PlaylistNode* GetNext() const;
    void PrintPlaylistNode() const;

    private:
    string uniqueID;
    string songName;
    string artistName;
    int songLength;
    PlaylistNode* nextNodePtr;

};

class Playlist
{
    public:
        Playlist();
        void print(string title) const;
        bool empty() const;
        void push_back(PlaylistNode*);
        PlaylistNode* remove(string);
        void changePos(int, int);
        void printByArtist(string) const;
        int totalTimeSeconds() const;

    private:
        PlaylistNode* head;
        PlaylistNode* tail;

};
#endif