/*
** EPITECH PROJECT, 2020
** OOP_arcade_2019
** File description:
** Sfml_c
*/

#include "../include/SFML.hpp"

/*--------------------------------AUDIO-----------------------------------*/

void SFML::LComponent::Audio::draw(std::shared_ptr<sf::RenderWindow>)
{
    if (this->audioState == Component::AudioState::RELOAD && this->reload == true) {
        this->sound.play();
        this->reload = false;
        this->onPlaying = true;
    }
    if (this->onPlaying == false && this->audioState == Component::AudioState::PLAY && this->display == true) {
        this->sound.play();
        this->onPlaying = true;
    }
    if (this->audioState == Component::AudioState::STOP) {
        this->sound.stop();
        this->onPlaying = false;
    }
    if (this->audioState == Component::AudioState::PAUSE  || this->display == false) {
        this->sound.pause();
        this->onPlaying = false;
    }
}

int SFML::LComponent::Audio::update(std::shared_ptr<Component::Audio> audio)
{
    Parser parserSrc = Parser(audio->serialize());
    Parser parserDest = Parser(this->serializedComponent);

    if (parserSrc.getValueOfKey("display") != parserDest.getValueOfKey("display"))
        this->display = audio->display;
    if (parserSrc.getValueOfKey("path") != parserDest.getValueOfKey("path")) {
        this->sound.stop();
        this->buffer.loadFromFile(audio->getAudioPath());
        this->sound.setBuffer(this->buffer);
    }
    if (parserSrc.getValueOfKey("audioState") != parserDest.getValueOfKey("audioState")) {
        if (audioState == Component::AudioState::PAUSE)
            this->audioState = Component::AudioState::PAUSE;
        else if (audioState == Component::AudioState::PLAY)
            this->audioState = Component::AudioState::PLAY;
        else if (audioState == Component::AudioState::STOP)
            this->audioState = Component::AudioState::STOP;
        else if (audioState == Component::AudioState::RELOAD) {
            this->audioState = Component::AudioState::RELOAD;
            this->reload = true;
        }
    }
    if (parserSrc.getValueOfKey("loop") != parserDest.getValueOfKey("loop")) {
        this->sound.setLoop(audio->isLoop());
    }
    this->serializedComponent = audio->serialize();
    return 0;
}

SFML::LComponent::Audio::Audio(std::shared_ptr<Component::Audio> audio)
{
    this->componentName = audio->componentName;
    this->serializedComponent = audio->serialize();
    this->display = audio->display;
    this->buffer.loadFromFile(audio->getAudioPath());
    this->sound.setBuffer(this->buffer);
    this->sound.setLoop(audio->isLoop());
    this->audioState = audio->getAudioState();
}

SFML::LComponent::Audio::~Audio()
{
    this->sound.stop();
    std::cout << "DELETED LCOMPONENT " << this->componentName << std::endl;
}

/*--------------------------------SPRITE-----------------------------------*/


void SFML::LComponent::Sprite::draw(std::shared_ptr<sf::RenderWindow> window)
{
    window = window;
    if (this->display == true)
        window->draw(this->sprite);
}

int SFML::LComponent::Sprite::update(std::shared_ptr<Component::Sprite> sprite)
{
    Parser parserSrc = Parser(sprite->serialize());
    Parser parserDest = Parser(this->serializedComponent);

    if (parserSrc.getValueOfKey("display") != parserDest.getValueOfKey("display"))
        this->display = sprite->display;
    if (parserSrc.getValueOfKey("path") != parserDest.getValueOfKey("path")) {
        this->texture.loadFromFile(sprite->getSpritePath());
        this->texture.setSmooth(true);
        this->sprite.setTexture(this->texture);
    }
    if (parserSrc.getValueOfKey("pos") != parserDest.getValueOfKey("pos")) {
        std::pair<float, float> xy = sprite->getPosition();
        this->sprite.setPosition(sf::Vector2f(xy.first, xy.second));
    }
    if (parserSrc.getValueOfKey("scale") != parserDest.getValueOfKey("scale")) {
        std::pair<float, float> scale = sprite->getScale();
        this->sprite.setScale(sf::Vector2f(scale.first, scale.second));
    }
    if (parserSrc.getValueOfKey("rect") != parserDest.getValueOfKey("rect")) {
        std::pair<std::pair<int, int>, std::pair<int, int>> rect = sprite->getRect();
        sf::IntRect sfRect;
        if (rect.first.first != -1 && rect.first.second != -1 && rect.second.first != -1 &&
        rect.second.second != -1) {
            sfRect.left = rect.first.first;
            sfRect.width = rect.first.second;
            sfRect.top = rect.second.first;
            sfRect.height = rect.second.second;
            this->sprite.setTextureRect(sfRect);
        }
    }
    this->serializedComponent = sprite->serialize();
    return 0;
}

