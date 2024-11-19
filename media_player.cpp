#include <iostream>
#include <queue>
#include <string>

using namespace std;

class MusicPlayer {
private:
    queue<string> playlist; // Queue to store the songs
    string current_song;    // The currently playing song
    bool is_playing;        // Flag to indicate if music is playing

public:
    // Constructor to initialize the music player
    MusicPlayer() : current_song(""), is_playing(false) {}

    // Method to add a song to the playlist
    void add_song(const string& song) {
        playlist.push(song);
    }

    // Method to play the current song
    void play() {
        if (is_playing) {
            cout << "Already playing: " << current_song << "\n";
            return;
        }

        if (!current_song.empty()) {
            // Resume the paused song
            is_playing = true;
            cout << "Resuming: " << current_song << "\n";
            return;
        }

        if (playlist.empty()) {
            cout << "Playlist is empty.\n";
            return;
        }

        // Play the next song in the playlist
        current_song = playlist.front();
        playlist.pop();
        is_playing = true;
        cout << "Now playing: " << current_song << "\n";
    }

    // Method to pause the current song
    void pause() {
        if (!is_playing) {
            cout << "Playback is not currently playing.\n";
            return;
        }
        is_playing = false;
        cout << "Playback paused: " << current_song << "\n";
    }

    // Method to skip the current song and play the next one
    void skip() {
        if (playlist.empty()) {
            cout << "Playlist is empty.\n";
            return;
        }

        current_song = playlist.front();
        playlist.pop();
        is_playing = true;
        cout << "Now playing: " << current_song << "\n";
    }

    // Method to stop the music player and clear the playlist
    void stop() {
        while (!playlist.empty()) {
            playlist.pop();
        }
        current_song = "";
        is_playing = false;
        cout << "Music Player Stopped.\n";
    }
};

int main() {
    MusicPlayer player;

    // Adding songs to the playlist
    while (true) {
        string song;
        cout << "Add a song (or type \"stop\" to stop adding songs): ";
        getline(cin, song);

        if (song == "stop" || song == "STOP") {
            break;
        }
        player.add_song(song);
        cout << "Song Added.\n";
    }

    // Menu to interact with the music player
    while (true) {
        int choice;
        cout << "\nWhat do you want to do:-\n1. Play\n2. Pause\n3. Skip\n4. Stop\n";
        cin >> choice;
        cin.ignore(); // To clear the newline character from the input buffer

        switch (choice) {
        case 1:
            player.play();
            break;
        case 2:
            player.pause();
            break;
        case 3:
            player.skip();
            break;
        case 4:
            player.stop();
            return 0;
        default:
            cout << "Invalid Option. Please enter a number between 1 and 4.\n";
        }
    }

    return 0;
}
