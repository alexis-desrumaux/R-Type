/*
** EPITECH PROJECT, 2020
** OOP_arcade_2019
** File description:
** Components
*/

#ifndef COMPONENTS_HPP_
#define COMPONENTS_HPP_

#include <iostream>
#include <vector>
#include <memory>
#include "../../../Parser/include/Parser.hpp"

namespace listComponent {
    enum listComponent {
        TEXT = 0,
        SPRITE = 1,
        AUDIO = 2,
    };
}

class Components {
    public:
    //functions
        Components() = default;
        virtual ~Components() = default;
        virtual std::string serialize(void) = 0;
    //data
        std::string componentName;
        listComponent::listComponent type;
        bool display;
    protected:
    private:
};

std::shared_ptr<Components> findInComponents(std::vector<std::shared_ptr<Components>>, std::string);

namespace Component
{
    namespace Color {
        enum Color {
            White = 0,
            Black = 1,
            Red = 2,
            Green = 3,
            Blue = 4,
        };
    }
    namespace AudioState {
        enum AudioState {
            STOP = -1,
            PAUSE = 0,
            PLAY = 1,
            RELOAD = 2,
        };
    }
    namespace State {
        enum State {
            NONE = -1,
            ADD = 0,
            UPDATE = 1,
            DELETE = 2,
        };
    }
    class Text : public Components {
        public:
        //functions
            Text(std::string componentName, std::string str, std::string fontPath, int size, Color::Color color, std::pair<float, float> pos);
            Text(std::string data);
            virtual ~Text();
            Color::Color getColor(void);
            void setColor(Color::Color color);
            std::string getText(void);
            void setText(std::string str);
            std::string getFontPath(void);
            void setFontPath(std::string path);
            int getFontSize(void);
            void setFontSize(int size);
            std::pair<float, float> getPosXY(void);
            void setPosXY(std::pair<float, float> pos);
            virtual std::string serialize(void);

        private:
        //settings
            Color::Color color;
            std::string str;
            std::string fontPath;
            int size;
            std::pair<float, float> pos;
    };
    class Sprite : public Components {
        public:
        //functions
            Sprite(std::string componentName, std::string path, std::pair<float, float> pos, std::pair<float, float> scale);
            Sprite(std::string data);
            virtual ~Sprite();
            std::string getSpritePath(void);
            void setSpritePath(std::string path);
            std::pair<float, float> getPosition();
            void setPosition(std::pair<float, float>);
            std::pair<float, float> getScale();
            void setScale(std::pair<float, float>);
            std::pair<std::pair<int, int>, std::pair<int, int>> getRect(void);
            void setRect(int x, int size_x, int y, int size_y);
            virtual std::string serialize(void);

        private:
        //settings
            std::string path;
            std::pair<float, float> pos;
            std::pair<float, float> scale;
            std::pair<std::pair<int, int>, std::pair<int, int>> rect;
    };
    class Audio : public Components {
        public:
        //functions
            Audio(std::string componentName, std::string path, AudioState::AudioState state, bool loop);
            Audio(std::string data);
            virtual ~Audio();
            std::string getAudioPath(void);
            void setAudioPath(std::string);
            AudioState::AudioState getAudioState(void);
            void setAudioState(AudioState::AudioState);
            bool isLoop(void);
            void setLoop(bool state);
            virtual std::string serialize(void);
        private:
        //settings
            std::string path;
            AudioState::AudioState audioState;
            bool loop;
    };
}

#endif /* !COMPONENTS_HPP_ */