SFML::LComponent::Sprite::Sprite(std::shared_ptr<Component::Sprite> sprite)
{
    std::pair<float, float> xy = sprite->getPosition();
    std::pair<float, float> scale = sprite->getScale();
    std::pair<std::pair<int, int>, std::pair<int, int>> rect = sprite->getRect();
    sf::IntRect sfRect;

    this->serializedComponent = sprite->serialize();
    this->texture.loadFromFile(sprite->getSpritePath());
    this->texture.setSmooth(true);
    this->sprite.setTexture(this->texture);
    this->sprite.setPosition(sf::Vector2f(xy.first, xy.second));
    this->sprite.setScale(sf::Vector2f(scale.first, scale.second));
    if (rect.first.first != -1 && rect.first.second != -1 && rect.second.first != -1 &&
    rect.second.second != -1) {
        sfRect.left = rect.first.first;
        sfRect.width = rect.first.second;
        sfRect.top = rect.second.first;
        sfRect.height = rect.second.second;
        this->sprite.setTextureRect(sfRect);
    }
    this->componentName = sprite->componentName;
    this->display = sprite->display;
}

SFML::LComponent::Sprite::~Sprite()
{
    std::cout << "DELETED LCOMPONENT " << this->componentName << std::endl;
}

/*--------------------------------TEXT-----------------------------------*/

void SFML::LComponent::Text::draw(std::shared_ptr<sf::RenderWindow> window)
{
    if (this->display == true) {
        window->draw(*this->text);
    }
}

int SFML::LComponent::Text::update(std::shared_ptr<Component::Text> text)
{
    Parser parserSrc = Parser(text->serialize());
    Parser parserDest = Parser(this->serializedComponent);


    if (parserSrc.getValueOfKey("display") != parserDest.getValueOfKey("display"))
        this->display = text->display;
    if (parserSrc.getValueOfKey("color") != parserDest.getValueOfKey("color")) {
        sf::Color color = convertColorFromComponent(text->getColor());
        this->text->setFillColor(color);
    }
    if (parserSrc.getValueOfKey("str") != parserDest.getValueOfKey("str"))
        this->text->setString(text->getText());
    if (parserSrc.getValueOfKey("fontPath") != parserDest.getValueOfKey("fontPath")) {
        this->font->loadFromFile(text->getFontPath());
        this->text->setFont(*this->font);
    }
    if (parserSrc.getValueOfKey("size") != parserDest.getValueOfKey("size"))
        this->text->setCharacterSize(text->getFontSize());
    if (parserSrc.getValueOfKey("pos") != parserDest.getValueOfKey("pos")) {
        std::pair<float, float> xy = text->getPosXY();
        this->text->setPosition(sf::Vector2f(xy.first, xy.second));
    }
    this->serializedComponent = text->serialize();
    return 0;
}

SFML::LComponent::Text::Text(std::shared_ptr<Component::Text> text)
{
    this->serializedComponent = text->serialize();
    sf::Color color;
    this->font = std::make_shared<sf::Font>();
    this->text = std::make_shared<sf::Text>();
    this->font->loadFromFile(text->getFontPath());
    this->text->setFont(*font);
    this->text->setString(sf::String(text->getText()));
    std::pair<float, float> xy = text->getPosXY();
    this->text->setPosition(sf::Vector2f(xy.first, xy.second));
    this->text->setCharacterSize(text->getFontSize());
    color = convertColorFromComponent(text->getColor());
    this->text->setFillColor(color);
    this->componentName = text->componentName;
    this->display = text->display;
}

SFML::LComponent::Text::~Text()
{
    std::cout << "DELETED LCOMPONENT " << this->componentName << std::endl;
}

/*---------------------------LComponents-----------------------------------*/

std::shared_ptr<SFML::LComponents> findInLComponents(std::vector<std::shared_ptr<SFML::LComponents>> &lcomponents, std::string name)
{
    for (size_t i = 0; i != lcomponents.size(); i += 1) {
        if (lcomponents.at(i)->componentName == name)
            return lcomponents.at(i);
    }
    return NULL;
}

