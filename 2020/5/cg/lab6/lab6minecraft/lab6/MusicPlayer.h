#ifndef MusicPlayer_H_INCLUDED
#define MusicPlayer_H_INCLUDED

#include <SFML/Audio.hpp>

//This is for when I send the game to friends.
//Music takes up alot of space, and I would rather send a 3mb .7z rather than
//a 50mb .7z, hence I can just comment out this define, and then

#define MusicPlayer_ACTIVE

class MusicPlayer
{
    public:
        MusicPlayer();

        void update();

    private:
        void getNextSong();

        sf::Music m_music;
        sf::Time  m_duration;
        sf::Clock m_timer;

        std::vector<std::string> m_songs;
        uint32_t m_currentSong = 0;
};

#endif // MusicPlayer_H_INCLUDED
