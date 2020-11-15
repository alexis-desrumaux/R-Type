/*
** EPITECH PROJECT, 2020
** OOP_arcade_2019
** File description:
** SFML
*/

#ifndef SFML_HPP_
#define SFML_HPP_

#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Graphics/Export.hpp>
#include <SFML/Graphics/Shape.hpp>
#include <SFML/System/String.hpp>
#include <SFML/Audio/Sound.hpp>
#include <SFML/Audio/SoundBuffer.hpp>
#include <SFML/Audio/Music.hpp>
#include "IGLib.hpp"
#include "../../../Parser/include/Parser.hpp"
#include "./Event.hpp"

namespace SFML
{
    class LComponents {
        public:
        //functions
            LComponents() = default;
            virtual ~LComponents() = default;
            virtual void draw(std::shared_ptr<sf::RenderWindow>) = 0;
        //settings
            std::string componentName;
            std::string serializedComponent;
            bool display;
    };
    namespace LComponent {
        class Sprite : public LComponents {
            public:
            //functions
                Sprite(std::shared_ptr<Component::Sprite>);
                virtual ~Sprite();
                int update(std::shared_ptr<Component::Sprite>);
                void draw(std::shared_ptr<sf::RenderWindow>);
            private:
            //settings
                sf::Sprite sprite;
                sf::Texture texture;
        };
        class Text : public LComponents {
            public:
            //functions
                Text(std::shared_ptr<Component::Text>);
                virtual ~Text();
                virtual int update(std::shared_ptr<Component::Text>);
                void draw(std::shared_ptr<sf::RenderWindow>);
            private:
            //settings
                std::shared_ptr<sf::Text> text;
                std::shared_ptr<sf::Font> font;
        };
        class Audio : public LComponents {
            public:
            //functions
                Audio(std::shared_ptr<Component::Audio>);
                ~Audio();
                virtual int update(std::shared_ptr<Component::Audio>);
                void draw(std::shared_ptr<sf::RenderWindow>);
            private:
            //settings
                sf::SoundBuffer buffer;
                sf::Sound sound;
                bool onPlaying;
                bool reload;
                int audioState;
        };
    }
    class SFML : public IGLib {
        public:
            SFML();
            virtual ~SFML();
            virtual std::shared_ptr<eventType_t> display(std::vector<std::shared_ptr<Components>>);
            int draw(void);
        protected:
        private:
        //fonctions
            void checkForNewComponents(std::vector<std::shared_ptr<Components>>&);
            void checkForDeletedComponents(std::vector<std::shared_ptr<Components>>&);
            void checkForMovedComponents(std::vector<std::shared_ptr<Components>>&);
            int manageUpdate(std::vector<std::shared_ptr<Components>>);
        //settings
            std::shared_ptr<sf::RenderWindow> window;
            std::shared_ptr<eventType_t> eventStruct;
            std::vector<std::shared_ptr<LComponents>> lComponents;
    };
}

sf::Color convertColorFromComponent(Component::Color::Color color);
std::string SFKeyToString(unsigned int keycode);
std::shared_ptr<SFML::LComponents> findInLComponents(std::vector<std::shared_ptr<SFML::LComponents>> &lcomponents, std::string name);

#endif /* !SFML_HPP_ */
